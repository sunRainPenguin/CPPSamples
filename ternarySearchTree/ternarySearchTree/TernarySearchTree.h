#pragma once
#include <string>
#include <iostream>
using namespace std;

class TSTNode
{
public:
	char data;
	bool is_end;
	TSTNode* left;
	TSTNode* mid;
	TSTNode* right;
	TSTNode();
	
	static TSTNode* insertInTSTNode(TSTNode* curr, string word, int position);
	static bool searchInTSTNode(TSTNode* curr, string word, int position);
	/*static void displayAllWords(TSTNode* root, string word, int i);*/
};

