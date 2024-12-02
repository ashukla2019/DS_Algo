//House rob-2:
/*
You are a professional robber planning to rob houses along a street. 
Each house has a certain amount of money stashed. All houses at this place are 
arranged in a circle. That means the first house is the neighbor of the last one.
Meanwhile, adjacent houses have a security system connected, and it will automatically
contact the police if two adjacent houses were broken into on the same night.
Input array: [1,2,3,1]
*/
int robOriginal(vector<int>& nums) 
{ 
	int n = nums.size(), pre = 0, cur = 0;
	for (int i = 0; i < n; i++) 
	{
		int temp = max(pre + nums[i], cur);
		pre = cur;
		cur = temp;
	 }
	return cur;
}

int rob(vector<int>& nums) 
{
	if(nums.empty()) return 0;
	if(nums.size() == 1) return nums[0];

	vector<int> numsA(nums.begin() + 1, nums.end());
	vector<int> numsB(nums.begin(), nums.end()-1);

	return max(robOriginal(numsA), robOriginal(numsB));
}
