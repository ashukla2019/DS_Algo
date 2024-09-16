https://leetcode.com/discuss/study-guide/3630462/Top-20-Sliding-Window-Problems-for-beginners

Sliding window:
1) Constant/Fixed size window:
	Maximum subarray sum with length k: You are given an integer array nums and an integer k.
	Find the maximum subarray sum of all the subarrays of nums that meet the following conditions:
	The length of the subarray is k, and
	All the elements of the subarray are distinct.
	Return the maximum subarray sum of all the subarrays that meet the conditions. If no subarray meets the conditions, return 0.
	A subarray is a contiguous non-empty sequence of elements within an array.

	Example 1:
	Input: nums = [1,5,4,2,9,9,9], k = 3
	Output: 15
	Explanation: The subarrays of nums with length 3 are:
	- [1,5,4] which meets the requirements and has a sum of 10.
	- [5,4,2] which meets the requirements and has a sum of 11.
	- [4,2,9] which meets the requirements and has a sum of 15.
	- [2,9,9] which does not meet the requirements because the element 9 is repeated.
	- [9,9,9] which does not meet the requirements because the element 9 is repeated.
	We return 15 because it is the maximum subarray sum of all the subarrays that meet the conditions

	Solution:
	 long long maximumSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        long long sum = 0;
        
        long long maxi = 0;  // Initialize maxi to 0
        unordered_map<int ,int>mp;
        for(int i=0;i<k;i++){
            sum += nums[i];
            mp[nums[i]]++;
        }
        // if all k elements are distinct then stote in maxi
        if(mp.size()==k){
            maxi = sum;
        }
        // then start from k to n and delete i-k and add i
        for(int i=k;i<n;i++){
            sum  = sum - nums[i-k] + nums[i];
            mp[nums[i]]++;
            mp[nums[i-k]]--;
// if frequency is 0 than remove the element
            if(mp[nums[i-k]] == 0){
                mp.erase(nums[i-k]);
            }
            // If the current subarray contains distinct elements and has length 'k',
        // update the result with the maximum of the result and the current sum
            if(mp.size() == k){
                maxi = max(sum , maxi);
            }
        }

        
        return maxi;
    }
	The time complexity is O(n)
	The space complexity is O(n)	


2) Sliding Subarray Beauty
Given an integer array nums containing n integers, find the beauty of each subarray of size k.
The beauty of a subarray is the xth smallest integer in the subarray if it is negative, or 0 if there are fewer than x negative integers.
Return an integer array containing n - k + 1 integers, which denote the beauty of the subarrays in order from the first index in the array.
A subarray is a contiguous non-empty sequence of elements within an array.

Example 1:
Input: nums = [1,-1,-3,-2,3], k = 3, x = 2
Output: [-1,-2,-2]
Explanation: There are 3 subarrays with size k = 3. 
The first subarray is [1, -1, -3] and the 2nd smallest negative integer is -1. 
The second subarray is [-1, -3, -2] and the 2nd smallest negative integer is -2. 
The third subarray is [-3, -2, 3] and the 2nd smallest negative integer is -2.

Example 2:
Input: nums = [-1,-2,-3,-4,-5], k = 2, x = 2
Output: [-1,-2,-3,-4]
Explanation: There are 4 subarrays with size k = 2.
For [-1, -2], the 2nd smallest negative integer is -1.
For [-2, -3], the 2nd smallest negative integer is -2.
For [-3, -4], the 2nd smallest negative integer is -3.
For [-4, -5], the 2nd smallest negative integer is -4. 

Example 3:
Input: nums = [-3,1,2,-3,0,-3], k = 2, x = 1
Output: [-3,0,-3,-3,-3]
Explanation: There are 5 subarrays with size k = 2.
For [-3, 1], the 1st smallest negative integer is -3.
For [1, 2], there is no negative integer so the beauty is 0.
For [2, -3], the 1st smallest negative integer is -3.
For [-3, 0], the 1st smallest negative integer is -3.
For [0, -3], the 1st smallest negative integer is -3.


