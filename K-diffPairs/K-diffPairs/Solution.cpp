#include "Solution.h"
#include <iostream>
using namespace std;

int main()
{
	Solution solution;
	vector<int> input;
	//input.insert(input.end(),2);
	//input.insert(input.end(),8);
	//input.insert(input.end(),6);
	//input.insert(input.end(),9);
	//input.insert(input.end(),7);
	//input.insert(input.end(),4);
	//input.insert(input.end(),9);
	//input.insert(input.end(),0);
	//input.insert(input.end(),5);
	//input.insert(input.end(),4);
	input.insert(input.end(), 1);
	input.insert(input.end(), 3);
	input.insert(input.end(), 1);
	input.insert(input.end(), 4);
	input.insert(input.end(), 5);
	cout << solution.findPairs(input, 0) << endl;
	return 0;
}
