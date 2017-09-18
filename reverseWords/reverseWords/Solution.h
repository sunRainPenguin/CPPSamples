#pragma once
#include <string>
#include <stack>
using namespace std;

class Solution {
public:
	string reverseWords(string s) {
		stack<char> stackChar;
		string result;
		for (int i = 0; i < s.length(); i++)
		{
			if (s[i] == ' ' || (i==s.length()-1))
			{
				if (i == s.length() - 1 && s[i]!=' ')
				{
					stackChar.push(s[i]);
				}

				while (!stackChar.empty())
				{
					result.push_back(stackChar.top());
					stackChar.pop();
				}
				if (i != (s.length() - 1))
				{
					result.push_back(' ');
				}
			}
			else
			{
				stackChar.push(s[i]);
			}
		}
		return result;
	}
};

// 别人的做法
// 每次读到一个非空格，记录位置i，然后，j=i，并将j移动到下一个空格位置，reverse[i,j)；最后将i=j-1;
//class Solution {
//public:
//	string reverseWords(string &s) {
//		for (int i = 0; i < s.length(); i++) {
//			if (s[i] != ' ') {   // when i is a non-space
//				int j = i;
//				for (; j < s.length() && s[j] != ' '; j++) {} // move j to the next space
//				reverse(s.begin() + i, s.begin() + j);
//				i = j - 1;
//			}
//		}
//
//		return s;
//	}
//};