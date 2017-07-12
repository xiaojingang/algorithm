#pragma once
struct  Node;

Node* creatRandomList(int size);

void printList(Node* head);

Node* inverseList(Node* head);

Node* inverseList_recursion(Node* head);

struct Node
{
	int data;
	Node* next;
	Node(int x, Node* p) : data(x), next(p)
	{

	}
};

void Josephus(int size, int number);

void sortList(Node* head);