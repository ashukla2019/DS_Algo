https://leetcode.com/discuss/study-guide/3630462/Top-20-Sliding-Window-Problems-for-beginners

https://builtin.com/data-science/sliding-window-algorithm

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
        // if all k elements are distinct then store in maximum
        if(mp.size()==k){
            maximum = sum;
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
                maximum = max(sum , maximum);
            }
        }

        
        return maximum;
    }
	The time complexity is O(n)
	The space complexity is O(n)	
------------------------------------------------------------------------
2) Substrings of Size Three with Distinct Characters
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

int countGoodSubstrings(string s) {
        int n=s.length();int ans=0;
        map<char,int>mp;
        for(int i=0;i<3;i++)mp[s[i]]++;
        if(mp.size()==3)ans++;
        int j=0;
        for(int i=3;i<n;i++){
            mp[s[j]]--;
            if(mp[s[j]]==0)mp.erase(s[j]);
            j++;
            mp[s[i]]++;
            if(mp.size()==3)ans++;
        }
        return ans;
    }
--------------------------------------------------------------------
3) Maximum Number of Vowels in a Substring of Given Length:
Given a string s and an integer k, return the maximum number of vowel letters in any substring of s with length k.

Vowel letters in English are 'a', 'e', 'i', 'o', and 'u'.

Example 1:
Input: s = "abciiidef", k = 3
Output: 3
Explanation: The substring "iii" contains 3 vowel letters.

Example 2:
Input: s = "aeiou", k = 2
Output: 2
Explanation: Any substring of length 2 contains 2 vowels.

Example 3:
Input: s = "leetcode", k = 3
Output: 2
Explanation: "lee", "eet" and "ode" contain 2 vowels.	

bool isvowel(char ch){
        return (ch=='a'||ch=='e'||ch=='i'||ch=='o'||ch=='u');
       
    }
    int maxVowels(string s, int k) {
        int maximum=0;
        for (int i=0; i<k; i++){
            if (isvowel(s[i]))maximum++;
        }
		//update ans with maximum value till now for o->k window
        int ans= maximum;
        for (int i=k; i<s.size(); i++){
            if (isvowel(s[i]))maximum++;
			//decrement maximum, if (i-k)th character was vowel, since we are shrinking window by 
			//removing that vowel count if it was vowel.
            if (isvowel(s[i-k]))maximum--;
			//update ans with maximum value till now for k->n window
            ans= max(ans,maximum);
        }
        return ans;
    }
Time complexity: O(n)	
------------------------------------------------------------------------------
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
---------------------------------------------------------------------
5) Maximum Points You Can Obtain from Cards
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
--------------------------------------------------------------------
6) Sliding Subarray Beauty
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
7) Number of Sub-arrays of Size K and Average Greater than or Equal to Threshold
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
        for(int i=0;i<k;i++)
        {
            sum+=arr[i];
        }
        int count=0;       
        
        if((sum/k)>=threshold)
        {
                count++;
        }
        for(int i=k;i<arr.size();i++)
        {
           sum+=(arr[i]-arr[i-k]);  
           if(sum/k>=threshold)
           {
            count++;
            }          
        }
       
        return count;
    }
Time complexity: O(n)
Space complexity: O(1)

-----------------------------------------------------------------------------------------
8) Check If a String Contains All Binary Codes of Size K
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
    // Unordered set of type string to store unique combination of k length binary codes
    unordered_set<string> us;
   
    //Iterate through string and find substring of length k with index i and store it in set.
    //i will go upto s.size()-k otherwise it will go out of bound for substr.
	for (int i = 0; i <= s.size()-k; i++) 
    {
        us.insert(s.substr(i, k));
    }
    return us.size() == 1 << k;
   
}

------------------------------------------------------------------------------------------
9) Find All Anagrams in a String
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
---------------------------------------------------------------------------------------------
-----------variable window size:
10) Subarray with Given Sum: 
Given a 1-based indexing array arr[] of integers and an integer sum. 
You mainly need to return the left and right indexes(1-based indexing) of that subarray. 
In case of multiple subarrays, return the subarray indexes which come first on moving from 
left to right. If no such subarray exists return an array consisting of element -1.

Examples: 
Input: arr[] = { 15, 2, 4, 8, 9, 5, 10, 23}, sum = 23
Output: 2 5
Explanation: Sum of elements between indices 2 and 5 is 2 + 4 + 8 + 9 = 23

Input: arr[] = {1, 4, 0, 0, 3, 10, 5}, sum = 7
Output: 2 5
Explanation: Sum of elements between indices 1 and 4 is 4 + 0 + 0 + 3 = 7

Input: arr[] = {1, 4}, sum = 0
Output: -1
Explanation: There is no subarray with 0 sum
Approach 1: Using nested loop:
#include <bits/stdc++.h>
using namespace std;

// Function to find a continuous sub-array which adds up to
// a given number.
vector<int> subarraySum(vector<int> arr, int sum)
{
    // To store the result
    vector<int> res;
    int n = arr.size();

    // Pick a starting point for a 
    // subarray
    for (int s = 0; s < n; s++)
    {
        int curr = 0;
      
        // Consider all ending points
        // for the picked starting point 
        for (int e = s; e < n; e++)
        {
            curr += arr[e];
            if (curr == sum)
            {
                res.push_back(s + 1);
                res.push_back(e + 1);
                return res;
            }
        }
    }
    return {-1}; // If no subarray is found
}

// Driver Code
int main()
{
    vector<int> arr = {15, 2, 4, 8, 9, 5, 10, 23};
    int sum = 23;
    vector<int> result = subarraySum(arr, sum);
    for (auto i : result)
        cout << i << " ";
    return 0;
}
Time Complexity: O(N2), Trying all subarrays from every index, used nested loop for the same
Auxiliary Space: O(1).
Approach 2: Using sliding window:
Start with an empty window 
add elements to the window while the current sum is less than sum 
If the sum is greater than sum, remove elements from the start of the current window.
If current sum becomes same as sum, return the result

#include <iostream>
#include <vector>
using namespace std;

vector<int> subarraySum(vector<int>& arr, int sum) 
{
    int l=0;
    int r=0;
    int n= arr.size();
    int total=0;
    while(r<n)
    {
        total = total + arr[r];
               
        while(total > sum)
        {
            total = total - arr[l];
            l++;
        }
        if(total == sum)
        {
            return{l+1, r+1};
        }
        r++;
       
    }
    return {};
    
}
Time Complexity: O(N), where N is the length of input array
Auxiliary Space: O(1). Since no extra space has been taken.
------------------------------------------------------------------------------------------
11) Longest sub-array with k sum
Given an array arr[] of size n containing integers. The problem is to find the length 
of the longest sub-array having sum equal to the given value k.

Examples: 
Input: arr[] = { 10, 5, 2, 7, 1, 9 }, k = 15
Output: 4
Explanation: The sub-array is {5, 2, 7, 1}.

Input: arr[] = {-5, 8, -14, 2, 4, 12}, k = -5
Output: 5	

Approach 1: Consider the sum of all the sub-arrays and return the length of the longest 
sub-array having the sum ‘k’. Time Complexity is of O(n^2).

