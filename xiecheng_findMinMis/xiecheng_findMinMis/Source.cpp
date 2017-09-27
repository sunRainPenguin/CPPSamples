#include <iostream>
#include <vector>
#include <numeric>
#include <limits>
#include <set>

using namespace std;

/*请完成下面这个函数，实现题目要求的功能
当然，你也可以不按照下面这个模板来作答，完全按照自己的想法来 ^-^
******************************开始写代码******************************/
int findMinMis(vector<int> A) {
	int v = -1;
	int j = -1;
	for (int i = 1; i < A.size(); i++)
	{
		v = A[i];
		j = i;
		while (j >= 1 && A[j - 1]>v)
		{
			A[j] = A[j - 1];
			j--;
		}
		A[j] = v;
	}
	j = 0;
	while (A[j]<=0)
	{
		j++;
	}
	int s = 1;
	while (A[j]==s)
	{
		j++;
		s++;
	}
	return s;
}
/******************************结束写代码******************************/


int main() {
	int res;

	int _A_size = 0;
	cin >> _A_size;
	cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	vector<int> _A;
	int _A_item;
	for (int _A_i = 0; _A_i<_A_size; _A_i++) {
		cin >> _A_item;
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		_A.push_back(_A_item);
	}



	res = findMinMis(_A);
	cout << res << endl;

	return 0;

}
