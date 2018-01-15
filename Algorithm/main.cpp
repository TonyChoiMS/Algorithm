#include <iostream>
#include "Algorithm.h"
#include "DijkstraAlgorithm.h"

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

    //최단경로 검색(0->6)
    dijkstra.findPath(0, 6);
	return 0;
}
