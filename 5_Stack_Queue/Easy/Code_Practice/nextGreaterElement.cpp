Problem:
You are given an array 'a' of size 'n'.
Print the Next Greater Element(NGE) for every element.
The Next Greater Element for an element 'x' is the first element on the right side of 'x' in the array, which is
greater than 'x'.

If no greater elements exist to the right of 'x', consider the next greater element as -1.

For example:
Input: 'a' = [7, 12, 1, 20]

Output: NGE = [12, 20, 20, -1]

Explanation: For the given array,

- The next greater element for 7 is 12.

- The next greater element for 12 is 20. 

- The next greater element for 1 is 20. 

- There is no greater element for 20 on the right side. So we consider NGE as -1.

------------------------------------------------------------------------------
#include<bits/stdc++.h>

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
			st.pop();
		}
		//Now update ans array with stack.top(), as it's next greater element
		if (!st.empty())
		{
			ans[i] = st.top();
		}
		//push array element to stack...
		st.push(nums[i]);
	}
	return ans;
}  

