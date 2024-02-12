/*
Find the id if stored in linked list data, if yes then update salary and if not then add data to list
*/

#include <iostream>
#include <string>
using namespace std;

class empData
{
public:
    int id;
    string name;
    int salary;
    empData* next;
};

class list
{
    empData* head;
public:
    list() :head(nullptr) {}
    void addData(empData& e)
    {
        empData* temp = new empData();
        temp->id = e.id;
        temp->name=e.name;
        temp->salary = e.salary;
        if (head == nullptr)
        {
            head = temp;
        }
        else
        {
            empData* q = head;
            while (q->next != nullptr)
            {
                q = q->next;
            }
            q->next = temp;
        }
    }
    void find(empData& e1)
    {
        empData* temp = head;
        if (head == nullptr)
        {
            addData(e1);
        }
        else
        {
            while (temp != nullptr)
            {
                if (temp->id == e1.id)
                {
                    cout << "salary to be updated";
                }
                temp = temp->next;
            }
            addData(e1);
        }
    }
    void display()
    {
        empData* temp = head;
        while (temp != nullptr)
        {
            cout << "id-->" << temp->id <<"    " <<"name--->" << temp->name<<"    "<<  "salary-->" << temp->salary << endl;
            temp = temp->next;
        }
    }
};

int main()
{
    list l1;
    empData e1 = { 1, "AB", 100 };
    l1.find(e1);
    empData e2 = { 2, "S", 10 };
    l1.find(e2);
    empData e3 = { 2, "S", 500 };
    l1.find(e3);
    l1.display();
    return 0;
}
