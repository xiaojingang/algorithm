#include<iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <memory>

// 单例 - 懒汉式/饿汉式公用
class Singleton
{
public:
	static Singleton* GetInstance();
	
	void func()
	{
		std::cout << "this is from singleton";
	}

private:
	Singleton() {}  // 构造函数（被保护）

private:
	static Singleton *m_pSingleton;  // 指向单例对象的指针
};

// 单例 - 饿汉式
Singleton *Singleton::m_pSingleton = new Singleton();

Singleton *Singleton::GetInstance()
{
	return m_pSingleton;
}

class S
{
	int i;
	std::string s;
public:
	S(int x, std::string y) :i(x), s(y)
	{

	}
	S() = default;
	void operator+(S y)
	{
		std::cout << "inner call";
	}
};

class Base
{
public:
	void func()
	{
		std::cout << "hello from Base\n";
	}
};

class Derive :private Base
{
public:
	using Base::func;
};

float myfabs(float x)
{
	*(int*)&x = 0x7fffffff;
	return x;
}

void printPair(int* arr, size_t N, int sum)
{
	int count = 0;
	int tempSum = 0;
	std::sort(arr, arr + N);
	int * left = arr;
	int * right = arr + N - 1;
	while (left < right)
	{
		tempSum = (*left) + (*right);
		if ( tempSum == sum)
		{
			std::cout << ++count << ":" << *left << " " << *right << "\n";
			++left;
			--right;
		}
		else if (tempSum < sum)
		{
			++left;
		}
		else
		{
			--right;
		}
	}
	std::cout << count;
}

struct Foo { // object to manage
	Foo() { std::cout << "Foo ctor\n"; }
	Foo(const Foo&) { std::cout << "Foo copy ctor\n"; }
	Foo(Foo&&) { std::cout << "Foo move ctor\n"; }
	~Foo() { std::cout << "~Foo dtor\n"; }
};

struct D { // deleter
	D() {}
	D(const D&) { std::cout << "D copy ctor\n"; }
	D(D&) { std::cout << "D non-const copy ctor\n"; }
	D(D&&) { std::cout << "D move ctor \n"; }
	void operator()(Foo* p) const {
		std::cout << "D is deleting a Foo\n";
		delete p;
	};
};


template<typename T>
void _unique(std::vector<T>& myvector)
{
	T* p = myvector.data();

	T* q = p;

	T* last = p + myvector.size();

	int num = 0;

	while (p < last)
	{
		while (((p + 1) < last) && (*p == *(p + 1)))
		{
			++p;
		}
		*q++ = *p++;
		++num;
	}

	myvector.resize(num);
}


int main()
{
	std::vector<int> myvector{1,1,1,1,1,1,1,1,1,1};

	_unique(myvector);
	
	/*myvector.erase(std::unique(myvector.begin(), myvector.end()), myvector.end()); */

	for (auto &i : myvector)
	{
		std::cout << i << "   ";
	}

	system("pause");
	return 0;
}

