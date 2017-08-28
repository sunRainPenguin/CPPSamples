#include "Solution.h"

int main()
{
	vector<vector<char>> board = { {'a','a','a','a'},{ 'a','a','a','a' },{ 'a','a','a','a' },{ 'a','a','a','a' },{ 'b','c','d','e' },{ 'f','g','h','i' },{ 'j','k','l','m' },{ 'n','o','p','q' },{ 'r','s','t','u' },{ 'v','w','x','y' },{ 'z','z','z','z' }};// { { 'b','a','a','b','a','b' }, { 'a','b','a','a','a','a' }, { 'a','b','a','a','a','b' }, { 'a','b','a','b','b','a' },{ 'a','a','b','b','a','b' },{ 'a','a','b','b','b','a' },{ 'a','a','b','a','a','b' } };	// { {'o'},{'a'},{'t'},{'x'} }; { 'o','a','a','n' },{ 'e','t','a','e' },{ 'i','h','k','r' },{ 'i','f','l','v' }
	Solution solution;
	vector<string> inputs = { "aaaaaaaaaaaaaaai","aaaaaaaaaaaaaaaj","aaaaaaaaaaaaaaak","aaaaaaaaaaaaaaal","aaaaaaaaaaaaaaam","aaaaaaaaaaaaaaan","aaaaaaaaaaaaaaao","aaaaaaaaaaaaaaap" };
	vector<string> vecStr = solution.findWords(board, inputs);
	for (int i = 0; i < vecStr.size(); i++)
	{
		cout << vecStr[i] << endl;
	}
	return 0;
}
//
//["aabbb babba ababa aaaba babba aba", "abaabbbaaaaababbbaaaaabbbaab", "ababaababaaabbabbaabbaabbaba"]