#include <iostream>
#include <iterator>
#include <algorithm>
using namespace std;

template<class	T>
void STLpermutations(T list[], int k, int m)
{
	sort(list, list + m+1);
	do 
	{
		copy(list, list + m + 1, ostream_iterator<T>(cout, ""));
		cout << endl;
	} while (next_permutation(list, list + m + 1));
}

template<class T>
void permutaion(T list[], int k, int m)
{
	if (k == m)
	{
		std::ostream_iterator<char> out_it(std::cout);
		copy(list, list + m + 1, out_it);
		cout << endl;
	}
	else
	{
		for (int i = k; i <=m; i++)
		{
			swap(list[k], list[i]);
			permutaion(list, k + 1, m);
			swap(list[k], list[i]);
		}
	}
}

int main()
{
	char chs[3] = { 'b','a','c' };
	permutaion(chs, 0, 2);
	STLpermutations(chs, 0, 2);
	return 0;
}