vector<int> getSubarrayBeauty(vector<int>& nums, int k, int x) {
	int n = nums.size();
	int cnt[101]{};
	for (int i = 0; i < k; ++i) {
		++cnt[nums[i] + 50];
	}
	vector<int> ans(n - k + 1);
	auto f = [&](int x) {
		int s = 0;
		for (int i = 0; i < 50; ++i) {
			s += cnt[i];
			if (s >= x) {
				return i - 50;
			}
		}
		return 0;
	};
	ans[0] = f(x);
	for (int i = k, j = 1; i < n; ++i) {
		++cnt[nums[i] + 50];
		--cnt[nums[i - k] + 50];
		ans[j++] = f(x);
	}
	return ans;
}

--------------------------------------------------------------------------------------
3)  Maximum Points You Can Obtain from Cards
There are several cards arranged in a row, and each card has an associated number of points. The points are given in the integer array cardPoints.
In one step, you can take one card from the beginning or from the end of the row. You have to take exactly k cards.
Your score is the sum of the points of the cards you have taken.
Given the integer array cardPoints and the integer k, return the maximum score you can obtain.


Example 1:
Input: cardPoints = [1,2,3,4,5,6,1], k = 3
Output: 12
Explanation: After the first step, your score will always be 1. However, choosing the rightmost card first will maximize your total score. The optimal strategy is to take the three cards on the right, giving a final score of 1 + 6 + 5 = 12.

Example 2:
Input: cardPoints = [2,2,2], k = 2
Output: 4
Explanation: Regardless of which two cards you take, your score will always be 4.

Example 3:
Input: cardPoints = [9,7,7,9,7,7,9], k = 7
Output: 55
Explanation: You have to take all the cards. Your score is the sum of points of all cards.

                            
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

// To calculate the maximum score obtainable
// by taking exactly 'k' cards from either
// the beginning or the end of the row
int maxScore(vector<int>& cardPoints, int k) {
    // Initialize left sum (lsum)
    // and right sum (rsum) to 0.
    int lsum = 0;
    int rsum = 0;
    
    // Initialize the
    // maximum sum (maxSum) to 0.
    int maxSum = 0;
    
    // Set rIndex to the index of 
    // he last element in cardPoints.
    int rIndex = cardPoints.size() - 1;
    
    // Calculate the sum of the first k
    // elements from the left side of the array.
    for(int i = 0; i < k; i++) {
        lsum += cardPoints[i];
    }
    
    // Initialize maxSum to the sum of
    // the first k elements from the left.
    maxSum = lsum;
    
    // Move one element from the
    // left to the right at a time.
    for(int i = k - 1; i >= 0; i--) {
        // Subtract the current element from
        // lsum as it's moved to the right.
        lsum = lsum - cardPoints[i];
        
        // Add the current right
        // element to rsum.
        rsum = rsum + cardPoints[rIndex];
        
        // Decrease the right index to point
        // to the next element on the left.
        rIndex = rIndex - 1;
        
        // Update maxSum to the maximum value
        // between the current maxSum and
        // the sum of lsum and rsum.
        maxSum = max(maxSum, lsum + rsum);
    }
    
    // Return the maximum sum obtained.
    return maxSum;
}

int main() {
    vector<int> arr = {6, 2, 3, 4, 7, 2, 1, 7, 1};
    int k = 4;
    
    cout << "Given cards: ";
    for(int &card: arr){
        cout << card << " ";
    }
    cout << endl;
    cout << "Number of cards to pick: "<< k << endl;
    
    int result = maxScore(arr, k);
    
    cout << "Maximum score: " << result << endl;
    
    return 0;
}
Time Complexity: O(2K) where K is the number of cards to choose. To calculate the initial sum of the left window we iterate over K elements then we slide this window to the maximum of K elements from the right giving complexity O(K + K).
Space Complexity: O(1) as the algorithm uses only a constant amount of extra space regardless of the size of the input array. It does not require any additional data structures that scale with the input size.           

