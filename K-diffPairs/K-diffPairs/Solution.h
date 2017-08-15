#pragma once
#include <vector>
#include <map>
#include <set>
using namespace std;

class Solution
{
public:
	int findPairs(vector<int>& nums, int k) {
		map<int, int> kDiffMap;
		set<pair<int, int>> setPair;
		int count = 0;
		if (k<0)
		{
			return 0;
		}
		for (int i = 0; i < nums.size(); i++)
		{
			// ¼ÓÈëmap
			if (kDiffMap.find(nums[i]) == kDiffMap.end())
			{
				kDiffMap[nums[i]] = 1;
			}
			else
			{
				kDiffMap[nums[i]]++;
			}
		}
		if (k == 0)
		{
			map<int, int>::iterator it = kDiffMap.begin();
			while (it != kDiffMap.end())
			{
				if (it->second>1)
				{
					count++;
				}
				it++;
			}
		}
		else
		{
			count = 0;
			for (int i = 0; i < nums.size(); i++)
			{
				if (kDiffMap.find(nums[i] + k) != kDiffMap.end())
				{
					if (setPair.find(std::pair<int, int>(nums[i], nums[i] + k)) == setPair.end())
					{
						count++;
						setPair.insert(pair<int, int>(nums[i], nums[i] + k));
					}

				}
			}
		}
		return count;
	}
};

