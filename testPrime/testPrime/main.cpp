#include <iostream>
using namespace std;
int main()
{
	int n, n2;
	cin >> n;
	n2 = n;
	cout << n << "=";
	for (int i = 2; i <= n; i++) {
		for (; n2%i == 0;) {
			n2 = n2 / i;
			cout << i << "*";
		}
	}
	cout << "1";

	return 0;
}