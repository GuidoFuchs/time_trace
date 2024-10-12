#pragma once
#include <cstdint>
#include "terminal_colors/rgb_colors.h"

namespace terminal_colors {

enum print_mode {no_color, rgb};

extern void terminal_colors_draw_example();

class terminal_colors {
private:
  // foreground colors: "\033[38;2;<r>;<g>;<b>m";
  // Background colors: "\033[48;2;<r>;<g>;<b>m";
  char work_string[38] = "\033[38;2;\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0";
  const char * empty_string = "\0";

  print_mode mode{rgb};

  static constexpr int header_length{7};
  int index{header_length};

  inline void copy_10digit_into_string(int n)
  {
    work_string[index] = n + '0';
    index++;
  }

  void copy_dec_number_into_string(u_int32_t n)
  {
    uint32_t m = n < 256 ? n : 255;
    int d100 = m / 100;
    m = m - d100*100;
    int d10 = m / 10;
    int d1 = m - d10*10;

    if (d100) copy_10digit_into_string(d100);
    if (d10 or d100) copy_10digit_into_string(d10);
    copy_10digit_into_string(d1);
  }

  inline const char * render_mode_dependent(const char * string)
  {
    if (mode == rgb)
      return string;
    else
      return empty_string;
  }

  void rgb_to_string(const rgb_color& color)
  {
    copy_dec_number_into_string(color.get_red());
    work_string[index] = ';';
    index++;
    copy_dec_number_into_string(color.get_green());
    work_string[index] = ';';
    index++;
    copy_dec_number_into_string(color.get_blue());
    work_string[index] = 'm';
    index++;
  }

  const char * finish_string()
  {
    work_string[index] = '\0';
    index = header_length;
    return render_mode_dependent(&work_string[0]);
  }

  const char * set_color(const rgb_color& color)
  {
    rgb_to_string(color);
    return finish_string();
  }

public:

  rgb_color hsv_to_rgb(double hue, double saturation, double value)
  { //converts hsv color space to rgb colors
    double r{0.};
    double g{0.};
    double b{0.};
    double p{0.};
    double q{0.};
    double t{0.};
    double remainder{0.};
    int32_t i{0};

    double v = value > 1.0 ? 1.0 : value;
    v = v < 0.0 ? 0.0 : v;
    double s = saturation > 1.0 ? 1.0 : saturation;
    if(s <= 0.0) {
        r = v;
        g = v;
        b = v;
        return rgb_color{r, g, b};
    }

    double h{hue};
    h = h > 360.0 ? 0.0 : h/60.0;
    i = static_cast<int32_t>(h);
    remainder = h - i;
    p = v * (1.0 - s);
    q = v * (1.0 - (s * remainder));
    t = v * (1.0 - (s * (1.0 - remainder)));

    switch(i) {
    case 0:
        r = v;
        g = t;
        b = p;
        break;
    case 1:
        r = q;
        g = v;
        b = p;
        break;
    case 2:
        r = p;
        g = v;
        b = t;
        break;

    case 3:
        r = p;
        g = q;
        b = v;
        break;
    case 4:
        r = t;
        g = p;
        b = v;
        break;
    case 5:
    default:
        r = v;
        g = p;
        b = q;
        break;
    }
    return rgb_color{r, g, b};
  }

  void print()
  {
    for (int i = 0; i < 39; ++i) std::cout << (int)work_string[i] << " " << (int)(work_string[i]-'0') << "    " ;
  }

  const char * foreground_and_background(const rgb_color& foreground, const rgb_color& background)
  {
    work_string[2] = '3';
    rgb_to_string(foreground);
    work_string[index] = 27;
    index++;
    work_string[index] = 91;
    index++;
    work_string[index] = '4';
    index++;
    work_string[index] = '8';
    index++;
    work_string[index] = ';';
    index++;
    work_string[index] = '2';
    index++;
    work_string[index] = ';';
    index++;
    rgb_to_string(background);
    return finish_string();
  }

  const char * foreground(rgb_color color)
  {
    work_string[2] = '3';
    return set_color(color);
  }
  template<class T>
  const char * foreground(T red, T green, T blue)
  {
    const rgb_color color{red, green, blue};
    return foreground(color);
  }

  // some terminals are opinionated and will not display the colors
  // as requested, when foreground and background is to similar in color
  const char * background(rgb_color color)
  {
    work_string[2] = '4';
    return set_color(color);
  }
  template<class T>
  const char * background(T red, T green, T blue)
  {
    const rgb_color color{red, green, blue};
    return background(color);
  }

  inline const char * foreground_readable(const rgb_color color)
  {
    constexpr int threshold = 99; // dark green the darkest predefined color beside black is "0, 100, 0"
    double bright = color.sum() > threshold;
    if (bright) return foreground_and_background(color, black);
    else return foreground_and_background(color, white);
  }

  inline const char * background_readable(const rgb_color color)
  {
    constexpr int threshold = 255 * 3 / 2;
    double bright = color.sum() > threshold;
    if (bright) return foreground_and_background(black, color);
    else return foreground_and_background(white, color);
  }

  inline const char * reset()
  {
    return render_mode_dependent("\033[0m");
  }
  inline const char * reset_foreground()
  {
    return render_mode_dependent("\033[39m");
  }
  inline const char * reset_background()
  {
    return render_mode_dependent("\033[49m");
  }
  inline const char * bold()
  {
    return render_mode_dependent("\033[1m");
  }
  inline const char * faint()
  {
    return render_mode_dependent("\033[2m");
  }
  inline const char * italic()
  {
    return render_mode_dependent("\033[3m");
  }
  inline const char * underlined()
  {
    return render_mode_dependent("\033[4m");
  }
  inline const char * inverse()
  {
    return render_mode_dependent("\033[7m");
  }
  inline const char * crossed_out()
  {
    return render_mode_dependent("\033[9m");
  }
};
} // namespace terminal_colors
