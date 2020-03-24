#ifndef TIMER_H
#define TIMER_H

#include <chrono>
#include <qmessagebox.h>
#include <iostream>

class Timer
{
public:
	Timer(const char* callFunction = "(Not specified)", const char* additionalInfo = "");
	~Timer();
	double getDuration();
	double duration;

private:
	const char* callFunction;
	const char* additionalInfo;
	std::chrono::time_point<std::chrono::steady_clock> startTime;
};


#endif