-----------------------------------------------------------------------------------------
4) Maximum Average Subarray I
You are given an integer array nums consisting of n elements, and an integer k.
Find a contiguous subarray whose length is equal to k that has the maximum average value and return this value. Any answer with a calculation error less than 10-5 will be accepted.

Example 1:
Input: nums = [1,12,-5,-6,50,3], k = 4
Output: 12.75000
Explanation: Maximum average is (12 - 5 - 6 + 50) / 4 = 51 / 4 = 12.75
Example 2:

Input: nums = [5], k = 1
Output: 5.00000

double findMaxAverage(vector<int>& nums, int k) {
        int n=nums.size();
        double sum=0;
        for(int i=0;i<k;i++)
        {
            sum+=nums[i];
        }
        double ans=sum;
        for(int i=k;i<n;i++)
        {
            sum=sum-nums[i-k]+nums[i];
            ans=max(ans,sum);
        }
        return ans/k;
    }
------------------------------------------------------------------------------------------
5) Number of Sub-arrays of Size K and Average Greater than or Equal to Threshold
Given an array of integers arr and two integers k and threshold, return the number of sub-arrays of size k and average greater than or equal to threshold.

Example 1:
Input: arr = [2,2,2,2,5,5,5,8], k = 3, threshold = 4
Output: 3
Explanation: Sub-arrays [2,5,5],[5,5,5] and [5,5,8] have averages 4, 5 and 6 respectively. All other sub-arrays of size 3 have averages less than 4 (the threshold).
Example 2:

Input: arr = [11,13,17,23,29,31,7,5,2,3], k = 3, threshold = 5
Output: 6
Explanation: The first 6 sub-arrays of size 3 have averages greater than 5. Note that averages are not integers.

 int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int sum=0;
        for(int i=0;i<k;i++){
            sum+=arr[i];
        }
        int count=0;
        for(int i=k;i<arr.size();i++){
            if((sum/k)>=threshold){
                count++;
            }
            sum+=(arr[i]-arr[i-k]);            
        }
        if(sum/k>=threshold){
            count++;
        }
        return count;
    }
Time complexity: O(n)
Space complexity: O(1)

---------------------------------------------------------------------------------------------
6) Check If a String Contains All Binary Codes of Size K
Given a binary string s and an integer k, return true if every binary code of length k is a substring of s. Otherwise, return false.

Example 1:

Input: s = "00110110", k = 2
Output: true
Explanation: The binary codes of length 2 are "00", "01", "10" and "11". They can be all found as substrings at indices 0, 1, 3 and 2 respectively.
Example 2:

Input: s = "0110", k = 1
Output: true
Explanation: The binary codes of length 1 are "0" and "1", it is clear that both exist as a substring. 
Example 3:

Input: s = "0110", k = 2
Output: false
Explanation: The binary code "00" is of length 2 and does not exist in the array.

 bool hasAllCodes(string s, int k) 
 {
        // Unordered map of type string
    unordered_set<string> us;
   
    for (int i = 0; i + k <= s.size(); i++) 
    {
        us.insert(s.substr(i, k));
    }
    return us.size() == 1 << k;
   
}

--------------------------------------------------------------------------------------------
7) Find All Anagrams in a String
Given two strings s and p, return an array of all the start indices of p's anagrams in s. You may return the answer in any order.
An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.

Example 1:
Input: s = "cbaebabacd", p = "abc"
Output: [0,6]
Explanation:
The substring with start index = 0 is "cba", which is an anagram of "abc".
The substring with start index = 6 is "bac", which is an anagram of "abc".
Example 2:

Input: s = "abab", p = "ab"
Output: [0,1,2]
Explanation:
The substring with start index = 0 is "ab", which is an anagram of "ab".
The substring with start index = 1 is "ba", which is an anagram of "ab".
The substring with start index = 2 is "ab", which is an anagram of "ab". 

Sliding Window Technique:
This technique id used mostly on strings, arrays, linked lists (basically iterables) and you need to find min, max, or contains
If you observe we are asked to check s contains anagrams of p
So Here's the algorithm:

