/*
1) Create two classes: 
	class Node: definition of linked list node
        class mystack: Implementation of stack, Add Node* top as private data member. here top is like head node of linked list
2) Push: Insert node at starting in linked list logic
3) Pop:  Remove node from starting in linked list logic
*/
#include<iostream>
using namespace std;

class Node
{
public:
	int data;
	Node* next;
};

class stack
{
	Node* top;
public:
	stack()
	{
		top = nullptr;
	}
	void push(int x)
	{
		Node* temp = new Node();
		temp->data = x;
		temp->next = top;
		top = temp;
	}
	int pop()
	{
		Node* temp = top;
		top = top->next;
		return temp->data;
	}
	
	void print()
	{
		Node* temp = top;
		while (temp != nullptr)
		{
			cout<<"value is stack"<<temp->data<<endl;
			temp = temp->next;
		}
	}
};

int main()
{
	stack s;
	s.push(10);
	s.push(20);
	s.push(30);
	s.push(40);
	s.push(50);
	s.pop();
	s.print();
	cout<<"********************"<<endl;
	s.pop();
	s.print();
	return 0;
}
