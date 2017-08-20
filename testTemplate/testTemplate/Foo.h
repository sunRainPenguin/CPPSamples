#pragma once
template<class T> class Foo
{
private:
	T tVar;
public:
	Foo(T t) : tVar(t) {}
};

template<class T> class FooDerived:public Foo<T>
{
public:
	FooDerived(T x);
};
