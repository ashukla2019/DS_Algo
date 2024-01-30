//Fibonacci series: 0 1 1 2 3 5 8 ...
Observation: Every nth term is result of/sum of n-1th and n-2th term. To solve T(n), we need to solve 
subproblems, can be solved by recursion method.
//Recurrence relation:
f(n) = f(n-1) + f(n-2), except n=0 and n=1(will be part of base case)

//Using recursion
int fib(int n) 
{
	//Base case:
	if(n<2) //while n=0 and n=1
		return n;
	return f(n-1)+f(n-2);
}
Time complexity: o(2^n)

Memorization:
int fib(int n) 
{
	vector<int>dp(n+1,-1);
	
	//Base case:
	if(n<2) //while n=0 and n=1
		return n;
	if(dp[n] !=-1)
		return dp[n];
		
	return dp[n] = fib(n-1)+fib(n-2);
}
Time Complexity: O(N)
Reason: The overlapping subproblems will return the answer in constant time O(1). 
Therefore the total number of new subproblems we solve is ‘n’. Hence total time complexity is O(N).

Space Complexity: O(N)
Reason: We are using a recursion stack space(O(N)) and an array (again O(N)). 
Therefore total space complexity will be O(N) + O(N) ≈ O(N)

Tabulation:
 int fib(int n) 
{
	 vector<int> dp(n+1,-1);
  
  dp[0]= 0;
  dp[1]= 1;
  
  for(int i=2; i<=n; i++){
      dp[i] = dp[i-1]+ dp[i-2];
  }
  return dp[n];
}

Time Complexity: O(N)
Reason: We are running a simple iterative loop

Space Complexity: O(N)
Reason: We are using an external array of size ‘n+1’.
