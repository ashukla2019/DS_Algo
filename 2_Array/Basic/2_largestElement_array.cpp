Example 1:
Input: arr[] = {2,5,1,3,0};
Output: 5
Explanation: 5 is the largest element in the array. 

Example2: 
Input: arr[] = {8,10,5,7,9};
Output: 10
Explanation: 10 is the largest element in the array. 
  ------------------------------------------------------------------------------
  int findLargestElement(int arr[], int n) 
{
   int max = arr[0];
  for (int i = 0; i < n; i++) 
  {
    if (max < arr[i]) 
    {
      max = arr[i];
    }
  }
  return max;
}
Time Complexity: O(N)
Space Complexity: O(1)
