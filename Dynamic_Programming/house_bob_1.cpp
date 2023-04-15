//House rob-1:
/*
You are a professional robber planning to rob houses along a street. 
Each house has a certain amount of money stashed, the only constraint stopping
you from robbing each of them is that adjacent houses have security systems 
connected and it will automatically contact the police if two adjacent houses 
were broken into on the same night.
Input array: [2,7,9,3,1]
*/
int rob(vector<int>& nums) 
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