Create two variables start and end
First store all the characters of p in a hash map with value as number of occurences
while end < s.length
if hashMap of s[end] is greater than 0, subtract 1 from it and increase end
inside the same if check end - start is equal to pLen

if it's pLen, push start to result array
else if start equals to end increment both start and end
else increment start and add 1 to hashMap of s[start]

vector<int> findAnagrams(string s, string p) {
    vector<int> ans;
    // Frequency arrays
    vector<int> arr1(26, 0), arr2(26, 0);
    int n = s.length(), m = p.length();
    if (m > n)
        return ans;
    // First window
    for (int i = 0; i < m; i++)
        arr1[p[i] - 'a']++, arr2[s[i] - 'a']++;
    if (arr1 == arr2)
        ans.push_back(0);
    // subsequent windows
    for (int i = m; i < n; i++)
    {
        arr2[s[i] - 'a']++;
        arr2[s[i - m] - 'a']--;
        if (arr1 == arr2)
            ans.push_back(i - m + 1);
    }
    return ans;

--------------------------------------------------------------------------------
8) Permutation in String
Given two strings s1 and s2, return true if s2 contains a permutation of s1, or false otherwise.

In other words, return true if one of s1's permutations is the substring of s2.

Example 1:

Input: s1 = "ab", s2 = "eidbaooo"
Output: true
Explanation: s2 contains one permutation of s1 ("ba").
Example 2:

Input: s1 = "ab", s2 = "eidboaoo"
Output: false

Approach 1: using backtracking:
// C++ program to print all 
// permutations with duplicates allowed 
#include <bits/stdc++.h> 
using namespace std; 

// Function to print permutations of string 
// This function takes three parameters: 
// 1. String 
// 2. Starting index of the string 
// 3. Ending index of the string. 
void permute(string& a, int l, int r) 
{ 
	// Base case 
	if (l == r) 
		cout << a << endl; 
	else { 
		// Permutations made 
		for (int i = l; i <= r; i++) { 

			// Swapping done 
			swap(a[l], a[i]); 

			// Recursion called 
			permute(a, l + 1, r); 

			// backtrack 
			swap(a[l], a[i]); 
		} 
	} 
} 

// Driver Code 
int main() 
{ 
	string str = "ABC"; 
	int n = str.size(); 

	// Function call 
	permute(str, 0, n - 1); 
	return 0; 
} 

Time Complexity: O(N * N!) Note that there are N! permutations and it requires O(N) time to print a permutation.
Auxiliary Space: O(R – L)

Approach 2: Using sliding window:
bool checkInclusion(string s1, string s2) {
        int ln= s1.size(), lnn= s2.size();
        if(lnn<ln) return false;
        
        map<char,int> m1;
        for(auto x:s1)m1[x]++;
        
        map<char,int> m2;
        for(int i=0;i<ln;i++){
            m2[s2[i]]++;
        }
        
        int i=0,j= ln-1;
        while(j<lnn){
            if(m1== m2)return true;
            m2[s2[i]]--;
            if(m2[s2[i]]==0)m2.erase(s2[i]);
            i++;
            j++;
            m2[s2[j]]++;
        }
        return false;
    }


------------------------------------------------------------------------------
9) Substrings of Size Three with Distinct Characters
A string is good if there are no repeated characters.
Given a string s​​​​​, return the number of good substrings of length three in s​​​​​​.
Note that if there are multiple occurrences of the same substring, every occurrence should be counted.

A substring is a contiguous sequence of characters in a string.
Example 1:
Input: s = "xyzzaz"
Output: 1
Explanation: There are 4 substrings of size 3: "xyz", "yzz", "zza", and "zaz". 
The only good substring of length 3 is "xyz".
Example 2:

Input: s = "aababcabc"
Output: 4
Explanation: There are 7 substrings of size 3: "aab", "aba", "bab", "abc", "bca", "cab", and "abc".
The good substrings are "abc", "bca", "cab", and "abc".

iint countGoodSubstrings(string s) {
       int n=s.length(),cnt=0;

        for(int i=0;i<n-2;i++)
            if(s[i]!=s[i+1] && s[i+1]!=s[i+2] && s[i]!=s[i+2])
                cnt++;

        return cnt;   
    }

