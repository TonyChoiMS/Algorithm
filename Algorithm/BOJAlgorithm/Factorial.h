#pragma once

class Factorial
{
public:
	Factorial();
	~Factorial();

	// ��� ���丮�� ���
	int* AllFactorials(int n)
	{
		int* results = new int[n == 0 ? 1 : n];
		DoAllFactorials(n, results, 0);
		return results;
	}

	int DoAllFactorials(int n, int* results, int level)
	{
		// ��� ���̽�
		if (n > 1)
		{
			results[level] = n * DoAllFactorials(n - 1, results, level + 1);
			return results[level];
		}
		else
		{
			// �Ϲ� ���̽�		
			results[level] = 1;
			return 1;
		}
	}


	// �ݺ��� ���丮�� ���
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