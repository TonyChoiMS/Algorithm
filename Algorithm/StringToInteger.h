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
		else if (answer < -2147483647)				// LeetCode에서는 2147483648로 설정해야 패스할 수 있음. 컴파일러의 차이로, 2147483648을 입력할 경우 unsigned 범위을 넘어간다는 에러 때문에 컴파일 안됨.
			return -2147483647;
		else return answer;
	}
};

