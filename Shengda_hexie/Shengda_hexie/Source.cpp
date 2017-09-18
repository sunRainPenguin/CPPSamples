#include <iostream>
#include <string>
using namespace std;

int main()
{
	string in;
	char x;
	string out;
	while (cin >> in)
	{
		cin >> x;
		for (int i = 0; i < in.length(); i++)
		{
			if (in[i] != x)
			{
				out.push_back(in[i]);
			}
		}
		cout << out << endl;
	}
	return 0;
}