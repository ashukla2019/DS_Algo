//Maximum sub array: Kadane's algo:
/*
Given an integer array nums, find the contiguous subarray (containing at least one 
number) which has the largest sum and return its sum.
A subarray is a contiguous part of an array.

Input: nums = [-2,1,-3,4,-1,2,1,-5,4]
Output: 6
Explanation: [4,-1,2,1] has the largest sum = 6.
*/

int maxSubArray(vector<int>& nums) 
{
	int totalMaxSum = nums[0], currMaxSum = nums[0];
	for (int i = 1; i < nums.size(); i++) 
	{
		currMaxSum = max(currMaxSum + nums[i], nums[i]);
		totalMaxSum = max(totalMaxSum, currMaxSum);
	}
	return totalMaxSum;
}
