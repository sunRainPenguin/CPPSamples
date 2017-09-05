#include "Solution.h"

bool Solution::containsDuplicate(vector<int>& nums)
{
    set<int> setInt;
    int setSize = 0;
    if(nums.empty())
    {
        return false;
    }
    for(int i=0;i<nums.size();i++)
    {
        setInt.insert(nums[i]);
        if(setSize==setInt.size())
        {
            return true;
        }
        setSize = setInt.size();
    }
    return false;
}

