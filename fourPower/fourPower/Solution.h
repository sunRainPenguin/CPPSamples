#pragma once
#include <iostream>
#include <math.h>
using namespace std;

class Solution
{
public:
	static bool isPowerOfFour(int num) {
		return  ((~(num^(int)(pow(4,0))))==-1?1:0 || (~(num ^ (int)(pow(4, 1)))) == -1 ? 1 : 0 || (~(num ^ (int)(pow(4, 2)))) == -1 ? 1 : 0 || (~(num ^ (int)(pow(4, 3)))) == -1 ? 1 : 0 || (~(num ^ (int)(pow(4, 4)))) == -1 ? 1 : 0 || (~(num ^ (int)(pow(4, 5)))) == -1 ? 1 : 0 || (~(num ^ (int)(pow(4, 6)))) == -1 ? 1 : 0 || (~(num ^ (int)(pow(4, 7)))) == -1 ? 1 : 0
			|| (~(num ^ (int)(pow(4, 8)))) == -1 ? 1 : 0 || (~(num ^ (int)(pow(4, 9)))) == -1 ? 1 : 0 || (~(num ^ (int)(pow(4, 10)))) == -1 ? 1 : 0 || (~(num ^ (int)(pow(4, 11)))) == -1 ? 1 : 0 || (~(num ^ (int)(pow(4, 12)))) == -1 ? 1 : 0 || (~(num ^ (int)(pow(4, 13)))) == -1 ? 1 : 0 || (~(num ^ (int)(pow(4, 14)))) == -1 ? 1 : 0 || (~(num ^ (int)(pow(4, 15)))) == -1 ? 1 : 0);
	}
};

