#include "Palindrome.h"

using namespace std;

Palindrome::Palindrome()
{
}


Palindrome::~Palindrome()
{
}

bool Palindrome::PalindromAlgorithmToInt(int n)
{
	int r = 0;
	int temp;
	int size = 0;

	temp = n;
	while (temp > 0)
	{
		temp = temp / 10;
		size++;
	}

	temp = n;
	size--;

	while (temp > 0)
	{
		r += (temp % 10) *pow((double)10, (double)size--);
		temp /= 10;
	}

	if (r == n)
		return true;
	else
		return false;
}

bool Palindrome::PalindromAlgorithmToString(string str)
{
	for (int i = 0; i < str.length(); i++)
	{
		for (int j = 0; j < str.length() / 2; j++)
		{
			if (tolower(str[i]) != tolower(str[str.length() - 1 - i]))
				return false;
		}
	}

	return true;
}
