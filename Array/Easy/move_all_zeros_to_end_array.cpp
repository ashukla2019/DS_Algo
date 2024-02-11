Example 1:
Input: 1 ,0 ,2 ,3 ,0 ,4 ,0 ,1
Output: 1 ,2 ,3 ,4 ,1 ,0 ,0 ,0
Explanation: All the zeros are moved to the end and non-negative integers are moved to front by maintaining order

Example 2:
Input: 1,2,0,1,0,4,0
Output: 1,2,1,4,0,0,0
Explanation: All the zeros are moved to the end and non-negative integers are moved to front by maintaining order
------------------------------------------------------------------------------------------- 
vector<int> moveZeros(int n, vector<int> a) 
{
    int count=0;
    for(int i=0; i<n; j++)
    {
    	if(a[i] !=0) //Checking non_zero element and storing in array with new index count.
    	{
			arr[count++]=arr[i];
    	}
    }
    while(count<n) //count upto n value will have zeros so store them
    {
    	a[count++] = 0;
    }
    return a;
    
}
Time Complexity: O(N), N = size of the array.
Space Complexity: O(1) as we are not using any extra space to solve this problem.  
