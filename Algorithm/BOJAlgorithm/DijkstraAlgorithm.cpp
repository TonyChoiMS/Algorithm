
#include "DijkstraAlgorithm.h"
#include <iostream>

using namespace std;

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
		_table[i] = nullptr;
	}
	delete[] _table;
	_table = nullptr;
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
	path = nullptr;
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
	
	cost = nullptr;
	visit = nullptr;
}

void DijkstraAlgorithm::printTable(int *cost, bool *visit, int length) 
{
	//print number
	cout << "Num\t:\t" << endl;
	for (int i = 0; i < length; i++)
		cout << i << endl;
		
	// print cost
	for (int i = 0;  i <length; i++) {
		if (cost[i] != INF)
			cout << cost[i] << endl;
		else 
			cout << "X\t" << endl;
	}
	
	// check visit
	cout << "\nVisit\t: \t" << endl;
	for (int i=0; i < length; i++) 
		cout << visit[i] << endl;
		
	cout << "\n\n" << endl;
}

void DijkstraAlgorithm::printShortestWay(int from, int to, int *prev) 
{
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
	{
		cout << "path not exist" << endl;
	}
	else 
	{
		path[lastIndex++] = to;
		
		//print path
		cout << "Optimal path : " <<  start << endl;
		
		for (int i = lastIndex-1; i>0; i--) 
		{
			cout << path[i] << endl;
		}
		
		cout << final << endl;
	}
	delete[] path;
	path = nullptr;
}
