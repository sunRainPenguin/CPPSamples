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

void TSTNode::displayAllWords(TSTNode * root, string prefix)
{
	string temp = "";
	if (root != NULL)
	{
		temp = prefix + root->data;
		if (root->is_end)
		{
			cout << temp << endl;
		}
		displayAllWords(root->left, prefix);
		displayAllWords(root->mid, temp);
		displayAllWords(root->right, prefix);
	}
}