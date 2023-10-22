Problem Statement: You are given two arrays of non-negative integers say ‘arr1’ and ‘arr2’ of sizes N and M respectively.
Find the maximum value of ( ‘A’ xor ‘B’ ) where ‘A’ and ‘B’ are any elements from ‘arr1’ and ‘arr2’ respectively and ‘xor’ represents the 
bitwise xor operation. Maximum XOR of Two Numbers in an Array.

Example 1:
Input: N=2, M=3
       arr1 = [6, 8] 
       arr2 = [7, 8, 2]

Output: 15
Explanation: Possible pairs are (6, 7), (6, 8), (6, 2), (8, 7), (8, 8), (6, 2). And 8 xor 7 will give the maximum result i.e. 15

Example 2:
Input: N=2, M=2
       arr1 = [1, 2
]
       arr2 = [1, 1]

Output: 3
Explanation: 3 is the maximum possible xor among all possible pairs.  
----------------------------------------------------------------------------------------------------------------  
Solution:
Pre-requisite: Bit Manipulation

To solve this problem let’s consider a subproblem and use the same approach to solve the above problem.
Q. Given an array of non-negative integer arr1 and a number x.find the maximum XOR value of (arr[i]^x).

Approach:
Step-I: Insert all the elements of arr1 into TRIE.
Step-II: Take x and find the maximum number from the arr1 where x^arr[i] is maximum.

Insertion into TRIE:
While inserting the number’s into the trie consider the binary format (Integer – 32bit) of the arr[i] and treat it as a string and insert the value. 
Let’s try to understand the insertion into trie by considering only 5bit’s but while coding we have to code it for 32bit.
arr[]:[9, 8, 7, 5, 4]
The binary format of the above array is as shown below.

    9             8             7              5             4

arr[ ]:[“01001”, “01000”, “00111”, “00101”, “00100”]

Insertion of 9 – “ 01001 ”


Inserting all the values of arr into the trie


Step – II: Maximizing XOR 

Prerequisite: L5. Bit PreRequisites for TRIE Problems

In order to have maximum value, we should have set bit’s from Left – Right.

XOR Operation:

XOR of Same bit’s – Zero(0)

XOR of Different bit’s – One(1)

For every ith bit find its opposite bit if not found then take that bit.

Dry run:

Consider the above Trie and x = 8.

X = 8 [“01000”]



Now using this concept let’s solve the actual problem.

arr1: push all the elements into the trie.

arr2: Treat every element of arr2 as x and find the MaxXOR and consider the maximum of all.

Code:

#include<iostream>
#include<bits/stdc++.h>
using namespace std;
 
struct Node {
  Node * links[2];
 
  bool containsKey(int ind) {
    return (links[ind] != NULL);
  }
  Node * get(int ind) {
    return links[ind];
  }
  void put(int ind, Node * node) {
    links[ind] = node;
  }
};
class Trie {
  private: Node * root;
  public:
    Trie() {
      root = new Node();
    }
 
  public:
    void insert(int num) {
      Node * node = root;
      // cout << num << endl; 
      for (int i = 31; i >= 0; i--) {
        int bit = (num >> i) & 1;
        if (!node -> containsKey(bit)) {
          node -> put(bit, new Node());
        }
        node = node -> get(bit);
      }
    }
  public:
    int findMax(int num) {
      Node * node = root;
      int maxNum = 0;
      for (int i = 31; i >= 0; i--) {
        int bit = (num >> i) & 1;
        if (node -> containsKey(!bit)) {
          maxNum = maxNum | (1 << i);
          node = node -> get(!bit);
        } else {
          node = node -> get(bit);
        }
      }
      return maxNum;
    }
};
int maxXOR(int n, int m, vector < int > & arr1, vector < int > & arr2) {
  Trie trie;
  for (int i = 0; i < n; i++) {
    trie.insert(arr1[i]);
  }
  int maxi = 0;
  for (int i = 0; i < m; i++) {
    maxi = max(maxi, trie.findMax(arr2[i]));
  }
  return maxi;
}
int main() {
  vector < int > arr1 = {6, 8};
  vector < int > arr2 = {7, 8, 2};
  int n = 2, m = 3;
  cout << maxXOR(n, m, arr1, arr2) << endl;
  return 0;
}
Output: 15

Time Complexity: O(N*32) + O(M*32)

Reason: For inserting all the elements of arr1 into the trie take O(N*32) [32 Bit] and O(M*32) for finding the maxXOR for every element of arr2.

Space Complexity: O(N*32)

Reason: Since we are inserting all the elements of arr1 into trie where every element is of size 32 bit but the space complexity will be less than O(N*32) because they might have overlapped.

  