int lenOfLongSubarr(int arr[], int N, int K)
{

	// Variable to store the answer
	int maxlength = 0;

	for (int i = 0; i < N; i++) {

		// Variable to store sum of subarrays
		int Sum = 0;
	  
		// if maximum possible subarray length from i is equal to maxLength
		if( maxlength == N - i )
		  break;
	  
		for (int j = i; j < N; j++) {

			// Storing sum of subarrays
			Sum += arr[j];

			// if Sum equals K
			if (Sum == K) {

				// Update maxLength
				maxlength = max(maxlength, j - i + 1);
			}
		}
	}

	// Return the maximum length
	return maxlength;
}

// Driver Code
int main()
{

	// Given input
	int arr[] = { 10, 5, 2, 7, 1, 9 };
	int n = sizeof(arr) / sizeof(arr[0]);
	int k = 15;

	// Function Call
	cout << "Length = " << lenOfLongSubarr(arr, n, k);

	return 0;
}
Time Complexity: O(N2), for calculating the sum of all subarrays.
Auxiliary Space: O(1)

Approach 2: Hashmap and Prefix Sum Technique
	
int lenOfLongSubarr(vector<int>& A, int N, int K)
{
	unordered_map<int, int> sum_index_map;
	int maxLen = 0;
	int prefix_sum = 0;

	for (int i = 0; i < N; ++i) {
		prefix_sum += A[i];

		if (prefix_sum == K) {
			maxLen = i + 1;
		}

		else if (sum_index_map.find(prefix_sum - K) != sum_index_map.end()) {
			maxLen = max(maxLen, i - sum_index_map[prefix_sum - K]);
		}

		if (sum_index_map.find(prefix_sum) == sum_index_map.end()) {
			sum_index_map[prefix_sum] = i;
		}
	}

	return maxLen;
}

int main()
{
	vector<int> arr = { 10, 5, 2, 7, 1, 9 };
	int n = arr.size();
	int k = 15;
	cout << "Length = " << lenOfLongSubarr(arr, n, k)
		 << endl;
	return 0;
}
Time Complexity: O(N), where N is the length of the given array.
Auxiliary Space: O(N) We are using Hash Table for storing prefix sums

Approach3: Using sliding window:
int getLongestSubarray(vector<int>& a, long long k) {
    int n = a.size(); // size of the array.

    int left = 0, right = 0; // 2 pointers
    long long sum = a[0];
    int maxLen = 0;
    while (right < n) {
        // if sum > k, reduce the subarray from left
        // until sum becomes less or equal to k:
        while (left <= right && sum > k) {
            sum -= a[left];
            left++;
        }

        // if sum = k, update the maxLen i.e. answer:
        if (sum == k) {
            maxLen = max(maxLen, right - left + 1);
        }

        // Move forward the right pointer:
        right++;
        if (right < n) sum += a[right];
    }

    return maxLen;
}

int main()
{
    vector<int> a = {2, 3, 5, 1, 9};
    long long k = 10;
    int len = getLongestSubarray(a, k);
    cout << "The length of the longest subarray is: " << len << "\n";
    return 0;
}
Time Complexity: O(2*N), where N = size of the given array.
Reason: The outer while loop i.e. the right pointer can move up to index n-1(the last index). Now, the inner while loop i.e. the left pointer can move up to the right pointer at most. So, every time the inner loop does not run for n times rather it can run for n times in total. So, the time complexity will be O(2*N) instead of O(N2).

Space Complexity: O(1) as we are not using any extra space.
--------------------------------------------------------------------------------
12) Largest subarray with 0 sum: Given an array containing both positive and negative integers,
we have to find the length of the longest subarray with the sum of all elements equal to zero.
Example 1:
Input Format
: N = 6, array[] = {9, -3, 3, -1, 6, -5}
Result
: 5
Explanation
: The following subarrays sum to zero:
{-3, 3} , {-1, 6, -5}, {-3, 3, -1, 6, -5}
Since we require the length of the longest subarray, our answer is 5!

Example 2:
Input Format:
 N = 8, array[] = {6, -2, 2, -8, 1, 7, 4, -10}
Result
: 8
Subarrays with sum 0 : {-2, 2}, {-8, 1, 7}, {-2, 2, -8, 1, 7}, {6, -2, 2, -8, 1, 7, 4, -10}
Length of longest subarray = 8

Example 3:
Input Format:
 N = 3, array[] = {1, 0, -5}
Result
: 1
Subarray : {0}
Length of longest subarray = 1

Example 4:
Input Format:
 N = 5, array[] = {1, 3, -5, 6, -2}
Result
: 0
Subarray: There is no subarray that sums to zero
int maxLen(int A[], int n)
{
    // Your code here
    unordered_map<int,int> mpp; 
    int maxi = 0;
    int sum = 0; 
    for(int i = 0;i<n;i++) {
        sum += A[i]; 
        if(sum == 0) {
            maxi = i + 1; 
        }
        else {
            if(mpp.find(sum) != mpp.end()) {
                maxi = max(maxi, i - mpp[sum]); 
            }
            else {
                mpp[sum] = i;
            }
        }   
    }

    return maxi; 
	Time Complexity: O(N), as we are traversing the array only once
	Space Complexity: O(N), in the worst case we would insert all array elements prefix sum into our hashmap

-----------------------------------------------------------------------------------------------
13) Smallest subarray with k distinct numbers	
We are given an array consisting of n integers and an integer k. We need to find the minimum range in array [l, r] (both l and r are inclusive) such that there are exactly k different numbers. If such subarray doesn’t exist print “Invalid k”.
Examples: 
Input : arr[] = { 1, 1, 2, 2, 3, 3, 4, 5} 
            k = 3
Output : 5 7

Input : arr[] = { 1, 2, 2, 3} 
            k = 2
Output : 0 1

Input : arr[] = {1, 1, 2, 1, 2}
            k = 3
Output : Invalid k

Approach 1: The simplest approach in this problem is, try to generate all the subarrays
and check for which subarray the size is k. But there are some points we need to take care
void minRange(int arr[], int n, int k)
{
	// Starting and ending index of resultant subarray
	int start = 0, end = n;

	// Selecting each element as the start index for
	// subarray
	for (int i = 0; i < n; i++) {
		// Initialize a set to store all distinct elements
		unordered_set<int> set;

		// Selecting the end index for subarray
		int j;
		for (j = i; j < n; j++) {
			set.insert(arr[j]);

			/*
			If set contains exactly k elements,
			then check subarray[i, j] is smaller in size
			than the current resultant subarray
			*/
			if (set.size() == k) {
				if (j - i < end - start) {
					start = i;
					end = j;
				}

				// There are already k distinct elements
				// now, no need to consider further elements
				break;
			}
		}

		// If there are no k distinct elements
		// left in the array starting from index i we will
		// break
		if (j == n) {
			break;
		}
	}

	// If no window found then print -1
	if (start == 0 && end == n)
		cout << "Invalid k";

	else
		cout << start << " " << end;
}

