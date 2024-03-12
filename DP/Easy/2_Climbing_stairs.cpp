Problem: There are n stairs, a person standing at the bottom wants to climb stairs to reach the nth stair.
The person can climb either 1 stair or 2 stairs at a time, the task is to count the number of ways 
that a person can reach at the top.

//Observation: We have to find all distinct ways to reach to top stair.
Recurrence releation:
f(n)=f(n-1)+f(n-2)

Recursion:
int climbStairs(int n) 
{
	//Base case: 
	//if n=1, there is only one way(1 step move) and n=0 then there is only one way.
	
	if(n<=1)
		return 1;
	return climbStairs(n-1)+climbStairs(n-2);
}

//Memorization
int climbStairs(int n) 
{
	vector<int>dp(n+1, -1);
	//Base case: 
	//if n=1, there is only one way(1 step move) and n=0 then there is only one way.
	if(n<=1)
		return 1;
    if(dp[n] != -1)    
        return dp[n];
	return dp[n]=climbStairs(n-1)+climbStairs(n-2);
}

//Tabulation:
int climbStairs(int n) 
{
	vector<int>dp(n+1, -1);
	//Base case: 
	//if n=1, there is only one way(1 step move) and n=0 then there is only one way.
	dp[0]=1;
	dp[1]=1;
    
	for(int i=2; i<=n; i++)
	{
		dp[i]=dp(i-1)+dp(i-2);
	}
	return dp[n];
}
