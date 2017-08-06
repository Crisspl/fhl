#include <FHL/Utility/Clock.h>

namespace fhl
{

	 Clock::Clock()
		 : m_start(InnerClock::now())
	 {

	 }

	 template <typename T>
	 float Clock::getElapsedTime()
	 {
		 T elapsedTime = InnerClock::now() - m_start;
		 return elapsedTime.count();
	 }

	 template <typename T>
	 float Clock::restart()
	 {
		 float elapsedTime = getElapsedTime<T>();
		 m_start = InnerClock::now();
		 return elapsedTime;
	 }

	 template float Clock::getElapsedTime<Seconds>();
	 template float Clock::getElapsedTime<Milliseconds>();
	 template float Clock::getElapsedTime<Microseconds>();

	 template float Clock::restart<Seconds>();
	 template float Clock::restart<Milliseconds>();
	 template float Clock::restart<Microseconds>();

} // ns
