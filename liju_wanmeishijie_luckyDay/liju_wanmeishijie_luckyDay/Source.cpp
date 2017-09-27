#include <iostream>
using namespace std;

int main()
{
	int n,c;
	int* year;
	int* d;
	int* ds;
	cin >> n;
	year = new int[n];
	d = new int[n];
	ds = new int[n];

	c = 0;
	while (c<n)
	{
		cin >> year[c] >> d[c];
		c++;
	}
	for (int i = 0; i < n; i++)
	{
		if (year[i] % 400 == 0 || (year[i] % 4 == 0 && year[i] % 100 != 0))
		{
			if (d[i] <= 28)
			{
				ds[i] = 12;
			}
			else if (d[i] == 29)
			{
				ds[i] = 11;
			}
			else if (d[i] == 30)
			{
				ds[i] = 7;
			}
			else if (d[i] > 30)
			{
				ds[i] = 0;
			}
		}
		else
		{
			if (d[i] <= 27)
			{
				ds[i] = 12;
			}
			else if (d[i] == 28 || d[i] == 29)
			{
				ds[i] = 11;
			}
			else if (d[i] == 30)
			{
				ds[i] = 7;
			}
			else if (d[i] > 30)
			{
				ds[i] = 0;
			}
		}
	}

	for (int i = 0; i < n; i++)
	{
		cout << ds[i] << endl;
	}
}