#pragma once
#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
	int titleToNumber(string s) {
		if (s.empty())
			return 0;
		reverse(s.begin(), s.end());
		int result = 0;
		for (int i = 0; i < s.length(); i++)
		{
			if (s[i] > 'Z' || s[i] < 'A')
			{
				return 0;
			}
			result = result + (s[i] - 'A' + 1)*pow(26, i);
		}
		return result;
	}
};

