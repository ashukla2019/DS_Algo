//Fibnoci series: 0,1,1,2,3,5,8,13,21.... T(n) = O(n)
f(n) = f(n-1) + f(n-2) 
f(0) = 0
f(1) = 1
f(4) = f(3) + f(2) = 3
//let's see recursion method:
int fib(int n)
{
	//Base case:
	if(n<=1)
		return n;
	return fib(n-1) + fib(n-2);
}

//Recursion: when you have to perform all possible ways.
//recursion tree: steps for recursion: f(5) = f(4) + f(3) 
                                       f(4) = f(3) + f(2)
                                       f(3) = f(2) + f(1)
                                       f(2) = f(1) + f(0) //this is our base case, f(2) = 1
         f(5)                          it will be returned to f(3), now f(3) = 1 + 1 =2 will be returned to
         /   \                         f(4) = 2 + f(2) => now we should not calculate f(2) again.
        /     \                        overlapping subproblem: end up with solving same subproblem again
       /       \                       like f(2), f(3), which we already calculated at left subtree.
     f(4)     f(3)
     /   \      
  f(3)    f(2)  
   / \        
f(2) f(1) 
/   \
f(1) f(0)

time complexity: O(2^n)


//Memorization approach: Top Down approach: we start with max value and go back to base case(fn,fn-1,fn-2..)
    
int fib(int n, vector<int>& dp) 
{
	//Base case
	if(n<=1) 
		return n;
  
    //f(n) is already calculated
    if(dp[n] != -1)
    {
    	return dp[n];
    }
        
    dp[n] = fib(n-1) + fib(n-2);
    return dp[n];
}
    
    
//Tabulation method: Tabulation is a bottom-up method for solving DP problems.
//why it is bottom up: we are starting fib[0], fib[1], fib[2] ....fib[n]
//Time complexity: O(n) & space complexity: O(n)
int fib(int n) 
{
	int dp[n+1];
    if(n==0)
    {
	    return 0;
    }
    if(n==1){
	    return 1;
    }
    dp[0]=0;
    dp[1]=1;
    for(int i=2;i<n+1;i++){
	    dp[i]=dp[i-1]+dp[i-2];
    }
    return dp[n];
    }
};


//using two variables prev1 and prev2:
//Time complexity: O(n) & space complexity: O(1)
int fib(int n)
{
	int prev2 = 0;
	int prev1 = 1;
	for(int i =2; i<=n; i++)
	{
		int current = prev1 + prev2;
		prev2 = prev1;
		prev1 = current;
	}
r	eturn prev;
}

