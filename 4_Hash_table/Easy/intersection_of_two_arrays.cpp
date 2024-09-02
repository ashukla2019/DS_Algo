//Intersection of Two Arrays II:
/*
Given two integer arrays nums1 and nums2, return an array of their intersection. 
Each element in the result must appear as many times as it shows in both arrays and 
you may return the result in any order.

Input: nums1 = [1,2,2,1], nums2 = [2,2]
Output: [2,2]
*/

vector<int> intersection(vector<int>& nums1, vector<int>& nums2)
{
        unordered_set<int> m(nums1.begin(), nums1.end());
        vector<int> res;
        for (auto a : nums2)
        {
            if (m.count(a)) 
            {
                res.push_back(a);
                m.erase(a);
            }
        }
        return res;
    }
