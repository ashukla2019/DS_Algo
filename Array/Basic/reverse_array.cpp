//Reverse array
void reverseArray(int arr[], int n)
{
    int t, i;
    for (i = 0; i < n/2; i++) 
    {
        t = arr[i];
        arr[i] = arr[n-1-i];
        arr[n-1-i] = t;    
        
    }
}
