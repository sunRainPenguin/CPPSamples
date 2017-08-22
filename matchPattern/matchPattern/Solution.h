#pragma once
#include <iostream>
#include <string>
#include "Automata.h"
using namespace std;

#define MAX_CHAR 256
#define SIZE 256
#define MAX(x, y) (x) > (y) ? (x) : (y)

class Solution
{
public:
	// 暴力法
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

	// Rabin-karp搜索
	void Rabin_Karp_search(const string &T, const string &P, int d, int q)
	{
		bool isFound = false;
		int m = P.length();
		int n = T.length();
		int i, j;
		int p = 0;  // hash value for pattern
		int t = 0; // hash value for txt
		int h = 1;

		// The value of h would be "pow(d, M-1)%q"
		for (i = 0; i < m - 1; i++)
			h = (h*d) % q;

		// Calculate the hash value of pattern and first window of text
		for (i = 0; i < m; i++)
		{
			p = (d*p + P[i]) % q;
			t = (d*t + T[i]) % q;
		}

		// Slide the pattern over text one by one 
		for (i = 0; i <= n - m; i++)
		{

			// Chaeck the hash values of current window of text and pattern
			// If the hash values match then only check for characters on by one
			if (p == t)
			{
				/* Check for characters one by one */
				for (j = 0; j < m; j++)
					if (T[i + j] != P[j])
						break;

				if (j == m)  // if p == t and pat[0...M-1] = txt[i, i+1, ...i+M-1]
				{
					cout << "Pattern found at index :" << i << endl;
					isFound = true;
				}
			}

			// Calulate hash value for next window of text: Remove leading digit, 
			// add trailing digit           
			if (i < n - m)
			{
				t = (d*(t - T[i] * h) + T[i + m]) % q;

				// We might get negative value of t, converting it to positive
				if (t < 0)
					t = (t + q);
			}
		}
		if (!isFound)
		{
			cout << "Pattern is not found." << endl;
		}
	}

	/******************************** KMP算法 ***********************************************/
	// KMP算法-求前缀
	int* Prefix_Table(const char P[], int m)
	{
		int i = 1;
		int j = 0;
		int* F = new int[m];
		F[0] = 0;	// 第0位之前一定没有最长相同前缀
		while (i < m)
		{
			// i的最长前缀长度加1
			if (P[i] == P[j])
			{
				F[i] = j + 1;	// 最长相同前缀为[0,j]
				i++;
				j++;
			}
			else if (j > 0)
			{
				j = F[j - 1];	// 开始与更短的前缀[0,F[j-1]]比较
			}
			else
			{
				// 没有可以匹配到的前缀，直接赋值为0，跳到下一个i来查找最长相同前缀
				F[i] = 0;
				i++;
			}
		}
		return F;
	}

	// KMP算法
	int KMP(const char T[], int n, const char P[], int m, int F[])
	{
		int i = 0, j = 0;
		F = Prefix_Table(P, m);
		while (i < n)
		{
			if (T[i] == P[j])
			{
				if (j == m - 1)
				{
					return i - j;
				}
				else
				{
					i++;
					j++;
				}
			}
			else if(j>0)
			{
				j = F[j];
			}
			else
			{
				// 回退到最前面也找不到可匹配的字符串，换下一个进行匹配
				i++;
			}
		}
		return -1;
	}

	/******************************** Boyer-Moore 算法 ***********************************************/
	// 记录每个字符出现在最右边的位置离最右边的距离;用于在匹配坏字符时尽快找到可以对应的字符位置
	void preBmBc(const char* pattern, int m, int bmBc[])
	{
		int i;
		for (i = 0; i < MAX_CHAR; i++)
		{
			bmBc[i] = m;	// 未出现该字符时，该字符位置的值为m
		}
		for (i = 0; i < m; i++)
		{
			bmBc[pattern[i]] = m - 1 - i;
		}
	}

	// 记录每个以每个位置i为后缀的后缀字符串 与 以最后一个字符为后缀的后缀字符串的公共字符串的长度
	void suffix_old(const char* pattern, int m, int suff[])
	{
		int i, j;
		suff[m - 1] = m;


		for (i=m-2; i>=0; i--)
		{
			j = i;
			while (j >= 0 && pattern[j] == pattern[m - 1 - i + j])
			{
				j++;
			}
			suff[i] = i - j;
		}
	}

	// 计算后缀数组，记录的是离右边最近的后缀字符串的后缀位置的距离
	void preBmGs(const char* pattern, int m, int bmGs[])
	{
		int i, j;
		int suff[SIZE];

		suffix_old(pattern, m, suff);

		// 包含case3：不包含相同后缀
		for (i = 0; i < m; i++)
		{
			bmGs[i] = m;
		}

		// case2：相同后缀字符串起始于0
		j = 0;
		for (i=m-1; i>=0; i--)
		{
			if (suff[i] == i + 1)
			{
				while (j<m-1-i)
				{
					if (bmGs[j] == m)
						bmGs[j] = m - 1 - i;
					j++;
				}
			}
		}

		for (i = 0; i < m-2; i++)
		{
			bmGs[m - 1 - suff[i]] = m - 1 - i;
		}
	}

	// BoyerMoore算法
	void BoyerMoore(const char *pattern, int m, const char *text, int n)
	{
		int i, j, bmBc[MAX_CHAR], bmGs[SIZE];

		// Preprocessing
		preBmBc(pattern, m, bmBc);
		preBmGs(pattern, m, bmGs);

		// Searching
		j = 0;
		while (j <= n - m)
		{
			for (i = m - 1; i >= 0 && pattern[i] == text[i + j]; i--);
			if (i < 0)
			{
				printf("Find it, the position is %d\n", j);
				j += bmGs[0];
				return;
			}
			else
			{
				j += MAX(bmBc[text[i + j]] - m + 1 + i, bmGs[i]);
			}
		}

		printf("No find.\n");
	}
		
};

