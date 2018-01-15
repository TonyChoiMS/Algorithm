#include "Sort.h"
#include "Heap.h"
#include <iostream>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
//void BubbleSort(int* array, const int length);
int main() {
	int array[9] = {1, 4, 3, 5, 7, 8, 9, 6, 10}; //length 9
	const int length = 9;
	Sort* sort = new Sort();
	//sort->SelectionSort(array, length);
	//sort->BubbleSort(array, length); 
	//sort->InsertionSort(array, length);
	//sort->ShellSort(array, length, 3);
	//sort->quickSort(array, 0, 8);
	//sort->MergeSort(array, 0, 8);
	Heap* heap = new Heap(9);
	heap->HeapSort(array, length);
	for (int i = 0; i < 9; i++) {
		printf("sort : %d\n", array[i]);
	}
	
	int radix[10] = {10, 20, 300, 21, 900, 1, 5, 4, 1000};
	sort->RadixSort(radix, 10, 1000);
	for (int i = 0; i < 10; i++) {
		printf("radix : %d\n", radix[i]);
	}
	delete sort;
	return 0;
}
