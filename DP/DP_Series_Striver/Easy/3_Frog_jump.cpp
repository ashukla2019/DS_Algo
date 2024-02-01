/*Problem Statement:
Problem statement
There is a frog on the '1st' step of an 'N' stairs long staircase. The frog wants to reach the
'Nth' stair. 'HEIGHT[i]' is the height of the '(i+1)th' stair.If Frog jumps from 'ith' to 'jth'
stair, the energy lost in the jump is given by absolute value of ( HEIGHT[i-1] - HEIGHT[j-1] ). If the Frog is on 'ith' staircase, he can jump either to '(i+1)th' stair or to '(i+2)th' stair. Your task is to find the minimum total energy used by the frog to reach from '1st' stair to 'Nth' stair.
For Example
If the given ‘HEIGHT’ array is [10,20,30,10], the answer 20 as the frog can jump from 1st
stair to 2nd stair (|20-10| = 10 energy lost) and then a jump from 2nd stair to last stair
(|10-20| = 10 energy lost). So, the total energy lost is 20.

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
    vector<int>dp(n, -1); //DP array size would be n(1->n)
    int cost =totalEnergyLost(n-1, heights, dp); //we are considering array from 0 to n-1, so max index would be n-1
    return cost;
}
