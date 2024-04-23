Given an integer array nums and an integer k, return the kth largest element in the array.
Note that it is the kth largest element in the sorted order, not the kth distinct element.
Can you solve it without sorting? (with sorting it will be N(logn)

Example 1:
Input: nums = [3,2,1,5,6,4], k = 2
Output: 5
  
Example 2:
Input: nums = [3,2,3,1,2,4,5,5,6], k = 4
Output: 4
-------------------------------------------------------------------------------------------------------  
Approach 1: using max heap: total complexity would be O(n) + k(logn) = O(n)
  int findKthLargest(vector<int>& nums, int k) 
    {
        int ans=0;
        priority_queue<int>pq(nums.begin(), nums.end()); //O(n)
        while(k--)
        {
            ans=pq.top();
            pq.pop();
        }
        return ans;
    } 

Approach 2: using min heap: 
 int findKthLargest(vector<int>& nums, int k) 
    {
        int ans=0;
        priority_queue<int, vector<int>, greater<int>>pq;
        for(auto x: nums)
        {
            pq.push(x);
            if(pq.size()>k)
                pq.pop();
        }
        return pq.top();
    }
