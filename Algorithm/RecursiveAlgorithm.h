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

	// ����ȣ �ܾ�
	void TelephoneNumber(int* n)
	{
		phoneNumber = n;
		PrintWords(0);
	}

private:
	bool* used;
	std::string strResult = "";
	std::string strIn;
	int* phoneNumber;
	char* ResultWord;

	const int PHONE_NUMBER_LENGTH = 7;
	
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

	void PrintWords(int curDigit)
	{
		if (curDigit == PHONE_NUMBER_LENGTH)
		{
			for (int i = 0; i < sizeof(ResultWord); i++)
			{
				std::cout << ResultWord[i];
			}
			std::cout << std::endl;
			return;
		}

		for (int i = 1; i <= 3; ++i)
		{
			ResultWord[curDigit] = GetCharKey(phoneNumber[curDigit], i);
			PrintWords(curDigit + 1);
			if (phoneNumber[curDigit] == 0 ||
				phoneNumber[curDigit] == 1)
				return;
		}
	}

	char GetCharKey(int telephoneKey, int place)
	{
		char charkey;

		switch (telephoneKey)
		{
		case 2:
			if (place == 1)
			{
				charkey = 'a';
			}
			else if (place == 2)
			{
				charkey = 'b';
			}
			else
			{
				charkey = 'c';
			}
			break;

		case 3:
			if (place == 1)
			{
				charkey = 'd';
			}
			else if (place == 2)
			{
				charkey = 'e';
			}
			else
			{
				charkey = 'f';
			}
			break;

		case 4:
			if (place == 1)
			{
				charkey = 'g';
			}
			else if (place == 2)
			{
				charkey = 'h';
			}
			else
			{
				charkey = 'i';
			}
			break;

		case 5:
			if (place == 1)
			{
				charkey = 'j';
			}
			else if (place == 2)
			{
				charkey = 'k';
			}
			else
			{
				charkey = 'l';
			}
			break;

		case 6:
			if (place == 1)
			{
				charkey = 'm';
			}
			else if (place == 2)
			{
				charkey = 'n';
			}
			else
			{
				charkey = 'o';
			}
			break;

		case 7:
			if (place == 1)
			{
				charkey = 'p';
			}
			else if (place == 2)
			{
				charkey = 'r';
			}
			else
			{
				charkey = 's';
			}
			break;
			
		case 8:
			if (place == 1)
			{
				charkey = 't';
			}
			else if (place == 2)
			{
				charkey = 'u';
			}
			else
			{
				charkey = 'v';
			}
			break;

		case 9:
			if (place == 1)
			{
				charkey = 'w';
			}
			else if (place == 2)
			{
				charkey = 'x';
			}
			else
			{
				charkey = 'y';
			}
			break;
		}
	}
};