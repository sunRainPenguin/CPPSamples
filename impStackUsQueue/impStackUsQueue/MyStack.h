#pragma once
#include <queue>
using namespace std;

class MyStack {
private:
	queue<int> stack;

public:
	/** Initialize your data structure here. */
	MyStack() {
	}

	/** Push element x onto stack. */
	void push(int x) {
		stack.push(x);
	}

	/** Removes the element on top of the stack and returns that element. */
	int pop() {
		if (stack.empty()) 
		{
			return NULL;
		}
		queue<int> tempQueue;
		while (stack.size()!=1)
		{
			tempQueue.push(stack.front());
			stack.pop();
		}

		int result;
		if (stack.size() == 1)
		{
			result = stack.front();
			stack.pop();
			stack = tempQueue;
			return result;
		}
		else {
			return NULL;
		}
	}

	/** Get the top element. */
	int top() {
		if (stack.empty())
		{
			return NULL;
		}
		queue<int> tempQueue;
		while (stack.size() != 1)
		{
			tempQueue.push(stack.front());
			stack.pop();
		}

		int result;
		if (stack.size() == 1)
		{
			result = stack.front();
			tempQueue.push(result);
			stack.pop();
			stack = tempQueue;
			return result;
		}
	}

	/** Returns whether the stack is empty. */
	bool empty() {
		return stack.empty();
	}
};

/**
* Your MyStack object will be instantiated and called as such:
* MyStack obj = new MyStack();
* obj.push(x);
* int param_2 = obj.pop();
* int param_3 = obj.top();
* bool param_4 = obj.empty();
*/