-------------------------------------------------------------------------------
10) Find the Longest Semi-Repetitive Substring
You are given a digit string s that consists of digits from 0 to 9.
A string is called semi-repetitive if there is at most one adjacent pair of the same digit. For example, "0010", "002020", "0123", "2002", and "54944" are semi-repetitive while the following are not: "00101022" (adjacent same digit pairs are 00 and 22), and "1101234883" (adjacent same digit pairs are 11 and 88).
Return the length of the longest semi-repetitive 
substring
 of s.

Example 1:
Input: s = "52233"
Output: 4
Explanation:
The longest semi-repetitive substring is "5223". Picking the whole string "52233" has two adjacent same digit pairs 22 and 33, but at most one is allowed.

Example 2:
Input: s = "5494"
Output: 4
Explanation:
s is a semi-repetitive string.

Example 3:
Input: s = "1111111"
Output: 2
Explanation:
The longest semi-repetitive substring is "11". Picking the substring "111" has two adjacent same digit pairs, but at most one is allowed.

 int longestSemiRepetitiveSubstring(string s) {
        int n = s.length();
        int cnt = 0, l = 0;
        for (int i = 1; i < n; ++i) {
            cnt += s[i] == s[i - 1] ? 1 : 0;
            if (cnt > 1) {
                cnt -= s[l] == s[++l] ? 1 : 0;
            }
        }
        return n - l;
    }
---------------------------------------------------------------------------------
11) Count the Number of Good Subarrays
Given an integer array nums and an integer k, return the number of good subarrays of nums.
A subarray arr is good if it there are at least k pairs of indices (i, j) such that i < j and arr[i] == arr[j].
A subarray is a contiguous non-empty sequence of elements within an array.

Example 1:
Input: nums = [1,1,1,1,1], k = 10
Output: 1
Explanation: The only good subarray is the array nums itself.
Example 2:

Input: nums = [3,1,4,3,2,2,4], k = 2
Output: 4
Explanation: There are 4 different good subarrays:
- [3,1,4,3,2,2] that has 2 pairs.
- [3,1,4,3,2,2,4] that has 3 pairs.
- [1,4,3,2,2,4] that has 2 pairs.
- [4,3,2,2,4] that has 2 pairs.

 long long countGood(vector<int>& nums, int k) {
        unordered_map<int, int> cnt;
        long long ans = 0;
        long long cur = 0;
        int i = 0;
        for (int& x : nums) {
            cur += cnt[x]++;
            while (cur - cnt[nums[i]] + 1 >= k) {
                cur -= --cnt[nums[i++]];
            }
            if (cur >= k) {
                ans += i + 1;
            }
        }
        return ans;
    }


-------------------------------------------------------------------------
12) Minimum Consecutive Cards to Pick Up
You are given an integer array cards where cards[i] represents the value of the ith card. A pair of cards are matching if the cards have the same value.

Return the minimum number of consecutive cards you have to pick up to have a pair of matching cards among the picked cards. If it is impossible to have matching cards, return -1.

Example 1:
Input: cards = [3,4,2,3,4,7]
Output: 4
Explanation: We can pick up the cards [3,4,2,3] which contain a matching pair of cards with value 3. Note that picking up the cards [4,2,3,4] is also optimal.
Example 2:
Input: cards = [1,0,5,3]
Output: -1
Explanation: There is no way to pick up a set of consecutive cards that contain a pair of matching cards.

int minimumCardPickup(vector<int>& cards) {
        set<int> s;
        int j=0,i=0,ans=INT_MAX;
        int n=cards.size();
        while(j<n){
            if(!s.insert(cards[j]).second){
                if(ans>s.size()+1)    ans=s.size()+1;
                s.erase(cards[i]);
                i++;
            }
            else    j++;
        }
        return ans==INT_MAX?-1:ans;
    }
	Time complexity: O(n)
    Space complexity:O(n)
