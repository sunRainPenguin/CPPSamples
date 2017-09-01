#include <iostream>
using namespace std;

int main()
{
	char(*c)[5];
	int n = 3;
	try
	{
		c = new char[n][5];
	}
	catch(bad_alloc)
	{
		cerr << "out of memory" << endl;
		exit(1);
	}
	return 0;
}