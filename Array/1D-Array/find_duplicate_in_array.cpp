Problem Statement: Given an array of N + 1 size, where each element is between 1 and N. Assuming there is only one duplicate number, 
your task is to find the duplicate number.

Example 1: 
Input: arr=[1,3,4,2,2]
Output: 2

Solution 1:Using sorting  
Code:
#include<bits/stdc++.h>

using namespace std;
int findDuplicate(vector < int > & arr) {
  int n = arr.size();
  sort(arr.begin(), arr.end());
  for (int i = 0; i < n - 1; i++) {
    if (arr[i] == arr[i + 1]) {
      return arr[i];
    }
  }
}
int main() {
  vector < int > arr;
  arr = {1,3,4,2,2};
  cout << "The duplicate element is " << findDuplicate(arr) << endl;
}  
Time Complexity:O(Nlogn + N)
Reason: NlogN for sorting the array and O(N) for traversing through the array and checking if adjacent elements are equal or not. But this will distort the array.
Space Complexity:O(1)  

 ------------------------------------------------------------------------------------------------------
 Solution 2:Using frequency array
#include<bits/stdc++.h>
using namespace std;
int findDuplicate(vector < int > & arr) {
  int n = arr.size();
  int freq[n + 1] = {
    0
  };
  for (int i = 0; i < n; i++) {
    if (freq[arr[i]] == 0) {
      freq[arr[i]] += 1;
    } else {
      return arr[i];
    }
  }
  return 0;
}
int main() {
  vector < int > arr;
  arr = {1,3,4,2,3};
  cout << "The duplicate element is " << findDuplicate(arr) << endl;
}
Output: The duplicate element is 3

Time Complexity: O(N), as we are traversing through the array only once.
Space Complexity: O(N), as we are using extra space for frequency array.  
  
