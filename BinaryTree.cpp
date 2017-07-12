#include "BinaryTree.h"
#include <iostream>
#include <deque>


void pre_order_access(BinaryTree* pRoot)//�������   �ȡ��С�������Ը��ڵ���˵��
{
	if (pRoot != nullptr)
	{
		std::cout << pRoot->m_value << "    ";   //�ȷ��ʸ��ڵ�
		pre_order_access(pRoot->left);     //������
		pre_order_access(pRoot->right);    //������
	}
}

void mid_order_access(BinaryTree* pRoot)  //��������
{
	if (pRoot != nullptr)
	{                                                                 //1����������ﶨ��int i;  
		mid_order_access(pRoot->left);   //�ȷ���������                  
		std::cout << pRoot->m_value << "    ";  //���ʸ��ڵ�            //2���������i��ֵ ipRoot->m_value
		mid_order_access(pRoot->right);   //����������            //3����ĩβΪi��ֵ����ô���շ��ص�i��ֵ���Ǹ��ڵ��ֵ i
	}                                                             //4����Ȼ���ڲ��i ���ȱ���ֵ
}

void post_order_access(BinaryTree* pRoot)  //��������
{
	if (pRoot != nullptr)
	{
		post_order_access(pRoot->left);   //�ȷ���������
		post_order_access(pRoot->right);   //Ȼ�����������
		std::cout << pRoot->m_value << "    ";   //�����ڵ�
	}
}

BinaryTree* creatBinaryTree(int arr[], int i, int n)   //�ݹ��������һ����ȫ������  
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