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
	// ������
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

	// Rabin-karp����
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

	/******************************** KMP�㷨 ***********************************************/
	// KMP�㷨-��ǰ׺
	int* Prefix_Table(const char P[], int m)
	{
		int i = 1;
		int j = 0;
		int* F = new int[m];
		F[0] = 0;	// ��0λ֮ǰһ��û�����ͬǰ׺
		while (i < m)
		{
			// i���ǰ׺���ȼ�1
			if (P[i] == P[j])
			{
				F[i] = j + 1;	// ���ͬǰ׺Ϊ[0,j]
				i++;
				j++;
			}
			else if (j > 0)
			{
				j = F[j - 1];	// ��ʼ����̵�ǰ׺[0,F[j-1]]�Ƚ�
			}
			else
			{
				// û�п���ƥ�䵽��ǰ׺��ֱ�Ӹ�ֵΪ0��������һ��i���������ͬǰ׺
				F[i] = 0;
				i++;
			}
		}
		return F;
	}

	// KMP�㷨
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
				// ���˵���ǰ��Ҳ�Ҳ�����ƥ����ַ���������һ������ƥ��
				i++;
			}
		}
		return -1;
	}

	/******************************** Boyer-Moore �㷨 ***********************************************/
	// ��¼ÿ���ַ����������ұߵ�λ�������ұߵľ���;������ƥ�仵�ַ�ʱ�����ҵ����Զ�Ӧ���ַ�λ��
	void preBmBc(const char* pattern, int m, int bmBc[])
	{
		int i;
		for (i = 0; i < MAX_CHAR; i++)
		{
			bmBc[i] = m;	// δ���ָ��ַ�ʱ�����ַ�λ�õ�ֵΪm
		}
		for (i = 0; i < m; i++)
		{
			bmBc[pattern[i]] = m - 1 - i;
		}
	}

	// ��¼ÿ����ÿ��λ��iΪ��׺�ĺ�׺�ַ��� �� �����һ���ַ�Ϊ��׺�ĺ�׺�ַ����Ĺ����ַ����ĳ���
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

	// �����׺���飬��¼�������ұ�����ĺ�׺�ַ����ĺ�׺λ�õľ���
	void preBmGs(const char* pattern, int m, int bmGs[])
	{
		int i, j;
		int suff[SIZE];

		suffix_old(pattern, m, suff);

		// ����case3����������ͬ��׺
		for (i = 0; i < m; i++)
		{
			bmGs[i] = m;
		}

		// case2����ͬ��׺�ַ�����ʼ��0
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

	// BoyerMoore�㷨
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

