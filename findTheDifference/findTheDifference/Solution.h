#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
	char findTheDifference(string s, string t) {
		int table[26] = {0};
		if (t.length() != s.length()+1)
		{
			return NULL;		// “Ï≥£
		}
		for (int i = 0; i < t.length(); i++)
		{
			if (i < s.length())
			{
				table[s[i] - 'a']++;
			}
			table[t[i] - 'a']++;
		}
		for (int i = 0; i < 26; i++)
		{
			if (table[i] % 2 == 1)
			{
				return 'a' + i;
			}
		}
		return NULL;
	}
};

