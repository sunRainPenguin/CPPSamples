#include "Solution.h"


int main()
{
	Solution solution;
	Node n20 = { 20, nullptr };
	Node n15 = { 15, &n20};
	Node n10 = { 10, &n15};
	Node n5 = { 5,&n10 };
	Node n25 = { 25, nullptr };
	Node n7 = { 7,&n25 };
	Node n6 = { 6, &n7};
	Node* result = solution.combineList(&n5,&n6);
	while (result!= nullptr) {
		cout << result->data << endl;
		result = result->next;
	}
	return 0;
}
