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

	 template float FHL_API Clock::getElapsedTime<Seconds>();
	 template float FHL_API Clock::getElapsedTime<Milliseconds>();
	 template float FHL_API Clock::getElapsedTime<Microseconds>();

	 template float FHL_API Clock::restart<Seconds>();
	 template float FHL_API Clock::restart<Milliseconds>();
	 template float FHL_API Clock::restart<Microseconds>();

}
