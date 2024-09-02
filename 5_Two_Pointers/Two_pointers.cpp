1) Two Sum II - Input Array Is Sorted
Given a 1-indexed array of integers numbers that is already sorted in non-decreasing order, find two numbers such that they add up to a specific target number. Let these two numbers be numbers[index1] and numbers[index2] where 1 <= index1 < index2 <= numbers.length.
Return the indices of the two numbers, index1 and index2, added by one as an integer array [index1, index2] of length 2.
The tests are generated such that there is exactly one solution. You may not use the same element twice.
Your solution must use only constant extra space.

Example 1:
Input: numbers = [2,7,11,15], target = 9
Output: [1,2]
Explanation: The sum of 2 and 7 is 9. Therefore, index1 = 1, index2 = 2. We return [1, 2].

Example 2:
Input: numbers = [2,3,4], target = 6
Output: [1,3]
Explanation: The sum of 2 and 4 is 6. Therefore index1 = 1, index2 = 3. We return [1, 3].

Example 3:
Input: numbers = [-1,0], target = -1
Output: [1,2]
Explanation: The sum of -1 and 0 is -1. Therefore index1 = 1, index2 = 2. We return [1, 2].

vector<int> twoSum(vector<int>& numbers, int target) {
        int left = 0;
        int right = numbers.size() - 1;

        while (left < right) {
            int total = numbers[left] + numbers[right];

            if (total == target) {
                return {left + 1, right + 1};
            } else if (total > target) {
                right--;
            } else {
                left++;
            }
        }
        return {-1, -1}; // If no solution is found        
    }

----------------------------------------------------------------------------------------------
2) 3Sum:
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

vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        set<vector<int>> set;
        vector<vector<int>> output;
        for(int i=0; i<n-2; i++){
            int low = i+1, high = n-1;
            while(low < high){
                if(nums[i] + nums[low] + nums[high] < 0){
                    low++;
                }
                else if(nums[i] + nums[low] + nums[high] > 0){
                    high--;
                }
                else{
                    set.insert({nums[i], nums[low], nums[high]});
                    low++;
                    high--;
                }
            }
        }
        for(auto it : set){
            output.push_back(it);
        }
        return output;
    }
	Time Complexity : O(N^2), Here Two nested loop creates the time complexity. Where N is the size of the
    array(nums).

    Space Complexity : O(1), Constant space. Extra space is only allocated for the Vector(output), however the
    output does not count towards the space complexity.

--------------------------------------------------------------------------------
3) 3Sum Closest
Given an integer array nums of length n and an integer target, find three integers in nums such that the sum is closest to target.
Return the sum of the three integers.
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
        for (int i = 0; i < nums.size() - 2; i++) {
            int j = i + 1;
            int k = nums.size() - 1;
            while (j < k) {
                int sum = nums[i] + nums[j] + nums[k];
                if (sum == target) {
                    return sum;
                } else if (abs(sum - target) < abs(ans)) {
                    ans = sum - target;
                    result = sum;
                }
                if (sum > target) {
                    k--;
                } else {
                    j++;
                }
            }
        }
        return result;
    }
	Time complexity:0(N*N)
	Space complexity:0(1)
	
-------------------------------------------------------------------------------
4) 4Sum:
Given an array nums of n integers, return an array of all the unique quadruplets [nums[a], nums[b], nums[c], nums[d]] such that:

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
void find4Numbers(int A[], int n, int X)
{
    int l, r;

    // Sort the array in increasing
    // order, using library function
    // for quick sort
    sort(A, A + n);

    /* Now fix the first 2 elements
    one by one and find
    the other two elements */
    for (int i = 0; i < n - 3; i++) {
        for (int j = i + 1; j < n - 2; j++) {
            // Initialize two variables as
            // indexes of the first and last
            // elements in the remaining elements
            l = j + 1;
            r = n - 1;

            // To find the remaining two
            // elements, move the index
            // variables (l & r) toward each other.
            while (l < r) {
                if (A[i] + A[j] + A[l] + A[r] == X) {
                    cout << A[i] << " " << A[j] << " "
                         << A[l] << " " << A[r] << endl;
                    l++;
                    r--;
                }
                else if (A[i] + A[j] + A[l] + A[r] < X)
                    l++;
                else // A[i] + A[j] + A[l] + A[r] > X
                    r--;
            } // end of while
        } // end of inner for loop
    } // end of outer for loop
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
5) Valid Triangle Number
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
        sort(nums.begin(), nums.end());
        int count = 0;
        /*
        for any three sides a b c
              * a + b > c
             * a + c > b
            * b + c > a
        */
        int n = nums.size();
        for (int i = n-1 ; i >= 2 ; i--) {// for(int i=2; i<n; i++) also possible 
            int left = 0, right = i - 1;
            while(left < right){
                if(nums[left] + nums[right] > nums[i]) {
                    count += (right - left);// if nums[left] + nums[right] > nums[i] satisfies then the the no of trianlge pair will be right - left;
                    right--;
                }else{
                    left++;
                }
            }
        }
        return count;
    }
	Time complexity: o(nlogn + n^2) => o(n^2)
	Space complexity:o(1)

