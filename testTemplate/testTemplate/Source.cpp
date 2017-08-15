template<class T> class BigNumber{
	int n;
public:
	BigNumber(T i):n(i) {}
	BigNumber operator +(BigNumber b)
	{
		return BigNumber(n+b.n);
		__super
	}
};

int main()
{
	BigNumber<int> b1(1);
	BigNumber<int> b2(2);
	b2+2;
	return 0;
}