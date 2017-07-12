#pragma once
#include <string>

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