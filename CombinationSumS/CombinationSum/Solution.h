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
		// ���㷨��ֹ�����������1. targetΪ0����֮ǰ����combination��������һ����ȷ���
		// 2. candidate���������ֶ�����target�ˣ�combination�е�������ϴ���
		if (!target) {
			// ��1����ֹ���
			res.push_back(combination);		
			return;
		}
		// ��2����ֹ���: target >= candidates[i]��û�н���ѭ�������߶�ν���ѭ�����Ѿ����㡰ѭ���˳����������˳�
		for (int i = begin; i != candidates.size() && target >= candidates[i]; ++i) {			
			combination.push_back(candidates[i]);
			combinationSum(candidates, target - candidates[i], res, combination, i);
			combination.pop_back();
		}
	}
};