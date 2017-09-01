#include <iostream>
#include <string>
using namespace std;

int filterRepeat(long input)
{
	int arr[] = { -1,-1,-1,-1,-1,-1,-1,-1,-1,-1 };
	int result;
	int temp = input;
	int len = 0;
	while (temp != 0)
	{
		temp = temp / 10;
		len++;
	}

	int* arrInput = new int[len];
	temp = input;
	for (int i = len-1; i >= 0; i--)
	{
		arrInput[i] = temp % 10;
		temp = temp / 10;
	}

	int currVal = 0;
	for (int i = 0; i < len; i++)
	{
		currVal = arrInput[i];
		if (arr[currVal] == -1)
		{
			arr[currVal] = i;
		}
		else
		{
			// ��ԭ��λ�õ��ٴγ���λ�ã��Ƿ��бȸ����ִ����
			for (int j = arr[currVal]+1; j <= i; j++)
			{
				if (arrInput[j] > currVal)
				{
					arr[currVal] = i;
					break;
				}
			}
		}
	}

	for (int i = 0; i < len; i++)
	{
		arrInput[i] = -1;
	}

	for (int i = 0; i < len; i++)
	{
		// �ѽ�������в�Ϊ-1��λ�õ����֣���䵽ԭ��������
		if (arr[i] != -1)
		{
			arrInput[arr[i]] = i;
		}
	}

	result = 0;
	temp = 1;
	for (int i = len-1; i >= 0; i--)
	{
		if (arrInput[i] != -1)
		{
			result = result + arrInput[i] * temp;
			temp = temp * 10;
		}
	}
	return result;
}

int main()
{
	long input;
	while (cin>>input)
	{
		cout << filterRepeat(input) << endl;
	}
	return 0;
}