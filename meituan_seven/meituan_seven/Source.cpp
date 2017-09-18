#include <iostream>
#include <sstream>
#include <string>
using namespace std;

int main()
{
	int n;
	int count = 0;
	string* a = NULL;
	string temp;
	long t;
	char x;
	stringstream ss("");
	int result = 0;
	while (cin >> n)
	{
		a = new string[n];
		result = 0;
		while (count<n)
		{
			cin >> a[count];
			count++;
		}
		for (int i = 0; i < n; i++)
		{
			for (int j = i; j < n; j++)
			{
				if (j == i)
					continue;
				temp = a[i] + a[j];
				ss.str("");
				ss.clear();
				ss << temp;
				ss.flush();
				ss >> t;
				if (t % 7 == 0)
				{
					result += 1;
				}

				temp = a[j] + a[i];
				ss.str("");
				ss.clear();
				ss << temp;
				ss.flush();
				ss >> t;
				
				if (t % 7 == 0)
				{
					result += 1;
				}
			}
		}
		cout << result << endl;
	}
	return 0;
}

