#include "Sort.h"
#include "Heap.h"

Sort::Sort(){

}

Sort::~Sort(){
	
}
// 버블 정렬 
void Sort::BubbleSort(int* array, const int length) {
	
	for (int i = 0; i < length-1; i++) {
		for (int j = 0; j < length-i-1; j++) {
			// 뒷자리 데이터가 더 작으면 자리 변경
			if (array[j+1] < array[j]) {
				swap(array, j+1, j);
			}
		}
	}
}

// 선택 정렬 
void Sort::SelectionSort(int* array, const int length) {
	//최소값 위치
	int min;
	
	for (int i=0; i < length; i++) {
		// 현재 자리를 최소값 위치로 지정
		min = i;
		
		// 최소값 검색
		for (int j=i+1; j < length; j++) {
			// 현재 최소값보다 지금 자리의 데이터가 더 작으면, 최소값으로 지정 
			if (array[min] > array[j])
				min = j;
		} 
		
		// 최소값 자리가 변경 안됐으면 패스
		if (min == i)
			continue; 
			
		swap(array, min, i);
	} 
}

// 삽입 정렬 
void Sort::InsertionSort(int* array, const int length) {
	int target, j;
	for (int i = 1; i < length; i++) {
		// 현재 데이터 저장 
		target = array[i];
		
		// (현재 데이터 < 앞자리 데이터)라면 자리 변경 
		for( j =i; j> 0 && array[j-1] > target; j--) {
			array[j] = array[j-1];
		}
		if (i==j)
			continue;
        array[j] = target;
	}
}

// 셸 정렬 
void Sort::ShellSort(int* array, const int length, const int div) {
	int target, k;
	int begin;
	
	// 간격 계산
	for (int interval = length/2; interval > 0; interval /= div) {
		//그룹에서 포지션 - > 그룹에서 첫번째, 두번째..
		for( int posInGroup = 0; posInGroup < interval; posInGroup++) {
			begin = posInGroup;
			
			// 삽입 정렬
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

// 퀵 정렬 
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

// 기수정렬 
void Sort::RadixSort(int* array, const int length, int maxNum) {
	int *store[10];			// 각 자리수를 저장하는 공간
	int rear[10];			// 각 저장공간에서 가장 늦게 입력된 데이터의 위치
	int radix;				// 어떤 큐에 데이터를 입/출력 할건지 지정하는 변수
	int MaxMultiples = 1;	// 최대 자리수 
	
	// 저장 공간 초기화
	for (int i=0; i<10; i++) {
		store[i] = new int[length];
		rear[i] = -1;
	} 
	
	// 최대 자릿수 계산
	while(maxNum > 0) {
		maxNum /= 10;
		MaxMultiples *= 10;
	} 
	
	// 정렬 시작
	for (int multiples = 10; multiples <= MaxMultiples; multiples *= 10) {
		// 비교하고자 하는 자릿수를 구하기 위해 나눠야 하는 수
		int div = multiples / 10;
		
		// 기수 별로 데이터 분류
		for (int i =0; i < length ; i++) {
			// 기수 계산
			radix = array[i] % multiples;
			radix /= div;
			
			// 구한 기수의 저장소에 데이터 저장
			// 데이터를 저장 할 수록 그 기수의 rear가 한칸씩 뒤로 밀린다.
			store[radix][++rear[radix]] = array[i]; 
		} 
		
		// 데이터를 기수 0-> 기수 9 순으로 순차적으로 입력
		int index = 0;
		for (radix = 0; radix < 10; radix++) {
			// 각 기수 순서대로 데이터 입력(각 기수 안에선 입력 받은 순으로 입력)
			for (int i = 0;  i <= rear[radix]; i++) {
				array[index++] = store[radix][i];
			} 
			
			// 입력이 완료된 기수의 rear는 -1로 초기화
			rear[radix] = -1; 
		} 
	} 
	
	// 저장소의 메모리 해제
	for (int i = 0; i < 10; i++) {
		delete[] store[i];
		store[i] = NULL;
	} 
}

// 병합 정렬
void Sort::MergeSort(int* array, int start, int end) {
	// 분할된 그룹의 크기가 1이하면 리턴
	if (end <= start) return;
	
	int mid = (start + end) / 2;		// 중간 데이터의 위치
	int length = end - start +1;		// 분할된 그룹의 크기
	int *copyArray = new int[length];	// 임시 저장공간
	
	int first = start;		// 첫번째 그룹의 시작 지점
	int second = mid +1;	// 두번째 그룹의 시작지점
	int copy = 0;			// 임시 저장공간 인덱스
	
	// 분할
	MergeSort(array, start, mid);	// 첫번째 그룹
	MergeSort(array, mid+1, end); 	// 두번째 그룹
	
	// 분할된 두 그룹을 다시 병합
	while(first <= mid && second <= end) {
		// 임시 저장공간에 데이터가 작은 순서대로 입력
		copyArray[copy++] = 
			array[first] < array[second] ?	// 첫번째 그룹의 데이터가 두번째 그룹의 데이터보다 작은가?
			array[first++] :				// 작다면 첫번째 그룹의 데이터 입력
			array[second++];				// 아니라면 두번째 그룹의 데이터 입력 
	} 
	
	// 입력이 되지 않고 남아있는 데이터 처리
	// 떠너 그룹의 데이터가 남았는지 찾기
	int i = first <= mid ? first : second;
	
	// 순서대로 임시저장 공간에 입력
	for (; copy<length; copy++, i++)
		copyArray[copy] = array[i];
	
	// 데이터 목록에 임시저장한 데이터들 입력
	for (i = start, copy = 0; i <= end; i++, copy++)
		array[i] = copyArray[copy];
		
	// 임시저장공간 메모리 해제
	delete[] copyArray;
	copyArray = NULL; 
} 

void Sort::swap(int* array, const int before, const int after) {
	int temp;
	temp = array[before];
	array[before] = array[after];
	array[after] = temp;
}

