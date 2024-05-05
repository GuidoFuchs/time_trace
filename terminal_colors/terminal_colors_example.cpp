#include <iostream>
#include <array>

#include "terminal_colors/terminal_colors.h"

void simple_example()
{
  terminal_colors::terminal_colors color;

  // colors can also be set directly as rgb colors
  uint8_t red{200};
  uint8_t green{0};
  uint8_t blue{255};
  std::cout << color.foreground(red, green, blue);
  std::cout << "RGB color purple text" << color.reset();
  std::cout << "\n\n";

  std::cout << "Text can be " << color.bold() << "bold, " << color.reset();
  std::cout << color.italic() << "or italic, " << color.reset();
  std::cout << color.faint() << "or faint, " << color.reset();
  std::cout << color.underlined() << "or underlined." << color.reset();
  std::cout << color.reset();
  std::cout << "\n\n";  

  // set foreground color (the characters) to predefined medium blue
  std::cout << color.foreground(terminal_colors::mediumblue); 
  // set background color to "wheat" color
  std::cout << color.background(terminal_colors::wheat);
  std::cout << "Text using predefined colors and colors for background and foreground(the characters)\n";
  std::cout << color.reset(); // go back to defaults

  // Some terminals allow setting foreground and background to the same color
  std::cout << "Some terminals allow setting the background the same color as the foreground: ";
  std::cout << color.foreground(terminal_colors::slategrey);
  std::cout << color.background(terminal_colors::slategrey);
  std::cout << "(in this case this text might be unreadable)";
  std::cout << color.reset();
  std::cout << " text can be unreadable.\nThis is terminal dependent.\n\n";

  std::cout << "To prevent this one can use the _readable functions, that always guarantied contrast.\n";
  std::cout << color.foreground(terminal_colors::slategrey);
  std::cout << color.background_readable(terminal_colors::slategrey);
  std::cout << "The _readable functions override the foreground for background_readable and the other way around to assure read-ability.";
  std::cout << color.reset();
  std::cout << "\n\n";
}


void rainbow_loren_ipsum()
{
  const char * loren_ipsum = "The quick brown fox jumps over the lazy dog";
  int i = 0;
  terminal_colors::terminal_colors color;
  for (double hue = 0. ; hue < 360.  ; hue += 360./43){
    // Rainbow created in hsv color space => converted then to rgb  
    terminal_colors::rgb_color c = color.hsv_to_rgb(hue, 1., .95);
    std::cout << color.foreground(c) << loren_ipsum[i++];
  }
  std::cout << color.reset() << "\n\n";
}

