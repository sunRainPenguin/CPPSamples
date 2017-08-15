#include <stdlib.h>
#include <iostream>
using namespace std;

int main()
{
	//int* a = new int(12);
	//free(a);
	//int *ip = static_cast<int*>(malloc(sizeof(int)));
	//*ip = 10;
	//delete ip;
	//double *b = new double[1];
	//delete b;
	int *ip2 = new int(12);
	cout << *ip2;
	for (int i = 0; i < 1; i++)
	{
		ip2[i] = i;
	}
	delete []ip2;
	ip2 = nullptr;
	return 0;
}