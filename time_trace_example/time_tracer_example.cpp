#include <iostream>
#include <array>
#include <iostream>

#include "time_trace/time_trace.h"
#include "terminal_colors/terminal_colors_example.h"


extern void terminal_colors_draw_example();

int main(int argc, char *argv[]) {
  static_cast<void>(argc);
  static_cast<void>(argv);
  time_trace::time_trace tr{};
  tr.start();
  terminal_colors_draw_example();
  tr.stop();

  std::cout << tr.delta()*1e-9 << std::endl;
  return 0;
}
