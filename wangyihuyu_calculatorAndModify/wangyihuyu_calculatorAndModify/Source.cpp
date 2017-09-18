#include <iostream>
#include <string>
#include <cstring>
#include <stack>
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

string intToStr(int ii)
{
	stringstream ss;
	ss << ii;
	ss.flush();
	return ss.str();
}

int calculate(string s)
{
	stack<string> st;
	string temp;
	int i = 0;
	string currOp;
	int a1, a2;
	while (i<s.length())
	{
		if (s[i] == ')')
		{
			a1 = strToInt(st.top());
			st.pop();
			currOp = st.top();
			st.pop();
			a2 = strToInt(st.top());
			st.pop();

			if (currOp == "|")
			{
				st.push(intToStr(a1 | a2));
			}
			else if (currOp == "&")
			{
				st.push(intToStr(a1 & a2));
			}
			if (i == (s.length() - 1))
			{
				return strToInt(st.top());
			}
		}
		else if (s[i] != '(')
		{
			temp = "";
			temp.push_back(s[i]);
			st.push(temp);
		}
		i++;
	}
}

int main()
{
	int n,c;
	string* inputs = NULL;
	int* outputs = NULL;
	while (cin>>n)
	{
		c = 0;
		inputs = new string[n];
		outputs = new int[n];
		while (c<n)
		{
			cin >> inputs[c];
			c++;
		}
		c = 0;
		while (c<n)
		{
			cout << calculate(inputs[c]) << endl;
			c++;
		}
	}
	return 0;
}