// Driver code for above function.
int main()
{
	int arr[] = { 1, 2, 3, 4, 5 };
	int n = sizeof(arr) / sizeof(arr[0]);
	int k = 3;
	minRange(arr, n, k);
	return 0;
}
Output
0 2
Time Complexity : O(N^2) ,where N is the number of elements in the array. Every time picking the end points of the subarray using two nested loops(one inside another) makes the time complexity O(N^2).
Space Complexity :  O(N)

Approach 2: Sliding Window:
Optimization is get rid of the repeated work while making all subarray, all subarray will not
help to find the resultant. The approach is –
Steps :
Initialize a map to store the frequencies of each element.
Taking two variables as taken before : start and end of the required subarray.
And here we are using i and j as the starting and ending index of the window respectively, initializing as i = 0 and j = 0.
Will traverse the array while the ending pointer of our window reach the end of given array. i.e.  while( j < n)
Add the current element to the map map[ arr[j] ]++ and make j pointing to the next index
Consider the window [ i, j-1 ] (reason for ‘j-1’ is as we incremented the value of ‘j’ just after insertion in last step) check whether its size is equal to k
If window size is lesser than k then continue
But if window size == k, then check its length whether it is the resultant subarray or not. 
After that we need to move our window, but in order to move our window, we have to check the starting element of our current window (i.e. i-th). If the i-th element is having a frequency of 1 then erase it from the map and else decrease its frequency by 1. And increase the i-value. Make i to point to the next element

void minRange(int arr[], int n, int k)
{
	/*
		start = starting index of resultant subarray
		end = ending index of resultant subarray
	*/
	int start = 0, end = n;

	unordered_map<int, int> map;

	/*
		i = starting index of the window (on left side)
		j = ending index of the window (on right side)
	*/
	int i = 0, j = 0;

	while (j < n) {
		// Add the current element to the map
		map[arr[j]]++;
		j++;

		// Nothing to do when having less element
		if (map.size() < k)
			continue;

		/*
				If map contains exactly k elements,
				consider subarray[i, j - 1] keep removing
				left most elements
		*/

		while (map.size() == k) {
			// as considering the (j-1)th and i-th index
			int windowLen = (j - 1) - i + 1;
			int subArrayLen = end - start + 1;

			if (subArrayLen > windowLen) {
				start = i;
				end = j - 1;
			}

			// Remove elements from left

			// If freq == 1 then totally erase
			if (map[arr[i]] == 1)
				map.erase(arr[i]);

			// decrease freq by 1
			else
				map[arr[i]]--;

			// move the starting index of window
			i++;
		}
	}

	if (start == 0 && end == n)
		cout << "Invalid k" << endl;

	else
		cout << start << " " << end << endl;
}

// Driver code for above function.
int main()
{
	int arr[] = { 1, 1, 2, 2, 3, 3, 4, 5 };
	int n = sizeof(arr) / sizeof(arr[0]);
	int k = 3;
	minRange(arr, n, k);
	return 0;
}

Time Complexity : O(N) ,where N is the number of elements in the array. In the worst case, each element will be added once and removed once from the map.
Space Complexity :  O(K)
--------------------------------------------------------------------------------------
14) Find the length of largest subarray with 0 sum
Input: arr[] = {15, -2, 2, -8, 1, 7, 10, 23}
Output: 5
Explanation: The longest sub-array with elements summing up-to 0 is {-2, 2, -8, 1, 7}

Input: arr[] = {1, 2, 3}
Output: 0
Explanation: There is no subarray with 0 sum

Input:  arr[] = {1, 0, 3}
Output:  1
Explanation: The longest sub-array with elements summing up-to 0 is {0}

Approach 1: 
Consider all sub-arrays one by one and check the sum of every sub-array. If the sum of
the current subarray is equal to zero then update the maximum length accordingly. After 
iterating over all the subarrays, return the maximum length.

int maxLen(int arr[], int N)
{
	// Initialize result
	int max_len = 0; 

	// Pick a starting point
	for (int i = 0; i < N; i++) {

		// Initialize curr_sum for
		// every starting point
		int curr_sum = 0;

		// Try all subarrays starting with 'i'
		for (int j = i; j < N; j++) {
			curr_sum += arr[j];

			// If curr_sum becomes 0, 
			// then update max_len
			// if required
			if (curr_sum == 0)
				max_len = max(max_len, j - i + 1);
		}
	}
	return max_len;
}

// Driver's Code
int main()
{
	int arr[] = {15, -2, 2, -8, 1, 7, 10, 23};
	int N = sizeof(arr) / sizeof(arr[0]);
  
  // Function call
	cout << "Length of the longest 0 sum subarray is "
		 << maxLen(arr, N);
	return 0;
}
Output
Length of the longest 0 sum subarray is 5
Time Complexity: O(N2)
Auxiliary Space: O(1)

Approach 2: Using Hashmap and Prefix Sum
	
int maxLen(int arr[], int N)
{
	// Map to store the previous sums
	unordered_map<int, int> presum;

	int sum = 0; // Initialize the sum of elements
	int max_len = 0; // Initialize result

	// Traverse through the given array
	for (int i = 0; i < N; i++) {

		// Add current element to sum
		sum += arr[i];
		if (sum == 0)
			max_len = i + 1;

		// Look for this sum in Hash table
		if (presum.find(sum) != presum.end()) {

			// If this sum is seen before, then update
			// max_len
			max_len = max(max_len, i - presum[sum]);
		}
		else {
			// Else insert this sum with index
			// in hash table
			presum[sum] = i;
		}
	}

	return max_len;
}

// Driver's Code
int main()
{
	int arr[] = { 15, -2, 2, -8, 1, 7, 10, 23 };
	int N = sizeof(arr) / sizeof(arr[0]);

	// Function call
	cout << "Length of the longest 0 sum subarray is "
		 << maxLen(arr, N);

	return 0;
}
Time Complexity: O(N), where N is the number of elements in the array.
Auxiliary Space: O(N)
-------------------------------------------------------------------------------------------
15) Permutation in String
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


-------------------------------------------------------------------------------
16) Find the Longest Semi-Repetitive Substring
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
        // Initialize the size of the string and variable to keep track of the
        // maximum length of the semi-repetitive substring found so far.
        int n = s.size();
        int longestLength = 0;
        int l=0;
        int r=0;
        int repeatCount=0;

        // Initialize pointers for substring window and a counter to track consecutive
        // character repetition count.
        while(r<n)
        {
        
            // If the character is the same as the previous one, increase repetition count.
            if (r > 0 && s[r] == s[r - 1]) {
                repeatCount++;
            }

            // If repeatCount is more than 1, it means the character has appeared
            // more than twice. Shift the left pointer to the right to reduce the count.
            while (repeatCount > 1) {
                if (s[l] == s[l + 1]) {
                    repeatCount--;
                }
                ++l;
            }

            // Update longestLength with the maximum length found so far.
            longestLength = max(longestLength, r - l + 1);
            r++;
        }

        // Return the length of the longest semi-repetitive substring.
        return longestLength;
    }
