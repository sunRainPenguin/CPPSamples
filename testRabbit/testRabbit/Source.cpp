#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int x = 0;
	int y = 0;
	int year = 1;
	int add = 0;
	int count = 0;
	cin >> x >> y;
	int* result = new int[x];
	memset(result, 0, sizeof(int)*x);
	result[0] = 1;
	while (year<y)
	{
		// 兔子岁数增长
		count = 0;
		for (size_t i = x-1; i >=1; i--)
		{
			count = count + result[i];
			if (i >= 1 && i!=x-1)
			{
				add = add + result[i];
			}
			result[i] = result[i - 1];
		}
		result[0] = add;
		count = count + result[0];

		if (count > 10)
		{
			for (size_t i = x - 1; i >0; i--)
			{
				if (result[i] >= 1)
				{
					result[i]--;
					break;
				}

			}

			for (size_t i = x-1; i >0; i--)
			{
				if (result[i] >=1)
				{
					result[i]--;
					break;
				}

			}
		}
		// 生兔子
		year++;
	}
	cout << count << endl;
	return 0;
}