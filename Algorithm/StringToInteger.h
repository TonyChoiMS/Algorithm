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
		else if (answer < -2147483647)
			return -2147483647;
		else return answer;
	}
};

