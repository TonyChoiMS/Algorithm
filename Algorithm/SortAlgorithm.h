#pragma once

class SortAlgorithm
{
public:
	SortAlgorithm();
	~SortAlgorithm();

	// 선택 정렬 알고리즘
	void SelectionSortRecursive(int* data)
	{
		SelectionSortRecursive(data, 0);
	}


private:
	void SelectionSortRecursive(int* data, int start)
	{
		if (start < sizeof(data) - 1)
		{
			Swap(data, start, findMinimumIndex(data, start));
			SelectionSortRecursive(data, start + 1);
		}
	}

	int findMinimumIndex(int* data, int start)
	{
		int minPos = start;

		for (int i = start + 1; i < sizeof(data); i++)
		{
			if (data[i] < data[minPos])
				minPos = i;
		}

		return minPos;
	}

	void Swap(int* data, int index1, int index2)
	{
		if (index1 != index2)
		{
			int temp = data[index1];
			data[index1] = data[index2];
			data[index2] = temp;
		}
	}
};
