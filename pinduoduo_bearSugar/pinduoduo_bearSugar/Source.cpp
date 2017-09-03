#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Bear
{
public:
	int ID;
	int fight;
	int hungery;
};

bool compare_fight(const Bear *a, const Bear *b)
{
	return (a->fight < b->fight);
}

bool compare_ID(const Bear *a, const Bear *b)
{
	return (a->ID < b->ID);
}

int main() {
	int bearNum = 0;
	int sugarNum = 0;
	int count = 0;
	int* energy = NULL;
	vector<Bear*> vecBear;
	while (cin>>bearNum>>sugarNum)
	{
		vecBear.clear();
		energy = new int[sugarNum];
		count = 0;
		while (count<sugarNum)
		{
			cin >> energy[count];
			count++;
		}

		count = 0;
		while (count<bearNum)
		{
			Bear* bear = new Bear();
			cin >> bear->fight >> bear->hungery;
			bear->ID = count;
			vecBear.push_back(bear);
			count++;
		}

		std::sort(energy, energy + sugarNum);
		std::sort(vecBear.begin(), vecBear.end(), compare_fight);

		// 假设已经按照战斗力升序排序、糖能量升序排序
		for (int i=bearNum-1; i>=0; i--)
		{
			for (int j = sugarNum-1; j>=0; j--)
			{
				if (energy[j] <= vecBear[i]->hungery && energy[j]>0)
				{
					vecBear[i]->hungery = vecBear[i]->hungery - energy[j];
					energy[j] = 0;
				}
			}
		}

		std::sort(vecBear.begin(), vecBear.end(), compare_ID);
		for (int i = 0; i < bearNum; i++)
		{
			cout << vecBear[i]->hungery << endl;
		}
	}
}