#pragma once
#include <iostream>

class SortAlgorithm
{
public:
	SortAlgorithm() {};
	~SortAlgorithm() {};

	
	// 선택 정렬 알고리즘
	// 최선, 평균, 최악의 경우 모두 O(n^2)이다. 처음 시작할 때의 정렬 상태는 비교 회수에 전혀 영향을 끼치지 않는다.
	// 그렇다고 알고리즘의 효율이 다른 정렬 알고리즘에 비해 좋은 편은 아님.
	// 선택 정렬의 장점은 원소를 맞바꾸는 횟수가 최대 n-1 번이라는 점이다.
	// 데이터 원소를 움직이는 게 비교 작업에 비해 비싼 경우에는 선택 정렬이 다른 알고리즘보다 빠를 수도 있다.
	// 제자리 정렬 알고리즘이며, 일반적인 선택 정렬 코드는 불안정하다.
	void SelectionSortRecursive(int* data)
	{
		SelectionSortRecursive(data, 0);
	}


	// 안정적인 선택 정렬
	// 안정적이라함은 키가 같은 원소의 순서를 입력된 순서 그대로 유지시켜주는 정렬 알고리즘을 뜻한다.
	/*void StableInsertionSort(int* data)
	{
		for (int i = 0; i < sizeof(data) - 1; ++i)
		{
			StableInsert(data, i, findMinimumIndex(data, i));
		}
	}*/

	// 삽입 정렬 알고리즘
	// 이미 정렬되 있을 때 O(n)으로, 이때는 삽입 정렬이 효율적이다.
	// 하지만 평균 및 최악의 경우엔 O(n^2)이므로, 무작위로 정렬된 많은 데이터를 처리하기엔 좋은 알고리즘은 아니다.
	// 소량의 데이터 집합을 처리할 때 강점을 발휘하기 때문에 다른 더 복잡한 정렬 알고리즘을 만드는 기본 단위로도 많이 쓴다.
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

	// 퀵 정렬 알고리즘
	// 데이터 집합 내에서 한 피벗 값을 고른 다음 그 기준으로 집합을 두 개의 부분집합으로 나눈다. 
	// 한 쪽 부분집합에는 피벗 값보다 작은 것만, 다른 부분집합에는 큰 것만 넣는다. 
	// 더 이상 쪼갤 부분집합이 없을 때까지 각각의 부분집합에 대해 피벗.쪼개기 작업을 재귀적으로 적용한다.
	// 퀵 정렬은 어떤 피벗값을 고르는지에 따라 성능이 결정된다.
	// 가장 이상적인 피벗 값은 전체 데이터를 절반씩으로 쪼갤 수 있는 값이다.
	// 분할정복
	// 현재 함수 상태는 오름차순 정렬의 상태이며, 내림차순으로 하길 원할 경우, Partition 함수 중 표시한 곳의 부호만 반대로 해주면된다.
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
			while (data[start] < pivot) start++;			// 표시
			while (data[end] > pivot) end--;				// 표시
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
		

	// 합치기 정렬(Merge Sort)
	// 데이터 집합을 둘 이상의 부분집합으로 가르고, 각 부분집합을 정렬한 다음 다시 정렬된 형태로 합치는 방식
	// 분할정복형 알고리즘
	// 다른 알고리즘과 달리 데이터 집합이 메모리에 한번에 올리기에 너무 클 때 쓰기 좋은 방법이다.
	// ex) 보통은 큰 파일에 있는 내용을 여러 개의 더 작은 파일로 나눈다. 각각의 작은 파일을 메모리로 읽어들여서 적당한 알고리즘으로 정렬한 다음 다시 파일로 저장하는 방식.
	// 최저, 최고, 평균 실행시간은 모두 O(n log(n)) 이다.
	// 하지만 다른 알고리즘 대비 O(n) 수준의 메모리가 추가로 필요하다는 단점을 지닌다.
	// 각각의 하위 목록은 메모리에 들어가야 하기 때문에 n개의 레코드를 담아두기 위한 저장 공간이 필요하다.
	// 그리고 합친 결과를 저장하기 위해 n개의 레코드를 저장하기 위한 임시 버퍼가 추가로 필요하다.
	int* MergeSort(int* data)
	{
		int Length = sizeof(data);

		// 기존의 종료조건.
		/*if (Length < 2)
		{
			return data;
		}*/

		// 종료조건에 삽입정렬을 이용하여 Hybrid MergeSort를 구현할 수 있다.
		// 삽입정렬은 합치기 정렬에 비해 대체로 오버헤드도 적고, 데이터 집합이 아주 작을 때 더 빠른편이기 때문에 최적화 방법으로 사용된다.
		if (Length < 10)			// 경험을 바탕으로 정한 적당히 작은 값
		{
			InsertionSort(data);
			return data;
		}

		// 배열을 크기가 거의 같은 두 개의 부분배열로 가른다.
		int mid = Length / 2;

		int* left = new int[mid];
		int* right = new int[Length - mid];

		//System.arraycopy(data, 0, left, 0, sizeof(left));
		//System.arraycopy(data, mid, right, 0, sizeof(right));

		// 각 부분배열을 정렬한 다음 결과를 합친다.
		MergeSort(left);
		MergeSort(right);

		return Merge(data, left, right);
	}

	// 정렬할 때 가장 적합한 알고리즘은 무엇인가?
	// 바로 대답하는 것이 아닌 몇가지의 사항을 반드시 파악한 후 대답할 수 있어야한다.
	// 1. 어떤 데이터인가? - 데이터가 이미 거의 또는 완전히 정렬되 있는가? 데이터 집합의 크기는 보통 어느정도 인가? 중복된 키 값이 있을 수 있는가?
	// 2. 정렬 조건이 어떻게 되는가? - 최선, 최악, 평균 중 어느 상황에 맞춰서 최적화해야 할까? 정렬 안정성을 만족시켜야 하는가?
	// 3. 어떤 시스템인지 알 수 있는가? - 정렬해야 하는 데이터의 최대치가 사용 가능한 메모리 크기랑 비교해서 더 큰지, 작은지?

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

		// 양쪽에 모두 원소가 있는 상태에서 배열을 합침
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

		// 아직 원소가 남은 배열에 있는 값을 복사함
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
