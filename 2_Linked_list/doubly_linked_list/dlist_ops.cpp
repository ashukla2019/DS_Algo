//This file is for all basic linked list operations

#include <iostream>
#include <cstring>
using namespace std;

class node
{
	public:
		int data;
		node* next;
		node* prev;
};
	
void add_data_end(node** head, int data)
{
	node *temp = new node();
	temp->data = data;
	temp->next = NULL;
	if(NULL == *head)
	{
		*head = temp;
		temp->prev = nullptr;
	}
	else
	{
		node* t = *head;
		while(t->next != nullptr)
		{
			t = t->next;
		}
		t->next = temp;
		temp->prev = t;
	}
}

void delete_data_end(node** head)
{
	node* temp, *q;
	temp = *head;
	while(temp->next !=nullptr)
	{
		q = temp;
		temp = temp->next;
	}
	q->next = NULL;
	free(temp);
}

void add_data_beg(node** head, int item)
{
	node* temp = new node();
	temp->data = item;
	temp->next = *head;
	(*head)->prev = temp;
	*head = temp;
}

void delete_data_beg(node** head)
{
	node* temp;
	temp = *head;
	*head = temp->next;
	(*head)->prev = nullptr;
	free(temp);
	
}

void reverse_list(node** head)
{
	node *temp = NULL;
	node *current = *head;
	while(current != NULL)
	{
		temp = current->prev;
		current->prev = current->next;
		current->next = temp;
		current = current->prev;
	}
	*head = temp->prev;
}
void show_data(node* head)
{
	node *temp;
	temp = head;
	while(temp !=NULL)
	{
		cout<<"data values:"<<temp->data<<endl;
		temp = temp->next;
	}
}


int main(int argc, char* argv[])
{
	node* head = nullptr; 
	add_data_end(&head,10);
	add_data_end(&head,20);
	show_data(head);
	reverse_list(&head);
	cout<<"After reversing:"<<endl;
	show_data(head);
	add_data_beg(&head, 5);	
	cout<<"After adding at begin"<<endl;
	show_data(head);
	delete_data_beg(&head);
	cout<<"After deleting at begin"<<endl;
	show_data(head);
	delete_data_end(&head);
	cout<<"After deleting at end"<<endl;
	show_data(head);
	add_data_end(&head,30);
	show_data(head);
	return 0;
}
