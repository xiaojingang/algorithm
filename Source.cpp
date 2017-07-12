#include<iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <memory>
#include "singleLinkList.h"
#include "BinaryTree.h"
#include "algorithm_.h"
#include <stack>
#include <boost/regex.hpp> 
#include <boost/asio.hpp>

// 单例 - 懒汉式/饿汉式公用




using namespace boost;

void unique_again(std::vector<int>& vec)
{
	int* p = vec.data();
	int* q = p;
	int* last = p + vec.size();
	int newSize = 0;

	while (p < last)
	{
		while (((p + 1) < last) && (*p == *(p + 1)))
		{
			++p;
		}
		*q++ = *p++;
		++newSize;
	}
	
	vec.resize(newSize);
}

int main(int argc, char *argv[])
{
	int arr[] = { 8, 4, 10, 2, 6, 9, 11, 1, 3, 5, 7 };
	BinaryTree* proot = creatBinaryTree(arr, 0, sizeof(arr) / sizeof(int));
	//mid_order_access(proot);
	level_access(proot);
	std::cout << height(proot);
	std::cin.get();
	return 0;
}

