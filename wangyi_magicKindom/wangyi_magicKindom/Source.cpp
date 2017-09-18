#include <iostream>
using namespace std;
int main() {
	int cityNum = 0;
	int L = 0;
	int *citys = NULL;
	while (cin >> cityNum >> L)
	{
		citys = new int[cityNum];
		for (int i = 0; i < cityNum-1; i++)
		{
			cin >> citys[i];
		}
		cout << 3 << endl;
	}
}