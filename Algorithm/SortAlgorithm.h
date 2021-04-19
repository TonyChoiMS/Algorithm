#pragma once
#include <iostream>

class SortAlgorithm
{
public:
	SortAlgorithm() {};
	~SortAlgorithm() {};

	
	// ���� ���� �˰���
	// �ּ�, ���, �־��� ��� ��� O(n^2)�̴�. ó�� ������ ���� ���� ���´� �� ȸ���� ���� ������ ��ġ�� �ʴ´�.
	// �׷��ٰ� �˰����� ȿ���� �ٸ� ���� �˰��� ���� ���� ���� �ƴ�.
	// ���� ������ ������ ���Ҹ� �¹ٲٴ� Ƚ���� �ִ� n-1 ���̶�� ���̴�.
	// ������ ���Ҹ� �����̴� �� �� �۾��� ���� ��� ��쿡�� ���� ������ �ٸ� �˰��򺸴� ���� ���� �ִ�.
	// ���ڸ� ���� �˰����̸�, �Ϲ����� ���� ���� �ڵ�� �Ҿ����ϴ�.
	void SelectionSortRecursive(int* data)
	{
		SelectionSortRecursive(data, 0);
	}


	// �������� ���� ����
	// �������̶����� Ű�� ���� ������ ������ �Էµ� ���� �״�� ���������ִ� ���� �˰����� ���Ѵ�.
	/*void StableInsertionSort(int* data)
	{
		for (int i = 0; i < sizeof(data) - 1; ++i)
		{
			StableInsert(data, i, findMinimumIndex(data, i));
		}
	}*/

	// ���� ���� �˰���
	// �̹� ���ĵ� ���� �� O(n)����, �̶��� ���� ������ ȿ�����̴�.
	// ������ ��� �� �־��� ��쿣 O(n^2)�̹Ƿ�, �������� ���ĵ� ���� �����͸� ó���ϱ⿣ ���� �˰����� �ƴϴ�.
	// �ҷ��� ������ ������ ó���� �� ������ �����ϱ� ������ �ٸ� �� ������ ���� �˰����� ����� �⺻ �����ε� ���� ����.
	void InsertionSort(int* data)
	{
		for (int i = 0; i < sizeof(data); i++)
		{
			int value = data[i];

			for (int j = 0; j < sizeof(data); j++)
			{
				if (data[j] > value)
				{
					Swap(data, data[i], data[j]);
					break;
				}
			}
		}
	}

	// �� ���� �˰���
	// ������ ���� ������ �� �ǹ� ���� �� ���� �� �������� ������ �� ���� �κ��������� ������. 
	// �� �� �κ����տ��� �ǹ� ������ ���� �͸�, �ٸ� �κ����տ��� ū �͸� �ִ´�. 
	// �� �̻� �ɰ� �κ������� ���� ������ ������ �κ����տ� ���� �ǹ�.�ɰ��� �۾��� ��������� �����Ѵ�.
	// �� ������ � �ǹ����� �������� ���� ������ �����ȴ�.
	// ���� �̻����� �ǹ� ���� ��ü �����͸� ���ݾ����� �ɰ� �� �ִ� ���̴�.
	// ��������
	// ���� �Լ� ���´� �������� ������ �����̸�, ������������ �ϱ� ���� ���, Partition �Լ� �� ǥ���� ���� ��ȣ�� �ݴ�� ���ָ�ȴ�.
	void QuickSort(int* data)
	{
		QuickSort(data, 0, sizeof(data) - 1);
	}

	void QuickSort(int* data, int start, int end)
	{
		int part2 = Partition(data, start, end);
		if (start < part2 - 1)
		{
			QuickSort(data, start, part2 - 1);
		}
		
		if (part2 < end)
		{
			QuickSort(data, part2, end);
		}
	}

	int Partition(int* data, int start, int end)
	{
		int pivot = data[(start + end) / 2];
		while (start <= end)
		{
			while (data[start] < pivot) start++;			// ǥ��
			while (data[end] > pivot) end--;				// ǥ��
			if (start <= end)
			{
				Swap(data, start, end);
				start++;
				end--;
			}
		}

		return start;
	}

	void PrintQuickSort(int* data)
	{
		for (int i = 0; i < sizeof(data); i++)
		{
			std::cout << data[i] << std::endl;
		}

		std::cout << "end " << std::endl;
	}
		

