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
		set<vector<int>> combinations;   // ���˵�ǰ��candi��ʣ�µ����
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
				// Ϊ�˷�ֹ�ظ�Ѱ��,ÿ�����µ�candidates��Ѱ��ʱ��ֻ��������
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

// ���˵�����
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
//			if (i > start && candidates[i] == candidates[i - 1]) continue;		// ��Ȼ��һ��combination�п��Գ����ظ����֣�������������Ѿ�������findComb�ĵݹ�������ˡ����ȥ����һ�䣬���������Ҫ�ĵݹ飬���ظ����
//			if (candidates[i] <= target) {
//				sol.push_back(candidates[i]);
//				findComb(allSol, sol, i + 1, candidates, target - candidates[i]);
//				sol.pop_back();
//			}
//		}
//	}
//};
#endif // SOLUTION_H
