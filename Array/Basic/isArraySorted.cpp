Example 1:
Input: N = 5, array[] = {1,2,3,4,5}
Output: True.
Explanation: The given array is sorted i.e Every element in the array is smaller than or 
equals to its next values, So the answer is True.
----------------------------------------------------------------------------   
  bool isSorted(int arr[], int n) 
{
  for (int i = 1; i < n; i++) 
  {
    if (arr[i] < arr[i - 1])
      return false;
  }

  return true;
}
Time Complexity: O(N)
Space Complexity: O(1)
