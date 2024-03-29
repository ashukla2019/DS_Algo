/*
Time Complexity: O(N)
Space Complexity: O(N)

Approach:
we will store Node and line(level number) to queue.
we will travere in level order traversal
we will store node->data into map[line]
*/        
vector <int> bottomView(Node *root) 
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

            //Add data into map, no need to check if exist in map or not, anyway it's bottom view and will be overwritten for bottom view nodes    
            mpp[line] = node->data; 
            
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
