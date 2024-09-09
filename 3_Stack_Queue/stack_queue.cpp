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
10) Backspace String Compare:
Given two strings s and t, return true if they are equal when both are typed into empty text editors. '#' means a backspace character.
Note that after backspacing an empty text, the text will continue empty.
Example 1:
Input: s = "ab#c", t = "ad#c"
Output: true
Explanation: Both s and t become "ac".
	
Example 2:
Input: s = "ab##", t = "c#d#"
Output: true
Explanation: Both s and t become "".
	
Example 3:
Input: s = "a#c", t = "b"
Output: false
Explanation: s becomes "c" while t becomes "b".

Approach:
1) will convert strings by putting all chars to stack.
2) will check current stack element, if it is '#' and stack is not empty then pop the last stack element
3) if it is other than '#' then push element to stack.
4) Now iterate through stack and crate new string with stack elements.
	
    string convert(string s)
    {
        stack<char>st;//stack of characters
        for(int i = 0;i<s.length();i++)
        {
            if(s[i]=='#')
            {
                if(st.empty()) continue;// if there is nothing to remove
                else st.pop();
            }
            else
                st.push(s[i]);
        }
        string a = "";
        while(!st.empty())
        {
            a+=st.top();
            st.pop();
        }
        return a;
    }
    bool backspaceCompare(string s, string t) {
        string s1 = convert(s);
        string s2 = convert(t);
        return s1==s2;
    }
Time complexity:O(N), N being the length of longer string
Space complexity:O(N)
-----------------------------------------------------------------------------
11) Implement two Stacks in an Array
Create a data structure twoStacks that represent two stacks. Implementation of twoStacks should use only 
one array, i.e., both stacks should use the same array for storing elements. 

Following functions must be supported by twoStacks.

push1(int x) –> pushes x to first stack 
push2(int x) –> pushes x to second stack
pop1() –> pops an element from first stack and return the popped element 
pop2() –> pops an element from second stack and return the popped element

Approach: 
will have single array with size n. Both top1 and top2 would be initialized with n/2+1 & n/2 respectively.
Push:will move top1-- until it is >0 and top2++ until <size-1;
Pop: will move top1++ to remove element until <size/2, will move top2-- until >=size/2
	
#include <bits/stdc++.h> 
using namespace std; 
class twoStacks { 
	int* arr; 
	int size; 
	int top1, top2; 
public: 
	// Constructor 
	twoStacks(int n) 
	{ 
		size = n; 
		arr = new int[n]; 
		top1 = n / 2 + 1; 
		top2 = n / 2; 
	} 

	// Method to push an element x to stack1 
	void push1(int x) 
	{ 
		// There is at least one empty 
		// space for new element 
		if (top1 > 0) { 
			top1--; 
			arr[top1] = x; 
		} 
		else { 
			cout << "Stack Overflow"
				<< " By element : " << x << endl; 
			return; 
		} 
	} 

	// Method to push an element 
	// x to stack2 
	void push2(int x) 
	{ 

		// There is at least one empty 
		// space for new element 
		if (top2 < size - 1) { 
			top2++; 
			arr[top2] = x; 
		} 
		else { 
			cout << "Stack Overflow"
				<< " By element : " << x << endl; 
			return; 
		} 
	} 

	// Method to pop an element from first stack 
	int pop1() 
	{ 
		if (top1 <= size / 2) { 
			int x = arr[top1]; 
			top1++; 
			return x; 
		} 
		else { 
			cout << "Stack UnderFlow"; 
			exit(1); 
		} 
	} 

	// Method to pop an element 
	// from second stack 
	int pop2() 
	{ 
		if (top2 >= size / 2 + 1) { 
			int x = arr[top2]; 
			top2--; 
			return x; 
		} 
		else { 
			cout << "Stack UnderFlow" << endl; 
			exit(1); 
		} 
	} 
}; 

/* Driver program to test twoStacks class */
int main() 
{ 
	twoStacks ts(5); 
	ts.push1(5); 
	ts.push2(10); 
	ts.push2(15); 
	ts.push1(11); 
	ts.push2(7); 
	cout << "Popped element from stack1 is "
		<< ": " << ts.pop1() << endl; 
	ts.push2(40); 
	cout << "Popped element from stack2 is "
		<< ": " << ts.pop2() << endl; 
	return 0; 
}
Time Complexity: 
Both Push operation: O(1)
Both Pop operation: O(1)
Auxiliary Space: O(N), Use of array to implement stack.
-------------------------------------------------------------------------------
12) Min Stack implementation:
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

