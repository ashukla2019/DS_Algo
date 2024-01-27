Input: nums = [10,9,2,5]
Output: 2		
		f(index=0, prev_index=-1)
			     /\
           Pick /  \ Don't pick
               /    \
			f(1,0)   f(1,-1)  
			    /\
          pick /  \ Don't pick
              /    \
			f(2,1) f(2, -1)

Incase of pick, will increase length by 1 and incase of don't pick, will consider 0.
---------------------------------------------------------------------------------------------------------			
 int findLongestSubsequence(vector<int>nums, int n, int index, int prev_index, vector<vector<int>>& dp)
    {
        //Base condition: if traversed all the indexes, return 0
        if(index==n)
            return 0;

		//Check if dp array has value of current index updated: not -1(initialized one)
        if (dp[index][prev_index + 1] != -1)
			return dp[index][prev_index + 1];
    
	//Not take/Not pick: current idex would be index+1 and prev_index will remain unchanged
    int notTake = 0 + findLongestSubsequence(nums, n, index + 1, prev_index, dp);
    
    int take = 0;
    //take/pick: current idex would be index+1 and prev_index will be index now.
    if (prev_index == -1 || nums[index] > nums[prev_index]) 
    {
        take = 1 + findLongestSubsequence(nums, n, index + 1, index, dp);
    }
    
    return dp[index][prev_index + 1] = max(notTake, take);    
    }
    int lengthOfLIS(vector<int>& nums) 
    {
        int n = nums.size();
        vector<vector<int>>dp(n, vector<int>(n+1, -1));
        int length= findLongestSubsequence(nums, n, 0, -1, dp);
        return length;
    }
