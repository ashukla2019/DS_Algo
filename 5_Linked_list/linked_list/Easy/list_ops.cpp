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


---------------------------------------------------------------------------------------- 
Method 2: Using list class:
#include <iostream>
#include <string>
using namespace std;

class node
{
public:
    int data;
    node* next;
};
 
class list
{
    node* head;
public:
    list():head(nullptr) {}
    void addDataAtEnd(int data)
    {
        node* temp = new node();
        temp->data = data;
        if (head == nullptr)
        {
            head = temp;
        }
        else
        {
            node* t = head;
            while (t->next != nullptr)
            {
                t = t->next;
            }
            t->next = temp;
        }

    }
    void addAtBeg(int data)
    {
        node* temp = new node();
        temp->data = data;
        temp->next = head;
        head = temp;
    }

    void deleteAtBeg()
    {
        node* temp = head;
        head = head->next;
        free(temp);
    }
    void deleteAtEnd()
    {
        node* temp = head;
        while (temp->next->next != nullptr)
        {
            temp = temp->next;
        }
        free(temp->next);
        temp->next = nullptr;
    }
    void reverseList()
    {
        node* temp = nullptr;
        node* prev = nullptr;
        node* curr = head;
        while (curr != nullptr)
        {
            temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }
        head = prev;
    }
    void display()
    {
        node* temp = head;
        while (temp != nullptr)
        {
            cout << "Node val=" << temp->data << endl;
            temp = temp->next;
        }
    }
};

int main()
{
    list l;
    l.addDataAtEnd(10);
    l.addDataAtEnd(20);
    l.addAtBeg(5);
    l.display();
    cout << "After reversing list\n";
    l.reverseList();
    l.display();
    l.deleteAtBeg();
    l.display();
    l.deleteAtEnd();
    l.display();
    return 0;
}
