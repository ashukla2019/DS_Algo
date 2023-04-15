/*
    Given array in range [0, n], return missing
    Ex. nums = [3,0,1] -> 2, nums = [0,1] -> 2

*/

int getMissingNo(int a[], int n)
{
 
    int total = (n + 1) * (n + 2) / 2; //calculate total of given n numbers
    for (int i = 0; i < n; i++)
        total -= a[i];
    return total;
}

