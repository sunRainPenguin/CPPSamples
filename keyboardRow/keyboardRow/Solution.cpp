#include "Solution.h"
#include <fstream>
using namespace std;

/*
Note:
You may use one character in the keyboard more than once.
You may assume the input string will only contain letters of alphabet.
*/
int main()
{
	//ifstream input("input.txt");
	//vector<string> words;
	//string word;
	//while (input>>word)
	//{
	//	words.push_back(word);
	//}

	//Solution* solution = new Solution();
	//vector<string> result = solution->findWords(words);

	//ofstream output("output.txt");
	//for each (string var in result)
	//{
	//	output << var;
	//	output << endl;
	//}

	vector<string> inputWords = { "Hello", "Alaska", ""};
	vector<string> outputWords = (new Solution())->findWords(inputWords);
	return 0;
}
