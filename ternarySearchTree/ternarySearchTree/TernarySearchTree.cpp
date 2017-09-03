#include "TernarySearchTree.h"

TSTNode::TSTNode():data(' '),is_end(false),left(nullptr),mid(nullptr),right(nullptr)
{
}

TSTNode * TSTNode::insertInTSTNode(TSTNode * curr, string word, int position)
{
	if (curr == NULL)
	{
		curr = new TSTNode();
		curr->data = word[position];
		if (position >= word.length() - 1)
		{
			curr->is_end = true;
			return curr;
		}
		curr->mid = insertInTSTNode(curr->mid, word, position+1);
		return curr;
	}
	else if(word[position]==curr->data)
	{
		if (position >= word.length() - 1)
		{
			curr->is_end = true;
			return curr;
		}
		curr->mid = insertInTSTNode(curr->mid, word, position + 1);
	}
	else if (word[position] < curr->data)
	{
		curr->left = insertInTSTNode(curr->left, word, position);
	}
	else if (word[position] > curr->data)
	{
		curr->right = insertInTSTNode(curr->right, word, position);
	}
	return curr;
}

bool TSTNode::searchInTSTNode(TSTNode * curr, string word, int position)
{
	if (curr == NULL)
	{
		return false;
	}
	else
	{
		if (word[position] < curr->data)
		{
			return searchInTSTNode(curr->left, word, position);
		}
		else if (word[position] > curr->data)
		{
			return searchInTSTNode(curr->right, word, position);
		}
		else
		{
			if (curr->is_end && position == word.length() - 1)
			{
				return true;
			}
			else
			{
				if (position != word.length() - 1)
				{
					return searchInTSTNode(curr->mid, word, position + 1);
				}
				else
				{
					return false;
				}
			}
		}
	}
	return false;
}

// 这段遍历有问题
//void TSTNode::displayAllWords(TSTNode * root, string word, int i)
//{
//	if (root == NULL)
//	{
//		return;
//	}
//	displayAllWords(root->left,word,i);
//	if (word.empty())
//	{
//		word.push_back('0');
//	}
//	while (word.length()-1  < i)
//	{
//		word.push_back('0');
//	}
//	word[i] = root->data;
//	if (root->is_end)
//	{
//		cout << word << endl;
//	}
//	i++;
//	displayAllWords(root->left, word, i);
//	i--;
//	displayAllWords(root->right, word, i);
//}
