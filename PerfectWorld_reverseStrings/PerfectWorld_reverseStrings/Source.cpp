#include <iostream>
#include <string>
using namespace std;

int main() {
	string input;
	string temp;
	int s,e,ts,c,l;
	while (getline(cin, input))
	{
		s = input.length() - 1;
		e = input.length() - 1;
		c = 0;

		c = 0; 
		while (input[c]==' ' && c != input.length())
		{
			c++;
		}
		while (input[c]!=' ' && c!=input.length())
		{
			c++;
		}
		l = input.length()-c;

		c = 0;
		while (c<=l)
		{
			s = input.length() - 1;
			e = input.length() - 1;
			// ÕÒµ½s\e
			while (e!=0 && input[e] == ' ')
			{
				e--;
				c++;
			}
			if (c > l)
			{
				break;
			}
			s = e;
			ts = s;
			while (s!=0 && input[s] != ' ')
			{
				ts = s;
				s--;
				c++;
			}
			if (c > l)
			{
				break;
			}
			if (input[s] == ' ')
			{
				s = ts;
			}

			// Á´½Ó
			input = input.substr(s, e - s + 1) + " " + input.substr(0, s);
		}
		cout << input << endl;
	}
}