#include "stdafx.h"
#include "Heap.h"

Heap::Heap() {
	reset();
	setSize(10);
}

Heap::Heap(int size) {
	reset();
	setSize(size);
}

Heap::~Heap() {
	clear();
}

bool Heap::isEmpty() {
	//last가 0이면 데이터 없음
	if (_last == 0) return true;
	else return false; 
}

bool Heap::isFull() {
	// last와 최대크기가 같으면 가득참
	if (_last == _size) return true;
	else return false; 
}

void Heap::insert(int value) {
	if (isFull()) return;
	
	// 가장 뒤쪽에 데이터 삽입
	_heap[_last] = value;
	
	// 처음 삽입된 데이터가 아니라면, 업힙 수행
	if (isEmpty() == false) upHeap(_last);
	
	// last를 뒤로 한칸 밀어냄
	_last++; 
}

int Heap::get() {
	if (isEmpty()) return -99999;
	
	// 리턴할 데이터 저장, ROOT = 0 <= 즉, 첫번째 데이터
	int data = _heap[ROOT];
	
	// 가장 마지막에 위치한 데이터를 첫번째 위치로 이동
	_heap[ROOT] = _heap[--_last];
	
	// 다운 힙 수행
	downHeap(ROOT);
	
	return data; 
}

void Heap::upHeap(int index) {
	// 현재 데이터의 부모 데이터
	int parent = PARENT(index);
	
	// 최대 힙
	// 자신보다 더 큰 부모를 찾을 때까지 반복
	while (_heap[parent] < _heap[index]) {
		// 부모와 자신의 위치 교환
		swap(&_heap[parent], &_heap[index]);
		index = parent; 
		
		parent = PARENT(index);
	} 
	
	 //최소 힙
	//자신보다 더 큰 부모를 찾을때까지 반
    //while (m_Heap[parent] > m_Heap[index])
    //{
      //부모와 자신의 위치 교환
  //      swap(m_Heap[parent], m_Heap[index]); //데이터
  //      index = parent;     //위치, 현재 위치에서 부모 위치 계산
 //      parent = PARENT(index);
    //}
}

void Heap::downHeap(int index) {
	// 위치를 교환할 자식의 위치
	int child = 0;
	
	// 왼쪽 자식
	int left = LEFT(index);
	
	// 오른쪽 자식의 위치
	int right = RIGHT(index);
	
	// 최대 힙
	while (left < _last) {
		//left = LEFT(index)		// 왼쪽 자식 위치
		right = RIGHT(index);		// 오른쪽 자식 위치
		
		// 오른쪽 자식이 있다면, 좌우 자식을 비교해 큰 자식을 고름
		if (right < _last)
			child = _heap[left] > _heap[right] ? left : right; 
		else	// 오른쪽 자식이 없다면, 왼쪽 자식을 선택 
			child = left;
		
		// 자식들 중 큰 수와 비교해, 밀어내릴 대상이 더 크다면 반복 종료
		if (_heap[index] >= _heap[child])
			break;
		
		// 자식과 대상을 교환
		swap(&_heap[index], &_heap[child]);
		
		// 자식의 위치를 현재 위치로
		index = child;
		
		left = LEFT(index);
		right = RIGHT(index); 
	} 
	
	//최소 힙
    //while (left < m_Last)
    //{
      //오른쪽 자식이 있다면, 좌우 자식을 비교해 작은 자식을 고름
//      if (right < m_Last)
//             child = m_Heap[left] < m_Heap[right] ? left : right;
//      else //오른쪽 자식이 없다면, 왼쪽 자식을 선택
//             child = left;
      //자식들 중 작은 수와 비교해, 밀어내릴 대상이 더 작다면 반복 종료
//      if (m_Heap[index] <= m_Heap[child])
//             break;
      //자식과 대상을 교환
//      swap(_heap[index], _heap[child]);
      //자식의 위치를 현재 위치로
//      index = child;
//      left = LEFT(index);             //왼쪽 자식 위치
//      right = RIGHT(index);   //오른쪽 자식 위치
    //}
}

void Heap::print() {
	for (int i = 0; i < _last; i++) {
		printf("%d", _heap[i]);
	}
	printf("\n");
}

void Heap::resize(int size) {
	clear();
	setSize(size);
	reset();
}

void Heap::clear() {
	delete[] _heap;
	_heap = NULL;
}

void Heap::reset() {
	_last = 0;
}

void Heap::setSize(int size) {
	_size = size;
	_heap = new int[_size];
}


void Heap::HeapSort(int* array, const int length) {
	// 힙 사이즈 조절 및 초기화
	resize(length);
	
	// 힙에 데이터 입력
	for (int i = 0; i < length; i++) {
		insert(array[i]);
	} 
	
	// 힙에서 데이터 다시 수령하여 입력
	// 오름차순 정렬을 위해 최소 힙 사용(최대 힙을 사용ㅇ하고, 데이터를 역순으로 넣어도 된다.
	for (int i = 0;  i < length; i++)
		array[i] = get(); 
}

void Heap::swap(int* a, int* b) {
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;

}
