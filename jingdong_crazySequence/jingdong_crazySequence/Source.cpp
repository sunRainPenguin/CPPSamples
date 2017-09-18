#include <iostream>
using namespace std;
//int main() {
//	long n;
//	long curr = 1;
//	long count = 1;
//	long index = 0;
//	while (cin >> n)
//	{
//		curr = 1;
//		count = 1;
//		index = 0;
//		while (index<n)
//		{
//			if (count == 0)
//			{
//				curr++;
//				count = curr;
//			}
//			count--;
//			index++;
//		}
//		cout << curr << endl;
//	}
//}

int main() {
	long n;
	long curr = 1;
	long index = 0;
	while (cin >> n)
	{
		curr = 1;
		index = 0;
		while (index<n)
		{
			index = index + curr;
			if (n <= index)
			{
				break;
			}
			curr++;
		}
		cout << curr << endl;
	}
}