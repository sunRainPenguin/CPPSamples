//#include <iostream>
//using namespace std;
//
//int gbs(int x, int y)
//{
//	int max = x > y ? x : y;
//	int min = x < y ? x : y;
//	for (int i = min; i < i<=x*y; i++)
//	{
//		if (i%x == 0 && i %y == 0)
//		{
//			return i;
//		}
//	}
//	return x;
//}
//
//int main() {
//	int a, b,n;
//	int mul = 1;
//	int time = 1;
//	int index = 1;
//	int count = 0;
//	while (cin >> a >> b >> n)
//	{
//		index = 1;
//		count = 0;
//		mul = gbs(a,b);
//		while (mul*index < n)
//		{
//			count++;
//			index++;
//		}
//		if (mul*index == n)
//		{
//			count++;
//		}
//		cout << count << endl;
//	}
//}
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