class MinStack {
public:
    vector< pair<int,int> > s;
    MinStack() { }
    void push(int val) 
    {
        if(s.empty())
            s.push_back({val,val});
        else
            s.push_back({val,min(s.back().second,val)});    
    }
    void pop() { s.pop_back(); }
    int top() { return s.back().first; }
    
    int getMin() { return s.back().second; }
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
15) Next Greater Element Using Stack:
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
16) Next Greater Element Using Stack-II:
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
17) Previous smaller element:
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
18) Minimum Cost Tree From Leaf Values
Given an array arr of positive integers, consider all binary trees such that:

Each node has either 0 or 2 children;
The values of arr correspond to the values of each leaf in an in-order traversal of the tree.
The value of each non-leaf node is equal to the product of the largest leaf value in its left and right subtree, respectively.
Among all possible binary trees considered, return the smallest possible sum of the values of each non-leaf node. It is guaranteed this sum fits into a 32-bit integer.

A node is a leaf if and only if it has zero children.

Input: arr = [6,2,4]
Output: 32
Explanation: There are two possible trees shown.
The first has a non-leaf node sum 36, and the second has non-leaf node sum 32.

int mctFromLeafValues(vector<int>& A) {
        int res = 0;
        vector<int> stack = {INT_MAX};
        for (int a : A) {
            while (stack.back() <= a) {
                int mid = stack.back();
                stack.pop_back();
                res += mid * min(stack.back(), a);
            }
            stack.push_back(a);
        }
        for (int i = 2; i < stack.size(); ++i) {
            res += stack[i] * stack[i - 1];
        }
        return res;
    }
	Time O(N) for one pass
	Space O(N) for stack in the worst cases

-----------------------------------------------------------
19) Daily Temperatures:
vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> result(n, 0);
        stack<int> stk;

        for(int i = 0; i < n; i++) {
            while(!stk.empty() && temperatures[stk.top()] < temperatures[i]) {
                result[stk.top()] = i - stk.top();
                stk.pop();
            }
            stk.push(i);
        }

        return result;
    }
	Time complexity: O(n), n is the total number of days and each index is pushed or popped from the stack at most onces.
	Space complexity: O(n), for stack O(n)
-----------------------------------------------------------------------------
20) Evaluate Reverse Polish Notation
You are given an array of strings tokens that represents an arithmetic expression in a Reverse Polish Notation.
Evaluate the expression. Return an integer that represents the value of the expression.

Note that:
The valid operators are '+', '-', '*', and '/'.
Each operand may be an integer or another expression.
The division between two integers always truncates toward zero.
There will not be any division by zero.
The input represents a valid arithmetic expression in a reverse polish notation.
The answer and all the intermediate calculations can be represented in a 32-bit integer.

Example 1:

Input: tokens = ["2","1","+","3","*"]
Output: 9
Explanation: ((2 + 1) * 3) = 9
Example 2:

Input: tokens = ["4","13","5","/","+"]
Output: 6
Explanation: (4 + (13 / 5)) = 6
Example 3:

Input: tokens = ["10","6","9","3","+","-11","*","/","*","17","+","5","+"]
Output: 22
Explanation: ((10 * (6 / ((9 + 3) * -11))) + 17) + 5
= ((10 * (6 / (12 * -11))) + 17) + 5
= ((10 * (6 / -132)) + 17) + 5
= ((10 * 0) + 17) + 5
= (0 + 17) + 5
= 17 + 5
= 22

	 int evalRPN(vector<string>& tokens) {
        stack<int> st;

        for (string c : tokens) {
            if (c == "+") {
                int second = st.top(); st.pop();
                int first = st.top(); st.pop();
                st.push(first + second);
            } else if (c == "-") {
                int second = st.top(); st.pop();
                int first = st.top(); st.pop();
                st.push(first - second);
            } else if (c == "*") {
                int second = st.top(); st.pop();
                int first = st.top(); st.pop();
                st.push(first * second);
            } else if (c == "/") {
                int second = st.top(); st.pop();
                int first = st.top(); st.pop();
                st.push(first / second);
            } else {
                st.push(stoi(c));
            }
        }

        return st.top();        
    }
	Time complexity: O(n)
	Space complexity: O(n)
-----------------------------------------------------------------------
21) Rotten Oranges:
Given a grid of dimension nxm where each cell in the grid can have values 0, 1 or 2 which has the following meaning:
0 : Empty cell
1 : Cells have fresh oranges
2 : Cells have rotten oranges