---------------------------------------------------------------------------------
17) Count the Number of Good Subarrays
Given an integer array nums and an integer k, return the number of good subarrays of 
nums.A subarray arr is good if it there are at least k pairs of indices (i, j) such 
that i < j and arr[i] == arr[j].
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
    long long res = 0;
    int l = 0, r = 0, count = 0, n = nums.size();
    unordered_map<int, int> freq;
    while (r < n) {
        cout << "freq[nums[r]]=" << freq[nums[r]] << endl;
        count = count + freq[nums[r]]++;
       
        while (count >= k) {
            freq[nums[l]]--;
            count -= freq[nums[l]];
            l++;
        }
        res += l;
        r++;
    }
    return res;
}
-------------------------------------------------------------------------
18) Minimum Consecutive Cards to Pick Up
You are given an integer array cards where cards[i] represents the value of the 
ith card. A pair of cards are matching if the cards have the same value.

Return the minimum number of consecutive cards you have to pick up to have a pair
of matching cards among the picked cards. If it is impossible to have matching cards, return -1.

Example 1:
Input: cards = [3,4,2,3,4,7]
Output: 4
Explanation: We can pick up the cards [3,4,2,3] which contain a matching pair of cards with value 3. Note that picking up the cards [4,2,3,4] is also optimal.
Example 2:
Input: cards = [1,0,5,3]
Output: -1
Explanation: There is no way to pick up a set of consecutive cards that contain a pair of matching cards.

 int minimumCardPickup(vector<int>& a) {
        int n=a.size();
        map<int,int>m;
        int l=0, r=0, ans=INT_MAX;
        while(r<n)
        {
            m[a[r]]++;
            while(m[a[r]]>1)
            {
                ans= min(ans, r-l+1);
                m[a[l]]--;
                l++;
            }
            r++;
        }
        return ans!=INT_MAX ? ans:-1;
    }
	Time complexity: O(n)
    Space complexity:O(n)

----------------------------------------------------------------------------
19) Count Number of Nice Subarrays:
Given an array of integers nums and an integer k. A continuous subarray is called 
nice if there are k odd numbers on it.

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
        int right = 0;
        map<int, int> map;
        int count = 0;
        int odd_count = 0;
        int ans_count = 0;
        while(right<nums.size())
        {
            if(nums[right]%2 ==1)
            {
                odd_count++;
                count=0;
            }
            while(odd_count>=k && left<=right)
            {
                if(nums[left]%2 ==1)
                {
                    odd_count--;
                }
                left++;
                count++;
            }
            ans_count +=count;
            right++;
        }
        return ans_count;
    }
};
---------------------------------------------------------------------------- 
20) Longest Substring with At Most K Distinct Characters:
Given a string you need to print longest possible substring that has exactly M unique characters. If there is more than one substring of longest possible length, then print any one of them.

Examples: 

Input: Str = “aabbcc”, k = 1
Output: 2
Explanation: Max substring can be any one from {“aa” , “bb” , “cc”}.

Input: Str = “aabbcc”, k = 2
Output: 4
Explanation: Max substring can be any one from {“aabb” , “bbcc”}.

Input: Str = “aabbcc”, k = 3
Output: 6
Explanation: 
There are substrings with exactly 3 unique characters
{“aabbcc” , “abbcc” , “aabbc” , “abbc” }
Max is “aabbcc” with length 6.

Input: Str = “aaabbb”, k = 3
Output: Not enough unique characters
Explanation: There are only two unique characters, thus show error message. 

Approach: using 2 pointers:
Take 2 pointers l & r pointing to starting index.
create unordered map<char, int>mp -> to store character with frequency. Insert elements with 
frequency until (r<n) and check if it's not valid(mp.size()> k)
then decrease frequency of mp[s[l]] and if it becomes zero, remove/erase it from map.
If mp.size()=k then it; svalid update max length.
 
int longestKSubstr(string s, int k)
{
	int longestKSubstr(string s, int k) {
    int l = 0;
	int r = 0;
	int ans = -1;
	int n = s.size();
	unordered_map<char, int> mp;
	while (r < n) 
	{
		mp[s[r]]++;
		if (mp.size() > k) 
		{
			mp[s[l]]--;
			if (mp[s[l]] == 0)
				mp.erase(s[l]);
			l++;
		}
		if (mp.size() == k) {
			ans = max(ans, r - l + 1);
		}
		r++;
	}
	return ans;
}

int main()
{
	string s = "aabacbebebe";
	int k = 3;
	cout << longestKSubstr(s, k) << endl;
	return 0;
}
Time Complexity: O(|S|)
Space Complexity:O(|S|)
-----------------------------------------------------------------------------
21) Fruit Into Baskets/max length subarray with at most 2 types of fruits
You are visiting a farm that has a single row of fruit trees arranged from left
to right. The trees are represented by an integer array fruits where fruits[i] is 
the type of fruit the ith tree produces.

You want to collect as much fruit as possible. However, the owner has some strict
rules that you must follow:

You only have two baskets, and each basket can only hold a single type of fruit. 
There is no limit on the amount of fruit each basket can hold.
Starting from any tree of your choice, you must pick exactly one fruit from every 
tree (including the start tree) while moving to the right. The picked fruits must
fit in one of your baskets.
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
        int n=fruits.size();
        int l=0,r=0;
        map<int,int>m;
        int ans=0;
        while(r<n)
        {
            m[fruits[r]]++;
             while(m.size()>2)
                {
                    m[fruits[l]]--;
                    if(m[fruits[l]]==0)
                        m.erase(fruits[l]);
                    l++;
                }
            if(m.size()<=2)
            {
                ans=max(ans,r-l+1); 
            }
            r++;  
               
        }
        return ans;
    }
Time complexity: O(n)
Space complexity: O(1)

-------------------------------------------------------------------------------
22) Max Consecutive Ones III
Given a binary array nums and an integer k, return the maximum number of consecutive 
1's in the array if you can flip at most k 0's.

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

Approach:
will increment cnt if we find 0 and if cnt becomes greater than k then will check 
if l is pointing to 0 will decrement cnt. 
 int longestOnes(vector<int>& arr, int k) {
        int cnt = 0,l = 0,r = 0,n = arr.size(),ans = -1;
        while(r<n)
        {
            if(arr[r] == 0) 
				cnt++;
            
            while(cnt>k)
			{				
				if(arr[l] == 0) 
				cnt--;
				l++;
			}
            r++;
            ans = max(ans,r-l);
			
        }
        return ans;    
    }

int main() {
  vector < int > nums = { 1, 1, 0, 1, 1, 1 };
  int ans =findMaxConsecutiveOnes(nums);
  cout << "The maximum  consecutive 1's are " << ans;
  return 0;
}
Time complexity: O(n)
Space complexity: O(1)
-----------------------------------------------------------------------------
23)Subarray Product Less Than K
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
-----------------------------------------------------------------------------------
-----Sliding window: Two pointer approach:
24) Two Sum : Check if a pair with given sum exists in Array:
Problem Statement: Given an array of integers arr[] and an integer target.
1st variant: Return YES if there exist two numbers such that their sum is equal to the target. Otherwise, return NO.
2nd variant: Return indices of the two numbers such that their sum is equal to the target. Otherwise, we will return {-1, -1}.
Note: You are not allowed to use the same element twice. Example: If the target is equal to 6 and num[1] = 3, then nums[1] + nums[1] = target is not a solution.

