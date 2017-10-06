#ifndef SOLUTION_H
#define SOLUTION_H
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

class Solution {
public:
	set<vector<int>> helper(vector<int>& candidates, int target) {
		set<vector<int>> result;
		vector<int> single;
		set<vector<int>> combinations;   // 除了当前的candi，剩下的组合
		vector<int> candidatesT;
		int candi = 0;
		bool find = false;
		for (int i = 0; i<candidates.size(); i++)
		{
			candi = candidates[i];
			if (target == candi)
			{
				find = false;
				for (vector<int> c : result)
				{
					for (int s : c)
					{
						if (s == candi)
						{
							find = true;
						}
					}
				}
				if (!find)
				{
					single = { candi };
					result.insert(single);
				}
			}
			else if (candi > target)
			{
				//...
			}
			else
			{
				candidatesT.clear();
				for (int j = 0; j<candidates.size(); j++)
				{
					candidatesT.push_back(candidates[j]);
				}
				// 为了防止重复寻找,每次在新的candidates中寻找时，只能往后找
				for (int k = 0; k <= i; k++)
				{
					candidatesT.erase(candidatesT.begin());
				}
				combinations = helper(candidatesT, target - candi);
				for (vector<int> com : combinations)
				{
					com.push_back(candi);
					sort(com.begin(), com.end());
					result.insert(com);
				}
			}
		}
		return result;
	}

	vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
		set<vector<int>> setResult = helper(candidates, target);
		vector<vector<int>> vecResult;
		for (vector<int> com : setResult)
		{
			vecResult.push_back(com);
		}
		return vecResult;
	}
};

// 别人的做法
//class Solution {
//public:
//	vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
//		vector<vector<int>> allSol;
//		vector<int> sol;
//		if (candidates.empty()) return allSol;
//		sort(candidates.begin(), candidates.end());
//		findComb(allSol, sol, 0, candidates, target);
//		return allSol;
//	}
//
//	void findComb(vector<vector<int>>& allSol, vector<int>& sol, int start, vector<int>& candidates, int target) {
//		if (target == 0) {
//			allSol.push_back(sol);
//			return;
//		}
//
//		for (int i = start; i < candidates.size(); i++) {
//			if (i > start && candidates[i] == candidates[i - 1]) continue;		// 虽然在一组combination中可以出现重复数字，但是这种情况已经包含在findComb的递归过程中了。如果去掉这一句，会产生不必要的递归，及重复结果
//			if (candidates[i] <= target) {
//				sol.push_back(candidates[i]);
//				findComb(allSol, sol, i + 1, candidates, target - candidates[i]);
//				sol.pop_back();
//			}
//		}
//	}
//};
#endif // SOLUTION_H
