#include "TrieNode.h"


int main()
{
	TrieNode* root = new TrieNode();

	root->insertInTrie(root,"a");
	root->insertInTrie(root, "all");
	root->insertInTrie(root, "als");
	root->insertInTrie(root, "as");
	cout << root->searchInTrie(root, "a") << endl;
	root->tranversal(root, "");
	return 0;
}