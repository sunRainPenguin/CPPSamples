#pragma once
class Solution
{
public:
	bool isUgly(int num) 
	{
		if (num == 1)
		{
			return true;
		}
		else if(num==0)
		{
			return false;
		}
		// ʹ��2-5֮��������ֽ������������ʹ����3������û�г��������num��Ϊ1�������ʾ����2,3,5֮�⻹��������������
		for (int i = 2; i <= 5; i++)
		{
			while (num%i==0)
			{
				num = num / i;
			}
		}
		if (num == 1)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
};

