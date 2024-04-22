/*
    Given int array & target, return indices of 2 nums that add to target
    Ex. nums = [2,7,11,15] & target = 9 -> [0,1], 2 + 7 = 9

    At each num, calculate complement, if exists in hash map then return

    Time: O(n)
    Space: O(n)
*/

vector<int> twoSum(vector<int>& nums, int target) 
{
        
     vector<int> ans;
     unordered_map<int,int> mpp;
     for(int i=0;i<nums.size();i++)
	 {
         if(mpp.find(target-nums[i])!=mpp.end())
		 {
             ans.push_back(mpp[target-nums[i]]);
             ans.push_back(i);
             return ans;
         }
         
        mpp[nums[i]]=i;
     }
        
     return ans;    
}
