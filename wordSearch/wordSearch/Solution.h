#pragma once
#include <vector>
#include <string>
#include <stack>
#include <iostream>
#include <algorithm>
using namespace std;

struct Pos {
	int x;
	int y;
};

//���սṹ�����ַ���str���ֵ�˳������
bool cmp(const string a, const string b)
{
	if (strcmp(a.c_str(), b.c_str()) < 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

class Solution {
public:
	vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
		vector<string> result;
		for (int i = 0; i < words.size(); i++)
		{
			if (findWord(board, words[i]) && find(result.begin(), result.end(), words[i])==result.end())
			{
				result.push_back(words[i]);
			}
		}
		sort(result.begin(), result.end(),cmp);
		return result;
	}


	bool findWord(vector<vector<char>> board, string target)
	{
		stack<Pos> stackPos;
		vector<vector<bool>> visited;

		if (board.empty())
		{
			return false;
		}
		int i = 0;
		int j = 0;
		vector<bool> tempVec;
		while (i<board.size())
		{
			tempVec.clear();
			j = 0;
			while (j < board[0].size())
			{
				tempVec.push_back(false);
				j++;
			}
			visited.push_back(tempVec);
			i++;
		}

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
		i = 0;
		j = 0;
		int x = 0;
		int y = 0;
		int count = 0;
		int count2 = 0;
		bool found = false;
		while (true)
		{
			count++;
			if (board[i][j]==target[0])
			{
				if (target.length() == 1)
				{
					return true;
				}

				start = { i,j };
				stackPos.push(start);
				visited[i][j] = true;

				index = 1;	// ���ҵ��˵�һ����ĸ֮��index��Ϊ1
				while (!stackPos.empty())
				{
					count2++;
					temp = stackPos.top();
					x = temp.x;
					y = temp.y;

					// ��4���������target[index]
					found = false;
					while (direction < 4)
					{
						switch (direction)
						{
						case 0:
							if (x != 0 && !visited[x-1][y])
							{
								if (board[x-1][y] == target[index])
								{
									temp = {--x,y};
									stackPos.push(temp);
									visited[x][y] = true;
									index++;
									found = true;
								}
							}
							break;
						case 1:
							if (y != numC - 1 && !visited[x][y+1])
							{
								if (board[x][y+1] == target[index])
								{
									temp = { x,++y };
									stackPos.push(temp);
									visited[x][y] = true;
									index++;
									found = true;
								}
							}
							break;
						case 2:
							if (x != numR - 1 && !visited[x + 1][y])
							{
								if (board[x + 1][y] == target[index])
								{
									temp = { ++x,y };
									stackPos.push(temp);
									visited[x][y] = true;
									index++;
									found = true;
								}
							}
							break;
						case 3:
							if (y != 0 && !visited[x][y-1])
							{
								if (board[x][y - 1] == target[index])
								{
									temp = { x,--y };
									stackPos.push(temp);
									visited[x][y] = true;
									index++;
									found = true;
								}
							}
						default:
							break;
						}
						if (found)
						{
							if (index == target.length())
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
						visited[temp.x][temp.y] = false;
						index--;

						// ���ջ��ÿ���ڵ㶼����һ���ڵ�����һ��������ֱ�ӽ�������
						while (!stackPos.empty() && temp.y == stackPos.top().y - 1)
						{
							temp = stackPos.top();
							stackPos.pop();
							visited[temp.x][temp.y] = false;
							index--;
						}

						// ����Ѿ���ջ���·���ų��ˣ���Ҫ����ѡ���һ���ַ�
						if (stackPos.empty())
						{
							direction = 0;
							break;
						}

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
					}
					else
					{
						direction = 0;
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


class TrieNode {
public:
	bool is_end;
	vector<TrieNode*> children;
	TrieNode() {
		is_end = false;
		children = vector<TrieNode*>(26, NULL);
	}
};

// ���˵�����
//class Trie {
//public:
//	TrieNode* getRoot() { return root; }
//	Trie(vector<string>& words) {
//		root = new TrieNode();
//		for (int i = 0; i<words.size(); ++i)
//			addWord(words[i]);
//	}
//	void addWord(const string& word) {
//		TrieNode* cur = root;
//		for (int i = 0; i<word.size(); ++i) {
//			int index = word[i] - 'a';
//			if (cur->children[index] == NULL)
//				cur->children[index] = new TrieNode();
//			cur = cur->children[index];
//		}
//		cur->is_end = true;
//	}
//private:
//	TrieNode* root;
//};
//
//class Solution {
//public:
//	vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
//		Trie* trie = new Trie(words);
//		TrieNode* root = trie->getRoot();
//		set<string> result_set;
//		for (int x = 0; x<board.size(); ++x)
//			for (int y = 0; y<board[0].size(); ++y)
//				findWords(board, x, y, root, "", result_set);
//
//		vector<string> result;
//		for (auto it : result_set)    result.push_back(it);
//		return result;
//	}
//private:
//	void findWords(vector<vector<char>>& board, int x, int y, TrieNode* root, string word, set<string>& result) {
//		if (x<0 || x >= board.size() || y<0 || y >= board[0].size() || board[x][y] == ' ') return;
//
//		if (root->children[board[x][y] - 'a'] != NULL) {
//			word = word + board[x][y];
//			root = root->children[board[x][y] - 'a'];
//			if (root->is_end) result.insert(word);
//			char c = board[x][y];
//			board[x][y] = ' ';
//			findWords(board, x + 1, y, root, word, result);
//			findWords(board, x - 1, y, root, word, result);
//			findWords(board, x, y + 1, root, word, result);
//			findWords(board, x, y - 1, root, word, result);
//			board[x][y] = c;
//		}
//	}
//};