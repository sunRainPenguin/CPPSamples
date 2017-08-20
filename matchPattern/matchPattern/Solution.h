#pragma once
class Solution
{
public:
	// ±©Á¦·¨
	int bruteForceMatch(int T[], int n, int P[], int m)
	{
		int j = 0;
		for (size_t i = 0; i < n-m+1; i++)
		{
			j = 0;
			while ( j<m && P[j]==T[i+j])
			{
				j++;
			}
			if (j == m)
			{
				return i;
			}
		}
		return -1;
	}

	// 
};

