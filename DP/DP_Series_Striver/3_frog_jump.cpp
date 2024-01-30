//Observation: Frog will jump from 1 to nth stair in two ways: jump step 1 or step 2. Basically, we need 
to check all possible way and then minimum energy consumption from it, so recursion would be applied to
solve the problem.

int solve(int ind, vector<int>&heights, vector<int>&dp)
{
    if(ind==0) 
        return 0;
    if(dp[ind]!=-1) 
        return dp[ind];
    int jumpTwo = INT_MAX;
    int jumpOne= solve(ind-1, heights, dp)+ abs(heights[ind]-heights[ind-1]);
    if(ind>1)
        jumpTwo = solve(ind-2, heights, dp)+ abs(heights[ind]-heights[ind-2]);
    
    return dp[ind]=min(jumpOne, jumpTwo);
}

int frogJump(int n, vector<int> &heights)
{
    vector<int>dp(n+1, -1);
	int min_cost = solve(n, heights, dp);
    return min_cost;
}
