Example 1:
Input: nums = [10,9,2,5,3,7,101,18]
Output: 4
Explanation: The longest increasing subsequence is [2,3,7,101], therefore the length is 4.
Example 2:

Input: nums = [0,1,0,3,2,3]
Output: 4

Recurrence_relation:
 f(ind, prev_ind) //f(0, -1) //first call to this method would be
 {
   //Base case: Reached at last index and no other index is left to pick
   if(ind==n)
   {
    return 0;
   }
   //Not take:
   notTake = 0+  f(ind+1, prev_ind)
   //Take:
    take=0
    take= 1+ f(ind+1, ind)
    return max(notTake, take)
 }   
 
-------------------------------------------------------------------------------------
 // Function to find the length of the longest increasing subsequence
int getAns(int ind, int prev_index, vector<int>nums, int n, vector<vector<int>>& dp) {
    // Base condition
    if (ind == n)
        return 0;
        
    if (dp[ind][prev_index + 1] != -1)
        return dp[ind][prev_index + 1];
    
    int notTake = 0 + getAns(ind + 1, prev_index, nums, n, dp);
    
    int take = 0;
    
    if (prev_index == -1 || nums[ind] > nums[prev_index]) {
        take = 1 + getAns(ind + 1, ind, nums, n, dp);
    }
    
    return dp[ind][prev_index + 1] = max(notTake, take);
}

    int lengthOfLIS(vector<int>& nums)
    {
        int n=nums.size();
         // Create a 2D DP array initialized to -1
        vector<vector<int>> dp(n, vector<int>(n + 1, -1));
        return getAns(0, -1, nums, n, dp); //getAns(ind, prev_ind, num_array, n, dp)
    }
