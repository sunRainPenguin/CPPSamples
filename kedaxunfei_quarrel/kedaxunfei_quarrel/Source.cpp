#include <iostream>
#include <string>
#include <set>
using namespace std;

string replaceAll(string input, string val, char left, char right)
{
	for (int i = 0; i < input.length()-1; i++)
	{
		if (input[i] == right && input[i + 1] == left)
		{
			if (i + 2 < input.length())
			{
				input = input.substr(0, i) + val+ input.substr(i + 2, input.length() - i - 2);
			}
			else
			{
				input = input.substr(0, i) + val;
			}
		}
	}
	return input;
}

int main()
{
	string input;
	string curr,temp,left,right;
	int p, result;
	bool findQ;
	set<string> s;
	while (cin>>input)
	{
		input = replaceAll(input,"N",'R','L');
		while (input.contains("RN")) {
			input = input.replaceAll("RN", "N");
		}
		while (input.contains("NL")) {
			input = input.replaceAll("NL", "N");
		}
		input = input.replaceAll("N+", "X");
		sysout(input.length());
		cout << result << endl;
	}
	return 0;
}