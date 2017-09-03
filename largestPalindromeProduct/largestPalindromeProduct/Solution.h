#include <iostream>
#include <sstream>
#include <math.h>
using namespace std;

class Solution {
public:
	int largestPalindrome(int n) 
	{
		if (n == 0)
		{
			return 0;
		}
		else if (n == 1)
		{
			return 9;
		}
		int max = pow(10, n) - 1;
		int min = pow(10, n - 1);
		long long product = 0;
		for (int i = max; i>=min; i--)
		{
			product = buildPalindrome(i);
			for (long long j = max; j*j>=product; j--)
			{
				if (product%j == 0 && product / j <= max && product/j>=min)
				{
					return product % 1337;
				}
			}
		}
		return -1;
	}

	long long buildPalindrome(int n)
	{
		string s = to_string(n);
		stringstream ss;
		long long result;
		reverse(s.begin(), s.end());
		s = to_string(n) + s;
		ss << s;
		ss >> result;
		return result;
	}
};

