#pragma once
#include <cstdint>
#include <type_traits>
#include <cmath>

namespace terminal_colors {
  struct rgb_color {
    private:
      uint8_t red;
      uint8_t green;
      uint8_t blue;

      template<class T>
      constexpr uint8_t float_or_int(T v)
      {
        if constexpr (std::is_floating_point<T>::value)
        {
          // Floating point scale is [0.0..1.0]
          return clamp_to_0_255(v*255 + 0.5); // Take care of rounding with 0.5
        }
        else
        {
          static_assert((std::is_integral<T>::value && !std::is_same_v<std::decay_t<T>, signed char> && !std::is_same_v<std::decay_t<T>, char>  ),
                    "Only floating points, and integer types able to hold numbers up to 255 or bigger are allowed. No char, no signed char.");
          // Integer scale is [0..255]
          return clamp_to_0_255(v);
        }
      }

      template<class T>
      constexpr uint8_t clamp_to_0_255(T i){
        // will round down for floating points!
        return ((i < 255) ? ((i > 0) ? static_cast<uint8_t>(i) : 0u) : 255u);
      }

    public:
      template<class T>
      constexpr rgb_color(T r, T g, T b) : red(float_or_int(r)), green(float_or_int(g)), blue(float_or_int(b))
      {}

      const auto sum() const
      {
        return (static_cast<int32_t>(red) + static_cast<int32_t>(green) + static_cast<int32_t>(blue));
      }

      const auto get_red() const
      {
        return red;
      }
      const auto get_green() const
      {
        return green;
      }
      const auto get_blue() const
      {
        return blue;
      }
  };

  bool operator==(const rgb_color& lhs, const rgb_color& rhs)
  {
    bool r{true};
    r = r && (lhs.get_red() == rhs.get_red());
    r = r && (lhs.get_green() == rhs.get_green());
    r = r && (lhs.get_blue() == rhs.get_blue());
    return r;
  }

