#include "Foo.h"

template<class X> class BigNumber{
	int n;
public:
	BigNumber(X i):n(i) {}
	BigNumber operator +(BigNumber b)
	{
		return BigNumber(n+b.n);
	}
};

int main()
{
	BigNumber<int> b1(1);
	BigNumber<int> b2(2);
	b2+2;

	FooDerived<int> d(5);
	return 0;
}