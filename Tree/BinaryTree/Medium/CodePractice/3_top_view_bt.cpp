/*
Time Complexity: O(N)
Space Complexity: O(N)

Approach:
we will store Node and line(level number) to queue.
we will travere in level order traversal
we will store node->data into map[line]
*/        
vector<int> topView(Node *root)
    {
         vector<int> ans; 
        if(root == NULL) return ans; 
        map<int,int> mpp; 
        queue<pair<Node*, int>> q; 
        q.push({root, 0}); 
        while(!q.empty()) {
            auto it = q.front(); 
            q.pop(); 
            Node* node = it.first; 
            int line = it.second; 
			
			//Check if level/line is not already entered then only add it in map
			//otherwise top view data will be overwritten by bottom view nodes.
			if(mpp.find(line) == mpp.end())
			{
				mpp[line] = node->data; 
			}
            
            if(node->left != NULL) {
                q.push({node->left, line-1}); 
            }
            if(node->right != NULL) {
                q.push({node->right, line + 1}); 
            }
            
        }
        
        for(auto it : mpp) {
            ans.push_back(it.second); 
        }
        return ans;  
    
    }
