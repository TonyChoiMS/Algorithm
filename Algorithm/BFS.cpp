#include "BFS.h"

BFS::BFS()
{
}


BFS::~BFS()
{
}

vector<int> BFS::StartBFS(int start)
{
	vector<bool> discovered(adj.size(), false);

	queue<int> saveVisit;

	vector<int> order;
	discovered[start] = true;

	saveVisit.push(start);

	while (!saveVisit.empty())
	{
		int current = saveVisit.front();
		saveVisit.pop();

		order.push_back(current);

		for (int i = 0; i < adj[current].size(); i++)
		{
			int next = adj[current][i];

			if (!discovered[next])
			{
				saveVisit.push(next);
				discovered[next] = true;
			}
		}
	}

	return order;
}

// start에서 시작해서 그래프를 너비 우선 탐색하고 시작점부터 각 정점까지의
// 최단 거리와 너비 우선 탐색 스패닝 트리를 계산.
// distance[i] = start부터 i까지의 최단거리
// parent[i] = 너비 우선 탐색 스패닝 트리에서 i의 부모의 번호. 루트인 경우 자신의 번호
void BFS::StartBFS2(int start, vector<int>& distance, vector<int>& parent)
{
	distance = vector<int>(adj.size(), -1);
	parent = vector<int>(adj.size(), -1);
	queue<int> saveVisit;
	distance[start] = 0;
	parent[start] = start;
	saveVisit.push(start);

	while (!saveVisit.empty())
	{
		int current = saveVisit.front();
		saveVisit.pop();
		// Current(현재)의 모든 인접한 정점을 검사한다.
		for (size_t i = 0; i < adj[current].size(); i++)
		{
			int next = adj[current][i];
			// 처음 방문한 정점이면 방문 목록에 저장.
			if (distance[next] == -1)
			{
				saveVisit.push(next);
				distance[next] = distance[current] + 1;
				parent[next] = current;
			}
		}
	}
}

// v로부터 시작점까지의 최단 경로를 계산한다.
vector<int> BFS::ShortestPath(int v, const vector<int>& parent)
{
	vector<int> path(1, v);
	while (parent[v] != v)
	{
		v = parent[v];
		path.push_back(v);
	}

	reverse(path.begin(), path.end());
	return path;
}


