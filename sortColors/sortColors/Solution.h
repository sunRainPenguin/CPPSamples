#pragma once
#include <vector>
using namespace std;

class Solution
{
public:
	void sortColors(vector<int>& nums) {
		int j = 0;
		int temp = 0;
		for (int i = 1; i < (int)nums.size(); i++)
		{
			// <
			temp = nums[i];
			j = i;
			while (j>=1 && nums[j-1]>temp)
			{
				nums[j] = nums[j-1];
				j--;
			}
			nums[j] = temp;
		}
	}
};

//
//// a�������һ����0����λ�ã�b������һ����2����λ��
//class Solution {
//public:
//	void sortColors(vector<int>& nums) {
//		int a = 0, b = nums.size() - 1;
//		for (int i = 0; i <= b; ++i) {
//			if (nums[i] == 0) swap(nums[a++], nums[i]);
//			else if (nums[i] == 2) swap(nums[b--], nums[i--]);
//		}
//	}
//};
