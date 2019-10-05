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

// start���� �����ؼ� �׷����� �ʺ� �켱 Ž���ϰ� ���������� �� ����������
// �ִ� �Ÿ��� �ʺ� �켱 Ž�� ���д� Ʈ���� ���.
// distance[i] = start���� i������ �ִܰŸ�
// parent[i] = �ʺ� �켱 Ž�� ���д� Ʈ������ i�� �θ��� ��ȣ. ��Ʈ�� ��� �ڽ��� ��ȣ
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
		// Current(����)�� ��� ������ ������ �˻��Ѵ�.
		for (size_t i = 0; i < adj[current].size(); i++)
		{
			int next = adj[current][i];
			// ó�� �湮�� �����̸� �湮 ��Ͽ� ����.
			if (distance[next] == -1)
			{
				saveVisit.push(next);
				distance[next] = distance[current] + 1;
				parent[next] = current;
			}
		}
	}
}

// v�κ��� ������������ �ִ� ��θ� ����Ѵ�.
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


