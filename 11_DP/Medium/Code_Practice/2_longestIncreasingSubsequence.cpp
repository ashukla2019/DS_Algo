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
    //Base case: we start from 0 index and when we reach n which means out of range[0..n-1], will return 0
    if (ind == n)
        return 0;
     
//column size would start from prev_index +1 as -1 can not be valid index.   
    if (dp[ind][prev_index + 1] != -1)
        return dp[ind][prev_index + 1];
    
    int notTake = 0 + getAns(ind + 1, prev_index, nums, n, dp);
    
    int take = 0;
    /*if its first element(prev_index = -1) or element of curent index is greater than previous index then only take it in solution*/ 
    if (prev_index == -1 || nums[ind] > nums[prev_index]) {
        take = 1 + getAns(ind + 1, ind, nums, n, dp);
    }
    
    return dp[ind][prev_index + 1] = max(notTake, take);
}

    int lengthOfLIS(vector<int>& nums)
    {
        int n=nums.size();
         // Create a 2D DP array initialized to -1
        vector<vector<int>> dp(n, vector<int>(n + 1, -1));// current index: 0 ->1 and precious_index: -1 to n(n+1)
        return getAns(0, -1, nums, n, dp); //getAns(ind, prev_ind, num_array, n, dp)
    }
