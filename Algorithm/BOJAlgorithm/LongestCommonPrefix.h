#pragma once

#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

class LongestCommonPrefix
{
public:
	string Solution(vector<string>& strs)
	{
		if (strs.size() == 0) return "";
		if (strs.size() == 1) return strs[0];

		const string standard = strs[0];
		string result;

		for (int i = 0; i < standard.size(); i++)
		{
			bool canAdd = true;

			for (int j = 0; j < strs.size(); j++)
			{
				if (i >= strs[j].size() || standard.at(i) != strs[j].at(i))
				{
					canAdd = false;
					break;
				}
			}

			if (!canAdd)
				break;

			result += standard.at(i);
		}

		return result;
	}
};