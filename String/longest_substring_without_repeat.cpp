Problem Statement: Given a String, find the length of longest substring without any repeating character.
Example 1:
Input: s = ”abcabcbb”
Output: 3
Explanation: The answer is abc with length of 3.

Example 2:
Input: s = ”bbbbb”
Output: 1
Explanation: The answer is b with length of 1 units.  
 ------------------------------------------------------------------------------------ 
Solution 1: Brute force Approach:
Approach: This approach consists of taking the two loops one for traversing the string and another loop – nested loop 
for finding different substrings and after that, we will check for all substrings one by one and check for each and 
every element if the element is not found then we will store that element in HashSet otherwise we will break from the
loop and count it.
  
#include<bits/stdc++.h>
using namespace std;

int solve(string str) {

  if(str.size()==0)
      return 0;
  int maxans = INT_MIN;
  for (int i = 0; i < str.length(); i++) // outer loop for traversing the string
  {
    unordered_set < int > set;
    for (int j = i; j < str.length(); j++) // nested loop for getting different string starting with str[i]
    {
      if (set.find(str[j]) != set.end()) // if element if found so mark it as ans and break from the loop
      {
        maxans = max(maxans, j - i);
        break;
      }
      set.insert(str[j]);
    }
  }
  return maxans;
}

int main() {
  string str = "takeUforward";
  cout << "The length of the longest substring without repeating characters is " << 
  solve(str);
  return 0;
}
Time Complexity: O( N2 )
Space Complexity: O(N) where N is the size of HashSet taken for storing the elements.

----------------------------------------------------------------------------------------------------
Solution 2: Optimised  Approach
We will have two pointers left and right. Pointer ‘left’ is used for maintaining the starting point of the substring
while ‘right’ will maintain the endpoint of the substring.’ right’ pointer will move forward and check for the duplicate
occurrence of the current element if found then the ‘left’ pointer will be shifted ahead so as to delete the duplicate
elements.

#include <bits/stdc++.h>

#include<unordered_set>

using namespace std;

int solve(string str) {

  if(str.size()==0)
      return 0;
  int maxans = INT_MIN;
  unordered_set < int > set;
  int l = 0;
  for (int r = 0; r < str.length(); r++) // outer loop for traversing the string
  {
    if (set.find(str[r]) != set.end()) //if duplicate element is found
    {
      while (l < r && set.find(str[r]) != set.end()) {
        set.erase(str[l]);
        l++;
      }
    }
    set.insert(str[r]);
    maxans = max(maxans, r - l + 1);
  }
  return maxans;
}

int main() {
  string str = "takeUforward";
  cout << "The length of the longest substring without repeating characters is " << 
  solve(str);
  return 0;
}  
Time Complexity: O( 2*N ) (sometimes left and right both have to travel a complete array)
Space Complexity: O(N) where N is the size of HashSet taken for storing the elements

