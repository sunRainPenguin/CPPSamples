#include <iostream>
using namespace std;

struct Foo
{
	Foo() {}
	Foo(int) {}
	void fun(){}
};
int main(void)
{
	Foo a(10);
	a.fun();
	Foo b;
	b.fun();
	return 0;
}