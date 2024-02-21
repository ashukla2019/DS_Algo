Input: arr[]={2,3,1,9,3,1,3,9}
Output:  {2,3,1,9}

// Function to remove duplicate elements from unsorted array
vector<int> removeDuplicate(int A[], int N) 
{
    vector<int>v;
    unordered_set<int>s;
    for(int i=0;i<N;i++)
    {
		if(s.find(A[i])==s.end())
        {
			s.insert(A[i]);
            v.push_back(A[i]);
        }
    }
    return v;
}
