#pragma once
#include <vector>
#include <stack>

int myabs(int x);
float myfabs(float x);
void printPair(int* arr, size_t N, int sum);

/*相邻相同的元素只保留一个*/
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

void insert_(int *p, int index, int size, int value);

void printPair(int* arr, size_t N, int sum);

template<typename T>
void myswap(T& x, T& y)
{
	x = x + y;
	y = x - y;
	x = x - y;
}

void stackSort(std::stack<int>& s);

