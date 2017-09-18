#include <iostream>
#include <stdlib.h>
#include <map>
#include <vector>
#include <string>
#include <memory>
#include <algorithm>
using namespace std;

// 可以进行移动构造和移动赋值操作
// 一般意义的复制构造和赋值或出错.但在函数中作为返回值却可以用
unique_ptr<int> GetVal() {
	unique_ptr<int> up(new int(88));
	return up;
}

void foo(int* p)
{
	std::cout << *p << std::endl;
}

class implementation
{
public:
	~implementation() { std::cout << "destroying implementation\n"; }
	void do_something() { std::cout << "did something\n"; }
};

int main()
{
	// auto类型推断，range for loop
	map<std::string, std::vector<int>> map;
	std::vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	map["one"] = v;

	for (const auto& kvp : map)
	{
		cout << kvp.first << std::endl;

		for (auto v : kvp.second)
		{
			std::cout << v << std::endl;
		}
	}

	bool f = nullptr;
	// int i = nullptr; // error: A native nullptr can only be converted to bool or, using reinterpret_cast, to an integral type

	// override、final
	class B
	{
	public:
		virtual void f(int) { std::cout << "B::f" << std::endl; }
	};

	class D : public B
	{
	public:
		virtual void f(int) override final { std::cout << "D::f" << std::endl; } // cannot be overriden by children
	};

	// 强类型枚举
	enum class Options { None, One, All };
	Options o = Options::All;

	// 智能指针,无法进行复制构造与赋值操作
	unique_ptr<int> ap(new int(88));
	//unique_ptr<int> one(ap); // 会出错
	//unique_ptr<int> two = one; //会出错

	unique_ptr<int> uPtr = GetVal();   //ok

	unique_ptr<int> up(new int(88));
	unique_ptr<int> uPtr2 = std::move(up); //这里是显式的所有权转移. 把up所指的内存转给uPtr2了,而up不再拥有该内存;move是C++11中的函数。

	unique_ptr<int> sp(new int(88));
	vector<unique_ptr<int> > vec;
	vec.push_back(std::move(sp));
	//vec.push_back( sp ); 这样不行,会报错的.
	//cout<<*sp<<endl;但这个也同样出错,说明sp添加到容器中之后,它自身报废了.


	std::unique_ptr<int> p1(new int(42));	// 与auto p3 = std::make_shared<int>(42); 等价
	std::unique_ptr<int> p2 = std::move(p1); // transfer ownership 

	if (p1)
		foo(p1.get());

	(*p2)++;

	if (p2)
		foo(p2.get());

	// shared_ptr所有权共享
	shared_ptr<implementation> sp1(new implementation());
	std::cout << "The Sample now has " << sp1.use_count() << " references\n";

	shared_ptr<implementation> sp2 = sp1;
	std::cout << "The Sample now has " << sp2.use_count() << " references\n";

	sp1.reset();
	std::cout << "After Reset sp1. The Sample now has " << sp2.use_count() << " references\n";

	sp2.reset();
	std::cout << "After Reset sp2.\n";

	// weak_ptr
	auto p = std::make_shared<int>(42);
	std::weak_ptr<int> wp = p;

	{
		auto sp = wp.lock();
		std::cout << *sp << std::endl;
	}
	p.reset();
	if (wp.expired())
		std::cout << "expired" << std::endl;

	// lambda
	std::vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);

	std::for_each(std::begin(v), std::end(v), [](int n) {std::cout << n << std::endl; });

	auto is_odd = [](int n) {return n % 2 == 1; };
	auto pos = std::find_if(std::begin(v), std::end(v), is_odd);
	if (pos != std::end(v))
		std::cout << *pos << std::endl;


	return 0;
}



