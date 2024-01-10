/*
1) Take two variables: maxsum(will have final sum) and currentsum(sum till current iteration)
2) Iterate through all array values and add them: currentsum=currentsum+nums[i]
3) In every iteration check if currentsum>maxsum then update maxsum with this value
*/  

int maxSubArray(vector<int>& nums) 
    {
        int maxSum = 0;
        int currentSum = 0;
        
        for (int i = 0; i < nums.size(); i++) 
        {
            currentSum += nums[i];
            
            if (currentSum > maxSum) 
            {
                maxSum = currentSum;
            }
            
            if (currentSum < 0) 
            {
                currentSum = 0;
            }
        }
        
        return maxSum;
    }
