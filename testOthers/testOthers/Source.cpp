#include <iostream>
#include <stdlib.h>
#include <map>
#include <vector>
#include <string>
#include "Header1.h"
using namespace std;

template<class T>
void delete2dArray(T** &x, int numberOfRows)
{
	//ɾ��������ռ�
	for (int i = 0; i < numberOfRows; i++)
	{
		delete [] x[i];
	}

	// ɾ����ָ��
	delete[] x;
	x = NULL;
}

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