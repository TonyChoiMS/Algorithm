#include "Algorithm.h"
#include <stdio.h>
Algorithm::Algorithm() {
	
}

Algorithm::~Algorithm() {
	
}
//////////////////////////// Hanoi /////////////////////////////////////////
// 출발지에서 가장 높은 번호의 원판(NUM)만 남을 때까지 원판을 경유지로 이동 
// NUM에 해당하는 원판을 목적지로 이동 성공했을 경우,
// 이후부터는 경유지에 있는 원판을 목적지로 이동시키는 작업을 수행  
// Num : 원판번호, Src : 출발지, mid : 경유지, Dest : 목적지 
void Algorithm::solveHanoi(int num, int src, int mid, int dest) {
	//원판 이동 
	if (num == 1)
		printf("원판 %d : %d -> %d\n", num, src, dest);
	else {
		
		// 자신의 위에서 원판들 이동(자신보다 작은 원판)
		// 출발지점 => 경유지점
		solveHanoi(num-1, src, dest, mid);
		
		// 원판 이동
		printf("원판 %d : %d -> %d\n", num, src, dest);
		
		// 경유지로 이동 시켰던 원판들 다시 자신의 위로 이동
		// 경유지점 => 도착지점
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
	int length = num1 < num2 ? num1 : num2;		// 작은 숫자만큼 반복 수행
	
	for (int i = 1; i <= length; i++) {
		// 두 수 모두 나누어 떨어지면 max 대체
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
	int num = num1 > num2 ? num1 : num2;	// 더 큰수를 시작점으로 
	// 최소 공배수를 찾을 때까지 반복
	while (true) {
		// 제일 먼저 두 수 모두로 나눠떨어지는 수가 최소 공배수
		if ((num % num1 == 0) && (num % num2 == 0)) {
			return num;	
		}
		// 찾을때까지 1씩 더함 
		num++;
	} 
}

int Algorithm::loopEuclideanLCM(int num1, int num2) {
	int divisor = recursiveEuclideanGCD(num1, num2);		// 최대 공약수
	int multiple = num1 * num2;	// 두 수의 곱
	
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

