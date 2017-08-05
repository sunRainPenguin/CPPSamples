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
			return -1;		// �쳣
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
						return -1;		// �쳣
					}
				}
 				else if (ch == ' ')
				{
					// �Թ�
				}
				else
				{
					return -1;		// �쳣
				}
			}
		}
		// ������һ���ո�֮ǰ�����ֻ������һ���ַ�������
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
					chStack.push(ch);	// ��������ֻ�мӼ��ţ��������ȼ���ͨ��������Ҫ���ȼ���
				}
				else if (ch == ' ')
				{
					// �Թ�
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


// ���˵��㷨�����㷨��ֻ�мӼ���ʱ������ֱ������׺���ʽ���㣬�ȽϿ��٣�
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

