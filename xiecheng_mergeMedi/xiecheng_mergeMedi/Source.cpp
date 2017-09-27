#include <string>
#include <iostream>
#include <vector>
using namespace std;


bool findx(vector<int> x, int val)
{
	for (int i = 0; i < x.size(); i++)
	{
		if (val == x[i])
			return true;
	}
	return false;
}

int main()
{
	int n1, n2,c;
	double re;
	int* i1 = NULL;
	int* i2 = NULL;
	vector<int> me;
	while (cin>>n1)
	{
		re = 0.0;
		c = 0;
		i1 = new int[n1];
		while (c<n1)
		{
			cin >> i1[c];
			me.push_back(i1[c]);
			c++;
		}
		c = 0;
		cin >> n2;
		i2 = new int[n2];
		while (c<n2)
		{
			cin >> i2[c];
			if (!findx(me, i2[c]))
			{
				me.push_back(i2[c]);
			}
			c++;
		}

		// 这里要用Merge的方法
		int v = -1;
		int j = -1;
		int s = me.size();
		for (int i = 1; i < s; i++)
		{
			v = me[i];
			j = i;
			while (j >= 1 && me[j - 1]>v)
			{
				me[j] = me[j - 1];
				j--;
			}
			me[j] = v;
		}

		if (s % 2 == 0)
		{
			re = (double)(me[s / 2] + me[s / 2 - 1]);
			re = re / 2.0;
			cout << re << endl;
		}
		else
		{
			cout << me[s / 2] << endl;
		}

	}
	return 0;
}