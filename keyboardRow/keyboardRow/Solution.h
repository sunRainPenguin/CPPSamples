#pragma once
#include <vector>
#include <string>
#include <regex>
#include <unordered_map>
using namespace std;

class Solution
{
public:
	vector<string> findWords(vector<string>& words) 
	{
		vector<string> result;
		string word;
		for (int i = 0; i < words.size(); i++)
		{
			word = words[i];
			if (inSameLine(word))
			{
				result.push_back(word);
			}
		}
		return result;
	}

	bool inSameLine(string word)
	{
		if (word.length() == 0 ||word.length()==1)
		{
			return true;
		}

		unordered_map<char, int> mapKeyboardLine = { { 'q',1 },{ 'w',1 },{ 'e',1 },{ 'r',1 },{ 't',1 },{ 'y',1 },{ 'u',1 },{ 'i',1 },{ 'o',1 },{ 'p',1 },
		{ 'a',2 },{ 's',2 },{ 'd',2 },{ 'f',2 },{ 'g',2 },{ 'h',2 },{ 'j',2 },{ 'k',2 },{ 'l',2 },
		{ 'z',3 },{ 'x',3 },{ 'c',3 },{ 'v',3 },{ 'b',3 },{ 'n',3 },{ 'm',3 },
		{ 'Q',1 },{ 'W',1 },{ 'E',1 },{ 'R',1 },{ 'T',1 },{ 'Y',1 },{ 'U',1 },{ 'I',1 },{ 'O',1 },{ 'P',1 },
		{ 'A',2 },{ 'S',2 },{ 'D',2 },{ 'F',2 },{ 'G',2 },{ 'H',2 },{ 'J',2 },{ 'K',2 },{ 'L',2 },
		{ 'Z',3 },{ 'X',3 },{ 'C',3 },{ 'V',3 },{ 'B',3 },{ 'N',3 },{ 'M',3 } };
		int targetLine = mapKeyboardLine[word[0]];
		int i = 1;
		char c = NULL;
		while (i<word.length())
		{
			c = word[i];
			if (mapKeyboardLine[c] == targetLine)
			{
				i++;
			}
			else
			{
				return false;
			}
		}
		return true;

		// 正则表达式简短，但是在解决目前问题上，效率极低
		//const std::regex pattern("[qwertyuiopQWERTYUIOP]*|[asdfghjklASDFGHJKL]*|[zxcvbnmZXCVBNM]*");
		//return regex_match(word, pattern);
	}
};

