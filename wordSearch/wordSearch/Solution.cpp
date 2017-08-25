#include "Solution.h"

int main()
{
	vector<vector<char>> board = { {'o','a','a','n'},{'e','t','a','e'},{'i','h','k','r'},{'i','f','l','v'} };
	Solution solution;
	cout << solution.findWord(board, "oath") << endl;
	return 0;
}
