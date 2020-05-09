#ifdef DEBUG

#include "Timer.h"


Timer::Timer(const char* callFunction, const char* additionalInfo)
	:startTime(std::chrono::high_resolution_clock().now()), callFunction(callFunction), additionalInfo(additionalInfo)
{
	
}


Timer::~Timer() {
	duration = std::chrono::duration<double>(std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::high_resolution_clock().now() - startTime)).count();
	std::cout << std::string("\nThe function \"") + std::string(callFunction) + std::string("\" took ") + std::to_string(duration) + std::string("ms (") + std::string(additionalInfo) + std::string(")") + "\n";
}


double Timer::getDuration() {
	return duration;
}

#endif