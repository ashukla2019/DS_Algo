 #include <iostream>
 #include <string>
 #include <unordered_map>
 using namespace std;
 int lengthOfLongestSubstring(string s) 
{
        int n=s.length();
        int left=0;
        int right=0;
        unordered_map<int,int> m;
        int maxcnt=0;
        for(right=0;right<n;right++){
        // if char s[right] is already present in map and index of s[right] >= left then update the left pointer to previoues accour of that s[right] char + 1 
            if(m.find(s[right])!=m.end() && m[s[right]]>=left)
            {
                left=m[s[right]]+1;
                cout<<"m[s[right]]"<<m[s[right]]<<endl;
                cout<<"left==========="<<left<<endl;
                /*
                m[s[right]]0
                left===========1
                m[s[right]]1
                left===========2
                m[s[right]]2
                left===========3
                m[s[right]]4
                left===========5
                m[s[right]]6
                left===========7
                */
            }
            // everytime update the index for s[right]
            m[s[right]]=right;
           // for calculating the count of non repeating char between left and right do this  ->> (right-left+1)take always max   ->> maxcnt=max(maxcnt,right-left+1);
            maxcnt=max(maxcnt,right-left+1);
        } 
        return maxcnt;
    }
    
int main()
{
    int len = lengthOfLongestSubstring("abcabcbb");
    cout<<"result"<<len<<std::endl;
    return 0;
}
O/p: 3
