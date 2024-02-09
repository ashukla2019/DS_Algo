Example 1:
Input:
 arr = [4, 7, 1, 0]
Output:
 7 1 0
Explanation:
 Rightmost element is always a leader. 7 and 1 are greater than the elements in their right side.

Example 2:
Input:
 arr = [10, 22, 12, 3, 0, 6]
Output:
 22 12 6
Explanation:
 6 is a leader. In addition to that, 12 is greater than all the elements in its right side (3, 0, 6), also 22 is greater than 12, 3, 0, 6.
------------------------------------------------------------------------------------ 
//An element is leader if it is greater than all the elements to its right side. And the rightmost element is always a leader. For ////example //int the array {16, 17, 4, 3, 5, 2}, leaders are 17, 5 and 2
/*C++ Function to print leaders in an array */
void printLeaders(int arr[], int size) 
{ 
    int max_from_right =  arr[size-1]; 
  
    /* Rightmost element is always leader */
    cout << max_from_right << " "; 
      
    for (int i = size-2; i >= 0; i--) 
    { 
        if (max_from_right <= arr[i])  
        {            
            max_from_right = arr[i]; 
            cout << max_from_right << " "; 
        } 
    }     
}   