Examples:
Example 1:
Input Format: N = 5, arr[] = {2,6,5,8,11}, target = 14
Result: YES (for 1st variant)
       [1, 3] (for 2nd variant)
Explanation: arr[1] + arr[3] = 14. So, the answer is “YES” for the first variant and [1, 3] for 2nd variant.

Example 2:
Input Format: N = 5, arr[] = {2,6,5,8,11}, target = 15
Result: NO (for 1st variant)
	[-1, -1] (for 2nd variant)
Explanation: There exist no such two numbers whose sum is equal to the target.

Code Variant 1:
string twoSum(int n, vector<int> &arr, int target) {
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i] + arr[j] == target) return "YES";
        }
    }
    return "NO";
}
Code Variant 2:
vector<int> twoSum(int n, vector<int> &arr, int target) {
    vector<int> ans;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i] + arr[j] == target) {
                ans.push_back(i);
                ans.push_back(j);
                return ans;
            }
        }
    }
    return { -1, -1};
}
Time Complexity: O(N), where N = size of the array.
Reason: The loop runs N times in the worst case and searching in a hashmap takes O(1) generally. So the time complexity is O(N).
Note: In the worst case(which rarely happens), the unordered_map takes O(N) to find an element. In that case, the time complexity will be O(N2). If we use map instead of unordered_map, the time complexity will be O(N* logN) as the map data structure takes logN time to find an element.
Space Complexity: O(N) as we use the map data structure.
	
Better Approach(using Hashing):
Code for Variant 1:
string twoSum(int n, vector<int> &arr, int target) {
    unordered_map<int, int> mpp;
    for (int i = 0; i < n; i++) {
        int num = arr[i];
        int moreNeeded = target - num;
        if (mpp.find(moreNeeded) != mpp.end()) {
            return "YES";
        }
        mpp[num] = i;
    }
    return "NO";
}
Code for Variant 2:
vector<int> twoSum(int n, vector<int> &arr, int target) {
    unordered_map<int, int> mpp;
    for (int i = 0; i < n; i++) {
        int num = arr[i];
        int moreNeeded = target - num;
        if (mpp.find(moreNeeded) != mpp.end()) {
            return {mpp[moreNeeded], i};
        }
        mpp[num] = i;
    }
    return { -1, -1};
}
Time Complexity: O(N), where N = size of the array.
Reason: The loop runs N times in the worst case and searching in a hashmap takes O(1) generally. So the time complexity is O(N).
Note: In the worst case(which rarely happens), the unordered_map takes O(N) to find an element. In that case, the time complexity will be O(N2). If we use map instead of unordered_map, the time complexity will be O(N* logN) as the map data structure takes logN time to find an element.
Space Complexity: O(N) as we use the map data structure.

Optimized Approach(using two-pointer): 
Code for Variant 1:
string twoSum(int n, vector<int> &arr, int target) {
    sort(arr.begin(), arr.end());
    int left = 0, right = n - 1;
    while (left < right) {
        int sum = arr[left] + arr[right];
        if (sum == target) {
            return "YES";
        }
        else if (sum < target) left++;
        else right--;
    }
    return "NO";
}
Time Complexity: O(N) + O(N*logN), where N = size of the array.
Reason: The loop will run at most N times. And sorting the array will take N*logN time complexity.
Space Complexity: O(1) as we are not using any extra space.

Code for Variant 2:
vector<int> twoSum(vector<int>& nums, int target) {
    
        //Need vector of pair<int,int> to store value with index, so that we can sort array and index value would be present with each element
        vector<pair<int, int>>ans; 
        for(int i=0; i<nums.size(); i++)
        {
            ans.push_back({nums[i], i});
        }
       
        //Sort array:
        sort(ans.begin(), ans.end());
        int left=0; int right=ans.size()-1;
        while(left<right)
        {
            int sum = ans[left].first+ans[right].first;
            if(sum == target)
            {
                return {ans[left].second, ans[right].second};
            }
            else if(sum > target)
            {
                right--;
            }
            else
            {
                left++;
            }
        }
    return {};
}
Time Complexity: O(N*logN), where N = size of the array.
Space Complexity: O(1) 
----------------------------------------------------------------------------------------
25) 3Sum:
Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] such that i != j,
i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.
Notice that the solution set must not contain duplicate triplets.

Example 1:
Input: nums = [-1,0,1,2,-1,-4]
Output: [[-1,-1,2],[-1,0,1]]
Explanation: 
nums[0] + nums[1] + nums[2] = (-1) + 0 + 1 = 0.
nums[1] + nums[2] + nums[4] = 0 + 1 + (-1) = 0.
nums[0] + nums[3] + nums[4] = (-1) + 2 + (-1) = 0.
The distinct triplets are [-1,0,1] and [-1,-1,2].
Notice that the order of the output and the order of the triplets does not matter.

Example 2:
Input: nums = [0,1,1]
Output: []
Explanation: The only possible triplet does not sum up to 0.

Example 3:
Input: nums = [0,0,0]
Output: [[0,0,0]]
Explanation: The only possible triplet sums up to 0.

Approach 1: Using nested loop:
vector<vector<int>> threeSum(vector<int>& nums) 
{
        int n = nums.size();
        sort(nums.begin(), nums.end());
        set<vector<int>> set;
        vector<vector<int>> output;
        for(int i=0; i<n-2; i++)
		{
            for(int j=i+1; j<n-1; j++)
			{
                for(int k=j+1; k<n; k++)
				{
                    if((nums[i] + nums[j] + nums[k] == 0) && i != j && j != k && k != i)
					{
                        set.insert({nums[i], nums[j], nums[k]});
                    }
                }
            }
        }
        for(auto it : set)
		{
            output.push_back(it);
        }
        return output;
}
Time Complexity : O(N^3), Here three nested loop creates the time complexity. Where N is the size of the
array(nums).
Space Complexity : O(N), Hash Table(set) space.

Approach 1: Using 2 pointers:
vector<vector<int>> threeSum(vector<int>& nums) 
    {
        int n=nums.size();
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        for (int low = 0; low < n-2; low++) 
        {
            //remove duplicates:
			//Check if it's not first element and first and second elements are same then continue loop, don't 
			//execute after if statement..
            if (low > 0 && nums[low] == nums[low - 1]) 
                continue;
            //moving 2 pointers:
            int mid = low + 1;
            int high = n - 1;
            while (mid < high) 
            {
                int sum = nums[low] + nums[mid] + nums[high];
				if( sum == 0)
                {
                    vector<int> temp = {nums[low], nums[mid], nums[high]};
                    ans.push_back(temp);
                    mid++;
                    high--;
                    //skip the duplicates:
                    while (mid < high && nums[mid] == nums[mid - 1]) mid++;
                    while (mid <high && nums[high] == nums[high + 1]) high--;
                }
                else if (sum < 0) 
                {
                   mid++;
                }
                else
                {
                    high--;
                }
            }
        }
    return ans;
    }
	Time Complexity : O(N^2), Here Two nested loop creates the time complexity. Where N is the size of the
    array(nums).

    Space Complexity : O(1), Constant space. Extra space is only allocated for the Vector(output), however the
    output does not count towards the space complexity.

