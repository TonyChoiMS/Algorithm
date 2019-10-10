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
 * ���� 3.
 * �ڿ��� n�� �־��� �� n�� ���� �ٸ� �� �Ҽ��� ������ ��Ÿ�� �� �ִ����� �˾ƺ��� �մϴ�. ������� n = 6�̸�,
 * ���� �ٸ� �� �Ҽ� 2�� 3�� ������ ��Ÿ�� �� �ֽ��ϴ�. �׷��� n = 12��� ���� �ٸ� �� �Ҽ��� ������ ��Ÿ�� �� �����ϴ�.
 * �ڿ��� n�� �Ű������� �־��� ��, ���ؼ� n�� �Ǵ� ���� �ٸ� �� �Ҽ��� ã�� return �ϵ��� solution �Լ��� �ϼ����ּ���.
 * ���ѻ���
 * 1. n�� 2�̻� 10^12 ������ �ڿ����Դϴ�.
 * 2. n�� ���� �ٸ� �� �Ҽ��� ������ ��Ÿ�� �� �ִٸ�, �ش��ϴ� �� �Ҽ��� ������������ �����ؼ� �迭 ���·� return���ּ���.
 * 3. ���� n�� ���� �ٸ� �� �Ҽ��� ������ ��Ÿ�� �� ���ٸ� [-1, -1]�� return ���ּ���.
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
 * LINE 2019 ��ݱ� ����ä�� ���� 1��.
 * ���� : ���� �ڴϿ� ������ ��Ȱ�� ���ǿ��� '�� ��ƺ���' ������ �Ѵ�. �� ������ ������ �ڴϸ� ��ų�, �ڴϰ� �ʹ� �ָ� �޾Ƴ��� ������. ������ �����µ� �ɸ��� �ּ� �ð��� ���Ͻÿ�.
 * ����
 * 1. �ڴϴ� ó�� ��ġ C���� 1�� �� 1��ŭ �����̰�, ���Ŀ��� ������ �پ� �� �ʸ��� ���� �̵� �Ÿ� + 1��ŭ �����δ�. �� �ð��� ���� �ڴ��� ��ġ�� C, C+1, C+3, C+6, ... �̴�.
 * 2. ������ ���� ��ġ B���� ���� ���� B-1, B+1, 2*B �� �ϳ��� ������ �� �ִ�.
 * 3. �ڴϿ� ������ ��ġ p�� ���� 0<= x <= 200,000�� �����Ѵ�.
 * 4. ������ ������ ����� ��ġ�δ� �̵��� �� ����, �ڴϰ� ������ ����� ������ ������.
 *
 * �Է� : ǥ�� �Է��� ù �ٿ� �ڴ��� ��ġ C�� ������ ��ġ B�� �������� �����Ͽ� ������� �д´�.
 * ��� : ������ �ڴϸ� ���� �� �ִ� �ּҽð� N�ʸ� ǥ�� ����Ѵ�. �� ������ �ڴϸ� ���� ���� ��쿡�� -1�� ����Ѵ�.
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

		// �ڴϰ� �ָ� �������� ���
		if (conyPosition > 200000)
			return -1;

		// ����ϰ� �ڴϸ� ����� ��� �ð� ���� ����
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

	// �Է�
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

	// ���
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
