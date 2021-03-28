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