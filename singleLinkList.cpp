#include "singleLinkList.h"
#include <iostream>
#include <random>
#include <chrono>

Node* creatRandomList(int size)
{
	Node *head = nullptr;
	Node* temp = nullptr;
	int i = 0;

	std::default_random_engine generator((unsigned)time(nullptr));
	std::uniform_int_distribution<int> distribution(0, 9);

	while (i++ < size)
	{
		temp = new Node(distribution(generator), head);
		head = temp;
	}
	return head;
}

void printList(Node* head)
{
	if (head != nullptr)
	{
		std::cout << head->data;
		head = head->next;
	}

	while (head != nullptr)
	{
		std::cout << " -> ";
		std::cout << head->data;
		head = head->next;
	}
	std::cout << std::endl;
}

Node* inverseList_recursion(Node* head) /*�ݹ�ʵ�ֵ���������*/
{
	if ((head == nullptr) || (head->next == nullptr))
	{
		return head;
	}

	Node* temp = head;
	head = head->next;
	Node* newHead = inverseList(head);   /*���˳�headָ��ԭ����β�����µ��ײ�����һջ֡ʱ��tail ָ�����ڶ���Ԫ��*/
	head->next = temp; /* 1 */          /*Ȼ���������˳�һջ֡ �˺�һջ֡����ִ���������*/
	temp->next = nullptr; /* 2 */
	return newHead;

}

Node* inverseList(Node* head) /*�ǵݹ�ʵ�ֵ���������*/
{
	if ((head == nullptr) || (head->next == nullptr))
	{
		return head;
	}
	Node* left = nullptr;
	Node* mid = head;
	head = head->next;
	while (head != nullptr)
	{
		mid->next = left;
		left = mid;
		mid = head;
		head = head->next;
	}
	mid->next = left;
	return mid;
}

/*vector ��ȫ����ģ��ջ   ����ջ��ȫ����ģ�����*/


/*Լɪ������*/
void Josephus(int size, int number)
{
	Node* head = new Node(1, nullptr);
	Node* last = head;
	for (int i = 1; i < size; ++i)
	{
		last->next = new Node(i, head);
	}

	while (head != head->next)
	{
		for (int j = 0; j < number; ++j)
		{
			head = head->next;
		}
		head->next = head->next->next;
	}
	std::cout << head->data;
}

void sortList(Node* head)
{
	if ((nullptr == head) || (nullptr == head->next))
	{
		return;
	}

	Node* pre = head;
	Node* post = head->next;

	int temp = 0;

	while (pre->next != nullptr)
	{
		while (post != nullptr)
		{
			if (pre->data > post->data)
			{
				temp = pre->data;
				pre->data = post->data;
				post->data = temp;
			}
			post = post->next;
		}
		pre = pre->next;
		post = pre->next;
	}
}