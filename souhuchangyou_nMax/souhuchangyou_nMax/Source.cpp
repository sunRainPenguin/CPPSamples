#include <iostream>
#include <algorithm>
using namespace std;

void insertionSort(int arr[], int n)
{
	int v = -1;
	int j = -1;
	for (int i = 1; i < n; i++)
	{
		v = arr[i];
		j = i;
		while (j >= 1 && arr[j - 1]>v)
		{
			arr[j] = arr[j - 1];
			j--;
		}
		arr[j] = v;
	}
}

int main()
{
	int n,c,i;
	bool hasSec;
	int* inputs = NULL;
	while (cin>>n)
	{
		c = 0;
		inputs = new int[n];
		while (c<n)
		{
			cin >> inputs[c];
			c++;
		}

		if (n == 1)
		{
			cout << inputs[0] << endl;
		}
		else
		{
			insertionSort(inputs, n);
			if (inputs[n - 1] == inputs[n - 2])
			{
				i = n - 1;
				hasSec = false;
				while (i>=0)
				{
					if (inputs[i] != inputs[n - 1])
					{
						cout << inputs[i];
						hasSec = true;
						break;
					}
					i--;
				}
				if (!hasSec)
				{
					cout << inputs[n-1] << endl;
				}
			}
			else
			{
				cout << inputs[n - 2] << endl;
			}
		}
		delete[] inputs;
	}
	return 0;
}