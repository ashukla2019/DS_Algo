Problem:
A thief is robbing a store and can carry a maximum weight of ‘W’ into his knapsack. 
There are 'N' items available in the store and the weight and value of each item is known
to the thief. Considering the constraints of the maximum weight that a knapsack can carry, 
you have to find the maximum profit that a thief can generate by stealing items.

Note: The thief is not allowed to break the items.

For example, N = 4, W = 10 and the weights and values of items are weights = [6, 1, 5, 3]
and values = [3, 6, 1, 4]. Then the best way to fill the knapsack is to choose items with 
weight 6, 1 and 3. The total value of knapsack = 3 + 6 + 4 = 13.

Observation:
we have indexes-> 0,1,2,3, will start from n-1th would be 3
f(index, W)
{
    // Base case
        if (ind == 0) {
            if (wt[0] <= W) return val[0];
            return 0;
        }
   int notpick = 0 + f(index-1, W) (if not picking current weight of n-1th index, adding 0 value and weight  will be w, as not picked
    //We can pick only if weight of current index <=W
    int pick = INT_MIN
    if(wt[index]<W)
        pick= val[index] + f(index-1, W-wt[index])
    return max(pick, notpick);
}
---------------------------------
    int f(int ind, int W, vector<int>& wt, vector<int>& val, vector<vector<int>>& dp) {
        // Base case
        if (ind == 0) {
            if (wt[0] <= W) return val[0];
            return 0;
        }
        
        
        if (dp[ind][W] != -1) return dp[ind][W];
        
    
        int notTake = 0 + f(ind - 1, W, wt, val, dp);
        
        
        int take = INT_MIN;
        if (wt[ind] <= W) {
            take = val[ind] + f(ind - 1, W - wt[ind], wt, val, dp);
        }
         
        return dp[ind][W] = max(take, notTake);
    }

    int knapsack(int W, vector<int>& val, vector<int>& wt) {
        int n = val.size();
        vector<vector<int>> dp(n, vector<int>(W + 1, -1));
        return f(n - 1, W, wt, val, dp);
    }
