1) Stack implementation using array:
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
---------------------------------------------------------------------------------
2) Stack implementation using linkedlist:
class Node
{
public:
	int data;
	Node* next;
};

class stack
{
	Node* top;
public:
	stack()
	{
		top = nullptr;
	}
	void push(int x)
	{
		Node* temp = new Node();
		temp->data = x;
		temp->next = top;
		top = temp;
	}
	int pop()
	{
		Node* temp = top;
		top = top->next;
		return temp->data;
	}
	
	void print()
	{
		Node* temp = top;
		while (temp != nullptr)
		{
			cout<<"value is stack"<<temp->data<<endl;
			temp = temp->next;
		}
	}
};

int main()
{
	stack s;
	s.push(10);
	s.push(20);
	s.push(30);
	s.push(40);
	s.push(50);
	s.pop();
	s.print();
	cout<<"********************"<<endl;
	s.pop();
	s.print();
	return 0;
}
-------------------------------------------------------------------------
3) Stack implementation using 2 queue:
//Logic:
push(x)
1) x->Q2
2) Q1 -> Q2
3) swap(Q1, Q2)
Pop():
remove Q1.top()
*/
#include<queue>
class MyStack 
{
queue<int>q1,q2;    
public:
    MyStack() 
    {
        
    }
    void push(int x) 
    {
        q2.push(x);
        while(!q1.empty())
        {
            q2.push(q1.front());
            q1.pop();
        }
        queue<int>q;
        q=q1;
        q1=q2;
        q2=q;
    }
    int pop() 
    {
       int x=q1.front();
       q1.pop();
       return x;
    }
    
    int top() 
    {
        return q1.front();
    }
    
    bool empty() 
    {
        return q1.size()==0;
    }
};


// Driver code
int main()
{
	Stack s;
	s.push(1);
	s.push(2);
	s.push(3);

	cout << "current size: " << s.size() << endl;
	cout << s.top() << endl;
	s.pop();
	cout << s.top() << endl;
	s.pop();
	cout << s.top() << endl;

	cout << "current size: " << s.size() << endl;
	return 0;
}
Time complexity:O(n)
Space complexity:O(2n)
------------------------------------------------------------------------------------
4) Stack implementation using single queue:
class Stack {

	queue<int> q;

public:
	void push(int data);
	void pop();
	int top();
	int size();
	bool empty();
};

// Push operation
void Stack::push(int data)
{
	// Get previous size of queue
	int s = q.size();

	// Push the current element
	q.push(data);

	// Pop all the previous elements and put them after
	// current element

	for (int i = 0; i < s; i++) {
		// Add the front element again
		q.push(q.front());

		// Delete front element
		q.pop();
	}
}

// Removes the top element
void Stack::pop()
{
	if (q.empty())
		cout << "No elements\n";
	else
		q.pop();
}

// Returns top of stack
int Stack::top() { return (q.empty()) ? -1 : q.front(); }

// Returns true if Stack is empty else false
bool Stack::empty() { return (q.empty()); }

int Stack::size() { return q.size(); }

int main()
{
	Stack st;
	st.push(1);
	st.push(2);
	st.push(3);
	cout << "current size: " << st.size() << "\n";
	cout << st.top() << "\n";
	st.pop();
	cout << st.top() << "\n";
	st.pop();
	cout << st.top() << "\n";
	cout << "current size: " << st.size();
	return 0;
}
-------------------------------------------------------------------------------
5) Queue implementation using array:

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
		else if (front==rear) //if there is only one node, then set front and rear to -1
		{
			front=rear=-1;
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
-----------------------------------------------------------------  
6) Queue implementation using linked list:
	Approach:
	1) Create two classes: 
		class Node: definition of linked list node
        class queue: Implementation of queue, Add Node* front and Node* rear as private data member. 
	2) Push/Enque(): Insert node at end in linked list logic:
		1) Create temp node and assign value.
        2) Check if first node: if((rear==NULL)&&(front==NULL)) if yes then rear = front = temp
	   else set rear->next to temp and set rear to last
	3) Pop/Dequeue():  Remove node from starting in linked list logic
		1) Check if queue is empty: if((front==NULL)&&(rear==NULL))
        2) check if only one node is there: else if(front == rear), then set them back to NULL
		3) else increment front pointer
class Node
{
public:
	int data;
	Node* next;
};

