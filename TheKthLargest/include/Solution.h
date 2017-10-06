#ifndef SOLUTION_H
#define SOLUTION_H
#include <vector>
using namespace std;

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        vector<int> larger;
        int temp;
        for(int j=0; j<k; j++)
        {
            for(int i=0; i<nums.size()-1-j; i++)
            {
               if(nums[i]>nums[i+1])
               {
                   temp = nums[i];
                   nums[i] = nums[i+1];
                   nums[i+1] = temp;
               }
            }
        }
        return nums[nums.size()-k];
    }
};

// 别人的做法
//class Solution {
//    int helper(vector<int>& nums,int k) {
//        if(nums.size() == 1) {
//            return nums[0];
//        }
//        int pivot = nums[0];
//        vector<int> before;
//        vector<int> after;
//        for(int i = 1;i < nums.size();i++) {
//            if(nums[i] <= pivot) before.push_back(nums[i]);
//            else after.push_back(nums[i]);
//        }
//        if(k == after.size() + 1) {
//            return pivot;
//        } else if(k > after.size() + 1) {
//            return helper(before,k - after.size() - 1);
//        } else {
//            return helper(after,k);
//        }
//    }
//    public:
//    int findKthLargest(vector<int>& nums, int k) {
//        random_shuffle(nums.begin(),nums.end());
//        if(nums.size() < k) return -1;
//        return helper(nums,k);
//    }
#endif // SOLUTION_H
