//This file is for all basic linked list operations

#include <iostream>
#include <cstring>
using namespace std;

class ListNode
{
	public:
		int val;
		ListNode* next;
};
	
void add_data_end(ListNode** head, int data)
{
	ListNode *temp = new ListNode();
	temp->val = data;
	temp->next = NULL;
	if(NULL == *head)
	{
		*head = temp;
	}
	else
	{
		ListNode* t = *head;
		while(t->next != nullptr)
		{
			t = t->next;
		}
		t->next = temp;
	}
}

void delete_data_end(ListNode** head)
{
	ListNode* temp, *q;
	temp = *head;
	while(temp->next->next !=nullptr)
	{
		//q = temp;
		temp = temp->next;
	}
	temp->next = NULL;
	//free(temp);
}

void add_data_beg(ListNode** head, int item)
{
	ListNode* temp = new ListNode();
	temp->val = item;
	temp->next = *head;
	*head = temp;
}

void delete_data_beg(ListNode** head)
{
	ListNode* temp;
	temp = *head;
	*head = temp->next;
	free(temp);
	
}

void show_data(ListNode* head)
{
	ListNode *temp;
	temp = head;
	while(temp !=NULL)
	{
		cout<<"data values:"<<temp->val<<endl;
		temp = temp->next;
	}
}

int main(int argc, char* argv[])
{
	ListNode* head = nullptr; 
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
	cout<<"After adding data at end"<<endl;
	show_data(head);
	return 0;
}












