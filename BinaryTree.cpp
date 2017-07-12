#include "BinaryTree.h"
#include <iostream>
#include <deque>


void pre_order_access(BinaryTree* pRoot)//先序遍历   先、中、后都是相对根节点来说的
{
	if (pRoot != nullptr)
	{
		std::cout << pRoot->m_value << "    ";   //先访问根节点
		pre_order_access(pRoot->left);     //左子树
		pre_order_access(pRoot->right);    //右子树
	}
}

void mid_order_access(BinaryTree* pRoot)  //中续遍历
{
	if (pRoot != nullptr)
	{                                                                 //1、如果在这里定义int i;  
		mid_order_access(pRoot->left);   //先访问左子树                  
		std::cout << pRoot->m_value << "    ";  //访问根节点            //2、在这里给i赋值 ipRoot->m_value
		mid_order_access(pRoot->right);   //访问右子树            //3、在末尾为i赋值，那么最终返回的i的值将是根节点的值 i
	}                                                             //4、虽然最内层的i 最先被赋值
}

void post_order_access(BinaryTree* pRoot)  //后续遍历
{
	if (pRoot != nullptr)
	{
		post_order_access(pRoot->left);   //先访问左子树
		post_order_access(pRoot->right);   //然后访问右子树
		std::cout << pRoot->m_value << "    ";   //最后根节点
	}
}

BinaryTree* creatBinaryTree(int arr[], int i, int n)   //递归的来构造一棵完全二叉树  
{
	BinaryTree* pRoot;
	if (i >= n)
		return nullptr;
	pRoot = (BinaryTree*)malloc(sizeof(BinaryTree));
	pRoot->m_value = arr[i];
	pRoot->left = creatBinaryTree(arr, 2 * i + 1, n);
	pRoot->right = creatBinaryTree(arr, 2 * i + 2, n);
	return pRoot;
}

void level_access(BinaryTree* pRoot)
{
	std::deque<BinaryTree*> BinaryQueue;
	BinaryQueue.push_back(pRoot);
	BinaryTree* front = nullptr;

	while (!BinaryQueue.empty())
	{
		front = BinaryQueue.front();
		BinaryQueue.pop_front();
		std::cout << front->m_value << "  ";
		if (nullptr != front->left)
		{
			BinaryQueue.push_back(front->left);
		}
		if (nullptr != front->right)
		{
			BinaryQueue.push_back(front->right);
		}
	}

	std::cout << std::endl;
}





int heightRecur(BinaryTree* pRoot)
{
	if (pRoot == nullptr)
	{
		return 0;
	}
		
	int leftH = height(pRoot->left);
	int rightH = height(pRoot->right);

	if (leftH < rightH)
	{
		return rightH + 1;
	}

	else
	{
		return leftH + 1;
	}
}

int height(BinaryTree* pRoot)
{
	return 0;
}