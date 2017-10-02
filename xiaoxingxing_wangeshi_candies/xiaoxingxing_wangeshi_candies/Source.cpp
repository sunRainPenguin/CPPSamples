#include <iostream>
using namespace std;

int maxCanNum(int x[], int w[], int A[], int B[], int maxNum, int value, int maxValue, int n)
{
	int putIndex = -1;
	int tempMaxNum = maxNum;
	int tempValue = value;
	int t = 0;
	while (true)
	{
		maxNum = tempMaxNum;
		value = tempValue;
		for (int i = 0; i < n; i++)
		{
			if (value + w[i] <= maxValue)
			{
				if (x[i] == 0)
				{
					t = maxNum + A[i] + B[i];
				}
				else
				{
					t = maxNum + A[i];
				}
				if (t > tempMaxNum)
				{
					if (putIndex!=-1)
					{
						--x[putIndex];
						tempValue = tempValue - w[putIndex];
					}
					putIndex = i;
					if (x[i] == 0)
					{
						tempMaxNum = maxNum + A[i] + B[i];
					}
					else
					{
						tempMaxNum = maxNum + A[i];
					}
					tempValue = tempValue + w[i];
				}
			}
		}

		if (putIndex != -1)
		{
			++x[putIndex];
		}
		putIndex = -1;
		if (tempValue >= maxValue)
		{
			break;
		}
	}
	
	return tempMaxNum;
}

int main()
{
	int maxValue, giftNum,c;
	int* w;
	int* A;
	int* B;
	int* re;
	cin >> maxValue >> giftNum;
	w = new int[giftNum];
	A = new int[giftNum];
	B = new int[giftNum];
	re = new int[giftNum];
	c = 0;
	while (c<giftNum)
	{
		cin >> w[c] >> A[c] >> B[c];
		c++;
	}

	for (int i = 0; i < giftNum; i++)
	{
		re[i] = 0;
	}
	cout << maxCanNum(re, w, A, B, 0, 0, maxValue, giftNum) << endl;
	return 0;
}