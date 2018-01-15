#include "Sort.h"
#include "Heap.h"

Sort::Sort(){

}

Sort::~Sort(){
	
}
// ���� ���� 
void Sort::BubbleSort(int* array, const int length) {
	
	for (int i = 0; i < length-1; i++) {
		for (int j = 0; j < length-i-1; j++) {
			// ���ڸ� �����Ͱ� �� ������ �ڸ� ����
			if (array[j+1] < array[j]) {
				swap(array, j+1, j);
			}
		}
	}
}

// ���� ���� 
void Sort::SelectionSort(int* array, const int length) {
	//�ּҰ� ��ġ
	int min;
	
	for (int i=0; i < length; i++) {
		// ���� �ڸ��� �ּҰ� ��ġ�� ����
		min = i;
		
		// �ּҰ� �˻�
		for (int j=i+1; j < length; j++) {
			// ���� �ּҰ����� ���� �ڸ��� �����Ͱ� �� ������, �ּҰ����� ���� 
			if (array[min] > array[j])
				min = j;
		} 
		
		// �ּҰ� �ڸ��� ���� �ȵ����� �н�
		if (min == i)
			continue; 
			
		swap(array, min, i);
	} 
}

// ���� ���� 
void Sort::InsertionSort(int* array, const int length) {
	int target, j;
	for (int i = 1; i < length; i++) {
		// ���� ������ ���� 
		target = array[i];
		
		// (���� ������ < ���ڸ� ������)��� �ڸ� ���� 
		for( j =i; j> 0 && array[j-1] > target; j--) {
			array[j] = array[j-1];
		}
		if (i==j)
			continue;
        array[j] = target;
	}
}

// �� ���� 
void Sort::ShellSort(int* array, const int length, const int div) {
	int target, k;
	int begin;
	
	// ���� ���
	for (int interval = length/2; interval > 0; interval /= div) {
		//�׷쿡�� ������ - > �׷쿡�� ù��°, �ι�°..
		for( int posInGroup = 0; posInGroup < interval; posInGroup++) {
			begin = posInGroup;
			
			// ���� ����
			for (int i = begin+interval; i<length; i+=interval) {
				target = array[i];
				for (k=i-interval; k>=begin && target < array[k]; k -= interval) {
					array[k+interval] = array[k];
				}
				array[k+interval] = target;
			} 
		} 
	} 
}

// �� ���� 
void Sort::quickSort(int* array, int left, int right) {
	int pivot = left;
	int j = pivot;       
	int i = left + 1;
	
	if (left < right) {
		for (; i <= right; i++) {
			if (array[i] < array[pivot]) {
				j++;
				swap(array, j, i);
			}
		}
		swap(array, left, j);
		pivot = j;
		
		quickSort(array, left, pivot-1);
		quickSort(array, pivot+1, right);
	}
}

// ������� 
void Sort::RadixSort(int* array, const int length, int maxNum) {
	int *store[10];			// �� �ڸ����� �����ϴ� ����
	int rear[10];			// �� ����������� ���� �ʰ� �Էµ� �������� ��ġ
	int radix;				// � ť�� �����͸� ��/��� �Ұ��� �����ϴ� ����
	int MaxMultiples = 1;	// �ִ� �ڸ��� 
	
	// ���� ���� �ʱ�ȭ
	for (int i=0; i<10; i++) {
		store[i] = new int[length];
		rear[i] = -1;
	} 
	
	// �ִ� �ڸ��� ���
	while(maxNum > 0) {
		maxNum /= 10;
		MaxMultiples *= 10;
	} 
	
	// ���� ����
	for (int multiples = 10; multiples <= MaxMultiples; multiples *= 10) {
		// ���ϰ��� �ϴ� �ڸ����� ���ϱ� ���� ������ �ϴ� ��
		int div = multiples / 10;
		
		// ��� ���� ������ �з�
		for (int i =0; i < length ; i++) {
			// ��� ���
			radix = array[i] % multiples;
			radix /= div;
			
			// ���� ����� ����ҿ� ������ ����
			// �����͸� ���� �� ���� �� ����� rear�� ��ĭ�� �ڷ� �и���.
			store[radix][++rear[radix]] = array[i]; 
		} 
		
		// �����͸� ��� 0-> ��� 9 ������ ���������� �Է�
		int index = 0;
		for (radix = 0; radix < 10; radix++) {
			// �� ��� ������� ������ �Է�(�� ��� �ȿ��� �Է� ���� ������ �Է�)
			for (int i = 0;  i <= rear[radix]; i++) {
				array[index++] = store[radix][i];
			} 
			
			// �Է��� �Ϸ�� ����� rear�� -1�� �ʱ�ȭ
			rear[radix] = -1; 
		} 
	} 
	
	// ������� �޸� ����
	for (int i = 0; i < 10; i++) {
		delete[] store[i];
		store[i] = NULL;
	} 
}

// ���� ����
void Sort::MergeSort(int* array, int start, int end) {
	// ���ҵ� �׷��� ũ�Ⱑ 1���ϸ� ����
	if (end <= start) return;
	
	int mid = (start + end) / 2;		// �߰� �������� ��ġ
	int length = end - start +1;		// ���ҵ� �׷��� ũ��
	int *copyArray = new int[length];	// �ӽ� �������
	
	int first = start;		// ù��° �׷��� ���� ����
	int second = mid +1;	// �ι�° �׷��� ��������
	int copy = 0;			// �ӽ� ������� �ε���
	
	// ����
	MergeSort(array, start, mid);	// ù��° �׷�
	MergeSort(array, mid+1, end); 	// �ι�° �׷�
	
	// ���ҵ� �� �׷��� �ٽ� ����
	while(first <= mid && second <= end) {
		// �ӽ� ��������� �����Ͱ� ���� ������� �Է�
		copyArray[copy++] = 
			array[first] < array[second] ?	// ù��° �׷��� �����Ͱ� �ι�° �׷��� �����ͺ��� ������?
			array[first++] :				// �۴ٸ� ù��° �׷��� ������ �Է�
			array[second++];				// �ƴ϶�� �ι�° �׷��� ������ �Է� 
	} 
	
	// �Է��� ���� �ʰ� �����ִ� ������ ó��
	// ���� �׷��� �����Ͱ� ���Ҵ��� ã��
	int i = first <= mid ? first : second;
	
	// ������� �ӽ����� ������ �Է�
	for (; copy<length; copy++, i++)
		copyArray[copy] = array[i];
	
	// ������ ��Ͽ� �ӽ������� �����͵� �Է�
	for (i = start, copy = 0; i <= end; i++, copy++)
		array[i] = copyArray[copy];
		
	// �ӽ�������� �޸� ����
	delete[] copyArray;
	copyArray = NULL; 
} 

void Sort::swap(int* array, const int before, const int after) {
	int temp;
	temp = array[before];
	array[before] = array[after];
	array[after] = temp;
}

