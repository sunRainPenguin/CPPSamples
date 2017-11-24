#pragma once
#include <string>
using namespace std;

// 能够比较“01”和“1”
int str2Int(string version)
{
	int j = 1;
	int result = 0;
	for (int i = version.length() - 1; i >= 0; i--)
	{
		result = result + (version[i] - '0')*j;
		j = j * 10;
	}
	return result;
}

class CompareVersion
{
public:
	int compareVersion(string version1, string version2) {
		string v1, v2;
		int iv1 = 0, iv2 = 0;
		if (version1 == version2)
		{
			return 0;
		}
		else
		{
			int i1 = 0, i2 = 0;
			while (i1<version1.length() || i2<version2.length())
			{
				// version1
				if (i1 >= version1.length())
				{
					iv1 = 0;
				}
				else
				{
					while (version1[i1] != '.' && i1<version1.length())
					{
						v1.push_back(version1[i1]);
						i1++;
					}
					i1++;

					iv1 = str2Int(v1.c_str());
					v1 = "";
				}

				// version2
				if (i2 >= version2.length())
				{
					iv2 = 0;
				}
				else
				{
					while (version2[i2] != '.' && i2<version2.length())
					{
						v2.push_back(version2[i2]);
						i2++;
					}
					i2++;

					iv2 = str2Int(v2.c_str());
					v2 = "";
				}

				// 比较两个.之间的整数值
				if (iv1>iv2)
				{
					return 1;
				}
				else if (iv1<iv2)
				{
					return -1;
				}
			}
			return 0;
		}
	}
};

