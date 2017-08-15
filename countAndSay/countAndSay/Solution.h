#pragma once
#include <string>
#include <sstream>
using namespace std;

class Solution {
public:
	string countAndSay(int n)
	{
		int i = 1;
		string result = "1";
		while (i<n)
		{
			result = countAndSayNext(result);
			i++;
		}
		return result;
	}

	string countAndSayNext(string s)
	{
		int length = s.length();
		if (length == 0)
		{
			return "";
		}

		string result="";
		char ch = NULL;
		char lastCh = NULL;
		int count = 0;

		int i = 0;
		stringstream ss;
		while (i < length)
		{
			ch = s[i];		// 以下主要是在什么条件下count是否需要加1及重置的问题
			if (i == 0)
			{
				count++;
			}
			else if (ch != lastCh)
			{
				ss.str("");
				ss << count;
				result = result.append(ss.str());
				result.insert(result.end(), lastCh);
				count = 1;
			}
			else
			{
				count++;
			}
			lastCh = ch;
			i++;
		}


		if (i == length)
		{
			if (count == 0)
			{
				count++;
			}
			ss.str("");
			ss << count;
			result.append(ss.str());
			result.insert(result.end(), lastCh);
		}
		return result;
	}
};

