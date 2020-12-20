#pragma once

#include <iostream>
#include <map>
#include <vector>

using namespace std;

class CalcNumCount
{
public:
	map<int, int> calcNumCount(vector<int> statements)
	{
		map<int, int> map;

		for (int i = 0; i < statements.size(); i++)
		{
			if (map.count(statements[i]) > 0)
			{
				map[statements[i]]++;
				//mapOne.find(statements[i])->second++;
			}
			else
			{
				map[statements[i]] = 1;
				//mapOne.insert(pair<int, int>(statements[i], 1));
				//mapOne[*one] = 1;
			}
		}

		return map;
	}

	int solution(vector<int> statements)
	{
		map<int, int> stateMap = calcNumCount(statements);

		int answer = 0;
		int count = -1;
		for (auto it = stateMap.begin(); it != stateMap.end(); ++it)
		{
			cout << "count : " << count << ", second : " << it->second << ", first : " << it->first << endl;
			if (count <= it->second && it->first == it->second)
			{
				count = it->second;
				answer = count;
			}

			cout << it->first << ", " << it->second << endl;
		}

		if (count == -1)
			answer = -1;

		return answer;
	}
};
