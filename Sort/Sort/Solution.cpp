#include "Solution.h"

int main()
{
	Solution solution;
	int arr[] = { 6,8,1,4,5,3,7,2 };
	int n = 8;
	solution.insertionSort(arr, n);
	//for (int i = 0; i < n; i++)
	//{
	//	cout << arr[i] << endl;
	//}
	int a[] = { 1,4,6,8,2,3,5,7};
	solution.MergeSort(a, 8);
	//solution.printArr(a, 8);

	int b[] = { 1,4,6,8,2,3,5,7 };
	solution.quickSort(b, 8, 0, 7);
	solution.printArr(b, 8);
	return 0;
}
