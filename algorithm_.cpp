#include "algorithm_.h"
#include <algorithm>
#include <iostream>

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
		if (tempSum == sum)
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






/*���һ��Ԫ�ر�����ȥ*/
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

/*���0 ����  ���1 ȡ�� ����Լ� Ϊ0*/
int myabs(int x)
{
	int signBit = (x >> 31) & 0x1;   /*�õ�����λ*/
	int allBit = 0 - signBit;   /*�õ�ȫ0 ���� ȫ1��������*/
	int ret = x ^ allBit;   /*ȫ��ȡ�����߲���*/
	ret += signBit;  /*ȡ����1 ���� ��0*/
	return ret;
}


/*��������һ��ջ���м��������ջ��������*/
void stackSort(std::stack<int>& s)
{
	std::stack<int> t;
	int temp;
	t.push(s.top());
	s.pop();
	while (!s.empty())   /*s������С  �򵯳��������м������*/
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