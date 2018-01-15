#pragma once
#include "stdio.h"

class Heap;

class Sort {

public:
	Sort();
	~Sort();
	
	void BubbleSort(int* array, const int length);
	void SelectionSort(int* array, const int length);
	void InsertionSort(int* array, const int length);
	void ShellSort(int* array, const int length, const int div);
	void quickSort(int* array, int left, int right);
	void RadixSort(int* array, const int length, int maxNum);
	void MergeSort(int* array, int start, int end);
	
	
	void swap(int* array, const int before, const int after);
};

