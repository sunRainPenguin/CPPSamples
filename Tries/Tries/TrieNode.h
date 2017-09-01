#pragma once
#include <vector>
#include <string>
#include <iostream>
using namespace std;

class TrieNode
{
public:
	char data;
	bool isEndOfString;
	vector<TrieNode*> children;

	TrieNode(char c)
	{
		isEndOfString = false;
		data = c;
	}

	// ����ĳ���ڵ�ĺ��ӽڵ�
	TrieNode* subNode(char c)
	{
		if (!children.empty())
		{
			for (int i = 0; i < children.size(); i++)
			{
				if (children[i]->data == c)
				{
					return children[i];
				}
			}
		}
		return NULL;
	}

};

class Trie 
{
private:
	TrieNode* root;

public:
	Trie()
	{
		root = new TrieNode(' ');
	}
	
	// ����ǰ׺��
	void insertInTrie(string s)
	{
		if (s.empty())
		{
			root->isEndOfString = true;
			return;
		}
		TrieNode* currNode = root;
		int index = 0;
		TrieNode* tempNode = NULL;
		while (index<s.length())
		{
			tempNode = currNode->subNode(s[index]);
			if (tempNode != NULL)
			{
				currNode = tempNode;
			}
			else
			{
				tempNode = new TrieNode(s[index]);
				currNode->children.push_back(tempNode);
				currNode = tempNode;
			}
			index++;
		}
		currNode->isEndOfString = true;
	}

	// ����
	bool searchInTries(string s)
	{
		if (s.empty() && root->isEndOfString)
		{
			return true;
		}

		if (s[0] != root->data)
		{
			return false;
		}
		else
		{
			int index = 1;
			TrieNode* finded = root;
			while (index<s.length())
			{
				finded = finded->subNode(s[index]);
				if (finded == NULL)
				{
					return false;
				}
				index++;
			}
			if (finded != NULL && finded->isEndOfString)
			{
				return true;
			}
			else
			{
				return false;
			}
		}
	}
};

