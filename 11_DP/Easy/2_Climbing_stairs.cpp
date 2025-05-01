Problem Statement: Given a number of stairs. Starting from the 0th stair we need to climb to the
“Nth” stair. At a time we can climb either one or two steps. We need to return the total number 
of distinct ways to reach from 0th to Nth stair.

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
        vector<int>dp(n+1, -1); //steps 0->n(n+1)
	    //Base case: 
	    //if n=1, there is only one way(1 step move) and n=0 then there is only one way.
	    if(n<=2)
		    return n;
        if(dp[n] != -1)    
            return dp[n];
	    return dp[n]=climbStairs(n-1)+climbStairs(n-2);
    }
-------------------------------------
Tabulation:
#include <iostream>
#include <vector>

using namespace std;

int climbStairs(int n) {
    if (n <= 2) {
        return n;
    }

    vector<int> dp(n + 1);
    dp[1] = 1;
    dp[2] = 2;

    for (int i = 3; i <= n; ++i) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }

    return dp[n];
}

int main() {
    int n;
    cout << "Enter the number of stairs: ";
    cin >> n;

    int ways = climbStairs(n);
    cout << "Number of ways to climb " << n << " stairs: " << ways << endl;

    return 0;
}