Problem:
You are given an integer array coins representing coins of different denominations and an integer
amount representing a total amount of money.
Return the fewest number of coins that you need to make up that amount. 
If that amount of money cannot be made up by any combination of the coins, return -1.
You may assume that you have an infinite number of each kind of coin.

 Recurrence_relation:
 f(ind, T)
 {
   //Base case:
   if(ind==0)
   {
    return (T%arr[0] ==0);
   }
   //Not take:
   notTake = f(ind-1, T)
   //Take:
    take=0
    if(arr[ind]<=T) //we can take it as current index value is less than or equal to Target sum
    take= f(ind, T-arr[ind])
    return take+notTake; 
    
 }
-----------------------------------------------------------------------------------
Example 1:

Input: coins = [1,2,5], amount = 11
Output: 3
Explanation: 11 = 5 + 5 + 1
Example 2:

Input: coins = [2], amount = 3
Output: -1
Example 3:

Input: coins = [1], amount = 0
Output: 0
 


long countWaysToMakeChangeUtil(vector<int>& arr, int ind, int T, vector<vector<long>>& dp) {
    // Base case: if we're at the first element
    if (ind == 0) {
        // Check if the target sum is divisible by the first element
        return (T % arr[0] == 0);
    }
    
    // If the result for this index and target sum is already calculated, return it
    if (dp[ind][T] != -1)
        return dp[ind][T];
        
    // Calculate the number of ways without taking the current element
    long notTaken = countWaysToMakeChangeUtil(arr, ind - 1, T, dp);
    
    // Calculate the number of ways by taking the current element
    long taken = 0;
    if (arr[ind] <= T)
        taken = countWaysToMakeChangeUtil(arr, ind, T - arr[ind], dp);
        
    // Store the sum of ways in the DP table and return it
    return dp[ind][T] = notTaken + taken;
}

    int coinChange(vector<int>& coins, int amount) 
    {
        int n=coins.size();
        vector<vector<long>> dp(n, vector<long>(amount+1 , -1)); // Create a DP table
    
    // Call the utility function to calculate the answer
    return countWaysToMakeChangeUtil(coins, n - 1, amount, dp);
    }
