/*
Given an array of integers nums and an integer k, return the total number of subarrays
whose sum equals to k. 
A subarray is a contiguous non-empty sequence of elements within an array.

Example 1:
Input: nums = [1,1,1], k = 2
Output: 2

Example 2:
Input: nums = [1,2,3], k = 3
Output: 2

approach: Either sum of elements or sum -k will be solution.

*/

int subarraySum(vector<int>& nums, int k)
{
	int n = nums.size();
	int sum=0, count=0, i=0;
	unordered_map<int,int> m;
	for(int i=0; i<n; i++)
	{
		sum+=nums[i];
		if(sum==k)
		{
			count++;
		}
		if(m.find(sum-k)!=m.end())
		{
			count+=m[sum-k];
		}
		m[sum]++;  
	}
	return count;
}
