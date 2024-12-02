Example 1:

Input: prices = {1, 1, 0, 1, 1, 1}

Output: 3

Explanation: There are two consecutive 1’s and three consecutive 1’s in the array out of which maximum is 3.

Input: prices = {1, 0, 1, 1, 0, 1} 

Output: 2

Explanation: There are two consecutive 1's in the array. 
------------------------------------------------------------------------  
int findMaxConsecutiveOnes(vector < int > & nums) 
{
      int cnt = 0;
      int maxi = 0;
      for (int i = 0; i < nums.size(); i++) 
      {
        if (nums[i] == 1) 
        {
          cnt++;
        } else 
        {
          cnt = 0;
        }

        maxi = max(maxi, cnt);
      }
      return maxi;
    }  
Time Complexity: O(N) since the solution involves only a single pass.
Space Complexity: O(1) because no extra space is used.
