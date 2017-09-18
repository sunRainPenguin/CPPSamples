#include <iostream>
using namespace std;

double abss(double x, double y)
{
	double result = (x > y ? (x - y) : y - x);
	if (result > 180.00000000)
	{
		return (360.00000000 - result);
	}
	else
	{
		return result;
	}
}

//int main()
//{
//	int inputNum = 0;
//	int count = 0;
//	double* distances = NULL;
//	double max = 0.0;
//	double pi = 180.00000000;
//	double twoPi = 360.00000000;
//	double dis = 0;
//	while (cin >> inputNum)
//	{
//		count = 0;
//		distances = new double[inputNum];
//		while (count<inputNum)
//		{
//			cin >> distances[count];
//			count++;
//		}
//
//		max = 0.0;
//		dis = 0.0;
//		for (int i = 0; i < inputNum; i++)
//		{
//			for (int j = i; j < inputNum; j++)
//			{
//				if (abss(distances[i], distances[j]) > pi)
//				{
//					dis = twoPi - (abss(distances[i], distances[j]));
//				}
//				else
//				{
//					dis = abss(distances[i], distances[j]);
//				}
//				if (dis > max)
//				{
//					max = dis;
//				}
//			}
//		}
//		printf("%.8f\n", max);
//	}
//	return 0;
//}

int main()
{
	int inputNum = 0;
	int count = 0;
	double* distances = NULL;
	double max = 0.0;
	double pi = 180.00000000;
	double twoPi = 360.00000000;
	double dis = 0.0;
	double oppo = 0.0;
	bool left = true;
	while (cin >> inputNum)
	{
		count = 0;
		distances = new double[inputNum];
		while (count<inputNum)
		{
			cin >> distances[count];
			count++;
		}

		max = 0.0;
		dis = 0.0;
		left = true;	// 有小于180的数字
		if (distances[0] > pi)
		{
			left = false;
		}

		for (int i = 0; i < inputNum; i++)
		{
			if (left)
			{
				if (distances[i] > 180)
				{
					break;
				}
			}
			
			oppo = (distances[i] < 180) ? (distances[i] + 180.0) : (distances[i] + 180.0 - twoPi);

			int j = i;
			for (j = i; j < inputNum; j++)
			{
				if (distances[j] > oppo )
				{
					break;
				}	
			}
			
			// 没有大于oppo的数据
			if (j == inputNum)
			{
				if (abss(distances[j - 1],distances[i]) > max)
				{
					max = abss(distances[j - 1], distances[i]);
				}
			}
			else
			{
				if (j>0 && abss(distances[j - 1], distances[i]) > max)
				{
					max = abss(distances[j - 1], distances[i]);
				}
				if (abss(distances[j], distances[i]) > max)
				{
					max = abss(distances[j], distances[i]);
				}
			}
		}
		printf("%.8f\n", max);
	}
	return 0;
}