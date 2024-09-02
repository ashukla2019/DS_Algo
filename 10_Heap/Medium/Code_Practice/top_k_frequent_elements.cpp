Given an integer array nums and an integer k, return the k most frequent elements. You may return the answer in any order.
Example 1:
Input: nums = [1,1,1,2,2,3], k = 2
Output: [1,2]
  
Example 2:
Input: nums = [1], k = 1
Output: [1]
 
Follow up: Your algorithm's time complexity must be better than O(n log n), where n is the array's size.

Approach:
1) Create unordered_map to store => {num , frequency}
2) Create min heap and push element {frequency , num} //sorting will be done on the basis of frequency value
3) Check if q.size() >k then pop elements
4) Now min heap is ready with k frequent elements.			     
----------------------------------------------------------------------------------------------------------------------  
 vector<int> topKFrequent(vector<int>& nums, int k) {
		unordered_map<int, int>m;
		for(int i=0; i<nums.size(); i++){
			m[nums[i]]++;
		}
		priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>q;
		for(auto it: m){
			q.push({it.second, it.first});
			if(q.size()>k){q.pop();}
		}
		vector<int>ans;
		while(!q.empty()){
			ans.push_back(q.top().second);
			q.pop();
		}
		return ans;
	} 
  
