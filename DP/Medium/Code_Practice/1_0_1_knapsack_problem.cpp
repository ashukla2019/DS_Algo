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
    //Base case:
    if(index==0) //this is first item, so we will see if weight[index]<=W, then take it else return 0
    {
        if(wt[0]<W)
        {
            return val[0];
        }
        else
        {
            return 0;
        }
    int notpick= 0 + f(index-1, W) (if not picking current weight of n-1th index, adding 0 value and weight  will be w, as not picked
    //We can pick only if weight of current index <=W
    int take = INT_MIN
    if(wt[index]<W)
        pick= val[index] + f(index-1, W-values[index])
    return max(pick, notpick);
}
------------------------------------------------------------------------------
int knapsackUtil(int W, int wt[], int val[], int index, vector<vector<int>>&dp)
    {
       //Base case:
       if (index < 0) 
       {
            return 0;
       }

       
    // If the result for this state is already calculated, return it
    if (dp[index][W] != -1) {
        return dp[index][W];
    }

    // Calculate the maximum value by either excluding the current item or including it
    int notTaken = knapsackUtil(W, wt, val, index - 1, dp);
    int taken = 0;

    // Check if the current item can be included without exceeding the knapsack's capacity
    if (wt[index] <= W) {
        taken = val[index] + knapsackUtil(W - wt[index], wt, val, index - 1, dp);
    }

    // Store the result in the DP table and return
    return dp[index][W] = max(notTaken, taken);
       
    }
    //Function to return max value that can be put in knapsack of capacity W.
    int knapSack(int W, int wt[], int val[], int n) 
    { 
       vector<vector<int>>dp(n, vector<int>(W+1, -1));    
       return knapsackUtil(W, wt, val, n-1, dp);
    }
    