--------------------------------------------------------------------------------
26) 3Sum Closest
Given an integer array nums of length n and an integer target, find three integers in nums such that the 
sum is closest to target. Return the sum of the three integers.
You may assume that each input would have exactly one solution.

Example 1:
Input: nums = [-1,2,1,-4], target = 1
Output: 2
Explanation: The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).

Example 2:
Input: nums = [0,0,0], target = 1
Output: 0
Explanation: The sum that is closest to the target is 0. (0 + 0 + 0 = 0).

int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int ans = INT_MAX;
        int result = 0;
        for (int low = 0; low < nums.size() - 2; low++) {
            int mid = low + 1;
            int high = nums.size() - 1;
            while (mid < high) 
			{
                int sum = nums[low] + nums[mid] + nums[high];
                if (sum == target) {
                    return sum;
                } else if (abs(sum - target) < abs(ans)) {
                    ans = sum - target;
                    result = sum;
                }
                if (sum > target) {
                    high--;
                } else {
                    mid++;
                }
            }
        }
        return result;
    }
	Time complexity:0(N*N)
	Space complexity:0(1)
	
-------------------------------------------------------------------------------
27) 4Sum:
Given an array nums of n integers, return an array of all the unique quadruplets 
[nums[a], nums[b], nums[c], nums[d]] such that:

Example 1:
Input: nums = [1,0,-1,0,-2,2], target = 0
Output: [[-2,-1,1,2],[-2,0,0,2],[-1,0,0,1]]

Example 2:
Input: nums = [2,2,2,2,2], target = 8
Output: [[2,2,2,2]]

// C++ program for to  print all combination
// of 4 elements in A[] with sum equal to X
#include <bits/stdc++.h>
using namespace std;

/* A sorting based solution to print
all combination of 4 elements in A[]
with sum equal to X */
vector<vector<int>> fourSum(vector<int>& nums, int target) {
    int n = nums.size(); //size of the array
    vector<vector<int>> ans;

    // sort the given array:
    sort(nums.begin(), nums.end());

    //calculating the quadruplets:
    for (int i = 0; i < n-3; i++) {
        // avoid the duplicates while moving i:
        if (i > 0 && nums[i] == nums[i - 1]) continue;
        for (int j = i + 1; j < n-2; j++) {
            // avoid the duplicates while moving j:
            if (j > i + 1 && nums[j] == nums[j - 1]) continue;

            // 2 pointers:
            int k = j + 1;
            int l = n - 1;
			while (k < l) {
                long long sum = nums[i];
                sum += nums[j];
                sum += nums[k];
                sum += nums[l];
                if (sum == target) {
                    vector<int> temp = {nums[i], nums[j], nums[k], nums[l]};
                    ans.push_back(temp);
                    k++; l--;

                    //skip the duplicates for pointer k and l:
                    while (k < l && nums[k] == nums[k - 1]) k++;
                    while (k < l && nums[l] == nums[l + 1]) l--;
                }
                else if (sum < target) k++;
                else l--;
            }
        }
    }

    return ans;
}
/* Driver code */
int main()
{
    int A[] = { 1, 2, 3, 4, 5, 9, 7, 8 };
    int X = 16;
    int n = sizeof(A) / sizeof(A[0]);
    find4Numbers(A, n, X);
    return 0;
}
Time Complexity : O(n^3)
Auxiliary Space: O(1)

------------------------------------------------------------------------------
28) Valid Triangle Number
Given an integer array nums, return the number of triplets chosen from the array that can make triangles if we take them as side lengths of a triangle.

Example 1:
Input: nums = [2,2,3,4]
Output: 3
Explanation: Valid combinations are: 
2,3,4 (using the first 2)
2,3,4 (using the second 2)
2,2,3

Example 2:
Input: nums = [4,2,3,4]
Output: 4

int triangleNumber(vector<int>& nums) {
        int n = nums.size();
        int cnt = 0;
        sort(nums.begin(),nums.end());
        for(int i = n-1; i >=2; i--){
            int low = 0;
            int high = i - 1 ;
            while(low < high){
                if(nums[low] + nums[high] > nums[i]){
                    cnt += (high - low); //adding high-low to count
//sort([4,2,3,4])=> 2,2,3,4=> if i is at 3 and low at 2 and high at i-1(4)
//2+3>4{a+b>c}=> r-l=>2 => count would be increased by 2 becuase a(0th index), b(2th index)
//c(3rd index) and a+b>c means if low{a} reaches to 1st index even then a + b>c					
                    high--;
                }else{
                    low++;
                }
            }
        }
        return cnt ;
    }
	Time complexity: o(nlogn + n^2) => o(n^2)
	Space complexity:o(1)

-----------------------------------------------------------------------------------
29) Valid Palindrome:
A phrase is a palindrome if, after converting all uppercase letters into lowercase letters and removing all non-alphanumeric characters, it reads the same forward and backward. Alphanumeric characters include letters and numbers.

Given a string s, return true if it is a palindrome, or false otherwise.

Example 1:
Input: s = "A man, a plan, a canal: Panama"
Output: true
Explanation: "amanaplanacanalpanama" is a palindrome.

Example 2:
Input: s = "race a car"
Output: false
Explanation: "raceacar" is not a palindrome.

Example 3:
Input: s = " "
Output: true
Explanation: s is an empty string "" after removing non-alphanumeric characters.
Since an empty string reads the same forward and backward, it is a palindrome.
 
bool isPalindrome(string s) {
        int start = 0;
        int end = s.size() - 1;

        while(start<=end){
            if(!isalnum(s[start])){
                start++;
                continue; //Don't proceed and skip this case
            }

            if(!isalnum(s[end])){
                end--;
                continue; //Don't proceed and skip this case
            }

            if(tolower(s[start]) != tolower(s[end])) 
				return false;
            else
{
                start++;
                end--;
            }
        }
        return true;
    }
	Time complexity:O(n)
	Space complexity:O(1)

------------------------------------------------------------------------------------
30) Sort colors:
Given an array nums with n objects colored red, white, or blue, sort them in-place so that objects of the same color are adjacent, with the colors in the order red, white, and blue.
We will use the integers 0, 1, and 2 to represent the color red, white, and blue, respectively.
You must solve this problem without using the library's sort function.

Example 1:
Input: nums = [2,0,2,1,1,0]
Output: [0,0,1,1,2,2]

Example 2:
Input: nums = [2,0,1]
Output: [0,1,2]

Approach: will use 3 pointers: low, mid & high
0000000->low 1111111->mid high->22222222(if we find nums[mid]==1, means only increment mid)

void sortColors(vector<int>& nums) {
    int n=nums.size(),low=0,high=n-1,mid=0; // Initialization of low,high and mid.
    while(mid<=high){          // contition until mid<=high to run loop 
        if(nums[mid]==0){   // if find 0 then swap to send the left side
            swap(nums[low],nums[mid]);
            low++;
        }
        if(nums[mid]==2){  // if find 2 then swap to send the right side
            swap(nums[high],nums[mid]);
            high--;
        }
        else{mid++;} // iterate through the nums
    }
}
	Time complexity:O(N)
	Space complexity:O(1)

