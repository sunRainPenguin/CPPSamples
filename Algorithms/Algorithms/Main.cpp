#include <iostream>
#include "CompareVersion.h"
using namespace std;

int main()
{
	// 对两个表示版本号的字符串进行比较
	CompareVersion* cv = new CompareVersion();
	cout << cv->compareVersion("1.0", "1") << endl;
	return 0;
}