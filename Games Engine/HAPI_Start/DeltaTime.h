#pragma once
#include <chrono>
#include <HAPI_lib.h>

class DeltaTime
{
private:
	unsigned long start;
	unsigned long end;
	double deltaTime{ 0.1 }; //so deltatime has a value to start
public:



	auto TimeStart()
	{
		start = HAPI.GetTime();
	}

	auto TimeEnd()
	{
		end = HAPI.GetTime();
	}

	auto CalculateFrametime()
	{
		deltaTime = (start - end) * (double)0.001; //since GetTime is 1.0 for 1 millisecond, i can multiply by 0.001 to translate time to 1.0f to 1 second
	}

	float FrameTime()
	{
		return deltaTime;
	}
};
