#pragma once

class Algorithm {
public:
	Algorithm();
	~Algorithm();
	// Hanoi Algorithm
	void solveHanoi(int num, int src, int mid, int dest);
	
	// Fibonacci 
	int recursiveFibonacci(int length);
	int loopFibonacci(int length);
	long fib(long n);
	long fibo_iter(long x, long a, long b);
	
	// GCD and LCM
	int loopGreatestCommonDivisor(int num1, int num2);
	int loopEuclideanGCD(int num1, int num2);
	int recursiveEuclideanGCD(int num1, int num2);
	
	int loopLeastCommonMultiple(int num1, int num2);
	int loopEuclideanLCM(int num1, int num2);
	
	// Greedy Algorithm (Coin Change)
	void CoinChange(int coins[], int numberOfType, int money);
};
