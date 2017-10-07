#ifndef SOLUTION_H
#define SOLUTION_H
#include <vector>
using namespace std;

class Solution {
public:
	bool searchMatrix(vector<vector<int>>& matrix, int target) {
		int l, r, mid, midi, midj;
		int h = matrix.size();
		if(h==0)
        {
            return false;
        }
		int w = matrix[0].size();
		if (w==0 || matrix[0][0]>target || matrix[h - 1][w - 1]<target)
		{
			return false;
		}
		l = 0;
		r = h*w - 1;
		while (l <= r)
		{
			mid = (l + r) / 2;
			midi = mid / w;
			midj = mid%w;
			if (target == matrix[midi][midj])
			{
				return true;
			}
			else if (target < matrix[midi][midj])
			{
				r = mid - 1;
			}
			else if (target > matrix[midi][midj])
			{
				l = mid + 1;
			}
		}
		return false;
	}
};

// 别人的做法：先对通过二分法找到target所在的行，再通过二分法找到target所在的列
//class Solution {
//public:
//    bool searchMatrix(vector<vector<int>>& matrix, int target) {
//        if (matrix.size() == 0 || matrix[0].size() == 0)
//          return false;
//        int start = 0;
//        int end = matrix.size() - 1;
//        int N = matrix[0].size();
//        int row = -1;
//        while (start <= end) {
//          int mid = (start + end) / 2;
//          if (target < matrix[mid][0])
//            end = mid - 1;
//          else if (target > matrix[mid][N - 1])
//            start = mid + 1;
//          else {
//            row = mid;
//            break;
//          }
//        }
//        if (row == -1)
//          return false;
//        start = 0;
//        end = N - 1;
//        while (start <= end) {
//          int mid = (start + end) / 2;
//          if (target < matrix[row][mid])
//            end = mid - 1;
//          else if (target > matrix[row][mid])
//            start = mid + 1;
//          else
//            return true;
//        }
//        return false;
//    }
//};
#endif // SOLUTION_H
