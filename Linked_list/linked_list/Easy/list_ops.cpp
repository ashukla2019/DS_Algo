#include <iostream>
using namespace std;

class NodeList
{
public:
	int data;
	NodeList* next;
};

NodeList* addAtEnd(NodeList* head, int data)
{
	NodeList* temp = new NodeList();
	temp->data=data;
	temp->next=nullptr;
	if(head ==nullptr)
	{
		head = temp;
	}
	else
	{
		NodeList* t=head;
		while(t->next != nullptr)
		{
			t=t->next;
		}
		t->next=temp;
	}
	return head;
}

NodeList* addAtStart(NodeList* head, int data)
{
	NodeList* temp=new NodeList();
	temp->data=data;
	temp->next=head;
	head=temp;
	return head;
}

NodeList* deleteAtStart(NodeList* head)
{
	NodeList* temp=head;
	head=head->next;
	free(temp);
	return head;
}

NodeList* deleteAtEnd(NodeList* head)
{
	NodeList* temp=head;
	while(temp->next->next !=nullptr)
	{
		temp=temp->next;
		
	}
	temp->next=nullptr;
	return head;
}

void printList(NodeList* head)
{
	NodeList* temp=head;
	while(temp !=nullptr)
	{
		cout<<"List-Nodes->>>"<<temp->data<<"\n";
		temp=temp->next;
	}
}

int main()
{
	NodeList* head=nullptr;
	head = addAtEnd(head, 10);
	head = addAtEnd(head, 20);
	head = addAtStart(head, 5);
	printList(head);
	head = deleteAtStart(head);
	cout<<"After deleting from starting";
	printList(head);
	head = deleteAtEnd(head);
	cout<<"After deleting from End";
	printList(head);
	return 0;
}
