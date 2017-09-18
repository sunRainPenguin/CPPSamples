#include <iostream>
#include <sstream>
#include <string>
using namespace std;

int main()
{
	int n;
	int count = 0;
	int* a = NULL;
	while (cin >> n)
	{
		a = new int[n];
		while (count<n)
		{
			cin >> a[count];
			count++;
		}
		cout << "Alice" << endl;
	}
	return 0;
}