We have to determine what is the earliest time after which all the oranges are rotten. A rotten orange at index [i,j] can rot other fresh orange at indexes [i-1,j], [i+1,j], [i,j-1], [i,j+1] (up, down, left and right) in unit time. 
 

Example 1:

Input: grid = {{0,1,2},{0,1,2},{2,1,1}}
Output: 1
Explanation: The grid is-
0 1 2
0 1 2
2 1 1
Oranges at positions (0,2), (1,2), (2,0)
will rot oranges at (0,1), (1,1), (2,2) and 
(2,1) in unit time.
Example 2:

Input: grid = {{2,2,0,1}}
Output: -1
Explanation: The grid is-
2 2 0 1
Oranges at (0,0) and (0,1) can't rot orange at
(0,3).

Your Task:
You don't need to read or print anything, Your task is to complete the function orangesRotting() which takes grid as input parameter and returns the minimum time to rot all the fresh oranges. If not possible returns -1.
 
Expected Time Complexity: O(n*m)
Expected Auxiliary Space: O(n*m)
  int orangesRotting(vector<vector<int>>& grid) {
          queue<pair<int, int>>q;
          int r = grid.size();
          int c = grid[0].size();
          
          for(int i=0; i<r; i++){
              for(int j=0; j<c; j++){
                  if(grid[i][j] == 2)
                    q.push({i, j});
              }   
          }
          int count = 0;
          q.push({-1, -1});
          while(!q.empty()){
              int x = q.front().first;
              int y = q.front().second;
              if((x == -1 and y == -1) and q.size() == 1){
                  q.pop();
                  break;
              }
              else if((x == -1 and y == -1) and q.size() > 1){
                  count++;
                  q.pop();
                  q.push({-1, -1});
              }
              else{
                  
                  if(x-1 >= 0 and grid[x-1][y] == 1 ){
                      q.push({x-1, y});
                       grid[x-1][y] = 2;
                  }
                  if(y-1 >= 0 and grid[x][y-1] == 1){
                      q.push({x, y-1});
                       grid[x][y-1] = 2;
                  }
                    if(x+1 < r and grid[x+1][y] == 1 ){
                      q.push({x+1, y});
                       grid[x+1][y] = 2;
                  }
                  if(y+1 < c and grid[x][y+1] == 1){
                      q.push({x, y+1});
                      grid[x][y+1] = 2;
                  }
                  q.pop();
              }
          }
           for(int i=0; i<r; i++){
              for(int j=0; j<c; j++){
                  if(grid[i][j] == 1)
                   return -1;
              }   
          }
          return count;
    }

------------------------------------------------------------------------------
22) Sum of Subarray Minimum: Given an array of integers arr, find the sum of min(b), where b ranges 
over every (contiguous) subarray of arr. Since the answer may be large, return the answer 
modulo 109 + 7.

arr[]={3,1,2,4}
subarray starts with 3: {3} => min = 3, {3,1}=> min = 1, {3,1,2}=> min = 1, {3,1,2,4}=> min = 1
subarray starts with 1: {1}=> min = 1, {1,2}=> min = 1, {1,2,4}=> min = 1
subarray starts with 2: {2}=> min = 2, {2,4}=> min = 2
subarray starts with 4: {4}=> min = 4
sum(3,1,1,1,1,1,1,2,2,4)=17

Approach:  2 9 7 8 3 4 6 1 => If we consider element 3 then we need to find  subarrays having 3 and 3
should be minimum:
{9,7,8,3}, {9,7,8,3,4}, {9,7,8,3,4,6}, {7,8,3}, {7,8,3,4},{7,8,3,4,6}, {8,3}, {8,3,4}, {8,3,4,6},
	{3}, {3,4}, {3,4,6} => total 12 subarray having 3 as minimum 
	we need to find previous smaller element of 3 and next smaller element of 3, because until we get smaller
	than 3 at left or right side, we can consider all those 3s in result.
	
	int sumSubarrayMins(vector<int>& arr) {
        int M = 1e9+7;
        long long int ans = 0;
        stack<int> s;
        vector<int> left(arr.size()), right(arr.size());

        // Calculate left
        for(int i = 0; i < arr.size(); i++){
            while(!s.empty() && arr[s.top()] > arr[i]) {
                s.pop();
            }
            left[i] = (s.empty()) ? -1 : s.top();
            s.push(i);
        }

        // Clear stack
        while(!s.empty()) {
            s.pop();
        }

        // Calculate right
        for(int i = arr.size()-1; i >= 0; i--){
            while(!s.empty() && arr[s.top()] >= arr[i]) {
                s.pop();
            }
            right[i] = (s.empty()) ? arr.size() : s.top();
            s.push(i);
        }

        // Calculate answer
        for(int i = 0; i < arr.size(); i++){
            ans = (ans + (long long)arr[i]*(i-left[i])*(right[i]-i)) % M;
        }

        return (int)ans;
    }
