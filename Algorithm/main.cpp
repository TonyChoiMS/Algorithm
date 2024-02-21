#include <iostream>
#include "BOJAlgorithm/Algorithm.h"
#include "BOJAlgorithm/DijkstraAlgorithm.h"
#include "BOJAlgorithm/Palindrome.h"
#include "BOJAlgorithm/RecursiveAlgorithm.h"
#include "BOJAlgorithm/PrevTest.h"
#include "BOJAlgorithm/StringToInteger.h"
#include "BOJAlgorithm/ImplementStrStr.h"
#include "BOJAlgorithm/ParseJson.h"
#include "BOJAlgorithm/MultiThreadTest.h"
#include "BOJAlgorithm/SortAlgorithm.h"
#include "BOJAlgorithm/AplindromeLinkedList.h"

using namespace std;

// Node ����
//class Node
//{
//public:
//	Node* head;
//	int data;
//	Node* nextNode = nullptr;
//
//	int count = 0;
//
//	void Insert(int data)
//	{
//		if (count == 0)
//		{
//			head->data = data;
//			head->nextNode = nullptr;
//		}
//		else
//		{
//			Node *currentNode = new Node();
//
//			currentNode->data = data;
//			currentNode->nextNode = nullptr;
//
//			Node *tempNode = head;
//
//			while (tempNode->nextNode != nullptr)
//			{
//				tempNode = tempNode->nextNode;
//			}
//
//			tempNode->nextNode = currentNode;
//		}
//
//		count++;
//	}
//};

// �����Լ� ��� ���� Ȯ��
class A {
public:
	virtual void f1() { cout << "A :: f1" << endl; }
	virtual void f2() { cout << "A :: f2" << endl; }
	void f3() { cout << "A :: f3" << endl; }
};

class B : public A {
public:
	virtual void f2() { cout << "B :: f2" << endl; }
	void f3() { cout << "B :: f3" << endl; }
	virtual void f4() { cout << "B :: f4" << endl; }
};

int NumOnesInBinary(int number)
{
	int numOnes = 0;
	while (number != 0)
	{
		if ((number & 1) == 1)
		{
			numOnes++;
		}
		number = number >> 1;
	}

	return numOnes;
}

#include <map>
#include <sstream>

vector<string> split(string input, char delimiter)
{
	vector<string> answer;
	stringstream ss(input);
	string temp;

	while (getline(ss, temp, delimiter))
	{
		answer.push_back(temp);
	}

	return answer;
}

#include <set>

//#include <bits/stdc++.h>
//#define fastio cin.tie(0)->sync_with_stdio(0)
//
//vector<int> solution(vector<string> id_list, vector<string> report, int k) {
//	// 1.
//	const int n = id_list.size();
//	map<string, int> Conv;
//	for (int i = 0; i < n; i++) Conv[id_list[i]] = i;
//
//	// 2.
//	vector<pair<int, int>> v;
//	sort(report.begin(), report.end());
//	report.erase(unique(report.begin(), report.end()), report.end());
//	for (const auto& s : report) {
//		stringstream in(s);
//		string a, b; in >> a >> b;
//		v.push_back({ Conv[a], Conv[b] });
//	}
//
//	// 3.
//	vector<int> cnt(n), ret(n);
//	for (const auto& [a, b] : v) cnt[b]++;
//	for (const auto& [a, b] : v) if (cnt[b] >= k) ret[a]++;
//	return ret;
//}

// �Ű� ��� �ޱ�
vector<int> Solution1(vector<string> id_list, vector<string> report, int k) 
{
	vector<int> answer(id_list.size(), 0);
	
	map<string, int> id_idx;

	map<string, set<string>> report_map;

	for (int i = 0; i < id_list.size(); i++)
	{
		id_idx[id_list[i]] = i;
	}

	for (const string rep : report)
	{
		vector<string> result = split(rep, ' ');

		report_map[result[1]].insert(result[0]);
	}

	for (const auto iter : report_map)
	{
		if (iter.second.size() >= k)
			for (auto in_iter : iter.second)
			{
				answer[id_idx[in_iter]]++;
			}
			
	}
	
	return answer;
}


