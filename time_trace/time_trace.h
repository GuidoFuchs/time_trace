#pragma once
#include <chrono>
#include <cstdint>
#include <array>

namespace time_trace {


 //   const std::chrono::duration<double> elapsed_seconds{end - start};
 
  #define unlikely_branch(x)    __builtin_expect (!!(x), 0)

  using time_point = std::chrono::time_point<std::chrono::steady_clock>;
  constexpr uint32_t nr_time_stamps{4u};
  constexpr uint32_t i_start{0u};

  class time_trace {
    
    time_point time_stamps[nr_time_stamps];
    const uint32_t i_stop = nr_time_stamps - 1u;
    uint32_t i{i_start};

  public:
    inline void start() { 
      if (unlikely_branch( i != i_start )) std::exit(EXIT_FAILURE);
      measure(); 
    }
    inline void stop() { 
        i = i_stop;
        measure(); 
        i = 0;
      }
    inline void next() { 
        measure();
        if (unlikely_branch( i >= nr_time_stamps )) std::exit(EXIT_FAILURE);
      }
    inline void loop();
    inline int64_t delta() { return std::chrono::duration_cast<std::chrono::nanoseconds>(time_stamps[i_stop] - time_stamps[i_start]).count();}
    inline void measure() { 
        time_stamps[i] = std::chrono::steady_clock::now();
        i++;
      }
  };
} // namespace time_trace
