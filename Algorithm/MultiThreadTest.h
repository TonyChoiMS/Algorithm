#pragma once

#include <iostream>
#include <Windows.h>
#include <process.h>

using namespace std;

class MultiThreadTest
{
private:
	int testInt = 0;

	unsigned int __stdcall Thread_Function_one(void *avg);
	unsigned int __stdcall Thread_Function_two(void *avg);

	CRITICAL_SECTION crs;

public:
	
	void Test();
};

