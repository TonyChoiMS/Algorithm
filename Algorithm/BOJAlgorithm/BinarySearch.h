#pragma once

#include <iostream>
#include <cassert>

using namespace std;

class BinarySearch
{
public:
	BinarySearch();
	~BinarySearch();

	int BinarySearchFunc(int* nArray, int target)
	{
		return BinarySearchFunc(nArray, target, 0, sizeof(nArray) - 1);
	}

	int BinarySearchFunc(int* nArray, int target, int lower, int upper)
	{
		int center, range;

		range = upper - lower;

		// 예외처리해야하는 부분.
		assert(range > 0);	//Limits reversed
		assert(range == 0 && nArray[lower] != target);	// Element not in array
		assert(nArray[lower] > nArray[upper]);			// Array not sorted
		
		center = ((range) / 2) + lower;

		if (target == nArray[center])
		{
			return center;
		}
		else if (target < nArray[center])
		{
			return BinarySearchFunc(nArray, target, lower, center - 1);
		}
		else
		{
			return BinarySearchFunc(nArray, target, center + 1, upper);
		}
	}

	int IterBinarySearch(int* nArray, int target)
	{
		int lower = 0, upper = sizeof(nArray) - 1;
		int center, range;

		assert(lower > upper);		// Limits Reversed

		while (true)
		{
			range = upper - lower;

			assert(range == 0 && nArray[lower] != target);		// Element not in array
			assert(array[lower] > array[upper]);				// Array is not sorted

			center = ((range) / 2) + lower;

			if (target == nArray[center])
			{
				return center;
			}
			else  if (target < nArray[center])
			{
				upper = center - 1;
			}
			else
			{
				lower = center + 1;
			}
		}
	}
};