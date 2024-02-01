Example 1:
Input: nums = [10,9,2,5,3,7,101,18]
Output: 4
Explanation: The longest increasing subsequence is [2,3,7,101], therefore the length is 4.
Example 2:

Input: nums = [0,1,0,3,2,3]
Output: 4

-------------------------------------------------------------------------------------
// Function to find the length of the longest increasing subsequence
int getAns(vector<int>nums, int n, int ind, int prev_index, vector<vector<int>>& dp) {
    // Base condition
    if (ind == n)
        return 0;
        
    if (dp[ind][prev_index + 1] != -1)
        return dp[ind][prev_index + 1];
    //Not Take case: length would be 0, as did not take current index. prev_index would remain same.
    int notTake = 0 + getAns(nums, n, ind + 1, prev_index, dp);

    //Take case: 1) if it's first index(prev_index=-1), it must be included
    // 2) if current element > prev element(means it's increasing)
    // prev_index will be ind and current ind would become now ind+1 to make new call
    
    int take = 0;
    if (prev_index == -1 || nums[ind] > nums[prev_index]) {
        take = 1 + getAns(nums, n, ind + 1, ind, dp);
    }
    
    return dp[ind][prev_index + 1] = max(notTake, take);
}

    int lengthOfLIS(vector<int>& nums)
    {
        int n=nums.size();
         // Create a 2D DP array initialized to -1
        vector<vector<int>> dp(n, vector<int>(n + 1, -1)); //2D DP: 1D for current index and 1D for prev index{-1 ...n}
        return getAns(nums, n, 0, -1, dp);
    }
