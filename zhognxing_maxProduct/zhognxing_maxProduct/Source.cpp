#include <iostream>
using namespace std;

int notExceedMaxNums(int rows, int columns, int max, int** mat)
{
	int result = 0;
	int** tmat;
	tmat = new int*[rows];
	for (int i = 0; i < rows; i++)
	{
		tmat[i] = new int[columns];
	}

	int i = 0;
	int j = 0;
	int temp = 0;
	int pro = 1;
	while (i<rows)
	{
		pro = 1;
		while (j<columns)
		{
			if (i - 1 >= 0)
			{
				temp = pro * mat[i][j] * tmat[i - 1][j];
			}
			else
			{
				temp = pro * mat[i][j];
			}
			pro = pro * mat[i][j];
			tmat[i][j] = temp;
			j++;
			if (temp <= max)
			{
				result++;
			}
		}
		i++;
		j = 0;
	}

	return result;
}

int main()
{
	int rows, columns,maxPro,i,j;
	int** matrix;

	cin >> rows >> columns>>maxPro;
	matrix = new int*[rows];
	for (int i = 0; i < rows; i++)
	{
		matrix[i] = new int[columns];
	}

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			cin >> matrix[i][j];
		}
	}

	cout << notExceedMaxNums(rows, columns, maxPro, matrix) << endl;
	return 0;
}