void draw_suspicious_ninja(){
  enum class ce // color_enum
  {
      b = 0,
      l = 1,
      g = 2,
      o = 3,
      m = 4,
      d = 5,
      s = 6,
      k = 7
  };

  std::array<terminal_colors::rgb_color, 8> color_map{
      terminal_colors::deepskyblue,
      terminal_colors::indianred,
      terminal_colors::dimgray,
      terminal_colors::maroon,
      terminal_colors::mediumseagreen,
      terminal_colors::steelblue,
      terminal_colors::lightsteelblue,
      terminal_colors::rgb_color{40, 20, 20}
  };

  const std::array<std::array<ce, 20>, 21> sus_ninja{{
  {{ce::b,ce::b,ce::b,ce::b,ce::b,ce::b,ce::b,ce::b,ce::b,ce::b,ce::b,ce::b,ce::b,ce::b,ce::b,ce::b,ce::b,ce::b,ce::b,ce::b}},
  {{ce::b,ce::b,ce::b,ce::b,ce::b,ce::b,ce::b,ce::k,ce::k,ce::k,ce::k,ce::k,ce::k,ce::k,ce::k,ce::b,ce::b,ce::b,ce::b,ce::b}},
  {{ce::b,ce::b,ce::b,ce::b,ce::b,ce::b,ce::k,ce::k,ce::l,ce::l,ce::l,ce::l,ce::l,ce::l,ce::k,ce::k,ce::b,ce::b,ce::b,ce::b}},
  {{ce::b,ce::b,ce::b,ce::k,ce::k,ce::k,ce::k,ce::k,ce::k,ce::k,ce::k,ce::k,ce::k,ce::k,ce::k,ce::k,ce::k,ce::b,ce::b,ce::b}},
  {{ce::b,ce::b,ce::b,ce::k,ce::k,ce::g,ce::g,ce::g,ce::g,ce::g,ce::g,ce::g,ce::g,ce::g,ce::g,ce::g,ce::g,ce::k,ce::b,ce::b}},
  {{ce::b,ce::b,ce::k,ce::k,ce::k,ce::k,ce::k,ce::k,ce::k,ce::k,ce::k,ce::k,ce::k,ce::k,ce::k,ce::k,ce::k,ce::k,ce::b,ce::b}},
  {{ce::b,ce::k,ce::g,ce::k,ce::b,ce::k,ce::l,ce::l,ce::k,ce::d,ce::d,ce::m,ce::m,ce::s,ce::s,ce::s,ce::m,ce::k,ce::b,ce::b}},
  {{ce::b,ce::k,ce::g,ce::k,ce::k,ce::k,ce::l,ce::l,ce::k,ce::d,ce::d,ce::d,ce::m,ce::m,ce::m,ce::m,ce::m,ce::k,ce::b,ce::b}},
  {{ce::b,ce::k,ce::g,ce::k,ce::l,ce::k,ce::o,ce::l,ce::k,ce::k,ce::d,ce::d,ce::d,ce::d,ce::d,ce::d,ce::k,ce::k,ce::b,ce::b}},
  {{ce::b,ce::k,ce::g,ce::k,ce::o,ce::k,ce::o,ce::l,ce::l,ce::k,ce::k,ce::k,ce::k,ce::k,ce::k,ce::k,ce::k,ce::b,ce::b,ce::b}},
  {{ce::b,ce::k,ce::g,ce::k,ce::o,ce::k,ce::o,ce::l,ce::l,ce::l,ce::l,ce::l,ce::l,ce::l,ce::l,ce::o,ce::k,ce::b,ce::b,ce::b}},
  {{ce::b,ce::k,ce::g,ce::k,ce::o,ce::k,ce::o,ce::o,ce::l,ce::l,ce::l,ce::l,ce::l,ce::l,ce::o,ce::o,ce::k,ce::b,ce::b,ce::b}},
  {{ce::b,ce::k,ce::k,ce::k,ce::o,ce::k,ce::o,ce::o,ce::l,ce::l,ce::l,ce::l,ce::l,ce::l,ce::o,ce::o,ce::k,ce::b,ce::b,ce::b}},
  {{ce::b,ce::b,ce::k,ce::o,ce::o,ce::k,ce::o,ce::o,ce::o,ce::l,ce::l,ce::l,ce::l,ce::o,ce::o,ce::o,ce::k,ce::b,ce::b,ce::b}},
  {{ce::b,ce::b,ce::k,ce::o,ce::o,ce::k,ce::o,ce::o,ce::o,ce::o,ce::o,ce::o,ce::o,ce::o,ce::o,ce::o,ce::k,ce::b,ce::b,ce::b}},
  {{ce::b,ce::b,ce::b,ce::k,ce::k,ce::k,ce::o,ce::o,ce::o,ce::o,ce::o,ce::o,ce::o,ce::o,ce::o,ce::o,ce::k,ce::b,ce::b,ce::b}},
  {{ce::b,ce::b,ce::b,ce::b,ce::b,ce::k,ce::o,ce::o,ce::o,ce::k,ce::k,ce::k,ce::k,ce::k,ce::o,ce::o,ce::k,ce::b,ce::b,ce::b}},
  {{ce::b,ce::b,ce::b,ce::b,ce::b,ce::k,ce::o,ce::o,ce::o,ce::k,ce::b,ce::b,ce::k,ce::o,ce::o,ce::o,ce::k,ce::b,ce::b,ce::b}},
  {{ce::b,ce::b,ce::b,ce::b,ce::b,ce::k,ce::o,ce::o,ce::o,ce::k,ce::b,ce::b,ce::k,ce::o,ce::o,ce::o,ce::k,ce::b,ce::b,ce::b}},
  {{ce::b,ce::b,ce::b,ce::b,ce::b,ce::b,ce::k,ce::k,ce::k,ce::b,ce::b,ce::b,ce::b,ce::k,ce::k,ce::k,ce::b,ce::b,ce::b,ce::b}},
  {{ce::b,ce::b,ce::b,ce::b,ce::b,ce::b,ce::b,ce::b,ce::b,ce::b,ce::b,ce::b,ce::b,ce::b,ce::b,ce::b,ce::b,ce::b,ce::b,ce::b}}}};

  terminal_colors::terminal_colors color;
  std::cout << "  ";
  for(const auto& line: sus_ninja)
  {
    std::cout << "  ";
    for(const auto& px: line)
     {
        auto px_color = color_map[static_cast<int>(px)];
        std::cout << color.background(px_color) << " ";
     }
     std::cout << color.reset() << "\n  ";
  }
}

