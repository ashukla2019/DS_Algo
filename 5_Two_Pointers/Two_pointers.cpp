1) Two Sum : Check if a pair with given sum exists in Array:
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
3) 3Sum Closest
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
4) 4Sum:
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
        int n = nums.size();
        int cnt = 0;
        sort(nums.begin(),nums.end());
        for(int i = 2; i <= n-1; i++){
            int low = 0;
            int high = i - 1 ;
            while(low < high){
                if(nums[low] + nums[high] > nums[i]){
                    cnt += (high - low);
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
11)Partition Array by Odd and Even/Segregate Even and Odd numbers:
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
12) Remove Duplicates from Sorted Array
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
13) Minimum Size Subarray Sum:
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
               minLength=min(minLength,right-left);
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
	
----------------------------------------------------------------------------------
15) Longest Substring with At Most K Distinct Characters:
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

-------------------------------------------------------------------------------------
16) The Smallest Difference
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

--------------------------------------------------------------------------------
-----------hard:
17) Minimum Window Substring:
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
