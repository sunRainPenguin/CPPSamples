#pragma once
#include <string>
#include <iostream>
#include <unordered_map>
using namespace std;

class Solution {
public:
	bool canConstruct(string randomNote, string magazine) {
		int rLen = randomNote.length();
		int mLen = magazine.length();
		int tempPos = 0;
		unordered_map<char, int> map;
		if (rLen > mLen)
		{
			return false;
		}
		else if(rLen==0)
		{
			return true;
		}
		else 
		{
			char var = NULL;
			for (int i = 0; i < randomNote.length(); i++)
			{
				var = randomNote.at(i);
				// 先判断原先找到的var的位置
				if (map.find(var) != map.end())
				{
					tempPos = map[var] + 1;
					tempPos = magazine.find(var, tempPos);
					if (tempPos != string::npos)
					{
						map[var] = tempPos;		// 找到字符的话，更新HashMap
					}
					else
					{
						return false;		// 否则，找字符失败
					}
				}
				else
				{
					// 之前没有找过这个字符的话，就从头找起。找到，更新map；没找到，返回失败
					tempPos = magazine.find(var, 0);
					if (tempPos != string::npos)
					{
						map[var] = tempPos;
					}
					else
					{
						return false;
					}
				}
			}
		return true;
		}
	}
};

