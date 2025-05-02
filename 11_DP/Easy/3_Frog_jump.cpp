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

Recurrence relation:
f(index, height[])
{
    //Base case:
    if(index==0)
        return 0; //energy loss would be 0.
    jumpone = f(index-1, height) + abs(height[index-1] - height[index])
    if(index>1)
    jumptwo = f(index-2, height) + abs(height[index-2] - height[index])  

        return min(jumpone, jumptwo)
}
------------------------------------------------------------------------------------------------------------
int solve(int ind, vector<int>& height, vector<int>& dp){
    if(ind==0) return 0;
    if(dp[ind]!=-1) return dp[ind];
    int jumpTwo = INT_MAX;
    int jumpOne= solve(ind-1, height,dp)+ abs(height[ind]-height[ind-1]);
    if(ind>1)
        jumpTwo = solve(ind-2, height,dp)+ abs(height[ind]-height[ind-2]);
    
    return dp[ind]=min(jumpOne, jumpTwo);
}


int main() {

  vector<int> height{30,10,60 , 10 , 60 , 50};
  int n=height.size();
  vector<int> dp(n,-1);
  cout<<solve(n-1,height,dp);
}

---------------------------------------
int main() {

  vector<int> height{30,10,60,10,60,50};
  int n=height.size();
  vector<int> dp(n,-1);
  dp[0]=0;
  for(int ind=1;ind<n;ind++){
      int jumpTwo = INT_MAX;
        int jumpOne= dp[ind-1] + abs(height[ind]-height[ind-1]);
        if(ind>1)
            jumpTwo = dp[ind-2] + abs(height[ind]-height[ind-2]);
    
        dp[ind]=min(jumpOne, jumpTwo);
  }
  cout<<dp[n-1];
}