--------------------------------------------------------------------------
13) Minimum Operations to Reduce X to Zero 

class Solution {
    
    /*
        Time Complexity : O(N)
        Space Complexity : O(1)
    */
    
public:
    int minOperations(vector<int>& nums, int x)
    {
        int n = nums.size();
        int totalS = 0;
 
        // Calculate the total sum of the
        // elements in the vector 'nums'
        for (int i = 0; i < n; i++) {
            totalS += nums[i];
        }
 
        // If the total sum is equal to 'x',
        // no operations are needed
        if (totalS == x) {
            return n;
        }
 
        // Calculate the difference between
        // the total sum and 'x'
        totalS = totalS - x;
        int i = 0;
        int j = 0;
        int sum = 0;
        int ans = 0;
 
        // Sliding window approach to find
        // the minimum operations
        while (j < n) {
            sum += nums[j];
 
            // If the current sum is greater
            // than the target difference, move
            // the window's left end (i) to
            // reduce the sum
            while (i < j && sum > totalS) {
                sum -= nums[i];
                i++;
            }
 
            // If the current sum equals the
            // target difference, update the
            // answer with the maximum
            // window size
            if (sum == totalS) {
                ans = max(ans, j - i + 1);
            }
 
            j++;
        }
 
        // If 'ans' is still 0, it means no
        // subarray with the target sum was found
        return ans == 0 ? -1 : n - ans;
    }
};
 
// Drivers code
int main()
{
    Solution solution;
    vector<int> nums = { 1, 1, 4, 2, 3 };
    int x = 5;
    int result = solution.minOperations(nums, x);
 
    if (result == -1) {
        cout << "No solution found." << endl;
    }
    else {
        cout << "Minimum operations required: " << result
             << endl;
    }
 
    return 0;
}

----------------------------------------------------------------------------
14) Count Number of Nice Subarrays:
Given an array of integers nums and an integer k. A continuous subarray is called nice if there are k odd numbers on it.

Return the number of nice sub-arrays.

Example 1:
Input: nums = [1,1,2,1,1], k = 3
Output: 2
Explanation: The only sub-arrays with 3 odd numbers are [1,1,2,1] and [1,2,1,1].
Example 2:

Input: nums = [2,4,6], k = 1
Output: 0
Explanation: There are no odd numbers in the array.
Example 3:

Input: nums = [2,2,2,1,2,2,1,2,2,2], k = 2
Output: 16

class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int left = 0;
        int odd = 0;
        int count = 0;
        int prefix_odd_count = 0;

        for (int right = 0; right < nums.size(); ++right) {
            if (nums[right] % 2 != 0) {
                ++odd;
                prefix_odd_count = 0;
            }
            
            while (odd == k) {
                ++prefix_odd_count;
                if (nums[left] % 2 != 0) {
                    --odd;
                }
                ++left;
            }
            
            count += prefix_odd_count;
        }
        
        return count;
    }
};


-----------------------------------------------------------------------------
15) Fruit Into Baskets
You are visiting a farm that has a single row of fruit trees arranged from left to right. The trees are represented by an integer array fruits where fruits[i] is the type of fruit the ith tree produces.

You want to collect as much fruit as possible. However, the owner has some strict rules that you must follow:

You only have two baskets, and each basket can only hold a single type of fruit. There is no limit on the amount of fruit each basket can hold.
Starting from any tree of your choice, you must pick exactly one fruit from every tree (including the start tree) while moving to the right. The picked fruits must fit in one of your baskets.
Once you reach a tree with fruit that cannot fit in your baskets, you must stop.
Given the integer array fruits, return the maximum number of fruits you can pick.

Example 1:
Input: fruits = [1,2,1]
Output: 3
Explanation: We can pick from all 3 trees.
Example 2:

Input: fruits = [0,1,2,2]
Output: 3
Explanation: We can pick from trees [1,2,2].
If we had started at the first tree, we would only pick from trees [0,1].
Example 3:

Input: fruits = [1,2,3,2,2]
Output: 4
Explanation: We can pick from trees [2,3,2,2].
If we had started at the first tree, we would only pick from trees [1,2].

