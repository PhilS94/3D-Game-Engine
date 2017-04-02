#pragma once

#include <iostream>
#include <stdio.h>
#include <time.h>

class Time
{
public:
	//Time();
	//~Time();
	inline static double getTime() {
		return time(0) / SECOND;
	}
private:
	static const long SECOND = 1000000000L;
};

