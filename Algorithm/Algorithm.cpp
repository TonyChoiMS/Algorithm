#include "Algorithm.h"
#include <stdio.h>
Algorithm::Algorithm() {
	
}

Algorithm::~Algorithm() {
	
}
//////////////////////////// Hanoi /////////////////////////////////////////
// ��������� ���� ���� ��ȣ�� ����(NUM)�� ���� ������ ������ �������� �̵� 
// NUM�� �ش��ϴ� ������ �������� �̵� �������� ���,
// ���ĺ��ʹ� �������� �ִ� ������ �������� �̵���Ű�� �۾��� ����  
// Num : ���ǹ�ȣ, Src : �����, mid : ������, Dest : ������ 
void Algorithm::solveHanoi(int num, int src, int mid, int dest) {
	//���� �̵� 
	if (num == 1)
		printf("���� %d : %d -> %d\n", num, src, dest);
	else {
		
		// �ڽ��� ������ ���ǵ� �̵�(�ڽź��� ���� ����)
		// ������� => ��������
		solveHanoi(num-1, src, dest, mid);
		
		// ���� �̵�
		printf("���� %d : %d -> %d\n", num, src, dest);
		
		// �������� �̵� ���״� ���ǵ� �ٽ� �ڽ��� ���� �̵�
		// �������� => ��������
		solveHanoi(num-1, mid, src, dest); 
	}
}
//////////////////////////// End Hanoi /////////////////////////////////////

//////////////////////////// Fibonacci//////////////////////////////////////
/////////////////////////////// Sample 1 ///////////////////////////////////
/**
* Big-O O(F(n)), Compile time 0.9537(number 40)
*/
int Algorithm::recursiveFibonacci(int length) {
	if (length < 2)
		return length;
	
	return recursiveFibonacci(length-2) + recursiveFibonacci(length-1);
}
/////////////////////////////// Sample 1 end ///////////////////////////////

/////////////////////////////// Sample 2 ///////////////////////////////////
/**
* Big-O O(n), Compile time 0.1877(number 40)
*/
long Algorithm::fib(long num) {
	return fibo_iter(num, 0, 1);
}

long Algorithm::fibo_iter(long x, long a, long b) {
	if (x == 0) return a;
	else return fibo_iter(x-1, b, a+b);
}
/////////////////////////////// Sample 2 end ///////////////////////////////

/////////////////////////////// Sample 3 ///////////////////////////////////
/**
* Big-O O(n), Compile time 0.1841(number 40)
*/
int Algorithm::loopFibonacci(int length) {
	int prev = 1;
	int now = 0;
	int sum = 0;
	
	for (int i = 0; i < length; i++) {
		sum = prev + now;
		
		prev = now;
		now = sum;
	}
	
	return sum;
}
/////////////////////////////// Sample 3 end ///////////////////////////////
//////////////////////////// End Fibonacci /////////////////////////////////

//////////////////////////// GCD & LCM /////////////////////////////////////
int Algorithm::loopGreatestCommonDivisor(int num1, int num2) {
	int max = 1;
	int length = num1 < num2 ? num1 : num2;		// ���� ���ڸ�ŭ �ݺ� ����
	
	for (int i = 1; i <= length; i++) {
		// �� �� ��� ������ �������� max ��ü
		if((num1 % i == 0) && (num2 % i == 0)){
			max = i;
		 } 
	} 
	return max;
}

int Algorithm::loopEuclideanGCD(int num1, int num2) {
	int reminder;
	while (num2) {
		reminder = num1 % num2;
		num1 = num2;
		num2 = reminder;
	}
	return num1;
}

int Algorithm::recursiveEuclideanGCD(int num1, int num2) {
	if (num2 == 0)
	return num1;
	
	recursiveEuclideanGCD(num2, num1 % num2);
}

int Algorithm::loopLeastCommonMultiple(int num1, int num2) {
	int num = num1 > num2 ? num1 : num2;	// �� ū���� ���������� 
	// �ּ� ������� ã�� ������ �ݺ�
	while (true) {
		// ���� ���� �� �� ��η� ������������ ���� �ּ� �����
		if ((num % num1 == 0) && (num % num2 == 0)) {
			return num;	
		}
		// ã�������� 1�� ���� 
		num++;
	} 
}

int Algorithm::loopEuclideanLCM(int num1, int num2) {
	int divisor = recursiveEuclideanGCD(num1, num2);		// �ִ� �����
	int multiple = num1 * num2;	// �� ���� ��
	
	return multiple / divisor;
}
//////////////////////////// End GCD & LCM //////////////////////////////////

// Greedy Algorithm (Coin Change) - probably edit this logic
void Algorithm::CoinChange(int coins[], int numberOfType, int money) {
	int *count = new int[numberOfType];	// count of exchange coins 
	int type = 0;						// Kinds of coins
	
	printf("exchange coins : %d won\n", money);
	
	// intialize 0 about coins
	for (int i = 0; i < numberOfType; i++)
		count[i] = 0;
		
	// loop while check last coin
	while(type < numberOfType) {
		// if coin larger than money, change coin type
		if (coins[type] > money) {
			type++;
		}
		// if coin less than money, up to coin count, and discount money to coin value
		else if (coins[type] < money) {
			money -= coins[type];
			count[type]++;
		}
		// if last coin value == money, up to coin count and end loop.
		else {
			money = 0;
			count[type]++;
			break;
		}
	}
	// print kinds of coins count
	for (int i=0; i <numberOfType; i++) {
		if (count[i] != 0)
			printf("%d coin %d\n", coins[i], count[i]);
	}
	
	// leftovers money
	if (money != 0)
		printf("left overs money is %d\n", money);
		
	delete count;
	count = NULL;
}
