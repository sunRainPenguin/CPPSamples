#pragma once
#include <vector>
#include <iostream>
using namespace std;

class Solution
{
public:
	int search(vector<int>& nums, int target) {
		vector<int> tempArr;
		int numsSize = nums.size();
		int minIndex = 0;
		int result = -1;
		if (nums.empty())
		{
			return -1;
		}
		for (int i = 0; i < numsSize; i++)
		{
			if (nums[i] < nums[minIndex])
			{
				minIndex = i;
			}
		}
		
		for (int i = 0; i < numsSize -minIndex; i++)
		{
			tempArr.push_back(nums[minIndex + i]);
		}
		int index = 0;
		while (index<minIndex)
		{
			tempArr.push_back(nums[index]);
			index++;
		}

		result = binarySearch(tempArr, target, 0, numsSize - 1);
		if (result == -1)
		{
			return -1;
		}
		else
		{
			return (binarySearch(tempArr, target, 0, numsSize - 1) + minIndex)%numsSize;
		}
		
	}

	// ¶þ·Ö²éÕÒ
	int binarySearch(vector<int> src, int target, int first, int last)
	{
		if (target<src[first] || target>src[last])
		{
			return -1;
		}
		int midIndex = (first+last) / 2;
		if (target == src[midIndex])
		{
			return midIndex;
		}
		else if (target < src[midIndex])
		{
			return binarySearch(src, target, first, midIndex);
		}
		else
		{
			return binarySearch(src, target, midIndex + 1, last);
		}
		return -1;
	}
};