------------------------------------------------------------------------------
6)Trapping Rain Water
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

---------------------------------------------------------------------------------
7) Container With Most Water
You are given an integer array height of length n. There are n vertical lines drawn such that the 
two endpoints of the ith line are (i, 0) and (i, height[i]).
Find two lines that together with the x-axis form a container, such that the container contains the most water.
Return the maximum amount of water a container can store.
Notice that you may not slant the container.

Input: height = [1,8,6,2,5,4,8,3,7]
Output: 49
Explanation: The above vertical lines are represented by array [1,8,6,2,5,4,8,3,7]. In this case, the max area of water (blue section) the container can contain is 49.
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

------------------------------------------------------------------------------------
9) Valid Palindrome:
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
                continue;
            }

            if(!isalnum(s[end])){
                end--;
                continue;
            }

            if(tolower(s[start]) != tolower(s[end])) return false;
            else{
                start++;
                end--;
            }
        }
        return true;
    }
	Time complexity:O(n)
	Space complexity:O(1)

------------------------------------------------------------------------------------
10) Sort colors:
Given an array nums with n objects colored red, white, or blue, sort them in-place so that objects of the same color are adjacent, with the colors in the order red, white, and blue.
We will use the integers 0, 1, and 2 to represent the color red, white, and blue, respectively.
You must solve this problem without using the library's sort function.

Example 1:
Input: nums = [2,0,2,1,1,0]
Output: [0,0,1,1,2,2]

Example 2:
Input: nums = [2,0,1]
Output: [0,1,2]

void sortColors(vector<int>& nums) {
    int n=nums.size(),l=0,r=n-1,i=0; // Initialization of l,r and i.
    while(i<=r){          // contition until i<=r to run loop 
        if(nums[i]==0){   // if find 0 then swap to send the left side
            swap(nums[l],nums[i]);
            l++;
        }
        if(nums[i]==2){  // if find 2 then swap to send the right side
            swap(nums[r],nums[i]);
            r--;
        }
        else{i++;} // iterate through the nums
    }
}
	Time complexity:O(N)
	Space complexity:O(1)

------------------------------------------------------------------------------------
11)Partition Array by Odd and Even/Segregate Even and Odd numbers:
Given an array A[], write a function that segregates even and odd numbers. The functions should put all even numbers first, and then odd numbers.
Example:  
Input  = {12, 34, 45, 9, 8, 90, 3}
Output = {12, 34, 8, 90, 45, 9, 3}

// C++ program to segregate even and odd elements of array
#include <iostream>
using namespace std;

/* Function to swap *a and *b */
void swap(int *a, int *b);

void segregateEvenOdd(int arr[], int size)
{
	/* Initialize left and right indexes */
	int left = 0, right = size-1;
	while (left < right)
	{
		/* Increment left index while we see 0 at left */
		while (arr[left] % 2 == 0 && left < right)
			left++;

		/* Decrement right index while we see 1 at right */
		while (arr[right] % 2 == 1 && left < right)
			right--;

		if (left < right)
		{
			/* Swap arr[left] and arr[right]*/
			swap(&arr[left], &arr[right]);
			left++;
			right--;
		}
	}
}

/* UTILITY FUNCTIONS */
void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
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
----------------------------------------------------------------------------------
12) Sort Letters by Case:
Description
Given a string chars which contains only letters. Sort it by lower case first and upper case second.
In different languages, chars will be given in different ways. For example, the string "abc" will be given in following ways:

Example 1:
Input:
chars = "abAcD"
Output:
"acbAD"
Explanation:
You can also return "abcAD" or "cbaAD" or other correct answers.

