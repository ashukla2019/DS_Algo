#include<iostream>
#define MAX 5
using namespace std;

class queue
{
	private:
	  int items[MAX], front, rear;
	public:
	  queue()
	  {
		front = -1;
		rear = -1;
	  }
	  void enqueue(int value)
	  {
		if (rear == MAX - 1)
		{
			cout<<"Queue is Full!!"<<endl;
		}
		else
		{
		    if (front == -1) //if going to add first node, should set front = 0
			{
				front = 0;
			}
			items[++rear] = value;
		}
	  }

	  void dequeue() 
	  {
		if (front == -1)
		{
			cout<<"Queue is Empty!!"<<endl;
		}
		else 
		{
			front++;
			
		}
	  }

	  // Function to print the queue
	  void display() 
	  {
		int i;
		cout<<"Queue elements are:";
		for (i = front; i <= rear; i++)
		{
			cout<<items[i]<<endl;;
		}
	  }
	  
	  //Function to reverse queue data
	  void reverse()
	  {
		int i,j,t;
		for(i=front,j=rear;i<j;i++,j--)
		{
			t = items[i];
			items[i] = items[j];
			items[j] = t;
		}
	  }
};

int main() 
{
  //deQueue is not possible on empty queue
  queue q1;

  //enqueue 5 elements
  q1.enqueue(1);
  q1.enqueue(2);
  q1.enqueue(3);
  q1.enqueue(4);
  q1.enqueue(5);

  q1.display();

  //deQueue removes element entered first i.e. 1
  q1.dequeue();

  //Now we have just 4 elements
  q1.display();
  
  q1.reverse();
  
  q1.display();

  return 0;
}
