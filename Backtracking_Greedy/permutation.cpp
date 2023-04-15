//Permutations:Given an array nums of distinct integers, return all the possible
// permutations. You can return the answer in any order.
/*
Input: nums = [1,2,3]
Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
*/
vector<vector<int>> permute(vector<int>& nums)
{
	
	sort(nums.begin(),nums.end());
	vector<vector<int>> ans;
	ans.push_back(nums);
	while(next_permutation(nums.begin(),nums.end()))
	{
		ans.push_back(nums);
	}
	
	return ans;
}


