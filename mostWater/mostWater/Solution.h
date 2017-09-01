#pragma once
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
	int maxArea(vector<int>& height) {
		int i = 0;
		int j = height.size();
		int h = min(height[i], height[j]);
		while (i<j && (min(height[i], height[j])<=h))
		{
			j--;
		}

	}
};

