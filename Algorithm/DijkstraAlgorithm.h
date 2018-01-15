#pragma once

#define INF 99999999

class DijkstraAlgorithm {
private:
	const int _numberOfNodes;			// Maximum nodes count
	int **_table;						// cost of node's length
	
public:
	DijkstraAlgorithm(int numberOfNodes);
	~DijkstraAlgorithm();
	
	void set(int from, int to, int cost);	// set path(route)
	void findPath(int from, int to);		// start find path
	
private:
	void calPath(int *&path, int from);		// calculate path
	void printTable(int *cost, bool *visit, int length);	// print table
	void printShortestWay(int from, int to, int *prev);		// print shortest way
};
