#pragma once

class SortAlgorithm
{
public:
	SortAlgorithm();
	~SortAlgorithm();

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
	//int* QuickSort(int* data)
	//{
	//	int Length = sizeof(data);
	//	if (Length < 2)
	//	{
	//		return data;
	//	}

	//	int pivotIndex = Length / 2;
	//	int pivotValue = data[pivotIndex];

	//	int leftCount = 0;

	//	// �ǹ����� ���� ���� ���� ����
	//	for (int i = 0; i < Length; i++)
	//	{
	//		if (data[i] < pivotValue) 
	//			++leftCount;
	//	}
	//	
	//	// �迭 �Ҵ� �� �κ����� �����
	//	int* left = new int[leftCount];
	//	int* right = new int[Length - leftCount - 1];
	//	int l = 0;
	//	int  r = 0;

	//	for (int i = 0; i < Length; i++)
	//	{
	//		if (i == pivotIndex) 
	//			continue;

	//		int value = data[i];

	//		if (value < pivotValue)
	//		{
	//			left[l++] = value;
	//		}
	//		else
	//		{
	//			right[r++] = value;
	//		}
	//	}

	//	// �κ����� ����
	//	left = QuickSort(left);
	//	right = QuickSort(right);

	//	// ���ĵ� �迭��� �ǹ��� ���ļ� ���� �迭�� ����
	//	system.array
	//}

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
		while(lind < sizeof(left))
		{
			dest[dind++] = left[lind++];
		}

		while (rind < sizeof(right))
		{
			dest[dind++] = right[rind++];
		}

		return dest;
	}
};
