#include<iostream>
using namespace std;

class Node
{
public:	
	int data;
	Node* next;
};


class queue
{
	Node *front = NULL;
	Node *rear = NULL;

public:
	void enqueue(int data) //Insert elements in Queue
	{
		Node* temp = new Node();
		temp->data = data;
		temp->next = NULL;
		if((rear==NULL)&&(front==NULL)) //first node
		{
			front = rear = temp;
			
		}
		else
		{
			rear->next = temp;
			rear = temp;
		}
	} 
	void dequeue() // Delete an element from Queue
	{
		Node* temp;
		temp = front;
		if((front==NULL)&&(rear==NULL))
			printf("\nQueue is Empty");
		else if(front == rear)
		{
			front = rear = NULL;
			free(temp);
		}
		else{
			front = front->next;
			free(temp);
		}
		
		
	}
	void print()
	{ 
		// Print the elements of Queue
		Node* temp;
		temp = front;
		while(temp != nullptr)
		{
			cout<<temp->data<<endl;
			temp = temp->next;
		}
		
	}
};
int main()
{
	queue q1;
	q1.enqueue(10);
	q1.enqueue(20);
	q1.enqueue(30);
	q1.print();
	q1.dequeue();
	q1.print();
	return 0;
}
