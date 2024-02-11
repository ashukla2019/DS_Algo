Example 1:
Input: [1,2,4,7,7,5]
Output: Second Smallest : 2
Second Largest : 5
Explanation: The elements are as follows 1,2,3,5,7,7 and hence second largest of these is 5 
and second smallest is 2

Example 2:
Input: [1]
Output: Second Smallest : -1
Second Largest : -1
Explanation: Since there is only one element in the array, it is the largest and smallest 
element present in the array. There is no second largest or second smallest element present.
---------------------------------------------------------------------------------------------- 
 int findSecondSmallestElement(int arr[])
{
	int n = sizeof(arr) / sizeof(arr[0]); 
    int smallest = INT_MAX; 
    // traversing the array to find 
    // smallest element. 
    for (int i = 0; i < n; i++) 
    { 
        if (arr[i] < smallest) 
        { 
            smallest = arr[i]; 
        } 
    } 
    cout << "smallest element is: " << smallest << endl; 
  
    int second_smallest = INT_MAX; 
  
    // traversing the array to find second smallest element 
    for (int i = 0; i < n; i++) 
    { 
        if (arr[i] < second_smallest && arr[i] > smallest) 
        { 
            second_smallest = arr[i]; 
        } 
    } 
    return second_smallest;
}
Time Complexity: O(n)
Auxiliary Space: O(1)
  
