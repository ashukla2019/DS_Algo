//Fibnoci series: 0,1,1,2,3,5,8,13,21.... T(n) = O(n)
//Tabulation method: Tabulation is a bottom-up method for solving DP problems.
//why it is bottom up: we are starting fib[0], fib[1], fib[2] ....fib[n]
int fib(int n) 
{
        if(n==0) return 0;
        int fibo[n+1];
        fibo[0] = 0;
        fibo[1] = 1;
        for(int i=2;i<=n;i++)
            fibo[i] = fibo[i-1] + fibo[i-2];
        return fibo[n];
}

//Memorization approach: Top Down approach
int[] dp = new int[31];
    
    public int fib(int n) {
        if(n<=1) return n;
        
        if(dp[n]>0){
            return dp[n];
        }
        
        dp[n] = fib(n-1) + fib(n-2);
        return dp[n];
    }

