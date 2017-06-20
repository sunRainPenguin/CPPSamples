#pragma once
#include <string>
#include <iostream>
using namespace std;

class Solution
{
public:
	bool detectCapitalUse(string word) {
		if (word.length() == 0)
		{
			return false;
		}
		bool allCapital = true;
		bool allLowercase = true;
		bool onlyFirstCapital = false;
		if (isupper(word[0]))
		{
			onlyFirstCapital = true;
			allLowercase = false;
		}
		else
		{
			onlyFirstCapital = false;
			allCapital = false;
		}

		int index = 1;
		int length = word.length();
		while (index < length)
		{
			if (allCapital || allLowercase)
			{
				if (isupper(word[index]))
				{
					allLowercase = false;
					onlyFirstCapital = false;
				}
				else
				{
					allCapital = false;
				}
			}
		}
		return (allCapital || allLowercase || onlyFirstCapital);
	}
};