Time complexity:O(n)
Space complexity:O(n)
--------------------------------------------------------------------------------
23) Sum of subarray ranges: You are given an integer array nums. The range of a subarray of nums
is the difference between the largest and smallest element in the subarray.
Return the sum of all subarray ranges of nums.
A subarray is a contiguous non-empty sequence of elements within an array.

Example 1:
Input: nums = [1,2,3]
Output: 4
Explanation: The 6 subarrays of nums are the following:
[1], range = largest - smallest = 1 - 1 = 0 
[2], range = 2 - 2 = 0
[3], range = 3 - 3 = 0
[1,2], range = 2 - 1 = 1
[2,3], range = 3 - 2 = 1
[1,2,3], range = 3 - 1 = 2
So the sum of all ranges is 0 + 0 + 0 + 1 + 1 + 2 = 4.

long long subArrayRanges(vector<int>& nums) {
        stack<int> increaseStk;
        stack<int> decreaseStk;
        int n = nums.size();
        vector<int> leftLess(n);
        vector<int> rightLess(n);
        vector<int> leftLarger(n);
        vector<int> rightLarger(n);
        // 1. Initialize
        for(int i=0; i<n; i++){
            leftLess[i] = leftLarger[i] = i+1;
            rightLess[i] = rightLarger[i] = n-i;            
        }
        // 2. Find leftLess and rightLess
        for(int i=0; i<n; i++){
            while(!increaseStk.empty() && nums[increaseStk.top()] > nums[i]){
                rightLess[increaseStk.top()] = i - increaseStk.top();
                increaseStk.pop();
            }
            leftLess[i] = increaseStk.empty() ? i + 1 : i - increaseStk.top();
            increaseStk.push(i);
        }
        // 3. Find leftLarger and rightLarger
        for(int i=0; i<n; i++){
            while(!decreaseStk.empty() && nums[decreaseStk.top()] < nums[i]){
                rightLarger[decreaseStk.top()] = i - decreaseStk.top();
                decreaseStk.pop();
            }
            leftLarger[i] = decreaseStk.empty() ? i + 1 : i - decreaseStk.top();
            decreaseStk.push(i);
        }
        // 4. accumulate sum of (larger - less) of nums[i]
        long long sum = 0;
        for(int i=0; i<n; i++){
            long long curDiff = leftLarger[i]*rightLarger[i] - leftLess[i]*rightLess[i];
            sum += nums[i] * curDiff;
        }
        return sum;
      
    }
------------------------------------------------------------------------------
24) Aestroid Collisions: We are given an array asteroids of integers representing asteroids in a row.
For each asteroid, the absolute value represents its size, and the sign represents its direction (positive meaning right, negative meaning left). Each asteroid moves at the same speed.
Find out the state of the asteroids after all collisions. If two asteroids meet, the smaller one will explode. If both are the same size, both will explode. Two asteroids moving in the same direction will never meet.

Example 1:
Input: asteroids = [5,10,-5]
Output: [5,10]
Explanation: The 10 and -5 collide resulting in 10. The 5 and 10 never collide.

Approach: Iterate through all elements of array:
case 1: if positive element is found then push it to stack
case 2: if not positive: 
		while stack is not empty and stack.top is positive 
		and current stack's abs value greater than stack.top(means current element is negative and greater than 
		stack.top()=> it will destroy positive value on stack.top()), then pop the elements from stack.
case 3: If stack is not empty and current element is same as stack.top() then pop stack.top()
case 4: If stack is empty or stack.top() is negative, push element in stack.		

vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> ans;
        // Loop through all asteroids
        for (int asteroid : asteroids) {
            // If asteroid is moving to the right (positive), add it to the stack.
            if (asteroid > 0) {
                ans.push_back(asteroid);
            } else {
                // While there are asteroids in the stack moving to the right (positive) 
                // and the current asteroid is larger (negative magnitude comparison)
                while (!ans.empty() && ans.back() > 0 && ans.back() < -asteroid) {
                    ans.pop_back(); // Pop the smaller asteroids as they are destroyed
                }
                // If the top asteroid on the stack is the same size (opposite direction),
                // Both asteroids destroy each other, pop the top asteroid from the stack.
                if (!ans.empty() && ans.back() == -asteroid) {
                    ans.pop_back();
                } else if (ans.empty() || ans.back() < 0) {
                    // If the stack is empty or the top asteroid is moving to the left (negative),
                    // Add the current asteroid to the stack, since no collision will happen.
                    ans.push_back(asteroid);
                } // If none of the above cases, the current asteroid is destroyed
            }
        }
        return ans; // Return the state of the stack after all collisions
    }

