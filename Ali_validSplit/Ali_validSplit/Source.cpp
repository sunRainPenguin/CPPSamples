#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <vector>
#include <set>
#include <map>
#include <iostream>
using namespace std;
#define MAX_DICT_LEN 255
#define MAX_STR 255

typedef struct simple_str {
	const char * str;
	int len;
} simple_str_t;


const char* subString(const char* str, int first, int count)
{
	string result = string(str);
	return result.substr(first, count).c_str();
}

void mincut(simple_str_t* str, simple_str_t* dict, int dict_len) {
	int lenCount[MAX_STR] = { 0 };		// 记录长度为i的字典单词
	vector<int> arrLen;		// 按升序记录字典单词可能的长度
	map<int,set<simple_str_t>> map_len_dicWord;	
	vector<int> result;

	// 构造map_len_dicWord
	for (int i = 0; i < dict_len; i++)
	{
		lenCount[dict[i].len] = 1;
		if (map_len_dicWord.find(dict[i].len) == map_len_dicWord.end())
		{
			set<simple_str> tempSet;
			tempSet.insert(tempSet.end(), dict[i]);
			map_len_dicWord[dict[i].len] = tempSet;
		}
		else
		{
			map_len_dicWord[dict[i].len].insert(map_len_dicWord[dict[i].len].end(), dict[i]);
		}
	}

	// 构造arrLen
	for (int i = 0; i < MAX_STR; i++)
	{
		if (lenCount[i] == 1)
		{
			arrLen.push_back(i);
		}
	}

	// 遍历arrLen
	int index = 0;
	int lengthW = 0;
	const char* strTemp;
	while (index < str->len)
	{
		for (int i = arrLen.size()-1; i >=0; i--)
		{
			lengthW = arrLen[i];
			strTemp = subString(str->str, index, lengthW);
			// 比较substr(index,count)是否等于set中的值
			for each (simple_str var in map_len_dicWord[lengthW])
			{
				if (strcmp(strTemp, var.str)==0)
				{
					result.push_back(index + lengthW - 1);
					index = index + lengthW;
				}
			}
		}
	}

	index = 0;
	for (int i = 0; i < str->len; i++)
	{
		if (index<result.size() && i == result[index])
		{
			cout << " ";
			index++;
		}
		else
		{
			cout << str[i].str;
		}
	}
}


int main(int argc, const char * argv[]) {
	char strS[MAX_STR];
	char dictStr[MAX_STR];
	int nDict;
	simple_str_t dict[MAX_DICT_LEN];
	simple_str_t srcStr;

	scanf("%s", strS);
	scanf("%d", &nDict);

	srcStr.str = strdup(strS);
	srcStr.len = strlen(strS);

	for (int i = 0; i < nDict; i++)
	{
		scanf("%s", strS);
		dict[i].str = strdup(strS);
		dict[i].len = strlen(strS);
	}

	mincut(&srcStr, dict, nDict);

	return 0;
}

