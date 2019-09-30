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

	// 팔길이 재귀 호출(arms-length recursion)
	// 스타일 면에서는 좋지 않음. 
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

	// 정수형 순열 알고리즘
	void InitPermutationsInt(int *a, const int k, const int m)			// k는 시작점
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
		else		// a[k] a[m]에 있는 여러 순열을 순환적으로 생성
		{
			for (int i = k; i <= m; i++)
			{
				Swap(a[k], a[i], temp);					// a[k]와 a[i]를 교환
				InitPermutationsInt(a, k + 1, m);		// a[k+1], ... a[m]에 대한 모든 순열
				Swap(a[k], a[i], temp);					// 원래 상태로 되돌리기 위해 a[k]와 a[i]를 다시 교환
			}
		}
	}

	// 조합알고리즘
	void InitCombinationAlgorithm(std::string str)
	{
		strIn = str;
		Combine(0);
	}

	// 폰번호 단어
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

		// 반복문 분할
		// for 반복문이 마지막으로 돌아갈 때 실행되어야 할 코드를 반복문의 밖으로 꺼내 if문을 없앤다.
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