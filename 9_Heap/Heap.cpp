Top K Frequent Elements:
Given an integer array nums and an integer k, return the k most frequent elements. You may return the answer in
any order.

Example 1:
Input: nums = [1,1,1,2,2,3], k = 2
  
Output: [1,2]
Example 2:

Input: nums = [1], k = 1
Output: [1]
  
vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int>ans;
        unordered_map<int, int>u_mp;
        int n = nums.size();
        //Store the nums with frequencies in unordered_map
        for(int i=0; i<n; i++)
        {
            u_mp[nums[i]]++;
        }
        //Store data into priority queue:
        priority_queue<pair<int,int>>pq;
        for(auto it: u_mp)
        {
            pq.push(make_pair(it.second, it.first));
            
        }
        //While k does not become 0, start pushing pq.top().second to ans vector
        while(k != 0)
        {
            ans.push_back(pq.top().second);
            pq.pop();
            k--;
        }
        return ans;
    }
