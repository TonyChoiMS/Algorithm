#pragma once

#include <iostream>

using namespace std;

class ExplorePoint
{
public:
	int solution(int x1, int y1, int x2, int y2, int d)
	{
		// d = 장축의 길이로 볼 수 있음.
	// 단축의 길이는 루트 (d/2)제곱 - 단축의 제곱

	// 중점 x, y
		int centerX = x2 - x1;
		int centerY = y2 - y1;

		int exploreStartX = centerX - d;
		int exploreEndX = centerX + d;
		int exploreStartY = centerY - d;
		int exploreEndY = centerY + d;

		int answer = 0;

		for (int i = exploreStartX; i < exploreEndX; i++)
		{
			for (int j = exploreStartY; j < exploreEndY; j++)
			{
				double pos1Distance = sqrt(pow((double)x1 - i, 2) + pow((double)y1 - j, 2));
				double pos2Distance = sqrt(pow((double)x2 - i, 2) + pow((double)y2 - j, 2));

				/*double ad = pow(pos1Distance, 2);
				double bd = pow(pos2Distance, 2);

				double powx = pow(i, 2);
				double powy = pow(j, 2);*/

				//float result = ((float)powx / pos1Distance) + ((float)powy / pos2Distance);
				double result = pos1Distance + pos2Distance;
				cout << result << endl;
				if (result < d)
				{
					answer++;
				}

			}
		}

		return answer;
	}
};
