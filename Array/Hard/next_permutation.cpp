Problem Statement: Given an array Arr[] of integers, rearrange the numbers of the given array 
into the lexicographically next greater permutation of numbers.
If such an arrangement is not possible, it must rearrange to the lowest possible order
(i.e., sorted in ascending order).
Input format: Arr[] = {1,3,2}
Output: Arr[] = {2,1,3}
Explanation: All permutations of {1,2,3} are {{1,2,3} , {1,3,2}, {2,13} , {2,3,1} ,
{3,1,2} , {3,2,1}}. So, the next permutation just after {1,3,2} is {2,1,3}.  
------------------------------------------------------------------------------  

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main() {
    int arr[] = {1,3,2};
    
    next_permutation(arr,arr+3);//using in-built function of C++
    
    cout<<arr[0]<<" "<<arr[1]<<" "<<arr[2];
    
    return 0;
}
  
