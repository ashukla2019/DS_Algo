/*
Time complexity: O(2n)
Space complexity: O(n)
*/  

bool isPalindrome(ListNode* head) 
    {
        vector<int>vec;
        ListNode* temp=head;
        while(temp !=NULL)
        {
            vec.push_back(temp->val);
            temp=temp->next;
        }
        int size=vec.size();
        for(int i=0; i<size/2; i++)
        {
            if(vec[i] != vec[size-1-i])
                return false;
        }
        return true;
    }
