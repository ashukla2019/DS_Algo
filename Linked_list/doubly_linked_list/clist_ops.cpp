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
            cout << "Node val=" << temp->data << endl;
            temp = temp->next;
        } while (temp != last->next);
        
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
