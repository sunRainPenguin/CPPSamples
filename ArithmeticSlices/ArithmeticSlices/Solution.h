#pragma once
#include <vector>
#include <windows.h>
using namespace std;
 
class Solution
{
public:
	// ���˵��㷨
	//int numberOfArithmeticSlices(vector<int>& A) {
	//	int res = 0;
	//	int n = A.size();
	//	int i = 0;
	//	while (i<n - 2) {
	//		int j = i;
	//		// �ȴӵ�ǰ��index�ҵ�һ����ĵȲ�����
	//		while (j<n - 2 && A[j + 1] - A[j] == A[j + 2] - A[j + 1]) j++;
	//		// �ټ�������Ȳ��������ж��ٸ��Ȳ�����
	//		int len = j - i;
	//		if (len) res += len*(len + 1) / 2;		

	//		i = j + 1;
	//	}
	//	return res;
	//}
	// �汾2
	int numberOfArithmeticSlices(vector<int>& A)
	{
		int Asize = A.size();
		if (Asize < 3)
		{
			return 0;
		}
		int result = 0;
		int index = 0;
		int length = 3;
		vector<int> temp;
		while (index <= Asize - 3)
		{
			length = 3;
			while (index + length - 1 < Asize)
			{
				temp = getSubArr(A, index, index + length - 1);
				if (!isArithmeticSlice(temp))
				{
					break;		// ��ǰ���в���׼�����������е�����Ҳ����׼
				}
				else
				{
					result++;
				}
				length++;
			}
			index++;
		}
		return result;
	}
	// �汾1
	/*int numberOfArithmeticSlices(vector<int>& A) 
	{
		int result = 0;
		if (A.size() < 3)
		{
			return 0;
		}
		int length = 3;
		int index;
		vector<int> temp;
		while (length <= A.size())
		{
			index = 0;
			while (index+length-1<A.size())
			{
				temp = getSubArr(A, index, index + length - 1);
				if (isArithmeticSlice(temp))
				{
					result++;
				}
				index++;
			}
			length++;
		}
		return result;
	}*/

	vector<int> getSubArr(vector<int>& B,int min, int max)
	{
		vector<int> result;
		while (min<=max)
		{
			result.push_back(B[min]);
			min++;
		}
		return result;
	}

	bool isArithmeticSlice(vector<int>& C)
	{
		int index = 2;
		int Csize = C.size();
		int targetDValue = C[1] - C[0];
		if ((C[Csize - 1] - C[0]) != (targetDValue * (Csize - 1)))
		{
			return false;
		}
		while (index < C.size())
		{
			if (C[index] - C[index - 1] != targetDValue)
			{
				return false;
			}
			index++;
		}
		return true;
	}
};

