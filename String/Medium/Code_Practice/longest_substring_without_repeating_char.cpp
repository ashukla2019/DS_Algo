Given a string str, find the length of the longest substring without repeating characters. 
Example:
Example 1:
Input: “ABCDEFGABEF”
Output: 7
Explanation: The longest substring without repeating characters are “ABCDEFG”, “BCDEFGA”, and “CDEFGAB” with lengths of 7

Example 2:
Input: “GEEKSFORGEEKS”
Output: 7
Explanation: The longest substrings without repeating characters are “EKSFORG” and “KSFORGE”, with lengths of 7
-----------------------------------------------------------------------------------------------
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
