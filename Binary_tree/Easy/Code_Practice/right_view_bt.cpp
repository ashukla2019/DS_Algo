void checkRightView(Node* root, int level, vector<int>&ans)
{
	if(root == NULL)
		return;
	if(ans.size()==level)
		ans.push_back(root->data);
	
    checkRightView(root->right, level+1, ans);	
	checkRightView(root->left, level+1, ans);	
	
		
}

vector<int> rightView(Node *root)
{
   vector<int>ans;
   checkRightView(root, 0, ans);
   return ans;
}