class queue
{
	Node* front = NULL;
	Node* rear = NULL;

public:
	void enqueue(int data) //Insert elements in Queue
	{
		Node* temp = new Node();
		temp->data = data;
		temp->next = NULL;
		if ((rear == NULL) && (front == NULL)) //first node
		{
			front = rear = temp;

		}
		else
		{
			rear->next = temp;
			rear = temp;
		}
	}
	void dequeue() // Delete an element from Queue
	{
		Node* temp;
		temp = front;
		if ((front == NULL) && (rear == NULL))
			printf("\nQueue is Empty");
		
		else if (front == rear) //If only one node in queue, then set null
		{
			front = rear = NULL;
			free(temp);
		}
		else {
			front = front->next;
			free(temp);
		}


	}
	void print()
	{
		// Print the elements of Queue
		Node* temp;
		temp = front;
		while (temp != nullptr)
		{
			cout << temp->data << endl;
			temp = temp->next;
		}

	}
};
int main()
{
	queue q1;
	q1.enqueue(10);
	//q1.enqueue(20);
	//q1.enqueue(30);
	//q1.print();
	q1.dequeue();
	q1.print();
	q1.enqueue(20);
	q1.enqueue(30);
	q1.print();
	return 0;
}
---------------------------------------------------------------------------------
7) Queue implementation using stack:
	//logic to follow
	push(x)
	1) s1->s2
	2) x->s1
	3) s2->s1

	pop()
	s1.pop()
	*/
struct Queue {
	stack<int> s1, s2;

	void enQueue(int x)
	{
		// Move all elements from s1 to s2
		while (!s1.empty()) {
			s2.push(s1.top());
			s1.pop();
		}

		// Push item into s1
		s1.push(x);

		// Push everything back to s1
		while (!s2.empty()) {
			s1.push(s2.top());
			s2.pop();
		}
	}

	// Dequeue an item from the queue
	int deQueue()
	{
		// if first stack is empty
		if (s1.empty()) {
			return -1;
		}

		// Return top of s1
		int x = s1.top();
		s1.pop();
		return x;
	}
};

// Driver code
int main()
{
	Queue q;
	q.enQueue(1);
	q.enQueue(2);
	q.enQueue(3);

	cout << q.deQueue() << '\n';
	cout << q.deQueue() << '\n';
	cout << q.deQueue() << '\n';

	return 0;
}
Complexity Analysis: 
Time Complexity: 
Push operation: O(N). In the worst case we have empty whole of stack 1 into stack 2.
Pop operation: O(1). Same as pop operation in stack.
Auxiliary Space: O(N). Use of stack for storing values.

-----------------------------------------------------------------------
8) Circular queue implementation:
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
--------------------------------------------------------------------------------
9) Check for Balanced Parentheses:
Input: str = “( )[ { } ( ) ]”
Output: True
Explanation: As every open bracket has its corresponding 
close bracket. Match parentheses are in correct order 
hence they are balanced.

Approach:
1) If we have character '(' or '{' or '[' then push to stack 
2) If we have character ')' and st.top()!= '(' or '}' and st.top()!= '{' '[' and st.top()!= ']'

bool isValid(string s) {
        stack<char> st;
        for(auto i:s)
        {
            if(i=='(' || i=='{'|| i=='[' )
            {
                st.push(i);
            }
            else
            {
                if(st.empty() || (st.top()=='(' && i!=')') ||(st.top()=='{' && i!='}')||(st.top()=='[' && i!=']'))
                {
                    return false;
                }
                else
                {
                    st.pop();
                }
            }
            
        }
        return st.empty();
        
    }
int main()
{
    string s="()[{}()]";
    if(isValid(s))
    cout<<"True"<<endl;
    else
    cout<<"False"<<endl;
}
Time Complexity: O(N)
Space Complexity: O(N)
---------------------------------------------------------------
10) Min Stack implementation:
Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.
Implement the MinStack class:
MinStack() initializes the stack object.
void push(int val) pushes the element val onto the stack.
void pop() removes the element on the top of the stack.
int top() gets the top element of the stack.
int getMin() retrieves the minimum element in the stack.

Input
["MinStack","push","push","push","getMin","pop","top","getMin"]
[[],[-2],[0],[-3],[],[],[],[]]

Output
[null,null,null,null,-3,null,0,-2]
Explanation
MinStack minStack = new MinStack();
minStack.push(-2);
minStack.push(0);
minStack.push(-3);
minStack.getMin(); // return -3
minStack.pop();
minStack.top();    // return 0
minStack.getMin(); // return -2

A// A user defined stack that supports getMin() in
// addition to push() and pop()
struct MyStack {
    stack<int> s;
    int minEle;
    // Prints minimum element of MyStack
    void getMin()
    {
        if (s.empty())
            cout << "Stack is empty\n";
        // variable minEle stores the minimum element
        // in the stack.
        else
            cout << "Minimum Element in the stack is: "
                 << minEle << "\n";
    }
    // Prints top element of MyStack
    void peek()
    {
        if (s.empty()) {
            cout << "Stack is empty ";
            return;
        }
        int t = s.top(); // Top element.
        cout << "Top Most Element is: ";
        // If t < minEle means minEle stores
        // value of t.
        (t < minEle) ? cout << minEle : cout << t;
    }
    // Remove the top element from MyStack
    void pop()
    {
        if (s.empty()) {
            cout << "Stack is empty\n";
            return;
        }
        cout << "Top Most Element Removed: ";
        int t = s.top();
        s.pop();
        // Minimum will change as the minimum element
        // of the stack is being removed.
        if (t < minEle) {
            cout << minEle << "\n";
            minEle = 2 * minEle - t;
        }
        else
            cout << t << "\n";
    }
    // Removes top element from MyStack
    void push(int x)
    {
        // Insert new number into the stack
        if (s.empty()) {
            minEle = x;
            s.push(x);
            cout << "Number Inserted: " << x << "\n";
            return;
        }
        // If new number is less than minEle
        else if (x < minEle) {
            s.push(2 * x - minEle);
            minEle = x;
        }
        else
            s.push(x);
        cout << "Number Inserted: " << x << "\n";
    }
};
 
