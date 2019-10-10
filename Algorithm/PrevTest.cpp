#include "PrevTest.h"
#include <queue>
#include <string>
#include <vector>
#include <cmath>
#include <ctime>
#include <math.h>

#include <algorithm>
#include <vector>

#define RIGHT 1
#define DOWN 2
#define RIGHTDOWN 3
#define LEFTDOWN 4

using namespace std;

PrevTest::PrevTest()
{
}
PrevTest::~PrevTest()
{
}

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

		for (size_t i = 0, size = queue.size(); i < size; i++)
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

void PrevTest::KakaoTest1()
{

	cout << "KakaoTest1" << endl;
	int n = 5;
	int* arr1 = new int[n] {9, 20, 28, 18, 11};
	int* arr2 = new int[n] {30, 1, 21, 17, 28};

	string* result = new string[n]();

	for (int i = 0; i < n; i++)
	{
		int targetBit = 1;
		string resultString = "";
		int arr = arr1[i] | arr2[i];
		for (int j = 0; j < n; j++)
		{
			resultString = ((arr & targetBit) > 0 ? "#" : " ") + resultString;
			targetBit = targetBit << 1;
		}

		result[i] = resultString;
		cout << result[i] << endl;
	}
}

void PrevTest::Test1()
{
	cout << "test1" << endl;
	vector<string> order_times;
	int k = 20;

	int answer = 0;
	int oldAnswer = 0;
	int h, m = 0;
	int ch, cm = 0;
	
	order_times.push_back("12:10");
	order_times.push_back("12:20");
	order_times.push_back("12:40");
	order_times.push_back("12:40");
	order_times.push_back("12:50");
	order_times.push_back("13:00");
	order_times.push_back("13:20");

	//sscanf_s(order_times[order_times.size() - 1], "%d:%d", )

	for (int i = 0; i < order_times.size(); i++)
	{
		sscanf_s(order_times[i].c_str(), "%d:%d", &h, &m);
	
		int min = h * 60 + m;
		oldAnswer = 0;
		cout << "min " << min << "    ";
		for (int j = 0; j < order_times.size(); j++)
		{
			sscanf_s(order_times[j].c_str(), "%d:%d", &ch, &cm);

			int compareTime = ch * 60 + cm + k;
			cout << "compare : " << compareTime << endl;
			if (min <= compareTime && compareTime <= min + k)
			{
				oldAnswer++;
			}
		}
		cout << "answer : " << answer << ", old : " << oldAnswer << endl;
		if (oldAnswer > answer)
			answer = oldAnswer;
	}
	cout << answer << endl;
}

void PrevTest::Test2()
{
	vector<int> target;
	target.push_back(2);
	target.push_back(2);
	target.push_back(2);
	target.push_back(2);
	target.push_back(2);
	vector<vector<int>> positions(
		{
			vector<int>({0, 0}),
			vector<int>({0, 1}),
			vector<int>({1, 1}),
			vector<int>({-3, 5}),
			vector<int>({7, 5}),
			vector<int>({10, 0}),
			vector<int>({-15, 22}),
			vector<int>({-6, -5}),
			vector<int>({3, 3}),
			vector<int>({5, -5})
		}
	);
	//positions.push_back(vector<int>(0, 0));

	int answer = 0;

	int a = 10, b = 8, c = 6, d = 4, e = 2, f = 0;
	int x, y = 0;

	int score[] = {10, 8, 6, 4, 2};

	double targetDistance = 0;
	for (int i = 0; i < positions.size(); i++)
	{
		x = positions[i][0];
		y = positions[i][1];
		//cout << "x : " << x << ", y : " << y << endl;
		double distance = sqrt(pow(x - 0, 2) + pow(y - 0, 2));
		//cout <<  "distance : " << distance << endl;
		targetDistance = 0;
		for (int j = 0; j < target.size(); j++)
		{
			targetDistance += target[j];
			//cout << "targetDistance : " << targetDistance << endl;
			if (0 <= distance && distance <= targetDistance)
			{
				answer += score[j];
				//cout << "score[j] : " << score[j] << ", answer : " << answer << endl;
				break;
			}
		}
	}

	//cout << "answer : " << answer << endl;

}

bool PrevTest::era(long long n)
{
	bool isPrime = true;

	for (int i = 2; i < sqrt(n); ++i)
	{
		if (n / i == 0)
		{
			isPrime = false;
			break;
		}
	}

	return isPrime;
}