------------------------------------------------------------------------------------
13) Minimum Size Subarray Sum:
Given an array of positive integers nums and a positive integer target, return the minimal length of a 
subarray whose sum is greater than or equal to target. If there is no such subarray, return 0 instead.

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
int minSubArrayLen(int k, vector<int>& arr) {
          
        int l=0,r=0;
        int n=arr.size();
        int sum=0;
        int mini=INT_MAX;
        while(r<n){
            sum+=arr[r++];
            while(sum>=k){
               sum-=arr[l++];
               mini=min(mini,r-l+1);
            }
        }
        if(mini<INT_MAX)
        return mini;
        else return 0;
       

    }
	Time complexity:O(n)
    Space complexity:O(1)
-------------------------------------------------------------------------------------
14) Longest Substring Without Repeating Characters
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
------------------------------------------------------------------------------------
15) Minimum Window Substring:
Given two strings s and t of lengths m and n respectively, return the minimum window 
substring of s such that every character in t (including duplicates) is included in the window. If there is no such substring, return the empty string "".
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
16) Longest Substring with At Most Two Distinct Characters
Given a string s, return the length of the longest substring that contains at most two distinct characters.

Example 1:
Input: s = "eceba"
Output: 3
Explanation: The substring is "ece" which its length is 3.
Example 2:

Input: s = "ccaabbb"
Output: 5
Explanation: The substring is "aabbb" which its length is 5.

class Solution {
public:
    int lengthOfLongestSubstringTwoDistinct(string s) {
        unordered_map<char, int> cnt;
        int n = s.size();
        int ans = 0;
        for (int i = 0, j = 0; i < n; ++i) {
            cnt[s[i]]++;
            while (cnt.size() > 2) {
                cnt[s[j]]--;
                if (cnt[s[j]] == 0) {
                    cnt.erase(s[j]);
                }
                ++j;
            }
            ans = max(ans, i - j + 1);
        }
        return ans;
    }
};

----------------------------------------------------------------------------------
17) Longest Substring with At Most K Distinct Characters:
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

Approach:
We declare a Map<Character,Integer> data structure to store frequency of characters.
Here we use acquire and release property .
In this we declare two pointers i and j, we traverse from i pointer and acquire characters until map size is greater than K. When map size get equals to k we store the length of i-j in a variable and traverse forward.
Once map size exceeds K,then we start releasing characters from map with the help of j pointer till map size again equals K, and we store the length and compare with 


#include <iostream>
#include <unordered_map>
using namespace std;

int longestKSubstr(string s, int k)
{
	int i = 0;
	int j = 0;
	int ans = -1;
	unordered_map<char, int> mp;
	while (j < s.size()) {
		mp[s[j]]++;
		while (mp.size() > k) {
			mp[s[i]]--;
			if (mp[s[i]] == 0)
				mp.erase(s[i]);
			i++;
		}
		if (mp.size() == k) {
			ans = max(ans, j - i + 1);
		}
		j++;
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


------------------------------------------------------------------------------------
18) Remove Duplicates from Sorted Array
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

-------------------------------------------------------------------------------------
19) The Smallest Difference
Example 1:

Input: A = [3, 6, 7, 4], B = [2, 8, 9, 3]
Output: 0
Explanation: A[0] - B[3] = 0
Example 2:

Input: A = [1, 2, 3, 4], B = [7, 6, 5]
Output: 1
Explanation: B[2] - A[3] = 1

// C++ Code to find Smallest 
// Difference between two Arrays
#include <bits/stdc++.h>
using namespace std;

// function to calculate Small 
// result between two arrays
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

		// Move Smaller Value
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

--------------------------------------------------------------------------------
20) Rotate Array:
Given an integer array nums, rotate the array to the right by k steps, where k is non-negative.

Example 1:

Input: nums = [1,2,3,4,5,6,7], k = 3
Output: [5,6,7,1,2,3,4]
Explanation:
rotate 1 steps to the right: [7,1,2,3,4,5,6]
rotate 2 steps to the right: [6,7,1,2,3,4,5]
rotate 3 steps to the right: [5,6,7,1,2,3,4]
Example 2:

Input: nums = [-1,-100,3,99], k = 2
Output: [3,99,-1,-100]
Explanation: 
rotate 1 steps to the right: [99,-1,-100,3]
rotate 2 steps to the right: [3,99,-1,-100]

void rotate(vector<int>& nums, int k) {
        int i, j;
        while(k>0)
        {
            j = nums.size() - 1;
            int temp;
            temp = nums[j];
            for(i = j-1; i>=0; i--)
                nums[i+1] = nums[i];
            
            nums[0] = temp;
            k--;
        }
    }

-----------------------------------------------------------------------------------
