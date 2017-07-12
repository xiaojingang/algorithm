#pragma once

struct BinaryTree
{
	int m_value;
	BinaryTree* left;
	BinaryTree* right;
};

void pre_order_access(BinaryTree* pRoot);
void mid_order_access(BinaryTree* pRoot);
void post_order_access(BinaryTree* pRoot);
BinaryTree* creatBinaryTree(int arr[], int i, int n);   //递归的来构造一棵完全二叉树 

void level_access(BinaryTree* pRoot);

int heightRecur(BinaryTree* pRoot);

int height(BinaryTree* pRoot);

