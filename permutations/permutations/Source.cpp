#include <iostream>
#include <iterator>
using namespace std;

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
	char chs[3] = { 'a','b','c' };
	permutaion(chs, 0, 2);
	return 0;
}