// ���ڿ� ����
int solution2(string s)
{
	int answer = s.size();
	for (int i = 1; i < s.size() / 2; i++)
	{
		int cnt = 1;
		string temp = "";
		string a = s.substr(0, i);
		for (int j = i; j < s.size(); j += i)
		{
			if (a == s.substr(j, i))
			{
				cnt++;
			}
			else
			{
				if (cnt > 1)
					temp += to_string(cnt);

				temp += a;
				a = s.substr(j, i);
				cnt = 1;
			}
		}
		
		if (cnt > 1)
			temp += to_string(cnt);

		temp += a;

		if (answer > temp.size())
			answer = temp.size();
	}

	return answer;
}

int solution3(string s) {
	int answer = s.length();
	//����� �� Ž���ϱ�
	for (int i = 1; i <= s.length() / 2; i++) 
	{
		int len = s.length();
		//���ڿ��� ��ü ���鼭 �ݺ�
		for (int j = 0; j < s.length(); j++) 
		{
			//�κ� ���ϱ�
			for (int count = 0, z = i; j + z < s.length(); z += i) 
			{
				//�ںκа� ��ġ�Ѵٸ� count ����
				if (s.substr(j, i) == s.substr(j + z, i))
				{
					count++;
				}
				else 
				{
					//�ڿ��κ��� ��ġ�����ʴ´ٸ� countȮ���� �ߺ��Ǵ� ���ڿ���ŭ ��������
					//�߰��Ǵ� ���ڸ�ŭ ��������
					len -= i * count;
					if (count)     len += to_string(count + 1).length();
					j += z - 1;
					break;
				}
				// �ѹ��̶� ������ �Ȼ��¿��� �ڿ��� ����� �ȵȴٸ�
				//������ �߰��ϰ� �������� �ڿ� �߰�
				if (j + z + i >= s.length()) 
				{
					len -= i * count;
					len += to_string(count + 1).length();
					j += z;
				}
			}
		}
		//���ڿ� ���̸� ���ؼ� �������ٸ� �����ɷ� ����
		if (len < answer)    
			answer = len;
	}
	return answer;
}

void print(string s, int answer) {
	int t = solution3(s);
	if (answer == t)
		cout << "����" << endl;
	else
		cout << "Ʋ��" << endl;
}

#include <format>

// ����ä�ù�
vector<string> Solution4(vector<string> record)
{
	vector<string> answer;
	map<string, string> userList;			// first : uid, second : userName

	string state;
	string uid;
	string UserName;

	for (string rec : record)
	{
		stringstream ss(rec);
		ss >> state;
		ss >> uid;

		if (state == "Enter" || state == "Change")
		{
			ss >> UserName;
			userList[uid] = UserName;
		}
	}

	for (string rec : record)
	{
		stringstream ss(rec);
		ss >> state;
		ss >> uid;

		if (state == "Enter")
		{
			answer.push_back(userList[uid] + "���� ���Խ��ϴ�.");
		}
		else if (state == "Leave")
		{
			answer.push_back(userList[uid] + "���� �������ϴ�.");
		}
	}
	

	
	return answer;
}

#include <queue>
int MaxSize;
int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };
bool Visit[100][100];

int BFS(int a, int b, int m, int n, vector<vector<int>> picture)
{
	int Color = picture[a][b];
	int Size = 1;
	queue<pair<int, int>> Q;
	Q.push(make_pair(a, b));
	Visit[a][b] = true;

	while (Q.empty() == 0)
	{
		int x = Q.front().first;
		int y = Q.front().second;
		Q.pop();

		for (int i = 0; i < 4; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx >= 0 && ny >= 0 && nx < m && ny < n)
			{
				if (picture[nx][ny] == Color && Visit[nx][ny] == false)
				{
					Visit[nx][ny] = true;
					Q.push(make_pair(nx, ny));
					Size++;
				}
			}
		}
	}

	return Size;
}

