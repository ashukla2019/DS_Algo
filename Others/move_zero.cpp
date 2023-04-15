/*
Given an integer array nums, move all 0's to the end of it while maintaining the relative
order of the non-zero elements.
Note that you must do this in-place without making a copy of the array.

Example 1:

Input: nums = [0,1,0,3,12]
Output: [1,3,12,0,0]
*/

void moveZeroes(vector<int>& nums) 
{
	fill(remove(nums.begin(), nums.end(), 0), nums.end(),0);
}