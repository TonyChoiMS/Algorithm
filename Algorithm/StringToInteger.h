#pragma once
#include <string>
#include <cctype>

class StringToInteger
{
public :
	int myAtoi(std::string str) 
	{
		if (((str[0] - '0' < 0) || (str[0] - '9' > 0)) && (str[0] != '+') && str[0] != '-' && (str[0] != ' '))
		{
			return 0;
		}

		int flag = 1, index = 0;
		double answer = 0;
		while (str[index] == ' ')
		{
			index++;
		}

		if (str[index] == '-')
		{
			flag = -1;
			index++;
		}
		else if (str[index] == '+')
		{
			index++;
		}
			
		for (int i = index, s = str.length(); i < s; i++)
		{
			if ((str[i] >= '0') && (str[i] <= '9'))
			{
				answer = (str[i] - '0') + answer * 10;
			}
			else
			{
				break;
			}
		}

		answer *= flag;
		//std::cout << answer << std::endl;
		if (answer > 2147483647)
			return 2147483647;
		else if (answer < -2147483647)				// LeetCode������ 2147483648�� �����ؾ� �н��� �� ����. �����Ϸ��� ���̷�, 2147483648�� �Է��� ��� unsigned ������ �Ѿ�ٴ� ���� ������ ������ �ȵ�.
			return -2147483647;
		else return answer;
	}

	// Interview�� ���� Ǯ��
	int StrToInt(std::string str)
	{
		int i = 0;
		int num = 0;
		bool bIsNeg = false;
		int length = str.length();

		while (str[i] == ' ')
		{
			i++;
		}

		if (str.at(i) == '-')
		{
			bIsNeg = true;
			i++;
		}

		while (i < length)
		{
			num *= 10;
			num += (str.at(i++) - '0');
		}

		if (bIsNeg)
			num = -num;

		return num;
	}
};

