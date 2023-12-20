/* Program to implement a stack using
two queue */
/*
//Logic:
push(x)
1) x->Q2
2) Q1 -> Q2
3) swap(Q1, Q2)
Pop():
remove Q1.top()
*/

#include <bits/stdc++.h>
using namespace std;

class Stack {
	// Two inbuilt queues
	queue<int> q1, q2;

public:
	void push(int x)
	{
		// Push x first in empty q2
		q2.push(x);

		// Push all the remaining
		// elements in q1 to q2.
		while (!q1.empty()) {
			q2.push(q1.front());
			q1.pop();
		}

		// swap the names of two queues
		queue<int> q = q1;
		q1 = q2;
		q2 = q;
	}

	void pop()
	{
		// if no elements are there in q1
		if (q1.empty())
			return;
		q1.pop();
	}

	int top()
	{
		if (q1.empty())
			return -1;
		return q1.front();
	}

	int size() { return q1.size(); }
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
--------------------------------------------------------------------------------------
/* Program to implement a stack using
single queue */
/*
Logic:
push(x)
1) x -> Q1
2) Pop Q1 and push to Q1
Pop()
Q1.pop()
*/	
	
#include <bits/stdc++.h>
using namespace std;

// Stack Class that acts as a queue
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
  
