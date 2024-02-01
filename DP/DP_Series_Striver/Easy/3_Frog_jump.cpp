//Observation: Frog will jump from 1 to nth stair in two ways: jump step 1 or step 2. Basically, we need 
to check all possible way and then minimum energy consumption from it, so recursion would be applied to
solve the problem.

int totalEnergyLost(int index, vector<int> &heights, vector<int>&dp)
{
    if(dp[index] != -1)
        return dp[index];
    //Base case:
    if(index==0)
        return 0;
    int oneStepJump= totalEnergyLost(index-1, heights, dp) + abs(heights[index-1] - heights[index]);
    int twoStepJump=INT_MAX;
    if(index>1)
        twoStepJump= totalEnergyLost(index-2, heights, dp) + abs(heights[index-2] - heights[index]);
    return dp[index] =min(oneStepJump, twoStepJump);    
}


int frogJump(int n, vector<int> &heights)
{
    vector<int>dp(n, -1);
    int cost =totalEnergyLost(n-1, heights, dp);
    return cost;
}
