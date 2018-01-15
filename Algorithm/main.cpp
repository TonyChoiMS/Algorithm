#include <iostream>
#include "Algorithm.h"

int main() {
	//int nt;
	//printf("하노이의 돌 갯수 : ");
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
	delete algorithm;
	return 0;
}
