#pragma once
class Solution
{
public:
	bool isContinue(int* number, int length)
	{
		int max = number[0];
		int min = number[0];
		int continueLen = -1;
		for (int i = 0; i < length; i++)
		{
			if (number[i] > max)
			{
				max = number[i];
			}
			if (number[i] < min)
			{
				min = number[i];
			}
		}
		continueLen = max - min + 1;
		if (length != continueLen)
		{
			return false;
		}
		else
		{
			int* numArr = new int[continueLen];
			for (int i = 0; i < length; i++)
			{
				numArr[i] = 0;
			}
			for (int i = 0; i < length; i++) 
			{
				numArr[number[i] - min]++;
				if (numArr[number[i] - min] > 1)
				{
					return false;
				}
			}
			return true;
		}
	}
};

