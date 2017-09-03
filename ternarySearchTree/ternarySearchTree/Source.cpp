#include "TernarySearchTree.h"

int main()
{
	TSTNode* root =  TSTNode::insertInTSTNode(NULL, "as", 0);
	TSTNode::insertInTSTNode(root, "at", 0);
	TSTNode::insertInTSTNode(root, "cup", 0);
	TSTNode::insertInTSTNode(root, "cute", 0);
	TSTNode::insertInTSTNode(root, "he", 0);
	TSTNode::insertInTSTNode(root, "i", 0);
	TSTNode::insertInTSTNode(root, "us", 0);
	cout << TSTNode::searchInTSTNode(root, "cu", 0) << endl;
	TSTNode::displayAllWords(root, "", 0);
	return 0;
}