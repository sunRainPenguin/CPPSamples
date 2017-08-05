#pragma once
#include <string>
#include <iostream>
#include <stack>
#include <unordered_map>
using namespace std;

class Solution {
public:
	int calculate(string s) 
	{
		s = infix2suffix(s);
		if (s == "error")
		{
			return -1;		// 异常
		}
		char ch = NULL;
		stack<int> intStack;
		bool digitFinished = true;
		int result = -1;
		string arg = "";
		int tempArg = -1;
		int arg1 = -1;
		int arg2 = -1;
		for (int i = 0; i < s.length(); i++)
		{
			ch = s[i];
			if (isDigit(ch))
			{
				digitFinished = false;
				arg.insert(arg.end(), ch);
			}
			else 
			{
				if (digitFinished == false)
				{
					tempArg = atoi(arg.c_str());
					intStack.push(tempArg);
					arg = "";
					digitFinished = true;
				}
				if (ch == '+' || ch == '-')
				{
					if (intStack.size() >= 2)
					{
						arg2 = intStack.top();
						intStack.pop();
						arg1 = intStack.top();
						intStack.pop();
						result = calculateBinary(arg1, arg2, ch);
						intStack.push(result);
					}
					else
					{
						return -1;		// 异常
					}
				}
 				else if (ch == ' ')
				{
					// 略过
				}
				else
				{
					return -1;		// 异常
				}
			}
		}
		// 如果最后一个空格之前是数字或者最后一个字符是数字
		if (intStack.size() == 1)
		{
			result = intStack.top();
			return result;
		}
		return result;
	}


	int calculateBinary(int arg1, int arg2, char arg3)
	{
		if(arg3=='+')
		{
			return arg1 + arg2;
		}
		else if (arg3 = '-')
		{
			return arg1 - arg2;
		}
		else
		{
			return -1;
		}
	}

	string infix2suffix(string s)
	{
		char ch = NULL;
		string str = "";
		string result = "";
		bool digitFinished = true;
		stack<char> chStack;
		for (int i = 0; i < s.length(); i++)
		{
			ch = s[i];
			if (isDigit(ch))
			{
				digitFinished = false;
				str.insert(str.end(), ch);
			}
			else
			{
				if (digitFinished == false)
				{
					result.append(str);
					result.insert(result.end(), ' ');
					str = "";
					digitFinished = true;
				}
				if (ch == '(')
				{
					chStack.push(ch);
				}
				else if (ch == ')')
				{
					while (!chStack.empty() && chStack.top() != '(')
					{
						result.insert(result.end(), chStack.top());
						result.insert(result.end(), ' ');
						chStack.pop();
					}
					if (!chStack.empty() && chStack.top() == '(')
					{
						chStack.pop();
					}
				}
				else if (ch == '+' || ch == '-')
				{
					while (!chStack.empty() && (chStack.top()=='+' || chStack.top() == '-'))
					{
						result.insert(result.end(), chStack.top());
						result.insert(result.end(), ' ');
						chStack.pop();
					}
					chStack.push(ch);	// 由于这里只有加减号，所以优先级想通过，不需要优先级表
				}
				else if (ch == ' ')
				{
					// 略过
				}
				else
				{
					return "error";
				}
			}
		}
		if (digitFinished == false)
		{
			result.append(str);
			result.insert(result.end(), ' ');
		}
		while (!chStack.empty())
		{
			result.insert(result.end(), chStack.top());
			result.insert(result.end(), ' ');
			chStack.pop();
		}
		return result;
	}

	bool isDigit(char ch)
	{
		if (ch >= 48 && ch <= 57)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
};


// 别人的算法，该算法在只有加减法时，可以直接用中缀表达式计算，比较快速；
//class Solution {
//public:
//	int calculate(string s) {
//
//		int number = 0;
//		int result = 0;
//		int sign = 1;
//		stack<int> st;
//
//		for (int i = 0; i<s.length(); i++)
//		{
//			if (s[i] >= '0' && s[i] <= '9')
//				number = number * 10 + (s[i] - '0');
//			else if (s[i] == '+')
//			{
//				result += sign*number;
//				number = 0;
//				sign = 1;
//			}
//			else if (s[i] == '-')
//			{
//				result += sign*number;
//				number = 0;
//				sign = -1;
//			}
//			else if (s[i] == '(')
//			{
//				st.push(result);
//				st.push(sign);
//				result = 0;
//				sign = 1;
//			}
//			else if (s[i] == ')')
//			{
//				result += sign * number;
//				result *= st.top();
//				st.pop();
//				result += st.top();
//				st.pop();
//				number = 0;
//			}
//
//		}
//
//		if (number != 0)
//			result += sign * number;
//
//		return result;
//	}
//};

