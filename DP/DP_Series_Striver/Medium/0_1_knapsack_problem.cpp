Problem:
A thief is robbing a store and can carry a maximum weight of ‘W’ into his knapsack. 
There are 'N' items available in the store and the weight and value of each item is known
to the thief. Considering the constraints of the maximum weight that a knapsack can carry, 
you have to find the maximum profit that a thief can generate by stealing items.

Note: The thief is not allowed to break the items.

For example, N = 4, W = 10 and the weights and values of items are weights = [6, 1, 5, 3]
and values = [3, 6, 1, 4]. Then the best way to fill the knapsack is to choose items with 
weight 6, 1 and 3. The total value of knapsack = 3 + 6 + 4 = 13.
------------------------------------------------------------------------------
// Function to solve the 0/1 Knapsack problem using memoization
int knapsackUtil(vector<int>& wt, vector<int>& val, int ind, int W, vector<vector<int>>& dp) {
    // Base case: If there are no items left or the knapsack has no capacity, return 0
    if (ind == 0 || W == 0) {
        return 0;
    }

    // If the result for this state is already calculated, return it
    if (dp[ind][W] != -1) {
        return dp[ind][W];
    }

    // Calculate the maximum value by either excluding the current item or including it
    int notTaken = knapsackUtil(wt, val, ind - 1, W, dp);
    int taken = 0;

    // Check if the current item can be included without exceeding the knapsack's capacity
    if (wt[ind] <= W) {
        taken = val[ind] + knapsackUtil(wt, val, ind - 1, W - wt[ind], dp);
    }

    // Store the result in the DP table and return
    return dp[ind][W] = max(notTaken, taken);
}


int maxProfit(vector<int> &values, vector<int> &weights, int n, int w)
{
	vector<vector<int>> dp(n, vector<int>(w + 1, -1));
    return knapsackUtil(weights, values, n-1, w, dp);
}