void draw_color_circle() {
  terminal_colors::terminal_colors color;
  constexpr int radius = 11;
  for (int y = -radius; y <= radius; ++y)
  {
    std::cout << "  ";
    for (int x = -radius; x <= radius; ++x)
    {
      if (x*x + y*y < radius*radius)
      {
        double hue = 360. * (atan2(y, x) + M_PI*.99999) / (2. * M_PI);
        double saturation = sqrt(x*x + y*y) / radius;
        terminal_colors::rgb_color c = color.hsv_to_rgb(hue, saturation, 1.0);
        std::cout << color.background(c) << " ";
      }
      else
      {
        std::cout << color.reset() << " ";
      }
    }
    std::cout << "\n";
  } 
}

void draw_color_tables(){
  using namespace terminal_colors;
  terminal_colors::terminal_colors color;
  std::cout << color.bold() << "  Different Foreground Colors\n  " << color.reset();
  std::cout << color.foreground_readable(black               ) << "black               ";
  std::cout << color.foreground_readable(bisque              ) << "bisque              ";
  std::cout << color.foreground_readable(forestgreen         ) << "forestgreen         ";
  std::cout << color.foreground_readable(slategrey           ) << "slategrey           ";
  std::cout << color.reset() << "\n  ";
  std::cout << color.foreground_readable(dimgray             ) << "dimgray             ";
  std::cout << color.foreground_readable(darkorange          ) << "darkorange          ";
  std::cout << color.foreground_readable(limegreen           ) << "limegreen           ";
  std::cout << color.foreground_readable(lightsteelblue      ) << "lightsteelblue      ";
  std::cout << color.reset() << "\n  ";
  std::cout << color.foreground_readable(dimgrey             ) << "dimgrey             ";
  std::cout << color.foreground_readable(burlywood           ) << "burlywood           ";
  std::cout << color.foreground_readable(darkgreen           ) << "darkgreen           ";
  std::cout << color.foreground_readable(cornflowerblue      ) << "cornflowerblue      ";
  std::cout << color.reset() << "\n  ";
  std::cout << color.foreground_readable(gray                ) << "gray                ";
  std::cout << color.foreground_readable(antiquewhite        ) << "antiquewhite        ";
  std::cout << color.foreground_readable(green               ) << "green               ";
  std::cout << color.foreground_readable(royalblue           ) << "royalblue           ";
  std::cout << color.reset() << "\n  ";
  std::cout << color.foreground_readable(grey                ) << "grey                ";
  std::cout << color.foreground_readable(terminal_colors::tan) << "tan                 ";
  std::cout << color.foreground_readable(lime                ) << "lime                ";
  std::cout << color.foreground_readable(ghostwhite          ) << "ghostwhite          ";
  std::cout << color.reset() << "\n  ";
  std::cout << color.foreground_readable(darkgray            ) << "darkgray            ";
  std::cout << color.foreground_readable(navajowhite         ) << "navajowhite         ";
  std::cout << color.foreground_readable(seagreen            ) << "seagreen            ";
  std::cout << color.foreground_readable(lavender            ) << "lavender            ";
  std::cout << color.reset() << "\n  ";
  std::cout << color.foreground_readable(darkgrey            ) << "darkgrey            ";
  std::cout << color.foreground_readable(blanchedalmond      ) << "blanchedalmond      ";
  std::cout << color.foreground_readable(mediumseagreen      ) << "mediumseagreen      ";
  std::cout << color.foreground_readable(midnightblue        ) << "midnightblue        ";
  std::cout << color.reset() << "\n  ";
  std::cout << color.foreground_readable(silver              ) << "silver              ";
  std::cout << color.foreground_readable(papayawhip          ) << "papayawhip          ";
  std::cout << color.foreground_readable(springgreen         ) << "springgreen         ";
  std::cout << color.foreground_readable(navy                ) << "navy                ";
  std::cout << color.reset() << "\n  ";
  std::cout << color.foreground_readable(lightgray           ) << "lightgray           ";
  std::cout << color.foreground_readable(moccasin            ) << "moccasin            ";
  std::cout << color.foreground_readable(mintcream           ) << "mintcream           ";
  std::cout << color.foreground_readable(darkblue            ) << "darkblue            ";
  std::cout << color.reset() << "\n  ";
  std::cout << color.foreground_readable(lightgrey           ) << "lightgrey           ";
  std::cout << color.foreground_readable(orange              ) << "orange              ";
  std::cout << color.foreground_readable(mediumspringgreen   ) << "mediumspringgreen   ";
  std::cout << color.foreground_readable(mediumblue          ) << "mediumblue          ";
  std::cout << color.reset() << "\n  ";
  std::cout << color.foreground_readable(gainsboro           ) << "gainsboro           ";
  std::cout << color.foreground_readable(wheat               ) << "wheat               ";
  std::cout << color.foreground_readable(mediumaquamarine    ) << "mediumaquamarine    ";
  std::cout << color.foreground_readable(blue                ) << "blue                ";
  std::cout << color.reset() << "\n  ";
  std::cout << color.foreground_readable(whitesmoke          ) << "whitesmoke          ";
  std::cout << color.foreground_readable(oldlace             ) << "oldlace             ";
  std::cout << color.foreground_readable(aquamarine          ) << "aquamarine          ";
  std::cout << color.foreground_readable(slateblue           ) << "slateblue           ";
  std::cout << color.reset() << "\n  ";
  std::cout << color.foreground_readable(white               ) << "white               ";
  std::cout << color.foreground_readable(floralwhite         ) << "floralwhite         ";
  std::cout << color.foreground_readable(turquoise           ) << "turquoise           ";
  std::cout << color.foreground_readable(darkslateblue       ) << "darkslateblue       ";
  std::cout << color.reset() << "\n  ";
  std::cout << color.foreground_readable(snow                ) << "snow                ";
  std::cout << color.foreground_readable(darkgoldenrod       ) << "darkgoldenrod       ";
  std::cout << color.foreground_readable(lightseagreen       ) << "lightseagreen       ";
  std::cout << color.foreground_readable(mediumslateblue     ) << "mediumslateblue     ";
  std::cout << color.reset() << "\n  ";
  std::cout << color.foreground_readable(rosybrown           ) << "rosybrown           ";
  std::cout << color.foreground_readable(goldenrod           ) << "goldenrod           ";
  std::cout << color.foreground_readable(mediumturquoise     ) << "mediumturquoise     ";
  std::cout << color.foreground_readable(mediumpurple        ) << "mediumpurple        ";
  std::cout << color.reset() << "\n  ";
  std::cout << color.foreground_readable(lightcoral          ) << "lightcoral          ";
  std::cout << color.foreground_readable(cornsilk            ) << "cornsilk            ";
  std::cout << color.foreground_readable(azure               ) << "azure               ";
  std::cout << color.foreground_readable(rebeccapurple       ) << "rebeccapurple       ";
  std::cout << color.reset() << "\n  ";
  std::cout << color.foreground_readable(indianred           ) << "indianred           ";
  std::cout << color.foreground_readable(gold                ) << "gold                ";
  std::cout << color.foreground_readable(lightcyan           ) << "lightcyan           ";
  std::cout << color.foreground_readable(blueviolet          ) << "blueviolet          ";
  std::cout << color.reset() << "\n  ";
  std::cout << color.foreground_readable(brown               ) << "brown               ";
  std::cout << color.foreground_readable(lemonchiffon        ) << "lemonchiffon        ";
  std::cout << color.foreground_readable(paleturquoise       ) << "paleturquoise       ";
  std::cout << color.foreground_readable(indigo              ) << "indigo              ";
  std::cout << color.reset() << "\n  ";
  std::cout << color.foreground_readable(firebrick           ) << "firebrick           ";
  std::cout << color.foreground_readable(khaki               ) << "khaki               ";
  std::cout << color.foreground_readable(darkslategray       ) << "darkslategray       ";
  std::cout << color.foreground_readable(darkorchid          ) << "darkorchid          ";
  std::cout << color.reset() << "\n  ";
  std::cout << color.foreground_readable(maroon              ) << "maroon              ";
  std::cout << color.foreground_readable(palegoldenrod       ) << "palegoldenrod       ";
  std::cout << color.foreground_readable(darkslategrey       ) << "darkslategrey       ";
  std::cout << color.foreground_readable(darkviolet          ) << "darkviolet          ";
  std::cout << color.reset() << "\n  ";
  std::cout << color.foreground_readable(darkred             ) << "darkred             ";
  std::cout << color.foreground_readable(darkkhaki           ) << "darkkhaki           ";
  std::cout << color.foreground_readable(teal                ) << "teal                ";
  std::cout << color.foreground_readable(mediumorchid        ) << "mediumorchid        ";
  std::cout << color.reset() << "\n  ";
  std::cout << color.foreground_readable(red                 ) << "red                 ";
  std::cout << color.foreground_readable(ivory               ) << "ivory               ";
  std::cout << color.foreground_readable(darkcyan            ) << "darkcyan            ";
  std::cout << color.foreground_readable(thistle             ) << "thistle             ";
  std::cout << color.reset() << "\n  ";
  std::cout << color.foreground_readable(mistyrose           ) << "mistyrose           ";
  std::cout << color.foreground_readable(beige               ) << "beige               ";
  std::cout << color.foreground_readable(aqua                ) << "aqua                ";
  std::cout << color.foreground_readable(plum                ) << "plum                ";
  std::cout << color.reset() << "\n  ";
  std::cout << color.foreground_readable(salmon              ) << "salmon              ";
  std::cout << color.foreground_readable(lightyellow         ) << "lightyellow         ";
  std::cout << color.foreground_readable(cyan                ) << "cyan                ";
  std::cout << color.foreground_readable(violet              ) << "violet              ";
  std::cout << color.reset() << "\n  ";
  std::cout << color.foreground_readable(tomato              ) << "tomato              ";
  std::cout << color.foreground_readable(lightgoldenrodyellow) << "lightgoldenrodyellow";
  std::cout << color.foreground_readable(darkturquoise       ) << "darkturquoise       ";
  std::cout << color.foreground_readable(purple              ) << "purple              ";
  std::cout << color.reset() << "\n  ";
  std::cout << color.foreground_readable(darksalmon          ) << "darksalmon          ";
  std::cout << color.foreground_readable(olive               ) << "olive               ";
  std::cout << color.foreground_readable(cadetblue           ) << "cadetblue           ";
  std::cout << color.foreground_readable(darkmagenta         ) << "darkmagenta         ";
  std::cout << color.reset() << "\n  ";
  std::cout << color.foreground_readable(coral               ) << "coral               ";
  std::cout << color.foreground_readable(yellow              ) << "yellow              ";
  std::cout << color.foreground_readable(powderblue          ) << "powderblue          ";
  std::cout << color.foreground_readable(fuchsia             ) << "fuchsia             ";
  std::cout << color.reset() << "\n  ";
  std::cout << color.foreground_readable(orangered           ) << "orangered           ";
  std::cout << color.foreground_readable(olivedrab           ) << "olivedrab           ";
  std::cout << color.foreground_readable(lightblue           ) << "lightblue           ";
  std::cout << color.foreground_readable(magenta             ) << "magenta             ";
  std::cout << color.reset() << "\n  ";
  std::cout << color.foreground_readable(lightsalmon         ) << "lightsalmon         ";
  std::cout << color.foreground_readable(yellowgreen         ) << "yellowgreen         ";
  std::cout << color.foreground_readable(deepskyblue         ) << "deepskyblue         ";
  std::cout << color.foreground_readable(orchid              ) << "orchid              ";
  std::cout << color.reset() << "\n  ";
  std::cout << color.foreground_readable(sienna              ) << "sienna              ";
  std::cout << color.foreground_readable(darkolivegreen      ) << "darkolivegreen      ";
  std::cout << color.foreground_readable(skyblue             ) << "skyblue             ";
  std::cout << color.foreground_readable(mediumvioletred     ) << "mediumvioletred     ";
  std::cout << color.reset() << "\n  ";
  std::cout << color.foreground_readable(seashell            ) << "seashell            ";
  std::cout << color.foreground_readable(greenyellow         ) << "greenyellow         ";
  std::cout << color.foreground_readable(lightskyblue        ) << "lightskyblue        ";
  std::cout << color.foreground_readable(deeppink            ) << "deeppink            ";
  std::cout << color.reset() << "\n  ";
  std::cout << color.foreground_readable(chocolate           ) << "chocolate           ";
  std::cout << color.foreground_readable(chartreuse          ) << "chartreuse          ";
  std::cout << color.foreground_readable(steelblue           ) << "steelblue           ";
  std::cout << color.foreground_readable(hotpink             ) << "hotpink             ";
  std::cout << color.reset() << "\n  ";
  std::cout << color.foreground_readable(saddlebrown         ) << "saddlebrown         ";
  std::cout << color.foreground_readable(lawngreen           ) << "lawngreen           ";
  std::cout << color.foreground_readable(aliceblue           ) << "aliceblue           ";
  std::cout << color.foreground_readable(lavenderblush       ) << "lavenderblush       ";
  std::cout << color.reset() << "\n  ";
  std::cout << color.foreground_readable(sandybrown          ) << "sandybrown          ";
  std::cout << color.foreground_readable(honeydew            ) << "honeydew            ";
  std::cout << color.foreground_readable(dodgerblue          ) << "dodgerblue          ";
  std::cout << color.foreground_readable(palevioletred       ) << "palevioletred       ";
  std::cout << color.reset() << "\n  ";
  std::cout << color.foreground_readable(peachpuff           ) << "peachpuff           ";
  std::cout << color.foreground_readable(darkseagreen        ) << "darkseagreen        ";
  std::cout << color.foreground_readable(lightslategray      ) << "lightslategray      ";
  std::cout << color.foreground_readable(crimson             ) << "crimson             ";
  std::cout << color.reset() << "\n  ";
  std::cout << color.foreground_readable(peru                ) << "peru                ";
  std::cout << color.foreground_readable(palegreen           ) << "palegreen           ";
  std::cout << color.foreground_readable(lightslategrey      ) << "lightslategrey      ";
  std::cout << color.foreground_readable(pink                ) << "pink                ";
  std::cout << color.reset() << "\n  ";
  std::cout << color.foreground_readable(linen               ) << "linen               ";
  std::cout << color.foreground_readable(lightgreen          ) << "lightgreen          ";
  std::cout << color.foreground_readable(slategray           ) << "slategray           ";
  std::cout << color.foreground_readable(lightpink           ) << "lightpink           ";
  std::cout << color.reset() << "\n\n";

  std::cout << color.bold() << "  Different Background Colors\n  " << color.reset();
  std::cout << color.background_readable(black               ) << "black               ";
  std::cout << color.background_readable(bisque              ) << "bisque              ";
  std::cout << color.background_readable(forestgreen         ) << "forestgreen         ";
  std::cout << color.background_readable(slategrey           ) << "slategrey           ";
  std::cout << color.reset() << "\n  ";
  std::cout << color.background_readable(dimgray             ) << "dimgray             ";
  std::cout << color.background_readable(darkorange          ) << "darkorange          ";
  std::cout << color.background_readable(limegreen           ) << "limegreen           ";
  std::cout << color.background_readable(lightsteelblue      ) << "lightsteelblue      ";
  std::cout << color.reset() << "\n  ";
  std::cout << color.background_readable(dimgrey             ) << "dimgrey             ";
  std::cout << color.background_readable(burlywood           ) << "burlywood           ";
  std::cout << color.background_readable(darkgreen           ) << "darkgreen           ";
  std::cout << color.background_readable(cornflowerblue      ) << "cornflowerblue      ";
  std::cout << color.reset() << "\n  ";
  std::cout << color.background_readable(gray                ) << "gray                ";
  std::cout << color.background_readable(antiquewhite        ) << "antiquewhite        ";
  std::cout << color.background_readable(green               ) << "green               ";
  std::cout << color.background_readable(royalblue           ) << "royalblue           ";
  std::cout << color.reset() << "\n  ";
  std::cout << color.background_readable(grey                ) << "grey                ";
  std::cout << color.background_readable(terminal_colors::tan) << "tan                 ";
  std::cout << color.background_readable(lime                ) << "lime                ";
  std::cout << color.background_readable(ghostwhite          ) << "ghostwhite          ";
  std::cout << color.reset() << "\n  ";
  std::cout << color.background_readable(darkgray            ) << "darkgray            ";
  std::cout << color.background_readable(navajowhite         ) << "navajowhite         ";
  std::cout << color.background_readable(seagreen            ) << "seagreen            ";
  std::cout << color.background_readable(lavender            ) << "lavender            ";
  std::cout << color.reset() << "\n  ";
  std::cout << color.background_readable(darkgrey            ) << "darkgrey            ";
  std::cout << color.background_readable(blanchedalmond      ) << "blanchedalmond      ";
  std::cout << color.background_readable(mediumseagreen      ) << "mediumseagreen      ";
  std::cout << color.background_readable(midnightblue        ) << "midnightblue        ";
  std::cout << color.reset() << "\n  ";
  std::cout << color.background_readable(silver              ) << "silver              ";
  std::cout << color.background_readable(papayawhip          ) << "papayawhip          ";
  std::cout << color.background_readable(springgreen         ) << "springgreen         ";
  std::cout << color.background_readable(navy                ) << "navy                ";
  std::cout << color.reset() << "\n  ";
  std::cout << color.background_readable(lightgray           ) << "lightgray           ";
  std::cout << color.background_readable(moccasin            ) << "moccasin            ";
  std::cout << color.background_readable(mintcream           ) << "mintcream           ";
  std::cout << color.background_readable(darkblue            ) << "darkblue            ";
  std::cout << color.reset() << "\n  ";
  std::cout << color.background_readable(lightgrey           ) << "lightgrey           ";
  std::cout << color.background_readable(orange              ) << "orange              ";
  std::cout << color.background_readable(mediumspringgreen   ) << "mediumspringgreen   ";
  std::cout << color.background_readable(mediumblue          ) << "mediumblue          ";
  std::cout << color.reset() << "\n  ";
  std::cout << color.background_readable(gainsboro           ) << "gainsboro           ";
  std::cout << color.background_readable(wheat               ) << "wheat               ";
  std::cout << color.background_readable(mediumaquamarine    ) << "mediumaquamarine    ";
  std::cout << color.background_readable(blue                ) << "blue                ";
  std::cout << color.reset() << "\n  ";
  std::cout << color.background_readable(whitesmoke          ) << "whitesmoke          ";
  std::cout << color.background_readable(oldlace             ) << "oldlace             ";
  std::cout << color.background_readable(aquamarine          ) << "aquamarine          ";
  std::cout << color.background_readable(slateblue           ) << "slateblue           ";
  std::cout << color.reset() << "\n  ";
  std::cout << color.background_readable(white               ) << "white               ";
  std::cout << color.background_readable(floralwhite         ) << "floralwhite         ";
  std::cout << color.background_readable(turquoise           ) << "turquoise           ";
  std::cout << color.background_readable(darkslateblue       ) << "darkslateblue       ";
  std::cout << color.reset() << "\n  ";
  std::cout << color.background_readable(snow                ) << "snow                ";
  std::cout << color.background_readable(darkgoldenrod       ) << "darkgoldenrod       ";
  std::cout << color.background_readable(lightseagreen       ) << "lightseagreen       ";
  std::cout << color.background_readable(mediumslateblue     ) << "mediumslateblue     ";
  std::cout << color.reset() << "\n  ";
  std::cout << color.background_readable(rosybrown           ) << "rosybrown           ";
  std::cout << color.background_readable(goldenrod           ) << "goldenrod           ";
  std::cout << color.background_readable(mediumturquoise     ) << "mediumturquoise     ";
  std::cout << color.background_readable(mediumpurple        ) << "mediumpurple        ";
  std::cout << color.reset() << "\n  ";
  std::cout << color.background_readable(lightcoral          ) << "lightcoral          ";
  std::cout << color.background_readable(cornsilk            ) << "cornsilk            ";
  std::cout << color.background_readable(azure               ) << "azure               ";
  std::cout << color.background_readable(rebeccapurple       ) << "rebeccapurple       ";
  std::cout << color.reset() << "\n  ";
  std::cout << color.background_readable(indianred           ) << "indianred           ";
  std::cout << color.background_readable(gold                ) << "gold                ";
  std::cout << color.background_readable(lightcyan           ) << "lightcyan           ";
  std::cout << color.background_readable(blueviolet          ) << "blueviolet          ";
  std::cout << color.reset() << "\n  ";
  std::cout << color.background_readable(brown               ) << "brown               ";
  std::cout << color.background_readable(lemonchiffon        ) << "lemonchiffon        ";
  std::cout << color.background_readable(paleturquoise       ) << "paleturquoise       ";
  std::cout << color.background_readable(indigo              ) << "indigo              ";
  std::cout << color.reset() << "\n  ";
  std::cout << color.background_readable(firebrick           ) << "firebrick           ";
  std::cout << color.background_readable(khaki               ) << "khaki               ";
  std::cout << color.background_readable(darkslategray       ) << "darkslategray       ";
  std::cout << color.background_readable(darkorchid          ) << "darkorchid          ";
  std::cout << color.reset() << "\n  ";
  std::cout << color.background_readable(maroon              ) << "maroon              ";
  std::cout << color.background_readable(palegoldenrod       ) << "palegoldenrod       ";
  std::cout << color.background_readable(darkslategrey       ) << "darkslategrey       ";
  std::cout << color.background_readable(darkviolet          ) << "darkviolet          ";
  std::cout << color.reset() << "\n  ";
  std::cout << color.background_readable(darkred             ) << "darkred             ";
  std::cout << color.background_readable(darkkhaki           ) << "darkkhaki           ";
  std::cout << color.background_readable(teal                ) << "teal                ";
  std::cout << color.background_readable(mediumorchid        ) << "mediumorchid        ";
  std::cout << color.reset() << "\n  ";
  std::cout << color.background_readable(red                 ) << "red                 ";
  std::cout << color.background_readable(ivory               ) << "ivory               ";
  std::cout << color.background_readable(darkcyan            ) << "darkcyan            ";
  std::cout << color.background_readable(thistle             ) << "thistle             ";
  std::cout << color.reset() << "\n  ";
  std::cout << color.background_readable(mistyrose           ) << "mistyrose           ";
  std::cout << color.background_readable(beige               ) << "beige               ";
  std::cout << color.background_readable(aqua                ) << "aqua                ";
  std::cout << color.background_readable(plum                ) << "plum                ";
  std::cout << color.reset() << "\n  ";
  std::cout << color.background_readable(salmon              ) << "salmon              ";
  std::cout << color.background_readable(lightyellow         ) << "lightyellow         ";
  std::cout << color.background_readable(cyan                ) << "cyan                ";
  std::cout << color.background_readable(violet              ) << "violet              ";
  std::cout << color.reset() << "\n  ";
  std::cout << color.background_readable(tomato              ) << "tomato              ";
  std::cout << color.background_readable(lightgoldenrodyellow) << "lightgoldenrodyellow";
  std::cout << color.background_readable(darkturquoise       ) << "darkturquoise       ";
  std::cout << color.background_readable(purple              ) << "purple              ";
  std::cout << color.reset() << "\n  ";
  std::cout << color.background_readable(darksalmon          ) << "darksalmon          ";
  std::cout << color.background_readable(olive               ) << "olive               ";
  std::cout << color.background_readable(cadetblue           ) << "cadetblue           ";
  std::cout << color.background_readable(darkmagenta         ) << "darkmagenta         ";
  std::cout << color.reset() << "\n  ";
  std::cout << color.background_readable(coral               ) << "coral               ";
  std::cout << color.background_readable(yellow              ) << "yellow              ";
  std::cout << color.background_readable(powderblue          ) << "powderblue          ";
  std::cout << color.background_readable(fuchsia             ) << "fuchsia             ";
  std::cout << color.reset() << "\n  ";
  std::cout << color.background_readable(orangered           ) << "orangered           ";
  std::cout << color.background_readable(olivedrab           ) << "olivedrab           ";
  std::cout << color.background_readable(lightblue           ) << "lightblue           ";
  std::cout << color.background_readable(magenta             ) << "magenta             ";
  std::cout << color.reset() << "\n  ";
  std::cout << color.background_readable(lightsalmon         ) << "lightsalmon         ";
  std::cout << color.background_readable(yellowgreen         ) << "yellowgreen         ";
  std::cout << color.background_readable(deepskyblue         ) << "deepskyblue         ";
  std::cout << color.background_readable(orchid              ) << "orchid              ";
  std::cout << color.reset() << "\n  ";
  std::cout << color.background_readable(sienna              ) << "sienna              ";
  std::cout << color.background_readable(darkolivegreen      ) << "darkolivegreen      ";
  std::cout << color.background_readable(skyblue             ) << "skyblue             ";
  std::cout << color.background_readable(mediumvioletred     ) << "mediumvioletred     ";
  std::cout << color.reset() << "\n  ";
  std::cout << color.background_readable(seashell            ) << "seashell            ";
  std::cout << color.background_readable(greenyellow         ) << "greenyellow         ";
  std::cout << color.background_readable(lightskyblue        ) << "lightskyblue        ";
  std::cout << color.background_readable(deeppink            ) << "deeppink            ";
  std::cout << color.reset() << "\n  ";
  std::cout << color.background_readable(chocolate           ) << "chocolate           ";
  std::cout << color.background_readable(chartreuse          ) << "chartreuse          ";
  std::cout << color.background_readable(steelblue           ) << "steelblue           ";
  std::cout << color.background_readable(hotpink             ) << "hotpink             ";
  std::cout << color.reset() << "\n  ";
  std::cout << color.background_readable(saddlebrown         ) << "saddlebrown         ";
  std::cout << color.background_readable(lawngreen           ) << "lawngreen           ";
  std::cout << color.background_readable(aliceblue           ) << "aliceblue           ";
  std::cout << color.background_readable(lavenderblush       ) << "lavenderblush       ";
  std::cout << color.reset() << "\n  ";
  std::cout << color.background_readable(sandybrown          ) << "sandybrown          ";
  std::cout << color.background_readable(honeydew            ) << "honeydew            ";
  std::cout << color.background_readable(dodgerblue          ) << "dodgerblue          ";
  std::cout << color.background_readable(palevioletred       ) << "palevioletred       ";
  std::cout << color.reset() << "\n  ";
  std::cout << color.background_readable(peachpuff           ) << "peachpuff           ";
  std::cout << color.background_readable(darkseagreen        ) << "darkseagreen        ";
  std::cout << color.background_readable(lightslategray      ) << "lightslategray      ";
  std::cout << color.background_readable(crimson             ) << "crimson             ";
  std::cout << color.reset() << "\n  ";
  std::cout << color.background_readable(peru                ) << "peru                ";
  std::cout << color.background_readable(palegreen           ) << "palegreen           ";
  std::cout << color.background_readable(lightslategrey      ) << "lightslategrey      ";
  std::cout << color.background_readable(pink                ) << "pink                ";
  std::cout << color.reset() << "\n  ";
  std::cout << color.background_readable(linen               ) << "linen               ";
  std::cout << color.background_readable(lightgreen          ) << "lightgreen          ";
  std::cout << color.background_readable(slategray           ) << "slategray           ";
  std::cout << color.background_readable(lightpink           ) << "lightpink           ";
  std::cout << color.reset() << "\n\n";
}


int main(int argc, char *argv[]) {
  static_cast<void>(argc);
  static_cast<void>(argv);
  simple_example();
  rainbow_loren_ipsum();
  draw_suspicious_ninja();
  draw_color_circle();
  draw_color_tables();
  return 0;
}
