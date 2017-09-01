#include <iostream>
using namespace std;

int main()
{
	int cinNum = 0;
	int* input = NULL;
	int count = 0;
	int k = 0;
	int sum = 0;
	int len = 0;
	while (cin >> cinNum)
	{
		count = 0;
		input = new int[cinNum];
		while (count < cinNum)
		{
			cin >> input[count];
			count++;
		}
		cin >> k;

		len = 0;
		for (int i = 0; i < count; i++)
		{
			sum = 0;
			for (int j = i; j < count; j++)
			{
				sum = sum + input[j];
				if (sum%k == 0 && (j - i + 1)>len)
				{
					len = j - i + 1;
				}
			}
		}
		cout << len << endl;
		delete[] input;
		input = NULL;
	}

	return 0;
}