void PrevTest::Test3()
{
	long long n = 12;
	vector<long long> answer;

	long long k = 2;
	int count = 0;

	bool correct = true;


	if (2 <= n && n <= 1000000000000)
	{
		while (n != 1)
		{
			if (n % k == 0)
			{
				cout << k << " ";
				n /= k;
				count++;
				answer.push_back(k);
			}
			else
			{
				k++;
			}

			if (count > 2)
			{
				correct = false;
				break;
			}
		}

		if (count == 2)
		{
			if (era(answer[0]) && era(answer[1]))
			{
				if (answer[0] > answer[1])
				{
					long long temp = answer[0];
					answer[0] = answer[1];
					answer[1] = temp;
				}
			}
			else
			{
				correct = false;
			}
		}
		else
		{
			correct = false;
		}
	}
	else
	{
		correct = false;
	}

	if (correct == false)
	{
		answer.clear();
		answer.push_back(-1);
		answer.push_back(-1);
	}

	string result = correct ? "true" : "false";

	cout << answer[0] << answer[1] << ", " << result << endl;
	
	//cout << answer << endl;
}

void PrevTest::solution()
{
	int h = 5;
	int w = 5;
	int n = 5;

	vector<string> board = vector<string>({
		"11111", "11111", "11111", "11111", "11111"});

	int answer = 0;

	vector<vector<int>> arr(h, vector<int>(w, 0));

	// 입력
	for (int y = 0; y < h; y++)
	{
		for (int x = 0; x < w; x++)
		{
			char aa = board[y].at(x);
			//arr[y].push_back(atoi(&aa));
			arr[y][x] = atoi(&aa);
			cout << board[y].at(x);
		}
	}

	// 출력
	for (int y = 0; y < h; y++)
	{
		for (int x = 0; x < w; x++)
		{
			int current = arr[y][x];
			cout << current << endl;
			if (current == 1)
			{
				if ((y >= 0 && y < h) && (x >= 0 && x < w))
				{
					vector<pair<int, int>> v;

					int dx = x;
					int dy = y;
					cout << "cur " << current << "arr[y][x + 1] " << arr[y][x + 1] << endl;
					if (current == arr[y][x + 1])
					{
						if (arr[y][x - 1] == 1)
						{
							v.clear();
							v.push_back(pair<int, int>(y, x));

							while (arr[dy][++dx] == 1)
							{
								if ((dy >= 0 && dy < h) && (dx >= 1 && dx < w))
								{
									v.push_back(pair<int, int>(dy, dx));
								}
								
							}
						}
						cout << v.size() << endl;
						if (v.size() == n)
						{
							answer++;
						}
					}
					if (current == arr[y + 1][x])
					{
						if (arr[y - 1][x] == 1)
						{
							v.clear();
							v.push_back(pair<int, int>(y, x));
							while (arr[++dy][dx] == 1)
							{
								if ((dy >= 0 && dy < h) && (dx >= 1 && dx < w))
								{
									v.push_back(pair<int, int>(dy, dx));
								}
								
							}
						}
						cout << v.size() << endl;
						if (v.size() == n)
						{
							answer++;
						}
					}
					if (current == arr[y + 1][x + 1])
					{
						if (arr[y - 1][x - 1] == 1)
						{
							v.clear();
							v.push_back(pair<int, int>(y, x));
							while (arr[++dy][++dx] == 1)
							{
								if ((dy >= 0 && dy < h) && (dx >= 1 && dx < w))
								{
									v.push_back(pair<int, int>(dy, dx));
								}
								
							}
						}
						cout << v.size() << endl;
						if (v.size() == n)
						{
							answer++;
						}
					}
					if (current == arr[y + 1][x - 1])
					{
						if (arr[y - 1][x + 1] == 1)
						{
							v.clear();
							v.push_back(pair<int, int>(y, x));
							while (arr[++dy][--dx] == 1)
							{
								if ((dy >= 0 && dy < h) && (dx >= 1 && dx < w))
								{
									v.push_back(pair<int, int>(dy, dx));
								}
								
							}
						}
						cout << v.size() << endl;
						if (v.size() == n)
						{
							answer++;
						}
					}
				}
			}
		}
	}


	cout << "answer : " << answer << endl;
}

bool PrevTest::isInside(int y, int x)
{
	return false;
}