	// ��ġ�� ����(Merge Sort)
	// ������ ������ �� �̻��� �κ��������� ������, �� �κ������� ������ ���� �ٽ� ���ĵ� ���·� ��ġ�� ���
	// ���������� �˰���
	// �ٸ� �˰���� �޸� ������ ������ �޸𸮿� �ѹ��� �ø��⿡ �ʹ� Ŭ �� ���� ���� ����̴�.
	// ex) ������ ū ���Ͽ� �ִ� ������ ���� ���� �� ���� ���Ϸ� ������. ������ ���� ������ �޸𸮷� �о�鿩�� ������ �˰������� ������ ���� �ٽ� ���Ϸ� �����ϴ� ���.
	// ����, �ְ�, ��� ����ð��� ��� O(n log(n)) �̴�.
	// ������ �ٸ� �˰��� ��� O(n) ������ �޸𸮰� �߰��� �ʿ��ϴٴ� ������ ���Ѵ�.
	// ������ ���� ����� �޸𸮿� ���� �ϱ� ������ n���� ���ڵ带 ��Ƶα� ���� ���� ������ �ʿ��ϴ�.
	// �׸��� ��ģ ����� �����ϱ� ���� n���� ���ڵ带 �����ϱ� ���� �ӽ� ���۰� �߰��� �ʿ��ϴ�.
	int* MergeSort(int* data)
	{
		int Length = sizeof(data);

		// ������ ��������.
		/*if (Length < 2)
		{
			return data;
		}*/

		// �������ǿ� ���������� �̿��Ͽ� Hybrid MergeSort�� ������ �� �ִ�.
		// ���������� ��ġ�� ���Ŀ� ���� ��ü�� ������嵵 ����, ������ ������ ���� ���� �� �� �������̱� ������ ����ȭ ������� ���ȴ�.
		if (Length < 10)			// ������ �������� ���� ������ ���� ��
		{
			InsertionSort(data);
			return data;
		}

		// �迭�� ũ�Ⱑ ���� ���� �� ���� �κй迭�� ������.
		int mid = Length / 2;

		int* left = new int[mid];
		int* right = new int[Length - mid];

		//System.arraycopy(data, 0, left, 0, sizeof(left));
		//System.arraycopy(data, mid, right, 0, sizeof(right));

		// �� �κй迭�� ������ ���� ����� ��ģ��.
		MergeSort(left);
		MergeSort(right);

		return Merge(data, left, right);
	}

	// ������ �� ���� ������ �˰����� �����ΰ�?
	// �ٷ� ����ϴ� ���� �ƴ� ����� ������ �ݵ�� �ľ��� �� ����� �� �־���Ѵ�.
	// 1. � �������ΰ�? - �����Ͱ� �̹� ���� �Ǵ� ������ ���ĵ� �ִ°�? ������ ������ ũ��� ���� ������� �ΰ�? �ߺ��� Ű ���� ���� �� �ִ°�?
	// 2. ���� ������ ��� �Ǵ°�? - �ּ�, �־�, ��� �� ��� ��Ȳ�� ���缭 ����ȭ�ؾ� �ұ�? ���� �������� �������Ѿ� �ϴ°�?
	// 3. � �ý������� �� �� �ִ°�? - �����ؾ� �ϴ� �������� �ִ�ġ�� ��� ������ �޸� ũ��� ���ؼ� �� ū��, ������?

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

	int* Merge(int* dest, int* left, int* right)
	{
		int dind = 0;
		int lind = 0;
		int rind = 0;

		// ���ʿ� ��� ���Ұ� �ִ� ���¿��� �迭�� ��ħ
		while (lind < sizeof(left) && rind < sizeof(right))
		{
			if (left[lind] <= right[rind])
			{
				dest[dind++] = left[lind++];
			}
			else
			{
				dest[dind++] = right[rind++];
			}
		}

		// ���� ���Ұ� ���� �迭�� �ִ� ���� ������
		while (lind < sizeof(left))
		{
			dest[dind++] = left[lind++];
		}

		while (rind < sizeof(right))
		{
			dest[dind++] = right[rind++];
		}

		return dest;
	}

	/*void StableInsert(vector<int> data, int start, int minIndex)
	{
		if (minIndex > start)
		{
			int tmp = data[minIndex];
			data.insert()
				data[start] = tmp;
		}
	}*/

};
