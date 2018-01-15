#pragma once

#define ROOT 0
#define PARENT(n) (n-1)/2 //�θ� ��ġ
#define LEFT(n) 2*n+1		// ���� �ڽ� ��ġ
#define RIGHT(n) 2*n+2		// ������ �ڽ� ��ġ
 
class Heap {
public:
	Heap();
	Heap(int size);
	~Heap();
		
private:
	int *_heap;			// �����͵��� ������ ����
	int _last;			// ���� ������ �ڷ��� ��ġ +1 (�� ��ġ)
	int _size;			// �ִ� ������
	
public:
	void swap(int* a, int* b);		// ��ȯ 
	bool isEmpty();		 			// ���� ������� Ȯ��
	bool isFull();					// ���� ���� á���� Ȯ��
	void insert(int value); 		// ����
	int get();						// ������ ����
	void print();					// ����Ʈ
	
	void resize(int size);			// �迭 ũ�� �ٽ� ����
	void clear();					// �ٽ� ��밡���� ���·�
	void reset();					// �ٽ� ��밡���� ���·�
	void HeapSort(int* array, const int length);

private:
	void upHeap(int index);			// ���� : �����͸� ���� �о
	void downHeap(int index);		// �ٿ��� : �����͸� �Ʒ��� �о
	void setSize(int size);			// ������ ���� 
}; 
