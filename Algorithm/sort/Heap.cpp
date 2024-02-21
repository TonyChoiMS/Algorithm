//#include "stdafx.h"
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
	//last�� 0�̸� ������ ����
	if (_last == 0) return true;
	else return false; 
}

bool Heap::isFull() {
	// last�� �ִ�ũ�Ⱑ ������ ������
	if (_last == _size) return true;
	else return false; 
}

void Heap::insert(int value) {
	if (isFull()) return;
	
	// ���� ���ʿ� ������ ����
	_heap[_last] = value;
	
	// ó�� ���Ե� �����Ͱ� �ƴ϶��, ���� ����
	if (isEmpty() == false) upHeap(_last);
	
	// last�� �ڷ� ��ĭ �о
	_last++; 
}

int Heap::get() {
	if (isEmpty()) return -99999;
	
	// ������ ������ ����, ROOT = 0 <= ��, ù��° ������
	int data = _heap[ROOT];
	
	// ���� �������� ��ġ�� �����͸� ù��° ��ġ�� �̵�
	_heap[ROOT] = _heap[--_last];
	
	// �ٿ� �� ����
	downHeap(ROOT);
	
	return data; 
}

void Heap::upHeap(int index) {
	// ���� �������� �θ� ������
	int parent = PARENT(index);
	
	// �ִ� ��
	// �ڽź��� �� ū �θ� ã�� ������ �ݺ�
	while (_heap[parent] < _heap[index]) {
		// �θ�� �ڽ��� ��ġ ��ȯ
		swap(&_heap[parent], &_heap[index]);
		index = parent; 
		
		parent = PARENT(index);
	} 
	
	 //�ּ� ��
	//�ڽź��� �� ū �θ� ã�������� ��
    //while (m_Heap[parent] > m_Heap[index])
    //{
      //�θ�� �ڽ��� ��ġ ��ȯ
  //      swap(m_Heap[parent], m_Heap[index]); //������
  //      index = parent;     //��ġ, ���� ��ġ���� �θ� ��ġ ���
 //      parent = PARENT(index);
    //}
}

void Heap::downHeap(int index) {
	// ��ġ�� ��ȯ�� �ڽ��� ��ġ
	int child = 0;
	
	// ���� �ڽ�
	int left = LEFT(index);
	
	// ������ �ڽ��� ��ġ
	int right = RIGHT(index);
	
	// �ִ� ��
	while (left < _last) {
		//left = LEFT(index)		// ���� �ڽ� ��ġ
		right = RIGHT(index);		// ������ �ڽ� ��ġ
		
		// ������ �ڽ��� �ִٸ�, �¿� �ڽ��� ���� ū �ڽ��� ��
		if (right < _last)
			child = _heap[left] > _heap[right] ? left : right; 
		else	// ������ �ڽ��� ���ٸ�, ���� �ڽ��� ���� 
			child = left;
		
		// �ڽĵ� �� ū ���� ����, �о�� ����� �� ũ�ٸ� �ݺ� ����
		if (_heap[index] >= _heap[child])
			break;
		
		// �ڽİ� ����� ��ȯ
		swap(&_heap[index], &_heap[child]);
		
		// �ڽ��� ��ġ�� ���� ��ġ��
		index = child;
		
		left = LEFT(index);
		right = RIGHT(index); 
	} 
	
	//�ּ� ��
    //while (left < m_Last)
    //{
      //������ �ڽ��� �ִٸ�, �¿� �ڽ��� ���� ���� �ڽ��� ��
//      if (right < m_Last)
//             child = m_Heap[left] < m_Heap[right] ? left : right;
//      else //������ �ڽ��� ���ٸ�, ���� �ڽ��� ����
//             child = left;
      //�ڽĵ� �� ���� ���� ����, �о�� ����� �� �۴ٸ� �ݺ� ����
//      if (m_Heap[index] <= m_Heap[child])
//             break;
      //�ڽİ� ����� ��ȯ
//      swap(_heap[index], _heap[child]);
      //�ڽ��� ��ġ�� ���� ��ġ��
//      index = child;
//      left = LEFT(index);             //���� �ڽ� ��ġ
//      right = RIGHT(index);   //������ �ڽ� ��ġ
    //}
}

void Heap::print() {
	// for (int i = 0; i < _last; i++) {
	// 	printf("%d", _heap[i]);
	// }
	// printf("\n");
}

void Heap::resize(int size) {
	clear();
	setSize(size);
	reset();
}

void Heap::clear() {
	// delete[] _heap;
	// _heap = NULL;
}

void Heap::reset() {
	_last = 0;
}

void Heap::setSize(int size) {
	_size = size;
	_heap = new int[_size];
}


void Heap::HeapSort(int* array, const int length) {
	// �� ������ ���� �� �ʱ�ȭ
	resize(length);
	
	// ���� ������ �Է�
	for (int i = 0; i < length; i++) {
		insert(array[i]);
	} 
	
	// ������ ������ �ٽ� �����Ͽ� �Է�
	// �������� ������ ���� �ּ� �� ���(�ִ� ���� ��뤷�ϰ�, �����͸� �������� �־ �ȴ�.
	for (int i = 0;  i < length; i++)
		array[i] = get(); 
}

void Heap::swap(int* a, int* b) {
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;

}
