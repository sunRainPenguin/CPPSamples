#include <iostream>
#include <stdlib.h>
#include "Header1.h"
using namespace std;

int func2(char *filename)
{
	FILE *fp;
	int key;
	fp = fopen(filename, "r");
	fscanf(fp, "%d", &key);
	return key;
}

int main()
{
	cout << x << endl;
	cout << sizeof(3) << endl;
	func2("test.txt");
	return 0;
}