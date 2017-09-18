#include<iostream>
using namespace std;
class A {
public:
	int xA;
	virtual void fun1() { cout << "in A's fun1" << endl; }
	void fun2() { cout << "in A's fun2" << endl; }
};
class B :public A {
public:
	int xB;
	void fun1() { cout << "in B's fun1" << endl; }
	void fun2() { cout << "in B's fun2" << endl; }
};
int main()
{
	B b;
	A* pa = &b;
	pa->fun1();
	pa->fun2();
	
	system("pause");
}