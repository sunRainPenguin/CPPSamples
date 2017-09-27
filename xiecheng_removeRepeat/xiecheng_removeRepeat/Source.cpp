#include <string>
#include <iostream>
#include <set>
using namespace std;

int main()
{
	string input;
	string output;
	set<char> setC;

	while (getline(cin, input))
	{
		setC.clear();
		output = "";
		for (int i = 0; i < input.length(); i++)
		{
			if (setC.find(input[i]) == setC.end())
			{
				output.push_back(input[i]);
				setC.insert(input[i]);
			}
		}
		cout << output << endl;
	}
	return 0;
}