// īī�������� �÷�����
vector<int> solution(int m, int n, vector<vector<int>> picture) {

	// �湮 ��� �ʱ�ȭ
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			Visit[i][j] = false;
		}
	}
	
	int number_of_area = 0;
	int max_size_of_one_area = 0;

	vector<int> answer(2);			// 1�� ������ ����, 2�� ���� ū ������ ĭ ��

	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (picture[i][j] != 0 && Visit[i][j] == false)
			{
				int Size = BFS(i, j, m, n, picture);
				if (Size > max_size_of_one_area)
					max_size_of_one_area = Size;

				number_of_area++;
			}
		}
	}

	answer[0] = number_of_area;
	answer[1] = max_size_of_one_area;

	

	return answer;
}

// ��ü���� ���
bool checkCondition(char opr, int num, int diff)
{
	if (opr == '=')
		return num == diff;
	else if (opr == '>')
		return diff > num;
	else 
		return diff < num;
}

int solution5(int n, vector<string> data)
{

	int answer = 0;
	string friends = "ACFJMNRT";
	vector<vector<char>> s;
	sort(friends.begin(), friends.end());

	do 
	{
		bool Check = true;

		for (string txt : data)
		{
			int firstIdx = friends.find(txt[0]);
			int secondIdx = friends.find(txt[2]);
			int diff = abs(firstIdx - secondIdx) - 1;
			int num = txt[4] - '0';

			if (checkCondition(txt[3], num, diff))
				continue;

			Check = false;
			break;
		}

		if (Check)
			answer++;
		
	} while (next_permutation(friends.begin(), friends.end()));

	return answer;
}

// ��ɰ���
vector<int> solution(vector<int> progresses, vector<int> speeds) {
	vector<int> answer;

	queue<int> Q;
	int SavedcalcDate = 0;
	int answerCount = 0;
	for (int i = 0; i < progresses.size(); i++)
	{
		float calcDate = ceil((100 - progresses[i]) / (float)speeds[i]);
		Q.push((int)calcDate);
	}

	SavedcalcDate = Q.front();

	while (!Q.empty())
	{
		int CalcDate = Q.front();
		Q.pop();
		//answer.push_back(CalcDate);
		if (SavedcalcDate >= CalcDate)
		{
			if (answer.empty())
				answer.push_back(1);
			else
				++answer.back();
		}
		else
		{
SavedcalcDate = CalcDate;
answer.push_back(1);
		}
	}

	return answer;
}

// ������ �簢��
int gcd(int a, int b) {
	if (a == 0) return b;
	return gcd(b % a, a);
}

long long solution(int w, int h)
{

	//answer = (long long) w * (long long)h - (w + h) + gcd(w, h);
	long long answer = ((long)w * h) - ((long)w + h - gcd(w, h));
	return answer;
}

// 124 ����
// 3���� ����.
string solution(int n)
{
	string answer = "";
	int share = n;
	int remainder = -1;

	while (share != 0)
	{
		remainder = share % 3;
		share = share / 3;

		if (remainder == 0)
			share -= 1;

		answer = "412"[remainder] + answer;
	}

	return answer;
}

// �� �ʰ� (�켱���� ť)
int solution(vector<int> scoville, int K)
{
	int answer = 0;
	priority_queue<int, vector<int>, greater<int>> pq(scoville.begin(), scoville.end());

	while (pq.size() > 1 && pq.top() < K)
	{
		int first = pq.top();
		pq.pop();
		int sec = pq.top();
		pq.pop();

		pq.push(first + (sec * 2));
		answer++;
	}

	if (pq.top() < K)
		return -1;

	return answer;
}

