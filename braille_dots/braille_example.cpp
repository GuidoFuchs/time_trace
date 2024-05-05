#include <iostream>
#include <cmath>
#include "braille_dots.h"



void draw_sin()
{
  std::cout << "\n\nSimple sin function plot using the braille patterns:";
  braille_dots::braille_dots dots;
  constexpr double step_plot{0.1};
  constexpr double x_offset_1{0.25};
  constexpr double x_offset_2{0.75};
  double x{0};
  double y{0};

  for(int32_t line = 5; line > -6; line--) {
    for(int32_t i_char = 0; i_char < 63; i_char++){
      dots.reset();
      // Loops over characters
      // 2 dots in x direction per character
      x = step_plot * (x_offset_1 + i_char);
      y = sin(x);
      y = 5 * y - line ;
      dots.set_closest_dot(x_offset_1, y);

      x = step_plot * (x_offset_2 + i_char);
      y = sin(x);
      y = 5 * y - line ;
      dots.set_closest_dot(x_offset_2, y);
      std::cout << dots.get_character();
    }
    std::cout << std::endl;
  }
}

void write_out_all_braille_dots() {
  std::cout << "\n\nBraille patterns character table\nhttps://en.wikipedia.org/wiki/Braille_Patterns\n";
  std::cout << "UniCode  0 1 2 3 4 5 6 7 8 9 A B C D E F\n";
  std::cout << "       ┌--------------------------------\n";
  for (int32_t i= 0; i < 16; ++i)
  {
    std::cout << "U+28" << std::hex << std::uppercase << i <<  "x | ";
    for (int32_t j= 0; j < 16; ++j)
    {
      std::cout << braille_dots::braille_table::dots_table[i*16 + j] << " ";
    }
    std::cout << std::endl;
  }
}

int main(int argc, char *argv[]) {
    static_cast<void>(argc);
    static_cast<void>(argv);
    
    std::cout << "\n";
    std::cout << "Examples for how to use the braille dots.\n";
    std::cout << "Especially when used for plotting and console graphics, the visual quality will very much depend on the font used.\n";
    std::cout << "Not all fonts distribute the braille dots equidistant.";
    std::cout << "\n";

    braille_dots::braille_dots dots;
    dots.set_dot(0, 3); // index start counting at "0". 0 == first from the bottom or left
    dots.set_dot(0, 1);
    dots.set_dot(1, 1);
    dots.set_dot(1, 2); 
    braille_dots::braille_dots z{dots};

    std::cout << "The symbol "<< z.get_character() << " stands for the letter z in the English Braille alphabet.\n";
    std::cout << "It has a dot in the top left corner:                          \"";
    dots.reset();
    dots.set_dot(0, 3);
    std::cout << dots.get_character();
    std::cout << "\".\n";
    std::cout << "It has a dot in the second line from the bottom on the left:  \"";
    dots.reset();
    dots.set_dot(0, 1);
    std::cout << dots.get_character();
    std::cout << "\".\n";
    std::cout << "It has a dot in the second line from the bottom on the right: \"";
    dots.reset();
    dots.set_dot(1, 1);
    std::cout << dots.get_character();
    std::cout << "\".\n";
    std::cout << "It has a dot in the third line from the bottom on the right:  \"";
    dots.reset();
    dots.set_dot(1, 2);
    std::cout << dots.get_character();
    std::cout << "\".\n";

    draw_sin();
    write_out_all_braille_dots();
    return 0;
}