-----------------------------------------------------------------------------
25) Online Stock Span
Design an algorithm that collects daily price quotes for some stock and returns the span of that stock's price for the current day.

The span of the stock's price in one day is the maximum number of consecutive days (starting from that day and going backward) for which the stock price was less than or equal to the price of that day.

For example, if the prices of the stock in the last four days is [7,2,1,2] and the price of the stock today is 2, then the span of today is 4 because starting from today, the price of the stock was less than or equal 2 for 4 consecutive days.
Also, if the prices of the stock in the last four days is [7,34,1,2] and the price of the stock today is 8, then the span of today is 3 because starting from today, the price of the stock was less than or equal 8 for 3 consecutive days.
Implement the StockSpanner class:

StockSpanner() Initializes the object of the class.
int next(int price) Returns the span of the stock's price given that today's price is price.

Example 1:

Input
["StockSpanner", "next", "next", "next", "next", "next", "next", "next"]
[[], [100], [80], [60], [70], [60], [75], [85]]
Output
[null, 1, 1, 1, 2, 1, 4, 6]

Explanation
StockSpanner stockSpanner = new StockSpanner();
stockSpanner.next(100); // return 1
stockSpanner.next(80);  // return 1
stockSpanner.next(60);  // return 1
stockSpanner.next(70);  // return 2
stockSpanner.next(60);  // return 1
stockSpanner.next(75);  // return 4, because the last 4 prices (including today's price of 75) were less than or equal to today's price.
stockSpanner.next(85);  // return 6 

class StockSpanner {
    vector<int> v;
public:
    StockSpanner(){
        
    }
    
    int next(int price){
        int cnt=1;
        for(int i=v.size()-1; i>=0; i--){
            if(v[i]<=price) cnt++;
            else break;
        }
        v.push_back(price);
        return cnt;
    }
};
Time complexity: O(1)
Space complexity: O(n)
----------------------------------------------------------------------------------- 
11) Implement Stack and Queue using Deque:
// C++ Program to implement stack and queue using Deque
#include <bits/stdc++.h>
using namespace std;

// structure for a node of deque
struct DQueNode {
    int value;
    DQueNode* next;
    DQueNode* prev;
};

// Implementation of deque class
class Deque {
private:

    // pointers to head and tail of deque
    DQueNode* head;
    DQueNode* tail;

public:
    // constructor
    Deque()
    {
        head = tail = NULL;
    }

    // if list is empty
    bool isEmpty()
    {
        if (head == NULL)
            return true;
        return false;
    }

    // count the number of nodes in list
    int size()
    {
        // if list is not empty
        if (!isEmpty()) {
            DQueNode* temp = head;
            int len = 0;
            while (temp != NULL) {
                len++;
                temp = temp->next;
            }
            return len;
        }
        return 0;
    }

    // insert at the first position
    void insert_first(int element)
    {
        // allocating node of DQueNode type
        DQueNode* temp = new DQueNode[sizeof(DQueNode)];
        temp->value = element;

        // if the element is first element
        if (head == NULL) {
            head = tail = temp;
            temp->next = temp->prev = NULL;
        }
        else {
            head->prev = temp;
            temp->next = head;
            temp->prev = NULL;
            head = temp;
        }
    }

    // insert at last position of deque
    void insert_last(int element)
    {
        // allocating node of DQueNode type
        DQueNode* temp = new DQueNode[sizeof(DQueNode)];
        temp->value = element;

        // if element is the first element
        if (head == NULL) {
            head = tail = temp;
            temp->next = temp->prev = NULL;
        }
        else {
            tail->next = temp;
            temp->next = NULL;
            temp->prev = tail;
            tail = temp;
        }
    }

    // remove element at the first position
    void remove_first()
    {
        // if list is not empty
        if (!isEmpty()) {
            DQueNode* temp = head;
            head = head->next;
            if(head) head->prev = NULL;
            delete temp;
            if(head == NULL) tail = NULL;
            return;
        }
        cout << "List is Empty" << endl;
    }