// N���� ǥ��
int getNs(int N, int idx)
{
	int result = N;
	for (int i = 1; i <= idx; i++)
	{
		result = result * 10 + N;
	}
	return result;
}
#include <unordered_set>

int solution5(int N, int number)
{
	if (N == number) return 1;

	vector<unordered_set<int>> DP(8);

	DP[0].insert(N);

	for (int k = 1; k < 8; k++)
	{
		DP[k].insert(getNs(N, k));

		for (int i = 0; i < k; i++)
		{
			for (int j = 0; j < k; j++)
			{
				if (i + j + 1 != k) continue;

				for (int a : DP[i])
				{
					for (int b : DP[j])
					{
						DP[k].insert(a + b);

						if (a - b > 0)
							DP[k].insert(a - b);

						DP[k].insert(a * b);

						if (a / b > 0) DP[k].insert(a / b);
					}
				}
			}
		}

		if (DP[k].find(number) != DP[k].end())
			return k + 1;
	}

	return -1;
}

// �Ա��ɻ�
long long solution(int n, vector<int> times)
{
	long long answer = 0;

	sort(times.begin(), times.end());

	long long start = 1;

	long long end = (long long) times[times.size() - 1] * n;

	long long mid;

	while (start <= end)
	{
		mid = (start + end) / 2;
		long long cnt = 0;

		for (int i = 0; i < times.size(); i++)
		{
			cnt += mid / times[i];
		}

		if (cnt < n)
		{
			start = mid + 1;
		}
		else
		{
			if (mid <= end)
			{
				answer = mid;
			}
			end = mid - 1;
		}
	}

	return answer;
}

string screen[64];

// BOJ 1992 [���� Ʈ��]
void RecursiveQuadTree(int size, int y, int x)
{
	char pixel = screen[y][x];

	for (int i = y; i < y + size; ++i)
	{
		for (int j = x; j < x + size; ++j)
		{
			if (screen[i][j] != pixel)
			{
				cout << '(';
				RecursiveQuadTree(size / 2, y, x);
				RecursiveQuadTree(size / 2, y, x + size / 2);
				RecursiveQuadTree(size / 2, y + size / 2, x);
				RecursiveQuadTree(size / 2, y + size / 2, x + size / 2);
				cout << ')';
				return;
			}
		}
	}

	cout << pixel;
}


