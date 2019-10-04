#pragma once

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class BFS
{
public:
	BFS();
	~BFS();

	vector<vector<int>> adj;

	vector<int> StartBFS(int start);
	void StartBFS2(int start, vector<int>& distance, vector<int>& parent);
	vector<int> ShortestPath(int v, const vector<int>& parent);
};

