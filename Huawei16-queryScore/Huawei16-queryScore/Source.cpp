#include <iostream>
#include <string>
#include <sstream>
using namespace std;

int findMax(int arr[], int n, int rangeLow, int rangeHigh)
{
	int max = arr[rangeLow - 1];
	for (int i = rangeLow-1; i <= rangeHigh-1; i++)
	{
		if (arr[i] > max)
		{
			max = arr[i];
		}
	}
	return max;
}

int main()
{
	int numStu = 0;
	int numOp = 0;
	char charOp = NULL;
	int value1 = 0;
	int value2 = 0;
	string result = "";
	int tempInt = 0;
	stringstream ss;

	while (cin >> numStu >> numOp)
	{
		result = "";
		int* arrScore = new int[numStu];
		int count = 0;
		while (count < numStu)
		{
			cin >> arrScore[count];
			count++;
		}

		count = 0;
		while (count < numOp)
		{
			cin >> charOp >> value1 >> value2;
			switch (charOp)
			{
			case 'Q':
				if (value1 <= value2)
				{
					tempInt = findMax(arrScore, numStu, value1, value2);
				}
				else
				{
					tempInt = findMax(arrScore, numStu, value2, value1);
				}
				ss.str(string());
				ss << tempInt;
				ss.flush();
				result = result + ss.str() + "\n";
				break;
			case 'U':
				arrScore[value1 - 1] = value2;
				break;
			default:
				break;
			}
			count++;
		}
		cout << result;
	}
	

	
	return 0;
}