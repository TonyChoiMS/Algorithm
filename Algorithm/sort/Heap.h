#pragma once

#define ROOT 0
#define PARENT(n) (n-1)/2 //부모 위치
#define LEFT(n) 2*n+1		// 왼쪽 자식 위치
#define RIGHT(n) 2*n+2		// 오른쪽 자식 위치
 
class Heap {
public:
	Heap();
	Heap(int size);
	~Heap();
		
private:
	int *_heap;			// 데이터들을 저장할 공간
	int _last;			// 현재 마지막 자료의 위치 +1 (빈 위치)
	int _size;			// 최대 사이즈
	
public:
	void swap(int* a, int* b);		// 교환 
	bool isEmpty();		 			// 힙이 비었는지 확인
	bool isFull();					// 힙이 가득 찼는지 확인
	void insert(int value); 		// 삽입
	int get();						// 데이터 수령
	void print();					// 프린트
	
	void resize(int size);			// 배열 크기 다시 설정
	void clear();					// 다시 사용가능한 상태로
	void reset();					// 다시 사용가능한 상태로
	void HeapSort(int* array, const int length);

private:
	void upHeap(int index);			// 업힙 : 데이터를 위로 밀어냄
	void downHeap(int index);		// 다운힙 : 데이터를 아래로 밀어냄
	void setSize(int size);			// 사이즈 지정 
}; 
