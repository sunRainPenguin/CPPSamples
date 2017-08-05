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
				// ���ж�ԭ���ҵ���var��λ��
				if (map.find(var) != map.end())
				{
					tempPos = map[var] + 1;
					tempPos = magazine.find(var, tempPos);
					if (tempPos != string::npos)
					{
						map[var] = tempPos;		// �ҵ��ַ��Ļ�������HashMap
					}
					else
					{
						return false;		// �������ַ�ʧ��
					}
				}
				else
				{
					// ֮ǰû���ҹ�����ַ��Ļ����ʹ�ͷ�����ҵ�������map��û�ҵ�������ʧ��
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

