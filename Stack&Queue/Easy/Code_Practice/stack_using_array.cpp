#include <iostream>
using namespace std;

class myStack
{
	int top;
	int size;
	int *arr;
public:
	myStack()
	{
		top=-1;
		size=100;
		arr=new int[size];
	}	
	void push(int data)
	{
		if(top>=size)
		{
			cout<<"stack is full\n";
		}
		else
		{
			arr[++top]=data;
		}
	}
	int pop()
	{
		if(top<=-1)
		{
			cout<<"stack is empty\n";
		}
		else
		{
			int x = arr[top];
			top--;
			return x;
		}
	}
	int Top()
	{
		return arr[top];
	}
	void printStack()
	{
		for(int i=0; i<=top; i++)
		{
			cout<<"Stack-elements"<<arr[i]<<"\n";
		}
	}
};


int main()
{
	myStack s;
	s.push(10);
	s.push(20);
	s.push(30);
	s.printStack();
	s.pop();
	cout<<"After pop";
	s.printStack();
	return 0;
}
