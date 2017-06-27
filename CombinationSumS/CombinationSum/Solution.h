#include <vector>
#include<algorithm>
using namespace std;

class Solution {
public:
	std::vector<std::vector<int> > combinationSum(std::vector<int> &candidates, int target) {
		std::sort(candidates.begin(), candidates.end());
		std::vector<std::vector<int> > res;
		std::vector<int> combination;
		combinationSum(candidates, target, res, combination, 0);
		return res;
	}
private:
	void combinationSum(std::vector<int> &candidates, int target, std::vector<std::vector<int> > &res, std::vector<int> &combination, int begin) {
		// 该算法终止有两种情况：1. target为0，即之前加入combination的数字是一种正确组合
		// 2. candidate中所有数字都大于target了，combination中的数字组合错误
		if (!target) {
			// 第1种终止情况
			res.push_back(combination);		
			return;
		}
		// 第2种终止情况: target >= candidates[i]，没有进入循环，或者多次进入循环后，已经满足“循环退出条件”而退出
		for (int i = begin; i != candidates.size() && target >= candidates[i]; ++i) {			
			combination.push_back(candidates[i]);
			combinationSum(candidates, target - candidates[i], res, combination, i);
			combination.pop_back();
		}
	}
};