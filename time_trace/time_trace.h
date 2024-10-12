#pragma once
#include <chrono>
#include <cstdint>

namespace time_trace {


 //   const std::chrono::duration<double> elapsed_seconds{end - start};
 
  using time_point = std::chrono::time_point<std::chrono::steady_clock>;

  class time_trace {
    time_point t_start;
    time_point t_stop;
  public:
    inline void start() { t_start = std::chrono::steady_clock::now(); }
    inline void stop() { t_stop = std::chrono::steady_clock::now(); }
    inline void next();
    inline void loop();
    inline int64_t delta() { return std::chrono::duration_cast<std::chrono::nanoseconds>(t_stop - t_start).count();}

  };
} // namespace time_trace
