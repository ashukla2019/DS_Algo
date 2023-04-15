/*
	Complexity: Easy
    Given array prices, return max profit w/ 1 buy & 1 sell
    Ex. prices = [7,1,5,3,6,4] -> 5 (buy at $1, sell at $6)

    For each, get diff b/w that & min value before, store max

    Time: O(n)
    Space: O(1)
*/

class Solution 
{
public:
    int maxProfitGain(vector<int>& prices) 
	{
        int minBuy = prices[0]; //buy should be minimum
        int maxProfit = 0; //profit should be max
        
        for (int i = 1; i < prices.size(); i++) 
		{
            minBuy = min(minBuy, prices[i]);
            maxProfit = max(maxProfit, prices[i] - minBuy);
        }
        
        return maxProfit;
    }
};