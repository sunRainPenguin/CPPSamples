#pragma once
#include <vector>
#include <string>
#include <stack>
#include <iostream>
using namespace std;

struct Pos {
	int x;
	int y;
};

class Solution {
public:
	//vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {

	//}

	bool findWord(vector<vector<char>> board, string target)
	{
		stack<Pos> stackPos;
		int numR = board.size();
		int numC = board[0].size();
		Pos start = {0,0};
		Pos temp = { 0,0 };
		int direction = 0;	// 0,1,2,3�ֱ��ʾ���ҷ����ϡ��ҡ��¡���
		int index = 0;		// ��ǰ����target�ĵڼ�����ĸ

		if (target.empty())
		{
			return false;
		}

		// �ҵ�����ĸ
		// �ҵ������return
		// �ҵ����λ�ã�return
		int i = 0;
		int j = 0;
		int x = 0;
		int y = 0;
		bool found = false;
		while (true)
		{
			if (board[i][j]==target[0])
			{
				index++;
				start = { x,y };
				stackPos.push(start);
				while (!stackPos.empty())
				{
					temp = stackPos.top();
					x = temp.x;
					y = temp.y;

					// ��4���������target[index]
					//direction = 0;
					found = false;
					while (direction < 4)
					{
						switch (direction)
						{
						case 0:
							if (x != 0)
							{
								if (board[x-1][y] == target[index])
								{
									temp = {--x,y};
									stackPos.push(temp);
									index++;
									found = true;
								}
							}
							break;
						case 1:
							if (x != numC - 1)
							{
								if (board[x][y+1] == target[index])
								{
									temp = { x,++y };
									stackPos.push(temp);
									index++;
									found = true;
								}
							}
							break;
						case 2:
							if (x != numR - 1)
							{
								if (board[x + 1][y] == target[index])
								{
									temp = { ++x,y };
									stackPos.push(temp);
									index++;
									found = true;
								}
							}
							break;
						case 3:
							if (y != 0)
							{
								if (board[x][y - 1] == target[index])
								{
									temp = { x,--y };
									stackPos.push(temp);
									index++;
									found = true;
								}
							}
						default:
							break;
						}
						if (found)
						{
							if (index == target.length() - 1)
							{
								return true;
							}
							else
							{
								break;
							}
						}
						direction++;
					}

					if (!found)
					{
						temp = stackPos.top();
						stackPos.pop();
						index--;
						if (temp.x == stackPos.top().x - 1)
						{
							direction = 1;
						}
						else if (temp.y == stackPos.top().y + 1)
						{
							direction = 2;
						}
						else if (temp.x == stackPos.top().x + 1)
						{
							direction = 3;
						}
						else if (temp.y == stackPos.top().y - 1)
						{
							direction = 0;
							return false;
						}
					}
				}
			}

			if (j < numC - 1)
			{
				j++;
			}
			else
			{
				if (i < numR - 1)
				{
					j = 0;
					i++;
				}
				else
				{
					return false;		// �������һ��λ��
				}
			}
		}
	}
};