int main() 
{
#pragma region aa
	////int nt;
	////printf("�ϳ����� �� ���� : ");
	////scanf("%d", &nt);
	//Algorithm* algorithm = new Algorithm();
	////algorithm->solveHanoi(nt, 1, 2, 3);
	//
	////int recursive = algorithm->recursiveFibonacci(40);
	////printf("recursive : %d\n", recursive);
	//int loop = algorithm->loopFibonacci(40);
	////printf("loop : %d\n", loop);
	////long recursive = algorithm->fib(40);
	////printf("recursiv : %d\n", recursive);
	//int case1 = algorithm->loopGreatestCommonDivisor(300, 150);
	//int case2 = algorithm->loopEuclideanGCD(300, 150);
	//int case3 = algorithm->recursiveEuclideanGCD(300, 150);
	//
	////printf("loop gcd : %d\n", case1);
	////printf("loop euclidean gcd : %d\n", case2);
	////printf("recursive gcd : %d\n", case3);
	//
	//int lcm1 = algorithm->loopLeastCommonMultiple(24, 7);
	//int lcm2 = algorithm->loopEuclideanLCM(24, 7);
	////printf("loop lcm : %d\n", lcm1);
	////printf("loop lcm : %d\n", lcm2);
	//
	//int coins[] = {10, 50, 100, 500};
	////algorithm->CoinChange(coins, 4, 2000);
	//delete algorithm;
	//
	//DijkstraAlgorithm dijkstra(7);    // initialize, max node is 7
 //   // setting path
 //   dijkstra.set(0, 1, 2);    //0 -> 1 : cost 2
 //   dijkstra.set(0, 3, 5);
 //   
 //   dijkstra.set(1, 2, 6);
 //   dijkstra.set(1, 4, 10);
 //   
 //   dijkstra.set(2, 6, 3);

 //   dijkstra.set(3, 4, 4);
 //   dijkstra.set(3, 5, 5);

 //   dijkstra.set(4, 5, 1);
 //   dijkstra.set(4, 6, 7);
 //
 //   dijkstra.set(5, 6, 2);

 //   //�ִܰ�� �˻�(0->6)
 //   //dijkstra.findPath(0, 6);


	//// �����Լ� ��Ӱ��� Ȯ��
	//auto *pA = new A;
	//pA->f1();
	//pA->f2();
	//pA->f3();
	//delete pA;

	//pA = new B;
	//pA->f1();
	//pA->f2();
	//pA->f3();
	//delete pA;


	//// �Ӹ���� �˰���
	////int n = 12321;

	//bool bPalindrom = false;

	//Palindrome palindrome;

	//bPalindrom = palindrome.PalindromAlgorithmToInt(12321);

	///*if (bPalindrom)
	//	cout << n << ": ȸ�� �����Դϴ�." << endl;
	//else
	//	cout << n << ": ȸ�� ���ڰ� �ƴմϴ�." << endl;*/

	//cout << bPalindrom << endl;
	//string str = "asdfdsa";
	//bPalindrom = palindrome.PalindromAlgorithmToString(str);

	///*if (bPalindrom)
	//	cout << "ȸ���Դϴ�. " << str << endl;
	//else
	//	cout << "ȸ���� �ƴմϴ�. " <<  str << endl;*/

	////cout << bPalindrom << endl;

	//string strRecursive = "asdf";
	//RecursiveAlgorithm* recur = new RecursiveAlgorithm;
	////recur->InitPermutations(strRecursive);

	//cout << "end " << endl;

	////recur->InitCombinationAlgorithm(strRecursive);

	//PrevTest* prev = new PrevTest;

	////prev->KakaoTest1();
	////prev->solution();


	///*int k, n;
	//char arr[] = "Mega Value!!";
	//char temp;
	//n = strlen(arr);
	//n--;
	//for (k = 0; k < n; k++)
	//{
	//	temp = *(arr + k);
	//	*(arr + k) = *(arr + n);
	//	*(arr + n) = temp;
	//	n--;
	//}

	//printf(" answer %s/n", arr);

	//int ShiftNum = NumOnesInBinary(100);
	//cout << ShiftNum << endl;*/

	///*StringToInteger strToInt;
	//cout << strToInt.myAtoi("-91283472332") << endl;*/
	///*ImplementStrStr sss;
	//sss.strStr("hello", "ll");*/

	//ParseJson pJson;
	//int size;	// ������ ũ��
	//char *doc = pJson.ReadFile("example.json", &size);		// ���Ͽ��� JSON ������ ����, ���� ũ�⸦ ����
	//if (doc == nullptr)
	//	return -1;

	//JSON json;// = { 0, };	// JSON ����ü ���� ���� �� �ʱ�ȭ

	//pJson.Parse(doc, size, &json);	// JSON ���� �Ľ�

	//printf("Title: %s\n", json.tokens[1].string);
	//printf("Year: %d\n", (int)json.tokens[3].number);    // ��ū�� ����� ���� ���(Year)
	//printf("Runtime: %d\n", (int)json.tokens[5].number); // ��ū�� ����� ���� ���(Runtime)
	//printf("Genre: %s\n", json.tokens[7].string);        // ��ū�� ����� ���ڿ� ���(Genre)
	//printf("Director: %s\n", json.tokens[9].string);     // ��ū�� ����� ���ڿ� ���(Director)

	//printf("Actors:\n");
	//int actors = pJson.GetArrayCount(&json, "Actors");                // Actors �迭�� ������ ����
	//for (int i = 0; i < actors; i++)                            // �迭�� ��� ������ŭ �ݺ�
	//	printf("  %s\n", pJson.GetArrayString(&json, "Actors", i));   // �ε����� �����Ͽ� ���ڿ��� ������

	//printf("imdbRating: %f\n", json.tokens[17].number);  // ��ū�� ����� ���� ���(imdbRating)


	//pJson.FreeJson(&json);		// json�� �Ҵ�� ���� �޸� ����

	//free(doc);					// ���� ���� �޸� ����

	//MultiThreadTest mt;
	//mt.BitTest();

	//SortAlgorithm so;
	//int data[] = {3, 9, 4, 7, 5, 0, 1, 6, 8, 2};
	//so.PrintQuickSort(data);
	//so.QuickSort(data);
	//so.PrintQuickSort(data);

	//PalindromeLinkedList pl;
	//pl.Start();

	/////////////////////////////////////////
	// BOJ 1992 [���� Ʈ��]
	// int N;
	// cin >> N;
	// for (int i = 0; i < N; i++)
	// {
	// 	cin >> screen[i];
	// }

	//RecursiveQuadTree(N, 0, 0);


	/////////////////////////////////////////
#pragma endregion


	
	return 0;
}