int totalFruit(vector<int>& fruits) {
        // Initialize a hash map to count the fruits
        unordered_map<int, int> fruitCounter;
      
        // Initialize the start of the current window
        int windowStart = 0;
      
        // Get the number of fruits
        int totalFruits = fruits.size();
      
        // Iterate over all fruits
        for (int windowEnd = 0; windowEnd < totalFruits; ++windowEnd) {
            // Increase the count for the current fruit
            fruitCounter[fruits[windowEnd]]++;
          
            // If there are more than 2 types of fruits in the current window
            while (fruitCounter.size() > 2) {
                // Decrease the count of the fruit at the start of the window
                fruitCounter[fruits[windowStart]]--;
              
                // If the count becomes zero, remove the fruit from the map
                if (fruitCounter[fruits[windowStart]] == 0) {
                    fruitCounter.erase(fruits[windowStart]);
                }
              
                // Move the window start forward
                ++windowStart;
            }
        }
      
        // The maximum number of fruits is the size of the array minus the start of the last valid window
        return totalFruits - windowStart;
    }
Time complexity: O(n)
Space complexity: O(1)

-------------------------------------------------------------------------------
16) Max Consecutive Ones III
Given a binary array nums and an integer k, return the maximum number of consecutive 1's in the array if you can flip at most k 0's.

Example 1:
Input: nums = [1,1,1,0,0,0,1,1,1,1,0], k = 2
Output: 6
Explanation: [1,1,1,0,0,1,1,1,1,1,1]
Bolded numbers were flipped from 0 to 1. The longest subarray is underlined.
Example 2:

Input: nums = [0,0,1,1,0,0,1,1,1,0,1,1,0,0,0,1,1,1,1], k = 3
Output: 10
Explanation: [0,0,1,1,1,1,1,1,1,1,1,1,0,0,0,1,1,1,1]
Bolded numbers were flipped from 0 to 1. The longest subarray is underlined.
 
int findMaxConsecutiveOnes(vector < int > & nums) {
      int cnt = 0;
      int maxi = 0;
      for (int i = 0; i < nums.size(); i++) {
        if (nums[i] == 1) {
          cnt++;
        } else {
          cnt = 0;
        }

        maxi = max(maxi, cnt);
      }
      return maxi;
    }
};

int main() {
  vector < int > nums = { 1, 1, 0, 1, 1, 1 };
  int ans =findMaxConsecutiveOnes(nums);
  cout << "The maximum  consecutive 1's are " << ans;
  return 0;
}
Time complexity: O(n)
Space complexity: O(1)
-----------------------------------------------------------------------------
17)Subarray Product Less Than K
Given an array of integers nums and an integer k, return the number of contiguous subarrays where the product of all the elements in the subarray is strictly less than k.

Example 1:

Input: nums = [10,5,2,6], k = 100
Output: 8
Explanation: The 8 subarrays that have product less than 100 are:
[10], [5], [2], [6], [10, 5], [5, 2], [2, 6], [5, 2, 6]
Note that [10, 5, 2] is not included as the product of 100 is not strictly less than k.
Example 2:

Input: nums = [1,2,3], k = 0
Output: 0

    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        
    if (k <= 1)
      return 0;

    int ans = 0;
    int prod = 1;

    for (int l = 0, r = 0; r < nums.size(); ++r) {
      prod *= nums[r];
      while (prod >= k)
        prod /= nums[l++];
      ans += r - l + 1;
    }

    return ans;
  }

Time complexity: O(n) for average and most of the cases
Space complexity: O(1) and we are using constant space that includes variables ri, pro, result, i 

--------------------------------------------------------------------------------
18) Minimum Size Subarray Sum
Given an array of positive integers nums and a positive integer target, return the minimal length of a 
subarray
 whose sum is greater than or equal to target. If there is no such subarray, return 0 instead.

Example 1:
Input: target = 7, nums = [2,3,1,2,4,3]
Output: 2
Explanation: The subarray [4,3] has the minimal length under the problem constraint.
Example 2:

