#include "algorithm_.h"
#include <algorithm>
#include <iostream>

/*利用浮点数的存储规则，1 8 23单精度 1 11 52双精度的符号位 指数阶码 小数位表示法求得绝对值*/
float myfabs(float x)
{
	*(int*)&x = 0x7fffffff;
	return x;
} /*三个非规格数
  NAN 阶码全1 小数位不全为0
  无穷大 阶码全1 小数位全0
  无穷小 解码全0 小数位不全为0*/

  /*找出一组数中，和为给定值的数对*/
  /*先排序，后从前后往中间找


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
		if (tempSum == sum)
		{
			std::cout << ++count << ":" << *left << " " << *right << "\n";
			rightTemp = *right;
			leftTemp = *left;
			while ((left < right) && (*right == rightTemp))
			{
				--right;
			}
			while ((left < right) && (*left == leftTemp)) /*跳过相同的元素*/
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






/*最后一个元素被挤出去*/
void insert_(int *p, int index, int size, int value)
{
	int i = size - 1;
	while (i >= index)
	{
		*(p + i) = *(p + i - 1);
		--i;
	}
	p[index] = value;
}

void del_(int *p, int index, int size)
{
	while (index < size - 1)
	{
		*(p + index) = *(p + index + 1);
		++index;
	}
	p[index] = 0;
}

/*异或0 保持  异或1 取反 异或自己 为0*/
int myabs(int x)
{
	int signBit = (x >> 31) & 0x1;   /*得到符号位*/
	int allBit = 0 - signBit;   /*得到全0 或者 全1的特殊数*/
	int ret = x ^ allBit;   /*全部取反或者不变*/
	ret += signBit;  /*取反加1 或者 加0*/
	return ret;
}


/*借助另外一个栈和中间变量来对栈进行排序*/
void stackSort(std::stack<int>& s)
{
	std::stack<int> t;
	int temp;
	t.push(s.top());
	s.pop();
	while (!s.empty())   /*s顶部的小  则弹出保存在中间变量里*/
	{
		if (s.top() < t.top())
		{
			temp = s.top();
			s.pop();
			while (!t.empty())
			{
				s.push(t.top());
				t.pop();
			}
			t.push(temp);
		}
		else
		{
			t.push(s.top());
			s.pop();
		}
	}
	while (!t.empty())   
	{
		s.push(t.top());
		t.pop();
	}

}