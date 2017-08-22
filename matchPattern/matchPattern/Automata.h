#pragma once
#include <set>
using namespace std;

enum state
{
	state0,
	state1,
	noState
};

class Automata
{
public:
	state q0;
	set<int> A;
	set<char> Alpha;

	Automata()
	{
		q0 = state0;
		A = { 1 };
		Alpha = { 'a','b' };
	}

	// 迁移（迁移规则）
	state transit(state currState, char input)
	{
		switch (currState)
		{
		case state0:
			if (input == 'a')
			{
				return state1;
			}
			else if (input == 'b')
			{
				return state0;
			}
			break;
		case state1:
			if (input == 'a')
			{
				return state0;
			}
			else if (input == 'b')
			{
				return state1;
			}
			break;
		default:
			break;
		}

		return noState;
	}

	// 自动机匹配以奇数个相同'b'字符结尾的字符串
	bool isMatched(string target)
	{
		state tempState = q0;
		for (size_t i = 0; i < target.length(); i++)
		{
			if (tempState != noState)
			{
				tempState = transit(tempState, target[i]);
			}
		}
		if (tempState == state1)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
};