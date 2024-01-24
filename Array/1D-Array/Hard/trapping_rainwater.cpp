Problem Statement: Given an array of non-negative integers representation elevation of ground.
Your task is to find the water that can be trapped after rain.
Example 1:
Input: height= [0,1,0,2,1,0,1,3,2,1,2,1]
Output: 6
Explanation: As seen from the diagram 1+1+2+1+1=6 unit of water can be trapped

#include<bits/stdc++.h>
using namespace std;
int trap(vector<int>& height) {
        int n=height.size();
        int res=0;
        int maxLeft=0;
        int maxRight=0;
        int left=0, right=n-1;
        for(int i=0; i<n; i++)
        {
            //left side height <= right side height: consider left side for trapped water
            if(height[left]<=height[right])
            {
                //update leftMax since current left height is greter than maxLeft
                if(height[left]>maxLeft)
                {
                    maxLeft=height[left];
                }
                else
                {
                    res += maxLeft-height[left];
                }
                //increment left pointer
                left++;
            }
            else //right side height >= left side height: consider right side for trapped wate
            {
                //update rightMax since current right height is greter than maxRight
                if(height[right]>maxRight)
                {
                    maxRight=height[right];
                }
                else
                {
                    res += maxRight-height[right];
                }
                //decrement right pointer
                right--;
             }
        }
        return res;
    }

int main() {
  vector < int > arr;
  arr = {0,1,0,2,1,0,1,3,2,1,2,1};
  cout << "The water that can be trapped is " << trap(arr) << endl;
}
Output: The water that can be trapped is 6
Time Complexity: O(N) because we are using 2 pointer approach.
Space Complexity: O(1) because we are not using anything extra.
