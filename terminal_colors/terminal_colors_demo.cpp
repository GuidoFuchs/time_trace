#include <iostream>
#include <array>

#include "terminal_colors/terminal_colors_example.h"

extern void terminal_colors_draw_example();

int main(int argc, char *argv[]) {
  static_cast<void>(argc);
  static_cast<void>(argv);
  terminal_colors_draw_example();
  return 0;
}
