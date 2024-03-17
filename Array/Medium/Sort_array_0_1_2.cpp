Problem Statement: Given an array consisting of only 0s, 1s, and 2s. Write a program to 
in-place sort the array without using inbuilt sort functions. 
( Expected: Single pass-O(N) and constant space)
Examples
Input: nums = [2,0,2,1,1,0]
Output: [0,0,1,1,2,2]

Input: nums = [2,0,1]
Output: [0,1,2]

Input: nums = [0]
Output: [0]
/*
Time complexity: O(n)
Space complexity: O(1)

Logic: Use binary search technique
1) if arr[mid]==1 then mid++
2) if arr[mid]==0 then swap arr[low] and arr[mid] and then low++, mid++
3) else arr[mid] is 2 then swap arr[high] and arr[mid] then high--
*/  

void sortColors(vector<int>& nums) 
{
        int low = 0, mid = 0, high = nums.size()-1;
        while(mid <= high){
            if(nums[mid] == 0){
                swap(nums[low], nums[mid]);
                low++;
                mid++;
            }
            else if(nums[mid] == 1){
                mid++;
            }
            else{
                swap(nums[mid], nums[high]);
                high--;
            }
        }
    }
