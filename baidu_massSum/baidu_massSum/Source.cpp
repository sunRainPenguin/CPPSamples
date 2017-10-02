#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
using namespace std;

int findMaxMolecules(int massA, int massB, int massC, int massD, int massX)
{
	int mc = 2 * massC;
	int md = 2 * massD;
	stack<int> s;

	vector<int> vecm;
	vecm.push_back(massA);
	vecm.push_back(massB);
	vecm.push_back(mc);
	vecm.push_back(md);
	sort(vecm.begin(), vecm.end());

	int sum = 0;
	int re = 0;

	int i = 0;
	while (i<4)
	{
		while (sum + vecm[i] <= massX)
		{
			s.push(vecm[i]);
			sum += vecm[i];
			re++;
			if (sum == massX)
			{
				return re;
			}
		}
		if (i <= 2 && massX - sum > vecm[i + 1])
		{
			s.push(vecm[i + 1]);
			sum += vecm[i + 1];
			re++;
		}
		else
		{
			sum = sum - s.top();
			s.pop();
			re--;
			i++;
		}
	}
	if (sum != massX)
	{
		return 0;
	}
	return re;
}

int main()
{
	cout << findMaxMolecules(2, 4, 1, 1, 11) << endl;
	return 0;
}
