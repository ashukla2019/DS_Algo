1) Implement linkedlist:
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

Node* delete_data_end(Node* head)
{
	Node* temp;
	temp = head;
	while(temp->next->next !=nullptr)
	{
		temp = temp->next;
	}
	free(temp->next);
	temp->next = NULL;
	return head;
}

void printList(NodeList* head)
{
	NodeList* temp=head;
	cout<<"List-Nodes->";
	while(temp !=nullptr)
	{
		cout<<temp->data<< " ";
		temp=temp->next;
	}
	cout<<"\n";
}

NodeList* reverseList(NodeList* head)
{
    NodeList*current=head;
    NodeList* temp=nullptr;
    NodeList* prev=nullptr;
    while(current != nullptr)
    {
        temp = current->next;
        current->next=prev;
        prev=current;
        current=temp;
    }
    head=prev;
    return head;
}

int main()
{
	NodeList* head=nullptr;
	head = addAtEnd(head, 10);
	head = addAtEnd(head, 20);
	head = addAtStart(head, 5);
	printList(head);
	head = reverseList(head);
	printList(head);
	head = deleteAtStart(head);
	cout<<"After deleting from starting";
	printList(head);
	head = deleteAtEnd(head);
	cout<<"After deleting from End";
	printList(head);
	return 0;
}
------------------------------------------------------------------------------
2) Implement doubly linked list:
	class Node
{
	public:
		int data;
		Node* next;
		Node* prev;
};
	
Node* add_data_end(Node* head, int data)
{
	Node *temp = new Node();
	temp->data = data;
	temp->next = NULL;
	if(NULL == head)
	{
		head = temp;
		temp->prev = nullptr;
	}
	else
	{
		Node* t = head;
		while(t->next != nullptr)
		{
			t = t->next;
		}
		t->next = temp;
		temp->prev = t;
	}
	return head;
}

Node* delete_data_end(Node* head)
{
	Node* temp;
	temp = head;
	while(temp->next->next !=nullptr)
	{
		temp = temp->next;
	}
	free(temp->next);
	free(temp->next->prev);
	temp->next = NULL;
	return head;
}

Node* add_data_beg(Node* head, int item)
{
	Node* temp = new Node();
	temp->data = item;
	temp->next = head;
	head->prev = temp;
	head = temp;
	
	return head;
}

Node* delete_data_beg(Node* head)
{
	Node* temp;
	temp = head;
	head = temp->next;
	head->prev = nullptr;
	free(temp);
	
	return head;
	
}

Node* reverse_list(Node* head)
{
	Node *temp = NULL;
	Node *current = head;
	while(current != NULL)
	{
		temp = current->prev;
		current->prev = current->next;
		current->next = temp;
		current = current->prev;
	}
	head = temp->prev;
	return head;
}
void show_data(Node* head)
{
	Node *temp;
	temp = head;
	while(temp !=NULL)
	{
		cout<<temp->data<<" ";
		temp = temp->next;
	}
	cout<<"\n";
}

int main(int argc, char* argv[])
{
	Node* head = nullptr; 
	head = add_data_end(head,10);
	head = add_data_end(head,20);
	show_data(head);
	head = reverse_list(head);
	cout<<"After reversing:"<<endl;
	show_data(head);
	head = add_data_beg(head, 5);	
	cout<<"After adding at begin"<<endl;
	show_data(head);
	head = delete_data_beg(head);
	cout<<"After deleting at begin"<<endl;
	show_data(head);
	head = delete_data_end(head);
	cout<<"After deleting at end"<<endl;
	show_data(head);
	head = add_data_end(head,30);
	cout<<"After deleting at end"<<endl;
	show_data(head);
	return 0;
}
------------------------------------------------------------------------------
3) Implement circular linked list:
class node
{
public:
    int data;
    node* next;
};
 
class clist
{
    node* last;
public:
    clist():last(nullptr) {}
    void addAtEnd(int data)
    {
        node* temp = new node();
        temp->data = data;
        //If it's first node we are gonna insert in circular linked list
        if (last == nullptr)
        {
            last = temp;
            temp->next = last;
        }
        else
        {
            //store last->next(first node) to temp->next
            //last->next should have address of temp
            //move last to temp
            temp->next = last->next;
            last->next = temp;
            last = temp;
        }
    }

    void addAtBeg(int data)
    {
        //assume(last->next means head)
        node* temp = new node();
        temp->data = data;
        temp->next = last->next; 
        last->next = temp;
    }

    void delete_data_beg()
    {
            node* temp = last->next;
            last->next = temp->next;
            temp->next = nullptr;
            free(temp);

    }
    
       
    void display()
    {
        node* temp = last->next;
        do
        {
            cout <<temp->data<<" ";
            temp = temp->next;
        } while (temp != last->next);
        cout<<"\n";
        
    }
};

int main()
{
    clist cl;
    cl.addAtEnd(10);
    cl.addAtEnd(20);
    cl.addAtEnd(30);
    cl.addAtEnd(40);
    cl.addAtBeg(5);
    cl.display();
    return 0;
}
-----------------------------------------------------------------------------------
4) Add two numbers in linked list:
Problem: You are given two non-empty linked lists representing two non-negative integers. The digits are
stored in reverse order, and each of their nodes contains a single digit. Add the two numbers and return 
the sum as a linked list.
You may assume the two numbers do not contain any leading zero, except the number 0 itself.

        2---->4---->3
        5---->6---->4
result= 7---->0---->8    

/*
1) Create dummy node with val 0
2) Set result to dummy
3) while(l1 !=NULL || l2 != NULL || carry !=0), do sum by adding
l1->val then l2->val and then carry;
4) Calculate carry by sum/10
5) Calculate node_value by (sum%10) and create new node and move result to next

*/  
ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) 
    {
        ListNode* dummy= new ListNode(0);
        ListNode* result=dummy;
        
        int carry=0;
        while(l1 !=NULL || l2 != NULL || carry !=0)
        {
            int sum=0;
            if(l1 != NULL)
            {
                sum=sum+l1->val;
                l1 = l1->next;
            }
             if(l2 != NULL)
            {
                sum=sum+l2->val;
                l2 = l2->next;
            }
            sum=sum+carry;
            carry=sum/10;
            result->next=new ListNode(sum%10);
            result=result->next;
        }
        return dummy->next;
    }
	TC-> O(max(l1, l2)
	SC-> O(max(l1,l2)
------------------------------------------------------------------------------
5) Odd & Even Linked list:
	
