#pragma once
#include <vector>
#include <string>
#include <iostream>
using namespace std;

class TrieNode
{
private:
	bool isWord;
	TrieNode* children[26];		// 26��Сд��ĸ

public:
	TrieNode():isWord(false)
	{
		for (int i = 0; i < 26; i++)
		{
			children[i] = NULL;
		}
	}

	void insertInTrie(TrieNode* root, string word)
	{
		TrieNode* rootbak = root;
		int index = 0;
		int id = 0;
		int length = word.length();
		while (index<length)
		{
			id = word[index] - 'a';
			if (root->children[id] == NULL)
			{
				root->children[id] = new TrieNode();
			}
			root = root->children[id];
			index++;
		}
		root->isWord = true;
		root = rootbak;	//ָ��ָ����
	}

	bool searchInTrie(TrieNode* root, string word)
	{
		TrieNode* rootbak = root;
		bool result = false;
		int index = 0;
		int id = 0;
		int length = word.length();
		while (index<length)
		{
			id = word[index] - 'a';
			if (root->children[id] == NULL)
			{
				return false;
			}
			root = root->children[id];
			index++;
		}
		result = root->isWord;
		root = rootbak;	//ָ��ָ����
		return result;
	}

	void tranversal(TrieNode* root,string prefixs)
	{
		if (root != NULL)
		{
			if (root->isWord)
			{
				cout << prefixs << endl;
			}
			for (int i = 0; i < 26; i++)
			{
				if (root->children[i] != NULL)
				{
					prefixs.push_back('a' + i);
					tranversal(root->children[i], prefixs);
				}
			}
		}
	}
};

