//Maximum sub array: Kadane's algo:
/*
Given an integer array nums, find the contiguous subarray (containing at least one 
number) which has the largest sum and return its sum.
A subarray is a contiguous part of an array.

Input: nums = [-2,1,-3,4,-1,2,1,-5,4]
Output: 6
Explanation: [4,-1,2,1] has the largest sum = 6.
*/
-------------------------------------------------------------------------------------------------
Brute Force approach:
We will check the sum of every possible subarray and consider the maximum among them. 
To get every possible subarray sum, we will be using three nested loops. The first loops(say i and j) will iterate over
every possible starting index and ending index of a subarray. Basically, in each iteration, the subarray range will be 
from index i to index j. Using another loop we will get the sum of the elements of the subarray [i…..j]. Among all values
of the sum calculated, we will consider the maximum one.

code:
#include <bits/stdc++.h>
using namespace std;

int maxSubarraySum(int arr[], int n) {
    int maxi = INT_MIN; // maximum sum

    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            // subarray = arr[i.....j]
            int sum = 0;

            //add all the elements of subarray:
            for (int k = i; k <= j; k++) {
                sum += arr[k];
            }

            maxi = max(maxi, sum);
        }
    }

    return maxi;
}

int main()
{
    int arr[] = { -2, 1, -3, 4, -1, 2, 1, -5, 4};
    int n = sizeof(arr) / sizeof(arr[0]);
    int maxSum = maxSubarraySum(arr, n);
    cout << "The maximum subarray sum is: " << maxSum << endl;
    return 0;
}
Time Complexity: O(N3), where N = size of the array.
Reason: We are using three nested loops, each running approximately N times.
Space Complexity: O(1) as we are not using any extra space.
----------------------------------------------------------------------------------------------------------
DP Approach:	
int maxSubArray(vector<int>& nums) 
{
	int totalMaxSum = nums[0], currMaxSum = nums[0];
	for (int i = 1; i < nums.size(); i++) 
	{
		currMaxSum = max(currMaxSum + nums[i], nums[i]);
		totalMaxSum = max(totalMaxSum, currMaxSum);
	}
	return totalMaxSum;
}

Time Complexity: O(N), where N = size of the array.
Space Complexity: O(1) as we are not using any extra space.

---------------------------------------------------------------------------------------------------------------
Divide & Conquer approach:

	
	
