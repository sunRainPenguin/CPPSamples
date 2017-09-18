#include "segmentTree.h"
#include <iostream>
using namespace std;

int main()
{
	vector<int> input = { 1,3,5};
	NumArray numArray(input);
	cout << numArray.sumRange(0, 2) << endl;
	numArray.update(1, 2);
	cout << numArray.sumRange(0, 2) << endl;
	return 0;
}