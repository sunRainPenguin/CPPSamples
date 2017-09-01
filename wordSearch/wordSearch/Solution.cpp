#include "Solution.h"

int main()
{
	vector<vector<char>> board = { { 'o','a','a','n' },{ 'e','t','a','e' },{ 'i','h','k','r' },{ 'i','f','l','v' } };// { { 'b','a','a','b','a','b' }, { 'a','b','a','a','a','a' }, { 'a','b','a','a','a','b' }, { 'a','b','a','b','b','a' },{ 'a','a','b','b','a','b' },{ 'a','a','b','b','b','a' },{ 'a','a','b','a','a','b' } };	// { {'o'},{'a'},{'t'},{'x'} }; 
	Solution solution;
	vector<string> inputs = { "oath","pea","eat","rain"};
	vector<string> vecStr = solution.findWords(board, inputs);
	for (int i = 0; i < vecStr.size(); i++)
	{
		cout << vecStr[i] << endl;
	}
	return 0;
}
//
//["aabbb babba ababa aaaba babba aba", "abaabbbaaaaababbbaaaaabbbaab", "ababaababaaabbabbaabbaabbaba"]