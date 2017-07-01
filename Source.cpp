#include<iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <memory>

// ���� - ����ʽ/����ʽ����
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

/*���ø������Ĵ洢����1 8 23������ 1 11 52˫���ȵķ���λ ָ������ С��λ��ʾ����þ���ֵ*/
float myfabs(float x)
{
	*(int*)&x = 0x7fffffff;
	return x;
} /*�����ǹ����
  NAN ����ȫ1 С��λ��ȫΪ0
  ����� ����ȫ1 С��λȫ0
  ����С ����ȫ0 С��λ��ȫΪ0*/

/*�ҳ�һ�����У���Ϊ����ֵ������*/
/*�����򣬺��ǰ�����м���


*/
void printPair(int* arr, size_t N, int sum)
{
	int count = 0;
	int tempSum = 0;
	std::sort(arr, arr + N);
	int * left = arr;
	int * right = arr + N - 1;
	int rightTemp = 0;
	int leftTemp = 0;
	while (left < right)
	{
		tempSum = (*left) + (*right);
		if ( tempSum == sum)
		{
			std::cout << ++count << ":" << *left << " " << *right << "\n";
			rightTemp = *right;
			leftTemp = *left;
			while ((left < right) && (*right == rightTemp))  
			{
				--right;
			}
			while ((left < right) && (*left == leftTemp)) /*������ͬ��Ԫ��*/
			{
				++left;
			}
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


/*������ͬ��Ԫ��ֻ����һ��*/
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
	int a[] = {1, 2, 3, 4, 5, 6, 6,5,4,3,2,3,2,4,7,7,7,5 };

	printPair(a, sizeof(a) / sizeof(int), 8);

	system("pause");
	return 0;
}

