#pragma once

#include <iostream>
#include <string>

using namespace std;


/**
 * LeetCode Implement strStr()
 */
class ImplementStrStr
{
public:
	int strStr(string haystack, string needle) 
	{
		int hayStackLength = haystack.length();
		int needleLength = needle.length();

		if (needleLength == 0)
			return 0;

		if (hayStackLength < needleLength)
			return -1;

		int Result = -1;
		int CorrectCount = 0;
		for (int i = 0; i < hayStackLength; i++)
		{
			if (i + needleLength <= hayStackLength)
			{
				CorrectCount = 0;
				for (int j = 0; j < needleLength; j++)
				{
					if (haystack.at(i + j) == needle.at(j))
					{
						CorrectCount++;
					}
				}

				if (CorrectCount == needleLength)
				{
					Result = i;
					break;
				}
			}
			else
			{
				break;
			}
		}

		return Result;
	}
};