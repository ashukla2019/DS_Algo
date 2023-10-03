// Function to remove duplicate elements from sorted array
// This function returns new size of modified
// array. Time Complexity : O(n), Auxiliary Space : O(1)
int removeDuplicates(int arr[], int n)
{
    if (n==0 || n==1)
    {
        return n;
    }

    // To store index of next unique element
    int j = 0;

     // Doing same as done in Method 1
    // Just maintaining another updated index i.e. j
    for (int i=1; i < n-1; i++)
    {
        if (arr[i] != arr[j])
        {
            j++;
            arr[j] = arr[i];
        }
    }

    return j+1;
}
