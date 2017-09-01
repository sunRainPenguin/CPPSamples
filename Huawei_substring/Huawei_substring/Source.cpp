#include <iostream>
#include <string>
using namespace std;

void ConvertStr(char *str, char* output)
{
	cout << output << endl;
	int len = 0;
	string result = "";
	while (str[len]!='\0')
	{
		if (len > 20)
		{
			output = "ERROR!";
			return;
		}
		if ((str[len] >= '0'  && str[len] <= '9') || (str[len] >= 'a' && str[len] <= 'z') || (str[len] >= 'A' && str[len] <= 'Z'))
		{
			if (len % 2 == 0)
			{
				result.insert(result.end(),str[len]);
			}
			len++;
		}
		else
		{
			output = "ERROR!";
			return;
		}
	}

	output = new char[result.length() + 1];
	for (int i = 0; i < result.length(); i++)
	{
		output[i] = result[i];
	}
	output[result.length()] = '\0';
	cout << output << endl;
}


int main()
{
	char input[] = "";
	char* output =0;
	while (cin >> input)
	{
		cout << *output << endl;
		ConvertStr(input, output);
		//cout << output << endl;
	}
	return 0;
}