    // remove element at the last position
    void remove_last()
    {
        // if list is not empty
        if (!isEmpty()) {
            DQueNode* temp = tail;
            tail = tail->prev;
            if(tail) tail->next = NULL;
            delete temp;
            if(tail == NULL) head = NULL;
            return;
        }
        cout << "List is Empty" << endl;
    }

    // displays the elements in deque
    void display()
    {
        // if list is not empty
        if (!isEmpty()) {
            DQueNode* temp = head;
            while (temp != NULL) {
                cout << temp->value << " ";
                temp = temp->next;
            }
            cout << endl;
            return;
        }
        cout << "List is Empty" << endl;
    }
};

// Class to implement stack using Deque
class Stack : public Deque {
public:
    // push to push element at top of stack
    // using insert at last function of deque
    void push(int element)
    {
        insert_last(element);
    }

    // pop to remove element at top of stack
    // using remove at last function of deque
    void pop()
    {
        remove_last();
    }
};

// class to implement queue using deque
class Queue : public Deque {
public:
    // enqueue to insert element at last
    // using insert at last function of deque
    void enqueue(int element)
    {
        insert_last(element);
    }

    // dequeue to remove element from first
    // using remove at first function of deque
    void dequeue()
    {
        remove_first();
    }
};

// Driver Code
int main()
{
    // object of Stack
    Stack stk;

    // push 7 and 8 at top of stack
    stk.push(7);
    stk.push(8);
    cout << "Stack: ";
    stk.display();

    // pop an element
    stk.pop();
    cout << "Stack: ";
    stk.display();

    // object of Queue
    Queue que;

    // insert 12 and 13 in queue
    que.enqueue(12);
    que.enqueue(13);
    cout << "Queue: ";
    que.display();

    // delete an element from queue
    que.dequeue();
    cout << "Queue: ";
    que.display();

    cout << "Size of Stack is " << stk.size() << endl;
    cout << "Size of Queue is " << que.size() << endl;
    return 0;
}
Time Complexity: O(n)
Auxiliary Space: O(n)	
--------------------------------------------------------------------------------
12) Evaluation of Postfix Expression:
Given a postfix expression, the task is to evaluate the postfix expression.
Postfix expression: The expression of the form “a b operator” (ab+) i.e., when a pair of operands is followed by an operator.

Examples:
Input: str = “2 3 1 * + 9 -“
Output: -4
Explanation: If the expression is converted into an infix expression, it will be 2 + (3 * 1) – 9 = 5 – 9 = -4.

Input: str = “100 200 + 2 / 5 * 7 +”
Output: 757

Evaluation of Postfix Expression using Stack:
To evaluate a postfix expression we can use a stack.

Iterate the expression from left to right and keep on storing the operands into 
a stack. Once an operator is received, pop the two topmost elements and evaluate 
them and push the result in the stack again.

// C++ program to evaluate value of a postfix expression
#include <bits/stdc++.h>
using namespace std;

// The main function that returns value 
// of a given postfix expression
int evaluatePostfix(string exp)
{
	// Create a stack of capacity equal to expression size
	stack<int> st;

	// Scan all characters one by one
	for (int i = 0; i < exp.size(); ++i) {
		
		// If the scanned character is an operand 
		// (number here), push it to the stack.
		if (isdigit(exp[i]))
			st.push(exp[i] - '0');

		// If the scanned character is an operator, 
		// pop two elements from stack apply the operator
		else {
			int val1 = st.top();
			st.pop();
			int val2 = st.top();
			st.pop();
			switch (exp[i]) {
			case '+':
				st.push(val2 + val1);
				break;
			case '-':
				st.push(val2 - val1);
				break;
			case '*':
				st.push(val2 * val1);
				break;
			case '/':
				st.push(val2 / val1);
				break;
			}
		}
	}
	return st.top();
}

// Driver code
int main()
{
	string exp = "231*+9-";

	// Function call
	cout << "postfix evaluation: " << evaluatePostfix(exp);
	return 0;
}
Time Complexity: O(N) 
Auxiliary Space: O(N)
-------------------------------Hard------------------------------------------------------
----------------------------------------------------------------------------------

Trapping Rainwater:(Hard)
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

----------------------------------------------------------------
Largest Histogram:


-------------------------------------------------------------------
Maximal Rectangle

----------------------------------------------------------------------
Sliding Window Maximum



--------------------------------------------------------------------------
LRU Cache

--------------------------------------------------------------------------
Celebrity problem

