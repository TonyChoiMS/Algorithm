#pragma once

#include <vector>

class RemoveDuplicatesFromSortedArray
{
public:
	int removeDuplicates(std::vector<int>& nums) {
		if (nums.size() == 0) return 0;

		int count = 0;

		for (int i = 0; i < nums.size(); i++)
		{
			if (nums[count] != nums[i])
			{
				count++;
				nums[count] = nums[i];
			}
		}

		return count + 1;
	}
};