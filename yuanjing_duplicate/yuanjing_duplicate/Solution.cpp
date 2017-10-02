#include "Solution.h"


int main()
{
	int arr[] = {2,3,1,0,2,5,3};
	Solution solution;
	int* dup = nullptr;
	solution.duplicate(arr, 7, dup);
	return 0;
}