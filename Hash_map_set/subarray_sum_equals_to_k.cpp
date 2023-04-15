/*
Given an array of integers nums and an integer k, return the total number of 
subarrays whose sum equals to k.
A subarray is a contiguous non-empty sequence of elements within an array.

Input: nums = [1,1,1], k = 2
Output: 2

Input: nums = [1,2,3], k = 3
Output: 2

*/

int subarraySum(vector<int>& nums, int k) 
{
	std::unordered_map<int, int> seen = {{0, 1}};
	int count = 0, sum = 0;
	for (auto n: nums) 
	{
		sum += n;
		count += seen[sum - k];
		seen[sum]++;
	}
    return count;
}