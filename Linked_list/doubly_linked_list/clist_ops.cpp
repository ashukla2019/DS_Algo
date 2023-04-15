#include <iostream>
using namespace std;

class node
{
	public: 
		int data;
		node* next;
};
	
void add_data_end(node** last, int item)
{
	node* temp = new node();
	temp->data = item;
	if(NULL == *last)
	{
		*last = temp;
		temp->next = *last;
		
	}
	else
	{
		temp->next = (*last)->next;
		(*last)->next = temp;
		*last = temp;
	}
}

void delete_data_beg(node** last)
{
	node* temp = (*last)->next;
	(*last)->next = temp->next;
	temp->next = nullptr;
	free(temp);
	
}


void add_data_beg(node** last, int item)
{
	node* temp = new node();
	temp->data = item;
	temp->next = (*last)->next;
	(*last)->next = temp;
}

void show_data(node* last)
{
	node* temp;
	temp = last->next;
	
	do{
		cout<<"value"<<temp->data<<endl;
		temp = temp->next;
		
	}while(temp != last->next);
}

int main()
{
	node* last = nullptr;
	add_data_end(&last,10);
	add_data_end(&last,20);
	add_data_end(&last,30);
	add_data_end(&last,40);
	add_data_beg(&last,5);
	show_data(last);
	cout<<"Before deletion from begining"<<endl;
	delete_data_beg(&last);
	show_data(last);
	return 0;
}
