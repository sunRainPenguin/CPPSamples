#include <iostream>
#include <iterator>
#include <algorithm>
using namespace std;

int main() {
	int seqNum = 0;
	int seqlen = 0;
	int *seq = NULL;
	bool* resArr = NULL;
	bool res = false;
	int count1 = 0;
	int count2 = 0;
	while (cin>>seqNum)
	{
		resArr = new bool[seqNum];
		for (int i = 0; i < seqNum; i++)
		{
			seqlen = 0;
			seq = NULL;
			res = false;
			scanf("%d", &seqlen);
			//cin >> seqlen;
			seq = new int[seqlen];
			for (int j = 0; j < seqlen; j++)
			{
				//cin >> seq[j];
				scanf("%d", &seq[j]);
			}

			//do
			//{
			//	res = true;
			//	for (int h = 0; h < seqlen; h++)
			//	{
			//		if (h > 0)
			//		{
			//			if ((seq[h] * seq[h - 1]) % 4 != 0)
			//			{
			//				res = false;
			//				break;
			//			}
			//		}
			//	}

			//	// 找到符合的排列
			//	if (res == true)
			//	{
			//		break;
			//	}
			//} while (next_permutation(seq, seq + seqlen));
			count1 = 0;
			count2 = 0;
			for (int h = 0; h < seqlen; h++)
			{
				if (seq[h] % 4 == 0)
				{
					count1++;
				}
				else if (seq[h] % 2 != 0)
				{
					count2++;
				}
			}
			if (count1 >= count2)
			{
				res = true;
			}
			else
			{
				res = false;
			}
			resArr[i] = res;
		}

		for (int i = 0; i < seqNum; i++)
		{
			if (resArr[i])
			{
				cout << "Yes" << endl;
			}
			else
			{
				cout << "No" << endl;
			}
		}
	}
	
}