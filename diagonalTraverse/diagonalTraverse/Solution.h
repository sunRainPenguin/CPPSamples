#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
	vector<int> findDiagonalOrder(vector<vector<int>>& matrix) {
		vector<int> result;
		if (matrix.empty())
		{
			return result;
		}
		int lineN = matrix.size();
		int colN = matrix[0].size();

		// 小兴兴教的算法
		int i = 0;
		int j = 0;
		int length = lineN*colN;
		bool direction = true;
		int count = 0;
		while (count < length)
		{
			result.push_back(matrix[i][j]);
			count++;
			if (direction)
			{
				if (j == colN - 1)
				{
					i++;
					direction = false;
				}
				else
				{
					if (i == 0)
					{
						j++;
						direction = false;
					}
					else
					{
						i--;
						j++;
					}
				}
			}
			else
			{
				if (i == lineN - 1)
				{
					j++;
					direction = true;
				}
				else
				{
					if (j == 0)
					{
						i++;
						direction = true;
					}
					else
					{
						i++;
						j--;
					}
				}
			}
		}

		//	int maxSum = lineN + colN -2;
		//	int sum = 0;
		//	bool reverse = false;
		//	int x = 0;
		//	for ( sum = 0; sum< lineN; sum++)
		//	{
		//		// 上三角：返回行列值和为n的对角线的元素
		//		if (!reverse)
		//		{
		//			for (int i = 0; i <= sum&&i<colN; i++)
		//			{
		//				result.push_back(matrix[sum - i][i]);
		//			}
		//		}
		//		else
		//		{
		//			if (sum >= colN)
		//			{
		//				x = 0;
		//			}
		//			else
		//			{
		//				x = sum;
		//			}
		//			for (; x >=0 && x<colN; x--)
		//			{
		//				result.push_back(matrix[sum - x][x]);
		//			}
		//		}
		//		reverse = !reverse;
		//	}

		//	// 下三角
		//	x = 0;
		//	for (int i = 1; i < colN; i++)
		//	{
		//		if (!reverse)
		//		{
		//			for (int j = i; j < colN&&j <= sum; j++)
		//			{
		//				result.push_back(matrix[sum - j][j]);
		//			}
		//		}
		//		else
		//		{
		//			if (colN-1>sum)
		//			{
		//				x = i;
		//			}
		//			else
		//			{
		//				x = colN - 1;
		//			}

		//			for (; x>=i && x <=sum; x--)
		//			{
		//				result.push_back(matrix[sum - x][x]);
		//			}
		//		}
		//		sum++;
		//		reverse = !reverse;
		//	}
			return result;
	}

		//// 返回行列值和为n的对角线的元素
		//vector<int> oneDiagonalOrder(vector<vector<int>>& matrix, int sum)
		//{
		//	vector<int> result;
		//	for (int i = 0; i <= sum; i++)
		//	{
		//		result.push_back(matrix[sum - i][i]);
		//	}
		//}
};