------------------------------------------------------------------------------------
31)Partition Array by Odd and Even/Segregate Even and Odd numbers:
Given an array A[], write a function that segregates even and odd numbers. The functions should put all even numbers first, and then odd numbers.
Example:  
Input  = {12, 34, 45, 9, 8, 90, 3}
Output = {12, 34, 8, 90, 45, 9, 3}

vector<int> sortArrayByParity(vector<int>& nums) 
    {
        int low=0, high=nums.size()-1;

        while(low<high)
        {
            //Until we are getting even integer at the beginning
            while(low<high && nums[low]%2==0) low++; 

            //Until we are getting odd integer at the end
            while(low<high && nums[high]%2==1) high--;

            //Swap odd integer from the beginning to the even integer at the end
            swap(nums[low], nums[high]);
            low++;
            high--;          
        }
        return nums;
    }
    
/* Driver code */
int main()
{
	int arr[] = {12, 34, 45, 9, 8, 90, 3};
	int arr_size = sizeof(arr)/sizeof(arr[0]);
	int i = 0;

	segregateEvenOdd(arr, arr_size);

	cout <<"Array after segregation ";
	for (i = 0; i < arr_size; i++)
		cout << arr[i] << " ";

	return 0;
}
Output : Array after segregation 12 34 90 8 9 45 3 
Time Complexity: O(n)
Auxiliary Space: O(1)
--------------------------------------------------------------------------
32) Remove Duplicates from Sorted Array
Given an integer array nums sorted in non-decreasing order, remove the duplicates in-place such that each unique element appears only once. The relative order of the elements should be kept the same. Then return the number of unique elements in nums.
Consider the number of unique elements of nums to be k, to get accepted, you need to do the following things:
Change the array nums such that the first k elements of nums contain the unique elements in the order they were present in nums initially. The remaining elements of nums are not important as well as the size of nums.
Return k.

Example 1:
Input: nums = [1,1,2]
Output: 2, nums = [1,2,_]
Explanation: Your function should return k = 2, with the first two elements of nums being 1 and 2 respectively.
It does not matter what you leave beyond the returned k (hence they are underscores).
Example 2:

Input: nums = [0,0,1,1,1,2,2,3,3,4]
Output: 5, nums = [0,1,2,3,4,_,_,_,_,_]
Explanation: Your function should return k = 5, with the first five elements of nums being 0, 1, 2, 3, and 4 respectively.
It does not matter what you leave beyond the returned k (hence they are underscores).

Approach:
Take two pointer left and right pointing to 0th and 1st index respectively.
Check if nums[left] != nums[right] then we got usinque element then store it to nums[left] and move left++

int removeDuplicates(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        int left = 0;
        for(int right =1; right< nums.size(); right++){
           if(nums[left] != nums[right])
               left++;
               nums[left] = nums[right];
           }
    return left+1;
    }
	Time Complexity - O(N)
	Space Complexity - O(1)

------------------------------------------------------------------------------------
33) Minimum Size Subarray Sum:
Given an array of positive integers nums and a positive integer target, return the minimal 
length of a subarray whose sum is greater than or equal to target. If there is no such subarray,
return 0 instead.

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
int minSubArrayLen(int target, vector<int>& nums) {
        int left=0,right=0;
        int n=nums.size();
        int sum=0;
        int minLength=INT_MAX;
        while(right<n)
        {
            sum+=nums[right];
            right++;
			while(sum>=target)
            {
			   //We have got the sum >= target then calculate minLength	
               minLength=min(minLength,right-left); //subarray length would be right-left
               sum-=nums[left];
               left++;
              
            }
        }
        if(minLength<INT_MAX)
            return minLength;
        else 
            return 0;
    }
	Time complexity:O(n)
    Space complexity:O(1)
-------------------------------------------------------------------------------------
34) Longest Substring Without Repeating Characters
Given a string s, find the length of the longest 
substring without repeating characters.

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

Approach 1: Using set:
int lengthOfLongestSubstring(string& s) {
        unordered_set<char> chars; // to store characters in the current window
        int maxSize = 0; // to store the maximum length of substring without repeating characters
        int left = 0, right = 0; // pointers for the sliding window
        
        // sliding window approach
        while (right < s.size()) {
            // if the current character at s[right] is already in the set
            while (chars.find(s[right]) != chars.end()) {
                // remove characters from the set and move the left pointer to the right
                chars.erase(s[left]);
                ++left;
            }
            
            // update the maximum length found so far
            maxSize = max(maxSize, right - left + 1);
            
            // add the current character to the set and move the right pointer to the right
            chars.insert(s[right]);
            ++right;
        }
        
        return maxSize;
    }
	Time complexity:O(n) because each character is processed at most twice (once by the right pointer and once by the left pointer).
	Space complexity:O(n) because in the worst case, we may need to store all characters in the set.

Approach 2: using map:
int lengthOfLongestSubstring(string s) {
      map<int, int >mpp;

      int left = 0, right = 0;
      int n = s.size();
      int len = 0;
      while (right < n) 
	  {
		  //Check if character is found in map 
		if (mpp.find(s[right]) != mpp.end())
		{
			//update left pointer: left should point to right+1
			//(it should be max then previous left index)
			left = max(mpp[s[right]] + 1, left);
		}
		//If character is not found in map: store character with index value
        mpp[s[right]] = right;

		//Update the length
        len = max(len, right - left + 1); //should add 1 to right-left, since we want length of included chars 
		// ex: abc{ l=0, r=2, r-l=2 but length of substring should be 3{abc}, so add 1.
        right++;
      }
      return len;
 }
    
-------------------------------------------------------------------------------------
35) The Smallest Difference
Example 1:

Input: A = [3, 6, 7, 4], B = [2, 8, 9, 3]
Output: 0
Explanation: A[0] - B[3] = 0
Example 2:

Input: A = [1, 2, 3, 4], B = [7, 6, 5]
Output: 1
Explanation: B[2] - A[3] = 1

Approach 1: using nested loop:
int findSmallestDifference(int A[], int B[], int m, int n) {
    int minDiff = INT_MAX; // Initialize with maximum integer value
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            int diff = abs(A[i] - B[j]); // Calculate absolute difference
            if (diff < minDiff) {
                minDiff = diff; // Update smallest difference found so far
            }
        }
    }
    return minDiff;
}
 
// Driver Code
int main()
{
    // Input given array A
    int A[] = {1, 2, 11, 5};
 
    // Input given array B
    int B[] = {4, 12, 19, 23, 127, 235};
 
 
    // Calculate size of Both arrays
    int m = sizeof(A) / sizeof(A[0]);
    int n = sizeof(B) / sizeof(B[0]);
 
    // Call function to print
    // smallest result
    cout << findSmallestDifference(A, B, m, n);
 
    return 0;
}

