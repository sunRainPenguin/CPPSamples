#include <iostream>
#include <string>
#include <sstream>
using namespace std;

int strToInt(string s)
{
	int r;
	stringstream ss;
	ss << s;
	ss >> r;
	ss.flush();
	return r;
}

int main() {
	int n,c,f;
	string* inputs = NULL;
	string* results = NULL;
	string h;
	string m;
	string s;
	while (cin >> n)
	{
		c = 0;
		inputs = new string[n];
		results = new string[n];
		while (c<n)
		{
			cin >> inputs[c];

			h = inputs[c].substr(0, 2);
			m = inputs[c].substr(3, 2);
			s = inputs[c].substr(6, 2);

			if (strToInt(h) > 23)
			{
				h[0] = '0';
			}
			if (strToInt(m) > 59)
			{
				m[0] = '0';
			}
			if (strToInt(s) > 59)
			{
				s[0] = '0';
			}

			results[c] = h + ":" + m + ":" + s;
			c++;
		}
		for (int i = 0; i < n; i++)
		{
			cout << results[i] << endl;
		}
	}
}