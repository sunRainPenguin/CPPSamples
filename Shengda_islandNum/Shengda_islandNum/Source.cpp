#include <iostream>
using namespace std;

void visit(int i, int j, int n, int m, char** mat)
{
	if (mat[i][j] == '1')
	{
		mat[i][j] = 0;
		if (i - 1 >= 0)
		{
			visit(i - 1, j, n, m, mat);
		}
		if (j + 1 < m)
		{
			visit(i, j + 1, n, m, mat);
		}
		if (i + 1 < n)
		{
			visit(i + 1, j, n, m, mat);
		}
		if (j - 1 >= 0)
		{
			visit(i, j - 1, n, m, mat);
		}
	}
	else
	{
		return;
	}
}

int main()
{
	int n = 0;
	int m = 0;
	char** mat = NULL;
	int result = 0;
	while (cin>>n>>m)
	{
		if (n > 500 || n < 0 || m < 0 || m>500)
		{
			cout << 0 << endl;
			continue;
		}
		result = 0;
		mat = new char*[n];
		for (int i = 0; i < n; i++)
		{
			mat[i] = new char[m];
			for (int j = 0; j < m; j++)
			{
				cin>>mat[i][j];
			}
		}


		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				if (mat[i][j] == '1')
				{
					result++;
					visit(i, j, n, m, mat);
				}
			}
		}
		
		cout << result << endl;
	}
	return 0;
}