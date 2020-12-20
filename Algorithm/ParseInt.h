#pragma once

#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class ParseInt
{
public:
	vector<int> parseInt(vector<string> sequence)
	{
		vector<int> result;

		for (int i = 0; i < sequence.size(); i++)
		{
			result.push_back(stoi(sequence[i]));
		}

		return result;
	}

	vector<string> solution(vector<string> sequence)
	{
		vector<int> parseIntArr = parseInt(sequence);

		sort(parseIntArr.begin(), parseIntArr.end());

		vector<string> result;

		for (int i = 0; i < parseIntArr.size(); i++)
		{
			result.push_back(to_string(parseIntArr[i]));
		}

		return result;
	}
};