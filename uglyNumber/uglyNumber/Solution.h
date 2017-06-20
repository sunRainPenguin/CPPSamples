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
		// 使用2-5之间的质数分解质因数，如果使用这3个质数没有除尽（最后num不为1），则表示除了2,3,5之外还有其他的质因数
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

