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

// ���˵�����
// ÿ�ζ���һ���ǿո񣬼�¼λ��i��Ȼ��j=i������j�ƶ�����һ���ո�λ�ã�reverse[i,j)�����i=j-1;
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