///////////////////

// 버프 적용하기 위해 호출하는 함수
// void ApplyBuff(int buffId)
// {
// 	if (mBuffId == NONE)
// 	{
// 		// 현재 적용중인 버프가 없으면 즉시 버프 적용
// 		mBuffId = buffId;
// 		mBuffTime = DEFAULT_TIME;
//
// 		// 만약 queue에 동일한 버프가 존재하면 제거
// 		DeleteSameBuff();
// 	}
// 	else if (mBuffId == buffId)
// 	{
// 		// 현재 적용중인 버프가 있는데, 같은 종류의 버프가 또 요청이 왔을 경우 시간만 초기화
// 		mBuffTime = DEFAULT_TIME;
// 	}
// 	else
// 	{
// 		// 다른 종류의 버프인 경우, 큐에 enqueue
// 		mBuffQueue.enqueue(buffId);
// 	}
// }
//
// // 버프 지속시간을 체크 및 버프 종료 하는 함수.
// void ExpiredBuff()
// {
// 	if (mBuffTime > 0)
// 	{
// 		// 아직 버프 시간이 남아있는 경우
// 		mBuffTime--;
//
// 		if (mBuffTime == 0)
// 		{
// 			// 버프 시간이 종료되면 다음에 적용할 버프가 있는지 확인
// 			int nextBuffId = GetBuffQueueFront();
// 			if (nextBuffId != NONE)
// 			{
// 				// 현재의 버프 정보 초기화
// 				ResetBuffData();
// 				// 다음에 적용할 버프가 있는 경우
// 				ApplyBuff(nextBuffId);
// 			}
// 			else
// 			{
// 				// 더이상 적용할 버프가 없는 경우
// 				ResetBuffData();
// 			}
// 		}
// 	}
// }
//
// // 버프 초기화
// void ResetBuffData()
// {
// 	mBuffId = NONE;
// 	mBuffTime = NONE;
// }
//
// void DeleteSameBuff()
// {
// 	// 현재 적용되어있는 버프Id가 Queue에 있다면, 모두 제거
// 	// 현재 버프큐에 있는 내용을 임시로 저장하기 위한 큐
// 	std::queue tempQueue;
// 	while (!mBuffQueue.empty())
// 	{
// 		// 현재 적용되어 있는 버프 id랑 다른 Id만 temp에 저장합니다.
// 		int frontBuffId = mBuffQueue.front();
// 		if (frontBuffId != mBuffId)
// 		{
// 			tempQueue.enqueue(frontBuffId);
// 		}
//
// 		// 큐에서 item 빼옴
// 		mBuffQueue.pop();
// 	}
//
// 	// temp에 따로 저장해둔 id를 mBuffQueue로 전달
// 	mBuffQueue = std::move(tempQueue);
// }