Input: target = 4, nums = [1,4,4]
Output: 1
Example 3:

Input: target = 11, nums = [1,1,1,1,1,1,1,1]
Output: 0

int subarraySumgreaterThanEqualToK(vector<int>& arr, int K) {
    // Initialize variables to keep
    // track of the count of subarrays
    // and the current sum.
    int count = 0, sum = 0;
    
    // Get the size of the array.
    int n = arr.size();
    // Initialize two pointers 'l'
    // and 'r' to define the
    // current subarray.
    int l = 0, r = 0;
    
    // Iterate through the array.
    while (r < n) {
        // Add the current
        // element to the sum.
        sum += arr[r];
        
        // Adjust 'l' to maintain the
        // sum greater than or equal to 'K'.
        while (sum > K && l <= r) {
            sum -= arr[l++];
        }
        
        // Update the count by the
        // length of the current subarray.
        count += (r - l + 1);
        
        // Move to the
        // next element.
        r++;
    }
    // Return the final count of
    // subarrays with sum greater
    // than or equal to 'K'.
    return count;
}

// Function to calculate
// the count of subarrays
// with sum equal to 'k'.
int subArraySum(vector<int>& nums, int k) {
    // Calculate the count of
    // subarrays with sum greater
    // than or equal to 'k'.
    int countK = subarraySumgreaterThanEqualToK(nums, k);
    // Calculate the count of
    // subarrays with sum greater
    // than or equal to 'k-1'.
    int countKMinus1 = subarraySumgreaterThanEqualToK(nums, k-1);
    // Return the difference between the
    // two counts, representing the count
    // of subarrays with sum equal to 'k'.
    return countK - countKMinus1;
}


int main() {
    vector<int> arr = {2, 2, 5, 5, 4, 10};
    int k = 14;

    int count = subArraySum(arr, k);

    cout << "Input Array: ";
    for(int i =0 ; i< arr.size(); i++){
        cout << arr[i] << " ";
    }
    cout << endl;
    cout << "Number of subarrays with sum equal "<< k;
    cout << ": " << count << endl;

    return 0;
}
 
--------------------------------------------------------------------------------
19) Longest Substring Without Repeating Characters
Given a string s, find the length of the longest 
substring
 without repeating characters.

Example 1:

Input: s = "abcabcbb"
Output: 3
Explanation: The answer is "abc", with the length of 3.
Example 2:

Input: s = "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.
Example 3:

Input: s = "pwwkew"
Output: 3
Explanation: The answer is "wke", with the length of 3.
Notice that the answer must be a substring, "pwke" is a subsequence and not a substring.

int lengthofLongestSubstring(string s) {
      map < int > mpp;

      int left = 0, right = 0;
      int n = s.size();
      int len = 0;
      while (right < n) {
        if (mpp[s[right]] != -1)
          left = max(mpp[s[right]] + 1, left);

        mpp[s[right]] = right;

        len = max(len, right - left + 1);
        right++;
      }
      return len;
    }
};

int main() {
  string str = "takeUforward";
  Solution obj;
  cout << "The length of the longest substring without repeating characters is " << obj.lengthofLongestSubstring(str);
  return 0;
}
----------------------------------------------------------------------------------
20) Sliding Window Maximum
You are given an array of integers nums, there is a sliding window of size k which is moving from the very left of the array to the very right. You can only see the k numbers in the window. Each time the sliding window moves right by one position.

Return the max sliding window.

Example 1:
Input: nums = [1,3,-1,-3,5,3,6,7], k = 3
Output: [3,3,5,5,6,7]
Explanation: 
Window position                Max
---------------               -----
[1  3  -1] -3  5  3  6  7       3
 1 [3  -1  -3] 5  3  6  7       3
 1  3 [-1  -3  5] 3  6  7       5
 1  3  -1 [-3  5  3] 6  7       5
 1  3  -1  -3 [5  3  6] 7       6
 1  3  -1  -3  5 [3  6  7]      7
Example 2:

Input: nums = [1], k = 1
Output: [1] 
