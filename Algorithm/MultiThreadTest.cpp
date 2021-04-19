#include "MultiThreadTest.h"

#define THREAD_COUNT 2

unsigned int __stdcall MultiThreadTest::Thread_Function_one(void *avg)
{
	cout << "(Before)ThreadOne Test int : " << testInt << endl;
	testInt++;
	cout << "(After)ThreadOne Test int : " << testInt << endl;

	_endthreadex(0);
	return testInt;
}

unsigned int __stdcall MultiThreadTest::Thread_Function_two(void *avg)
{
	cout << "(Before)ThreadTwo Test Int : " << testInt << endl;
	testInt++;
	cout << "(After)ThreadTwo Test Int : " << testInt << endl;

	_endthreadex(0);
	return testInt;
}

void MultiThreadTest::Test()
{
	//HANDLE thread[THREAD_COUNT];
	//
	//DWORD thread_one_id;
	//DWORD thread_two_id;

	//cout << "Main Test Int : " << testInt << endl;

	//// Create Thread One
	//thread[0] = CreateThread(NULL, 0, ::Thread_Function_one, NULL, 0, NULL);
	//thread[0] = (HANDLE)_beginthreadex(NULL, 0, MultiThreadTest::Thread_Function_one, NULL, 0, (unsigned*)&thread_one_id);
	//if (thread[0] == 0)
	//{
	//	cout << "_beginThreades Error" << endl;
	//}
	//else
	//{
	//	cout << "Create Thread one" << endl;
	//}

	//// Create Thread Two
	//thread[1] = (HANDLE)_beginthreadex(NULL, 0, MultiThreadTest::Thread_Function_two, NULL, 0, (unsigned*)&thread_two_id);
	//if (thread[1] == 0)
	//{
	//	cout << "_beginThreades Error" << endl;
	//}
	//else
	//{
	//	cout << "Create Thread one" << endl;
	//}

	//WaitForMultipleObjects(THREAD_COUNT, thread, true, INFINITE);

	//for (int i = 0; i < THREAD_COUNT; i++)
	//{
	//	CloseHandle(thread[i]);
	//}
	//
	//DeleteCriticalSection(&crs);

	cout << "main test int " << testInt << endl;
	cout << "main exit " << endl;
}

void MultiThreadTest::BitTest()
{
	unsigned char c = 0;
	std::cout << std::bitset<8>(c) << std::endl;			// 0000 0000

	//1번 비트 변환.
	c |= 1;													// 0000 0000 OR 0000 00001
	std::cout << std::bitset<8>(c) << std::endl;			// 0000 0001

	c |= (1 << 1);											// 0000 0001 OR 0000 0010
	std::cout << std::bitset<8>(c) << std::endl;			// 0000 0011

	c &= ~(1 << 0);											// 0000 0011 AND 1111 1110
	std::cout << std::bitset<8>(c) << std::endl;			// 0000 0010

	c &= ~(1 << 1);											// 0000 0010 AND 1111 1101
	std::cout << std::bitset<8>(c) << std::endl;			// 0000 0000

	c |= (1 << 1);

	// 4번째 비트 번환.
	NthBitSet(c, 4, false);									// 0001 0000
}


// flag on  = 0 -> 1
// flag off = 1 -> 0
void MultiThreadTest::NthBitSet(unsigned char c, int n, bool flagOn)
{
	if (flagOn)
	{
		c &= ~(1 << n);
	}
	else
	{
		c |= (1 << n);
	}

	std::cout << "NthBitSet n : " << n << ", Result :" << std::bitset<8>(c) << endl;
}
