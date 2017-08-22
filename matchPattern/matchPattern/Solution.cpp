#include "Solution.h"



int main()
{
	int T[] = { 1,2,3,4,5,6 };
	int P[] = { 3,4,5 };
	Solution solution;
	cout << solution.bruteForceMatch(T, 6, P, 3) << endl;

	string T1 = "I am a fool.";
	string P1 = "fool";
	solution.Rabin_Karp_search(T1, P1, 101, 16);
	cout << "KMP Ëã·¨£º" << solution.KMP(T1.c_str(), T1.length(), P1.c_str(), P1.length(), solution.Prefix_Table(P1.c_str(), P1.length())) << endl;
	solution.BoyerMoore(P1.c_str(), P1.length(), T1.c_str(), T1.length());

	Automata automata;
	cout << automata.isMatched("b") << endl;
	return 0;
}
