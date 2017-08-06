#ifndef FHL_CLOCK_H
#define FHL_CLOCK_H

#include <chrono>
#include <ratio>

#include <FHL/common.h>

namespace fhl
{

	 using Seconds = std::chrono::duration<float>;
	 using Milliseconds = std::chrono::duration<float, std::milli>;
	 using Microseconds = std::chrono::duration<float, std::micro>;

	 class FHL_API Clock
	 {
		  using InnerClock = std::chrono::high_resolution_clock;
		  using TimePoint = std::chrono::time_point<InnerClock>;

	 public:
		  Clock();

		  template<typename T = Seconds>
		  float getElapsedTime();

		  template<typename T = Seconds>
		  float restart();

	 private:
		  TimePoint m_start;
	 };

} // ns

#endif // FHL_CLOCK_H