// Driver Code
int main()
{
    MyStack s;
    // Function calls
    s.push(3);
    s.push(5);
    s.getMin();
    s.push(2);
    s.push(1);
    s.getMin();
    s.pop();
    s.getMin();
    s.pop();
    s.peek();
 
    return 0;
}
Time Complexity: O(1)
Auxiliary Space: O(1)
----------------------------------------------------------------------------
11) Next Greater Element Using Stack:
Example 1: 
Input: N = 5, A[] = {6,0,8,1,3}
Output: 8,8,-1,3,-1

Approach: 
1) Start iterating array from last(n-1)th index and check if stack is not empty and stack.top() does not 
have greater element than current element, then pop out all elements until you get greater element.
2) If stack is not empty means defenitly, stack has greater element than current element, update answer with stack.top()
3) 

vector<int> nextGreaterElement(vector<int>& nums, int n)
{
    //Vector to store nextGreaterElement array
	vector<int> ans(n,-1);
	stack<int> st;
	for (int i = n - 1; i >= 0; i--) 
	{
		//if stack is not empty and stack.top() is less than current index data then 
		//do stack.pop() utnitl we get greater element in stack or stack becomes empty
		while (!st.empty() && st.top() <= nums[i])
		{
			st.pop(); //can remove n elements at max => O(n)
		}
		//Now update ans array with stack.top(), as it's next greater element
		if (!st.empty())
		{
			ans[i] = st.top();
		}
		//push array element to stack...
		st.push(nums[i]); //can push n elements at max => O(n)
	}
	return ans;
}  
TC-> O(2n)
SC-> O(n)+ O(n) //n for stack + n for vector
--------------------------------------------------------------------------
12) Next Greater Element Using Stack-II:
Input: N = 5, A[] = {2,10,12,1,11}
Output: 10,12,-1,11,12

Approach: {2,10,12,1,11} => Take double of array so that it can have view till whole array elements and 
that will be ok for circular view.
2,10,12,1,11 | 2,10,12,1,11
Start checking elements from (2N-1)th index but don't add next greater element in answer vector.
only update the stack for putting only greater element in stack to than current element.

vector<int> nextGreaterElements(vector<int>& a) {
	int n = a.size();
    vector<int>ans(n,-1);
    stack<int>st;
    for(int i = 2*n - 1; i >= 0; i--)
    {
		//we pop out all elements smaller than current element
        while(!st.empty() && (a[i%n] >= st.top()))
        {
			st.pop();   //can remove 2n elements at max => O(2n)
        }
        // if stack is empty means no greater element is there
        // if not empty we make answer at that index equal to top element
        if(!st.empty() && (i < n))
        {
			ans[i] = st.top();
        }
		//from 2*n-1 to n(9 to 4) will store only 
        st.push(a[i%n]); //can push 2n elements at max => O(2n)
    }
    return ans;
}
TC-> O(4n)
SC-> O(2n)+ O(n) //2n for stack + n for vector
--------------------------------------------------------------------------------
13) Previous smaller element:
arr[]={4,5,2,10,8};

vector<int> nextSmallerElement(vector<int>& nums, int n)
{
    //Vector to store nextGreaterElement array
	vector<int> ans(n,-1);
	stack<int> st;
	for (int i = 0; i<0; i++) 
	{
		//if stack is not empty and stack.top() is greater than current index data then 
		//do stack.pop() utnitl we get smaller element in stack or stack becomes empty
		while (!st.empty() && st.top() >= nums[i])
		{
			st.pop(); //can remove n elements at max => O(n)
		}
		//Now update ans array with stack.top(), as it's next smaller element
		if (!st.empty())
		{
			ans[i] = st.top();
		}
		//push array element to stack...
		st.push(nums[i]); //can push n elements at max => O(n)
	}
	return ans;
}  
TC-> O(2n)
SC-> O(n)+ O(n) //n for stack + n for vector
--------------------------------------------------------------------------
14) Trapping Rainwater:(Hard)
Given n non-negative integers representing an elevation map where the width of each bar is 1, 
compute how much water it can trap after raining.
Input: height = [0,1,0,2,1,0,1,3,2,1,2,1]
Output: 6
Explanation: The above elevation map (black section) is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. In this case, 6 units of rain water (blue section) are being trapped.
                     3
         2          |--|2     2
   1    |--|1     1 |  |--|1 |--|1
0 |--|  |  |--|  |--|  |  |--|  |--|
--|--|--|--|--|--|--|--|--|--|--|--|

Approach:
min(leftMax, rightmax) - arr[i]

----pending






-------------------------------------------------------------------------------------
15) 
