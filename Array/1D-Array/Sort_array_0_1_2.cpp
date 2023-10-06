Problem Statement: Given an array consisting of only 0s, 1s, and 2s. 
Write a program to in-place sort the array without using inbuilt sort functions.
( Expected: Single pass-O(N) and constant space)

Approach: 
Take 3 variables to maintain the count of 0, 1 and 2.
Travel the array once and increment the corresponding counting variables
( let’s consider count_0 = a, count_1 = b, count_2 = c )
In 2nd traversal of array, we will now over write the first ‘a’ indices / positions in 
array with ’0’, the next ‘b’ with ‘1’ and the remaining ‘c’ with ‘2’.
	
Code:
#include <bits/stdc++.h>
using namespace std;

void sortArray(vector<int>& arr, int n) {

    int cnt0 = 0, cnt1 = 0, cnt2 = 0;

    for (int i = 0; i < n; i++) {
        if (arr[i] == 0) cnt0++;
        else if (arr[i] == 1) cnt1++;
        else cnt2++;
    }

    //Replace the places in the original array:
    for (int i = 0; i < cnt0; i++) arr[i] = 0; // replacing 0's

    for (int i = cnt0; i < cnt0 + cnt1; i++) arr[i] = 1; // replacing 1's

    for (int i = cnt0 + cnt1; i < n; i++) arr[i] = 2; // replacing 2's

}

int main()
{
    int n = 6;
    vector<int> arr = {0, 2, 1, 2, 0, 1};
    sortArray(arr, n);
    cout << "After sorting:" << endl;
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}
