#include "stdafx.h"
#include "DijkstraAlgorithm.h"

DijkstraAlgorithm::DijkstraAlgorithm(int numberOfNodes): _numberOfNodes(numberOfNodes) {
	// initialize cost table
	_table = new int*[numberOfNodes];
	
	for (int i = 0; i < numberOfNodes; i++)	{
		_table[i] = new int[numberOfNodes];
		
		for (int j=0; j < numberOfNodes; j++) {
			if (i == j)
				_table[i][j] = 0;
			else
				_table[i][j] = INF;
		}
	}
}

DijkstraAlgorithm::~DijkstraAlgorithm() {
	// delete cost table memory
	for (int i =0;  i < _numberOfNodes; i++) {
		delete[] _table[i];
		_table[i] = NULL;
	}
	delete[] _table;
	_table = NULL;
}
	
void DijkstraAlgorithm::set(int from, int to, int cost) {
	if (from < _numberOfNodes && to < _numberOfNodes) {
		_table[from][to] = cost;
	}
}

void DijkstraAlgorithm::findPath(int from, int to) {
	// initialize path array 
	int *path = new int[_numberOfNodes];
	
	//calc path
	calPath(path, from);
	
	// print shortest way
	printShortestWay(from, to, path);
	
	// array delete memory
	delete[] path;
	path = NULL;
}

void DijkstraAlgorithm::calPath(int *&path, int from) {
	int min, index;
	int *cost = new int[_numberOfNodes];
	bool *visit = new bool[_numberOfNodes];
	
	// initiailize array
	for (int i = 0; i < _numberOfNodes; i++) {
		cost[i] = INF;
		visit[i] = false;
		path[i] = -1;
	}
	
	// start path cost = 0;
	cost[from] = 0;
	
	// loop total node count
	for (int i=0; i < _numberOfNodes; i++) {
		min = INF + 1;
		index = -1;
		
		// search node
		for (int j = 0; j < _numberOfNodes; j++) {
			// alreay checked node, pass
			if (visit[j])
				continue;
			
			// if (current minimum < current node cost) => next node
			if (min > cost[j]) {
				min = cost[j];
				index = j;
			}
		}
		
		// re calc node cost
		for (int j = 0; j < _numberOfNodes; j++) {
			//if (current cost > node cost) => renewal
			if (cost[j] > cost[index] + _table[index][j]) {
				// renewal cost
				cost[j] = cost[index] + _table[index][j];
				// renewal path
				path[j] = index;
			}
		}
		
		// current node's visit value change true
		visit[index] = true;
		
		// print table //check progress
		printTable(cost, visit, _numberOfNodes);
	}
	
	delete[] cost;
	delete[] visit;
	
	cost = NULL;
	visit = NULL;
}

void DijkstraAlgorithm::printTable(int *cost, bool *visit, int length) {
	//print number
	printf("Num\t:\t");
	for (int i = 0; i < length; i++)
		printf("%d\t", i);
		
	// print cost
	for (int i = 0;  i <length; i++) {
		if (cost[i] != INF)
			printf("%d\t", cost[i]);
		else 
			printf("X\t");
	}
	
	// check visit
	printf("\nVisit\t: \t");
	for (int i=0; i < length; i++) 
		printf("%d\t", visit[i]);
		
	printf("\n\n");
}

void DijkstraAlgorithm::printShortestWay(int from, int to, int *prev) {
	// save print path
	int *path = new int[_numberOfNodes];
	// last index of saved path
	int lastIndex = 0;
	
	int final = to;		// start path
	int start = from;	// arrive path
	
	from = prev[to];
	
	// reverse final arrive path to find
	while (from != start && from != -1) {
		path[lastIndex++] = to;
		
		to = from;
		from = prev[from];
	}
	
	// if path not exist
	if (from == -1) 
		printf("path not exist\n");
	else {
		path[lastIndex++] = to;
		
		//print path
		printf("Optimal path : %d->", start);
		
		for (int i = lastIndex-1; i>0; i--) {
			printf("%d-> ", path[i]);
		}
		
		printf("%d\n", final);
	}
	delete[] path;
	path = NULL;
}
