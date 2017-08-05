#include "MyStack.h"
#include <iostream>
using namespace std;

int main() {
	MyStack myStack;
	myStack.push(1);
	myStack.push(2);
	myStack.push(3);
	int param_2 = myStack.pop();
	int param_3 = myStack.top();
	bool param_4 = myStack.empty();
	cout << param_2 << endl;
	cout << param_3 << endl;
	cout << param_4 << endl;
	myStack.pop();
	myStack.pop();
	param_4 = myStack.empty();
	cout << param_4 << endl;
	return 0;
}
