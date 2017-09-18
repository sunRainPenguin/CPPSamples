#include <iostream>

using namespace std;


int main()
{
	int n;
	cin >> n;

	int *m = new int[n];

	for (int i = 0; i < n; ++i)
	{
		cin >> m[i];
	}

	int A = 0, B = 0;
	int turn = 0;
	int a, b, c, d, tmp;
	for (int i = 0; i < n;)
	{
		a = i < n ? m[i] : 0;
		b = (i + 1) < n ? m[i + 1] : 0;
		c = (i + 2) < n ? m[i + 2] : 0;
		d = (i + 3) < n ? m[i + 3] : 0;

		if (b <= d)
		{
			tmp = a;
			++i;
		}
		else
		{
			tmp = a + b;
			i += 2;
		}

		if (turn % 2 == 0)
		{
			A += tmp;
		}
		else
		{
			B += tmp;
		}

		turn++;
	}

	cout << (A > B ? "true" : "false") << endl;

	return 0;
}