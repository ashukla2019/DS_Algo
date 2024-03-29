/*
1) Initialize front and rear to -1
2) Enqueue:
   1) Check if queue is full:if ((rear + 1) % MAX == front) then print queue is full.
   2) Check if it's first node to insert: else if (front == -1 && rear == -1), set front and rear to 0
      and store value in arr[rear] =val
   3) else Normal case: increment rear and store value
      rear = (rear + 1) % MAX;
      arr[rear] = val;
 3) Dequeue:
    1) Check if queue is empty: if (front == -1 && rear == -1) 
    2) Check if there is only one node: else if (rear == front) then set them back to -1
    3) Else normal case: Increment front: front = (front + 1) % MAX;

	
*/

#include<iostream>
#define MAX 5
using namespace std;

class CircularQueue 
{
private:
	int front;
	int rear;
	int arr[MAX];
	int itemCount;

public:
	CircularQueue() 
	{
      front = -1;
      rear = -1;
    }
	void enqueue(int val)
	{
		if ((rear + 1) % MAX == front) 
		{
			cout << "Queue full" << endl;
			return;
		} 
		else if (front == -1 && rear == -1) 
		{
			rear = 0;
			front = 0;
			arr[rear] = val;

		} 
		else 
		{
			rear = (rear + 1) % MAX;
			arr[rear] = val;

		}
	}

  	int dequeue() 
  	{
    	int x = 0;
    	if (front == -1 && rear == -1) 
		{
      		cout << "Queue is Empty" << endl;
      		
    	} 
		else if (rear == front) 
		{
      		x = arr[rear];
      		rear = -1;
      		front = -1;
      		return x;
    	} 
		else 
		{
      		x = arr[front];
      		arr[front] = 0;
      		front = (front + 1) % MAX;
     		return x;
    	}
	}

  	void display() 
	{
    	int i = front;
  		while(i != rear)
  		{          
    		cout<<arr[i]<<endl;
    		i = (i+1) % MAX;
      	}
     	cout<<arr[rear]<<endl;
   		
  	}


};

int main() 
{
  CircularQueue q1;
  q1.enqueue(10);
  q1.enqueue(20);
  q1.enqueue(30);
  q1.enqueue(40);
  q1.enqueue(50);
  q1.enqueue(60);
  q1.display();
  q1.dequeue();
  q1.display();
  return 0;
}
