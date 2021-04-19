#pragma once

#include <iostream>
#include <Windows.h>
#include <process.h>
#include <bitset>

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
	void BitTest();

	void NthBitSet(unsigned char c, int n, bool flagOn);

};

