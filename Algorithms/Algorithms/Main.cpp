#include <iostream>
#include "CompareVersion.h"
using namespace std;

int main()
{
	// ��������ʾ�汾�ŵ��ַ������бȽ�
	CompareVersion* cv = new CompareVersion();
	cout << cv->compareVersion("1.0", "1") << endl;
	return 0;
}