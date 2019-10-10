#include "PrevTest.h"
#include <queue>
#include <string>
#include <vector>
#include <cmath>

using namespace std;


/**
 * 코테 3.
 * 자연수 n이 주어질 때 n을 서로 다른 두 소수의 곱으로 나타낼 수 있는지를 알아보려 합니다. 예를들어 n = 6이면,
 * 서로 다른 두 소수 2와 3의 곱으로 나타낼 수 있습니다. 그러나 n = 12라면 더로 다른 두 소수의 곱으로 나타낼 수 없습니다.
 * 자연수 n이 매개변수로 주어질 때, 곱해서 n이 되는 서로 다른 두 소수를 찾아 return 하도록 solution 함수를 완성해주세요.
 * 제한사항
 * 1. n은 2이상 10^12 이하의 자연수입니다.
 * 2. n을 서로 다른 두 소수의 곱으로 나타낼 수 있다면, 해당하는 두 소수를 오름차순으로 정렬해서 배열 형태로 return해주세요.
 * 3. 만약 n을 서로 다른 두 소수의 곱으로 나타낼 수 없다면 [-1, -1]을 return 해주세요.
 */
bool IsPrime(long long n)
{
	long long end = sqrt(n);
	for (long long i = 0; i <= end; ++i)
	{
		if (n % i == 0)
		{
			return false;
		}
	}

	return true;
}

void PrevTest::Test3()
{
	long long n = 1234124214;

	if (IsPrime(n))
	{
		
	}
	else
	{

	}
}

/**
 * LINE 2019 상반기 인턴채용 코테 1번.
 * 문제 : 연인 코니와 브라운은 광활한 들판에서 '나 잡아봐라' 게임을 한다. 이 게임은 브라운이 코니를 잡거나, 코니가 너무 멀리 달아나면 끝난다. 게임이 끝나는데 걸리는 최소 시간을 구하시오.
 * 조건
 * 1. 코니는 처음 위치 C에서 1초 후 1만큼 움직이고, 이후에는 가속이 붙어 매 초마다 이전 이동 거리 + 1만큼 움직인다. 즉 시간에 따른 코니의 위치는 C, C+1, C+3, C+6, ... 이다.
 * 2. 브라운은 현재 위치 B에서 다음 순간 B-1, B+1, 2*B 중 하나로 움직일 수 있다.
 * 3. 코니와 브라운의 위치 p는 조건 0<= x <= 200,000을 만족한다.
 * 4. 브라운은 범위를 벗어나는 위치로는 이동할 수 없고, 코니가 범위를 벗어나면 게임이 끝난다.
 *
 * 입력 : 표준 입력의 첫 줄에 코니의 위치 C와 브라운의 위치 B를 공백으로 구분하여 순서대로 읽는다.
 * 출력 : 브라운이 코니를 잡을 수 있는 최소시간 N초를 표준 출력한다. 단 브라운이 코니를 잡지 못한 경우에는 -1을 출력한다.
 */
int PrevTest::LineTest1(int conyPosition, int brownyPosition)
{
	int time = 0;
	bool visit[200001][2];
	queue<pair<int, int>> queue;

	memset(visit, 0, sizeof(visit));
	queue.push(make_pair(brownyPosition, 0));

	while (true)
	{
		conyPosition += time;

		// 코니가 멀리 도망갔을 경우
		if (conyPosition > 200000)
			return -1;

		// 브라우니가 코니를 잡았을 경우 시간 변수 리턴
		if (visit[conyPosition][time % 2])
			return time;

		for (int i = 0, size = queue.size(); i < size; i++)
		{
			int currentPosition = queue.front().first;
			int newTime = (queue.front().second + 1) % 2;
			int newPosition;

			queue.pop();

			newPosition = currentPosition - 1;
			if (newPosition > 0 && !visit[newPosition][newTime])
			{
				visit[newPosition][newTime] = true;
				queue.push(make_pair(newPosition, newTime));
			}

			newPosition = currentPosition + 1;
			if (newPosition < 200001 && !visit[newPosition][newTime])
			{
				visit[newPosition][newTime] = true;
				queue.push(make_pair(newPosition, newTime));
			}

			newPosition = currentPosition * 2;
			if (newPosition < 200001 && !visit[newPosition][newTime])
			{
				visit[newPosition][newTime] = true;
				queue.push(make_pair(newPosition, newTime));
			}
		}
		time++;
	}
}
