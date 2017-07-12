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
	Singleton() {}  // ���캯������������

private:
	static Singleton *m_pSingleton;  // ָ���������ָ��
};

// ���� - ����ʽ
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