Approach 2: Using 2 pointers
Sort both the arrays
Put pointer a on Array A and pointer b on array B 
now check diff(A[a]-B[b]) and update the result with minimum value 
now check if element of A is less or element of B is less:
if A[a]<B[b] then move to next in Array A else move pointer b to B.(Sothat difference would be min)

int findSmallestDifference(int A[], int B[],
						int m, int n)
{
	// Sort both arrays using
	// sort function
	sort(A, A + m);
	sort(B, B + n);

	int a = 0, b = 0;

	// Initialize result as max value
	int result = INT_MAX;

	// Scan Both Arrays upto 
	// sizeof of the Arrays
	while (a < m && b < n)
	{
		if (abs(A[a] - B[b]) < result)
			result = abs(A[a] - B[b]);

		// Move Smaller Value: diff would be min if we have first operand min than second opernad
		//that's why we consider min(A, B)
		if (A[a] < B[b])
			a++;

		else
			b++;
	}

	// return final sma result
	return result; 
}

// Driver Code
int main()
{
	// Input given array A
	int A[] = {1, 2, 11, 5};

	// Input given array B
	int B[] = {4, 12, 19, 23, 127, 235};


	// Calculate size of Both arrays
	int m = sizeof(A) / sizeof(A[0]);
	int n = sizeof(B) / sizeof(B[0]);

	// Call function to print 
	// smallest result
	cout << findSmallestDifference(A, B, m, n);

	return 0;
}
Time Complexity: O(m log m + n log n)
This algorithm takes O(m log m + n log n) time to sort and O(m + n) time to find the minimum difference. Therefore, the overall runtime is O(m log m + n log n). 
Auxiliary Space: O(1)
-----------------------------------------------------------------------------------------------------
36) Find a pair with the given difference:
Given an unsorted array and a number n, find if there exists a pair of elements in the array whose difference is n. 
Examples: 

Input: arr[] = {5, 20, 3, 2, 50, 80}, n = 78
Output: Pair Found: (2, 80)

Input: arr[] = {90, 70, 20, 80, 50}, n = 45
Output: No Such Pair
Approach 1: Using nested loops:
Approach 2: Use sorting and two pointers
int findPair(int n, int x, vector<int> &arr) {
        // code here
        sort(arr.begin(), arr.end());
        int i=0, j=1;
        while(j<n){
            int diff=abs(arr[j]-arr[i]);
            
            if(diff==x){
                return 1;
            }
            else if(diff<x){
                j++;
            }
            else{
                i++;
            }
        }
        
        return -1;
    }
// Driver program to test above function 
int main() 
{ 
    int arr[] = {1, 8, 30, 40, 100}; 
    int size = sizeof(arr)/sizeof(arr[0]); 
    int n = -60; 
    findPair(arr, size, n); 
    return 0; 
} 
Time Complexity: O(n*log(n)) [Sorting is still required as first step], 
Where n is number of element in given array
Auxiliary Space: O(1)

---------------------------------------------------------
36) Container With Most Water
You are given an integer array height of length n. There are n vertical lines drawn such that the 
two endpoints of the ith line are (i, 0) and (i, height[i]).
Find two lines that together with the x-axis form a container, such that the container contains the most water.
Return the maximum amount of water a container can store.
Notice that you may not slant the container.
    
   |-|Water filled area    
   | |--------------|-|             
   | | |-|          | |
   | | | |          | |
   | | | |          | |
   | | | |          | |
   | | | | |-|      | |
 |-| | | | | |      | |
-------------------------------------
Input: height = [1,8,6,2,5,4,8,3,7]
Output: 49
Explanation: The above vertical lines are represented by array [1,8,6,2,5,4,8,3,7]. In this case, 
the max area of water (blue section) the container can contain is 49.
Example 2:

Input: height = [1,1]
Output: 1

int maxArea(vector<int>& height) {
        int maxArea = 0;
        int left = 0;
        int right = height.size() - 1;

        while (left < right) {
            maxArea = max(maxArea, (right - left) * min(height[left], height[right]));

            if (height[left] < height[right]) {
                left++;
            } else {
                right--;
            }
        }

        return maxArea;        
    }
	Time complexity: O(n)
	Space complexity: O(1)
--------------------------------------------------------------------------------
-----------hard:
37)Trapping Rain Water
Given n non-negative integers representing an elevation map where the width of each bar is 1,
compute how much water it can trap after raining

Input: height = [0,1,0,2,1,0,1,3,2,1,2,1]
Output: 6
Explanation: The above elevation map (black section) is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. In this case, 6 units of rain water (blue section) are being trapped.
Example 2:

Input: height = [4,2,0,3,2,5]
Output: 9

vector<int> getLeft(vector<int> height){
        int n = height.size();
        int maxi = -1;
        vector<int> ans(n);
        
        for(int i=0; i<n; i++){
            maxi = max(maxi, height[i]);
            ans[i] = maxi;
        }
        
        return ans;
    }
    
    vector<int> getRight(vector<int> height){
        int n = height.size();
        int maxi = -1;
        vector<int> ans(n);
        
        for(int i=n-1; i>=0; i--){
            maxi = max(maxi, height[i]);
            ans[i] = maxi;
        }
        
        return ans;
    }
    
    int trap(vector<int>& height) {
        vector<int> left = getLeft(height);
        vector<int> right = getRight(height);
        
        int ans = 0;
        
        for(int i=0; i<height.size(); i++){
            int tall = min(left[i], right[i]);
            
            int water = tall - height[i];
            ans += water;
        }
        
        return ans;
    }
	Time complexity:O(n)
	Space complexity:O(n)
------------------------------------------------------------------------
38) Minimum Window Substring:
Given two strings s and t of lengths m and n respectively, return the minimum window 
substring of s such that every character in t (including duplicates) is included in 
the window. If there is no such substring, return the empty string "".
The testcases will be generated such that the answer is unique.

Example 1:

Input: s = "ADOBECODEBANC", t = "ABC"
Output: "BANC"
Explanation: The minimum window substring "BANC" includes 'A', 'B', and 'C' from string t.

Example 2:
Input: s = "a", t = "a"
Output: "a"
Explanation: The entire string s is the minimum window.

Example 3:
Input: s = "a", t = "aa"
Output: ""
Explanation: Both 'a's from t must be included in the window.
Since the largest window of s only has one 'a', return empty string.

string minWindow(string s, string t) {
        int sizeS = s.size(), sizeT = t.size();
        if (sizeS==0 || sizeT==0 || sizeS<sizeT) return "";

        unordered_map<char, int> freq;
        for (char c:t){
            freq[c]++;
        }

        int minLen = INT_MAX;
        int start = 0;
        int l = 0, r = 0;
        int count = sizeT;  // tracks how many required chars from t are still needed in s
        while(r < sizeS){
            if (freq[s[r++]]-- > 0) count--;

            while (count==0){
                if (r-l < minLen){
                    start = l;
                    minLen = r-l;
                }

                if (freq[s[l++]]++==0) count++;
            }
        }

        return minLen == INT_MAX ? "" : s.substr(start, minLen);
    }

----------------------------------------------------------------------------------
39) Sliding Window Maximum
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
