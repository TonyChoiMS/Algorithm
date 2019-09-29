#pragma once

#include <iostream>
#include <string>
#include <sstream>

#define Swap(a, b, temp) temp = a; a = b; b = temp;

class RecursiveAlgorithm
{
public:
	RecursiveAlgorithm()
	{}

	~RecursiveAlgorithm()
	{}

	// �ȱ��� ��� ȣ��(arms-length recursion)
	// ��Ÿ�� �鿡���� ���� ����. 
	void InitPermutations(std::string str)
	{
		strIn = str;
		used = new bool[str.length()];

		for (int i = 0; i < sizeof(used); i++)
		{
			used[i] = false;
		}
		
		Permutations();
	}

	// ������ ���� �˰���
	void InitPermutationsInt(int *a, const int k, const int m)			// k�� ������
	{
		int temp;

		if (k == m)
		{
			for (int i = 0; i <= m; i++)
			{
				std::cout << a[i];
			}
			std::cout << std::endl;
			cnt++;
		}
		else		// a[k] a[m]�� �ִ� ���� ������ ��ȯ������ ����
		{
			for (int i = k; i <= m; i++)
			{
				Swap(a[k], a[i], temp);					// a[k]�� a[i]�� ��ȯ
				InitPermutationsInt(a, k + 1, m);		// a[k+1], ... a[m]�� ���� ��� ����
				Swap(a[k], a[i], temp);					// ���� ���·� �ǵ����� ���� a[k]�� a[i]�� �ٽ� ��ȯ
			}
		}
	}

	// ���վ˰���
	void InitCombinationAlgorithm(std::string str)
	{
		strIn = str;
		Combine(0);
	}

private:
	bool* used;
	std::string strResult = "";
	std::string strIn;
	
	int cnt = 0;

	void Permutations()
	{
		if (strIn.length() == strResult.length())
		{
			std::cout << strResult << std::endl;
			return;
		}

		for (int i = 0; i < strIn.length(); i++)
		{
			if (used[i]) continue;
			std::stringstream ss;
			ss << strResult << strIn.at(i);
			strResult = ss.str();
			used[i] = true;
			Permutations();
			used[i] = false;
			strResult.resize(strResult.length() - 1);
		}
	}

	void Combine(int start)
	{

		for (int i = start; i < strIn.length(); ++i)
		{
			std::stringstream sstream;
			sstream << strResult << strIn.at(i);
			strResult = sstream.str();
			std::cout << strResult << std::endl;

			if (i < strIn.length())
				Combine(i + 1);

			strResult.resize(strResult.length() - 1);
		}

		// �ݺ��� ����
		// for �ݺ����� ���������� ���ư� �� ����Ǿ�� �� �ڵ带 �ݺ����� ������ ���� if���� ���ش�.
	}
};