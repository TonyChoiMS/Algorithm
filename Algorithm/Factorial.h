#pragma once

class Factorial
{
public:
	Factorial();
	~Factorial();

	// 재귀 팩토리얼 계산
	int* AllFactorials(int n)
	{
		int* results = new int[n == 0 ? 1 : n];
		DoAllFactorials(n, results, 0);
		return results;
	}

	int DoAllFactorials(int n, int* results, int level)
	{
		// 재귀 케이스
		if (n > 1)
		{
			results[level] = n * DoAllFactorials(n - 1, results, level + 1);
			return results[level];
		}
		else
		{
			// 일반 케이스		
			results[level] = 1;
			return 1;
		}
	}


	// 반복문 팩토리얼 계산
	int FactorialToLoop(int n)
	{
		int i, val = 1;

		for (i = n; i > 1; i--)
		{
			val *= i;
		}

		return val;
	}
};