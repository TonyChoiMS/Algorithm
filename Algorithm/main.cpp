#include <iostream>
#include "Algorithm.h"
#include "DijkstraAlgorithm.h"
#include "Palindrome.h"
#include "RecursiveAlgorithm.h"
#include "PrevTest.h"

using namespace std;

// Node ����
class Node
{
public:
	Node* head;
	int data;
	Node* nextNode = nullptr;

	int count = 0;

	void Insert(int data)
	{
		if (count == 0)
		{
			head->data = data;
			head->nextNode = nullptr;
		}
		else
		{
			Node *currentNode = new Node();

			currentNode->data = data;
			currentNode->nextNode = nullptr;

			Node *tempNode = head;

			while (tempNode->nextNode != nullptr)
			{
				tempNode = tempNode->nextNode;
			}

			tempNode->nextNode = currentNode;
		}

		count++;
	}
};

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


int main() {
	//int nt;
	//printf("�ϳ����� �� ���� : ");
	//scanf("%d", &nt);
	Algorithm* algorithm = new Algorithm();
	//algorithm->solveHanoi(nt, 1, 2, 3);
	
	//int recursive = algorithm->recursiveFibonacci(40);
	//printf("recursive : %d\n", recursive);
	int loop = algorithm->loopFibonacci(40);
	printf("loop : %d\n", loop);
	//long recursive = algorithm->fib(40);
	//printf("recursiv : %d\n", recursive);
	int case1 = algorithm->loopGreatestCommonDivisor(300, 150);
	int case2 = algorithm->loopEuclideanGCD(300, 150);
	int case3 = algorithm->recursiveEuclideanGCD(300, 150);
	
	printf("loop gcd : %d\n", case1);
	printf("loop euclidean gcd : %d\n", case2);
	printf("recursive gcd : %d\n", case3);
	
	int lcm1 = algorithm->loopLeastCommonMultiple(24, 7);
	int lcm2 = algorithm->loopEuclideanLCM(24, 7);
	printf("loop lcm : %d\n", lcm1);
	printf("loop lcm : %d\n", lcm2);
	
	int coins[] = {10, 50, 100, 500};
	algorithm->CoinChange(coins, 4, 2000);
	delete algorithm;
	
	DijkstraAlgorithm dijkstra(7);    // initialize, max node is 7
    // setting path
    dijkstra.set(0, 1, 2);    //0 -> 1 : cost 2
    dijkstra.set(0, 3, 5);
    
    dijkstra.set(1, 2, 6);
    dijkstra.set(1, 4, 10);
    
    dijkstra.set(2, 6, 3);

    dijkstra.set(3, 4, 4);
    dijkstra.set(3, 5, 5);

    dijkstra.set(4, 5, 1);
    dijkstra.set(4, 6, 7);
 
    dijkstra.set(5, 6, 2);

    //�ִܰ�� �˻�(0->6)
    dijkstra.findPath(0, 6);


	// �����Լ� ��Ӱ��� Ȯ��
	A *pA = new A;
	pA->f1();
	pA->f2();
	pA->f3();
	delete pA;

	pA = new B;
	pA->f1();
	pA->f2();
	pA->f3();
	delete pA;


	// �Ӹ���� �˰���
	int n = 12321;

	bool bPalindrom = false;

	Palindrome palindrome;

	bPalindrom = palindrome.PalindromAlgorithmToInt(12321);

	if (bPalindrom)
		cout << n << ": ȸ�� �����Դϴ�." << endl;
	else
		cout << n << ": ȸ�� ���ڰ� �ƴմϴ�." << endl;

	cout << bPalindrom << endl;
	string str = "asdfdsa";
	bPalindrom = palindrome.PalindromAlgorithmToString(str);

	/*if (bPalindrom)
		cout << "ȸ���Դϴ�. " << str << endl;
	else
		cout << "ȸ���� �ƴմϴ�. " <<  str << endl;*/

	cout << bPalindrom << endl;

	string strRecursive = "asdf";
	RecursiveAlgorithm* recur = new RecursiveAlgorithm;
	recur->InitPermutations(strRecursive);

	cout << "end " << endl;

	recur->InitCombinationAlgorithm(strRecursive);

	PrevTest* prev = new PrevTest;

	prev->KakaoTest1();
	prev->solution();

	return 0;
}