  // Python matplotlib colors. List generated with:
  // import matplotlib
  //   for name, hex in matplotlib.colors.cnames.items():
  //   print(name, hex)
  constexpr rgb_color aliceblue{0xF0, 0xF8, 0xFF};
  constexpr rgb_color antiquewhite{0xFA, 0xEB, 0xD7};
  constexpr rgb_color aqua{0x00, 0xFF, 0xFF};
  constexpr rgb_color aquamarine{0x7F, 0xFF, 0xD4};
  constexpr rgb_color azure{0xF0, 0xFF, 0xFF};
  constexpr rgb_color beige{0xF5, 0xF5, 0xDC};
  constexpr rgb_color bisque{0xFF, 0xE4, 0xC4};
  constexpr rgb_color black{0x00, 0x00, 0x00};
  constexpr rgb_color blanchedalmond{0xFF, 0xEB, 0xCD};
  constexpr rgb_color blue{0x00, 0x00, 0xFF};
  constexpr rgb_color blueviolet{0x8A, 0x2B, 0xE2};
  constexpr rgb_color brown{0xA5, 0x2A, 0x2A};
  constexpr rgb_color burlywood{0xDE, 0xB8, 0x87};
  constexpr rgb_color cadetblue{0x5F, 0x9E, 0xA0};
  constexpr rgb_color chartreuse{0x7F, 0xFF, 0x00};
  constexpr rgb_color chocolate{0xD2, 0x69, 0x1E};
  constexpr rgb_color coral{0xFF, 0x7F, 0x50};
  constexpr rgb_color cornflowerblue{0x64, 0x95, 0xED};
  constexpr rgb_color cornsilk{0xFF, 0xF8, 0xDC};
  constexpr rgb_color crimson{0xDC, 0x14, 0x3C};
  constexpr rgb_color cyan{0x00, 0xFF, 0xFF};
  constexpr rgb_color darkblue{0x00, 0x00, 0x8B};
  constexpr rgb_color darkcyan{0x00, 0x8B, 0x8B};
  constexpr rgb_color darkgoldenrod{0xB8, 0x86, 0x0B};
  constexpr rgb_color darkgray{0xA9, 0xA9, 0xA9};
  constexpr rgb_color darkgreen{0x00, 0x64, 0x00};
  constexpr rgb_color darkgrey{0xA9, 0xA9, 0xA9};
  constexpr rgb_color darkkhaki{0xBD, 0xB7, 0x6B};
  constexpr rgb_color darkmagenta{0x8B, 0x00, 0x8B};
  constexpr rgb_color darkolivegreen{0x55, 0x6B, 0x2F};
  constexpr rgb_color darkorange{0xFF, 0x8C, 0x00};
  constexpr rgb_color darkorchid{0x99, 0x32, 0xCC};
  constexpr rgb_color darkred{0x8B, 0x00, 0x00};
  constexpr rgb_color darksalmon{0xE9, 0x96, 0x7A};
  constexpr rgb_color darkseagreen{0x8F, 0xBC, 0x8F};
  constexpr rgb_color darkslateblue{0x48, 0x3D, 0x8B};
  constexpr rgb_color darkslategray{0x2F, 0x4F, 0x4F};
  constexpr rgb_color darkslategrey{0x2F, 0x4F, 0x4F};
  constexpr rgb_color darkturquoise{0x00, 0xCE, 0xD1};
  constexpr rgb_color darkviolet{0x94, 0x00, 0xD3};
  constexpr rgb_color deeppink{0xFF, 0x14, 0x93};
  constexpr rgb_color deepskyblue{0x00, 0xBF, 0xFF};
  constexpr rgb_color dimgray{0x69, 0x69, 0x69};
  constexpr rgb_color dimgrey{0x69, 0x69, 0x69};
  constexpr rgb_color dodgerblue{0x1E, 0x90, 0xFF};
  constexpr rgb_color firebrick{0xB2, 0x22, 0x22};
  constexpr rgb_color floralwhite{0xFF, 0xFA, 0xF0};
  constexpr rgb_color forestgreen{0x22, 0x8B, 0x22};
  constexpr rgb_color fuchsia{0xFF, 0x00, 0xFF};
  constexpr rgb_color gainsboro{0xDC, 0xDC, 0xDC};
  constexpr rgb_color ghostwhite{0xF8, 0xF8, 0xFF};
  constexpr rgb_color gold{0xFF, 0xD7, 0x00};
  constexpr rgb_color goldenrod{0xDA, 0xA5, 0x20};
  constexpr rgb_color gray{0x80, 0x80, 0x80};
  constexpr rgb_color green{0x00, 0x80, 0x00};
  constexpr rgb_color greenyellow{0xAD, 0xFF, 0x2F};
  constexpr rgb_color grey{0x80, 0x80, 0x80};
  constexpr rgb_color honeydew{0xF0, 0xFF, 0xF0};
  constexpr rgb_color hotpink{0xFF, 0x69, 0xB4};
  constexpr rgb_color indianred{0xCD, 0x5C, 0x5C};
  constexpr rgb_color indigo{0x4B, 0x00, 0x82};
  constexpr rgb_color ivory{0xFF, 0xFF, 0xF0};
  constexpr rgb_color khaki{0xF0, 0xE6, 0x8C};
  constexpr rgb_color lavender{0xE6, 0xE6, 0xFA};
  constexpr rgb_color lavenderblush{0xFF, 0xF0, 0xF5};
  constexpr rgb_color lawngreen{0x7C, 0xFC, 0x00};
  constexpr rgb_color lemonchiffon{0xFF, 0xFA, 0xCD};
  constexpr rgb_color lightblue{0xAD, 0xD8, 0xE6};
  constexpr rgb_color lightcoral{0xF0, 0x80, 0x80};
  constexpr rgb_color lightcyan{0xE0, 0xFF, 0xFF};
  constexpr rgb_color lightgoldenrodyellow{0xFA, 0xFA, 0xD2};
  constexpr rgb_color lightgray{0xD3, 0xD3, 0xD3};
  constexpr rgb_color lightgreen{0x90, 0xEE, 0x90};
  constexpr rgb_color lightgrey{0xD3, 0xD3, 0xD3};
  constexpr rgb_color lightpink{0xFF, 0xB6, 0xC1};
  constexpr rgb_color lightsalmon{0xFF, 0xA0, 0x7A};
  constexpr rgb_color lightseagreen{0x20, 0xB2, 0xAA};
  constexpr rgb_color lightskyblue{0x87, 0xCE, 0xFA};
  constexpr rgb_color lightslategray{0x77, 0x88, 0x99};
  constexpr rgb_color lightslategrey{0x77, 0x88, 0x99};
  constexpr rgb_color lightsteelblue{0xB0, 0xC4, 0xDE};
  constexpr rgb_color lightyellow{0xFF, 0xFF, 0xE0};
  constexpr rgb_color lime{0x00, 0xFF, 0x00};
  constexpr rgb_color limegreen{0x32, 0xCD, 0x32};
  constexpr rgb_color linen{0xFA, 0xF0, 0xE6};
  constexpr rgb_color magenta{0xFF, 0x00, 0xFF};
  constexpr rgb_color maroon{0x80, 0x00, 0x00};
  constexpr rgb_color mediumaquamarine{0x66, 0xCD, 0xAA};
  constexpr rgb_color mediumblue{0x00, 0x00, 0xCD};
  constexpr rgb_color mediumorchid{0xBA, 0x55, 0xD3};
  constexpr rgb_color mediumpurple{0x93, 0x70, 0xDB};
  constexpr rgb_color mediumseagreen{0x3C, 0xB3, 0x71};
  constexpr rgb_color mediumslateblue{0x7B, 0x68, 0xEE};
  constexpr rgb_color mediumspringgreen{0x00, 0xFA, 0x9A};
  constexpr rgb_color mediumturquoise{0x48, 0xD1, 0xCC};
  constexpr rgb_color mediumvioletred{0xC7, 0x15, 0x85};
  constexpr rgb_color midnightblue{0x19, 0x19, 0x70};
  constexpr rgb_color mintcream{0xF5, 0xFF, 0xFA};
  constexpr rgb_color mistyrose{0xFF, 0xE4, 0xE1};
  constexpr rgb_color moccasin{0xFF, 0xE4, 0xB5};
  constexpr rgb_color navajowhite{0xFF, 0xDE, 0xAD};
  constexpr rgb_color navy{0x00, 0x00, 0x80};
  constexpr rgb_color oldlace{0xFD, 0xF5, 0xE6};
  constexpr rgb_color olive{0x80, 0x80, 0x00};
  constexpr rgb_color olivedrab{0x6B, 0x8E, 0x23};
  constexpr rgb_color orange{0xFF, 0xA5, 0x00};
  constexpr rgb_color orangered{0xFF, 0x45, 0x00};
  constexpr rgb_color orchid{0xDA, 0x70, 0xD6};
  constexpr rgb_color palegoldenrod{0xEE, 0xE8, 0xAA};
  constexpr rgb_color palegreen{0x98, 0xFB, 0x98};
  constexpr rgb_color paleturquoise{0xAF, 0xEE, 0xEE};
  constexpr rgb_color palevioletred{0xDB, 0x70, 0x93};
  constexpr rgb_color papayawhip{0xFF, 0xEF, 0xD5};
  constexpr rgb_color peachpuff{0xFF, 0xDA, 0xB9};
  constexpr rgb_color peru{0xCD, 0x85, 0x3F};
  constexpr rgb_color pink{0xFF, 0xC0, 0xCB};
  constexpr rgb_color plum{0xDD, 0xA0, 0xDD};
  constexpr rgb_color powderblue{0xB0, 0xE0, 0xE6};
  constexpr rgb_color purple{0x80, 0x00, 0x80};
  constexpr rgb_color rebeccapurple{0x66, 0x33, 0x99};
  constexpr rgb_color red{0xFF, 0x00, 0x00};
  constexpr rgb_color rosybrown{0xBC, 0x8F, 0x8F};
  constexpr rgb_color royalblue{0x41, 0x69, 0xE1};
  constexpr rgb_color saddlebrown{0x8B, 0x45, 0x13};
  constexpr rgb_color salmon{0xFA, 0x80, 0x72};
  constexpr rgb_color sandybrown{0xF4, 0xA4, 0x60};
  constexpr rgb_color seagreen{0x2E, 0x8B, 0x57};
  constexpr rgb_color seashell{0xFF, 0xF5, 0xEE};
  constexpr rgb_color sienna{0xA0, 0x52, 0x2D};
  constexpr rgb_color silver{0xC0, 0xC0, 0xC0};
  constexpr rgb_color skyblue{0x87, 0xCE, 0xEB};
  constexpr rgb_color slateblue{0x6A, 0x5A, 0xCD};
  constexpr rgb_color slategray{0x70, 0x80, 0x90};
  constexpr rgb_color slategrey{0x70, 0x80, 0x90};
  constexpr rgb_color snow{0xFF, 0xFA, 0xFA};
  constexpr rgb_color springgreen{0x00, 0xFF, 0x7F};
  constexpr rgb_color steelblue{0x46, 0x82, 0xB4};
  constexpr rgb_color tan{0xD2, 0xB4, 0x8C};
  constexpr rgb_color teal{0x00, 0x80, 0x80};
  constexpr rgb_color thistle{0xD8, 0xBF, 0xD8};
  constexpr rgb_color tomato{0xFF, 0x63, 0x47};
  constexpr rgb_color turquoise{0x40, 0xE0, 0xD0};
  constexpr rgb_color violet{0xEE, 0x82, 0xEE};
  constexpr rgb_color wheat{0xF5, 0xDE, 0xB3};
  constexpr rgb_color white{0xFF, 0xFF, 0xFF};
  constexpr rgb_color whitesmoke{0xF5, 0xF5, 0xF5};
  constexpr rgb_color yellow{0xFF, 0xFF, 0x00};
  constexpr rgb_color yellowgreen{0x9A, 0xCD, 0x32};
} // namespace terminal_colors
