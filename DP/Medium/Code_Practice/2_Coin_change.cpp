Problem:
You are given an integer array coins representing coins of different denominations and an integer
amount representing a total amount of money.
Return the fewest number of coins that you need to make up that amount. 
If that amount of money cannot be made up by any combination of the coins, return -1.
You may assume that you have an infinite number of each kind of coin.

 Recurrence_relation:
 f(ind, T)  //f(n-1, T)
 {
   //Base case: reached to last index and should return return T/coins[0](divisible) or INT_MAX(not divisible)
         if(index==0)
        {
            if(T%coins[index]==0)
            {
                return T/coins[index];
            }
            else
            {
                return INT_MAX;
            }
           //Not take:
          notTake = f(ind-1, T)
         //Take:
         take=0
         if(arr[ind]<=T) //we can take it as current index value is less than or equal to Target sum
         take= f(ind, T-arr[ind]) //Don't jump to ind-1 index as coins have many denominations of it.
         return min(take, notTake);
    
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
 
int coinChangeUtil(int index, int T, vector<vector<int>>& dp, vector<int>& coins)
   {
        if(index==0)
        {
            if(T%coins[index]==0)
            {
                return T/coins[index];
            }
            else
            {
                return INT_MAX;
            }
        }
        if(dp[index][T]!=-1)
        {
            return dp[index][T];
        }
        int notTake=coinChangeUtil(index-1, T, dp, coins);
        int take=INT_MAX;
        if(T>=coins[index])
        {
            take=1+coinChangeUtil(index, T-coins[index], dp, coins);
        }
        return dp[index][T]=min(take, notTake);
    }
    int coinChange(vector<int>& coins, int amount) 
    {
        int n=coins.size();
        vector<vector<int>>dp(n, vector<int>(amount+1, -1));
        int ans=coinChangeUtil(n-1, amount, dp, coins);
        
        if(ans>=INT_MAX)
        {
            return -1;
        }
        return ans;
    }
