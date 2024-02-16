Problem: Given a string s, remove all its adjacent duplicate characters recursively.
Example 1:
Input:
S = "geeksforgeek"
Output: "gksforgk"
Explanation: 
g(ee)ksforg(ee)k -> gksforgk

Example 2:
Input: 
S = "abccbccba"
Output: ""
Explanation: 
ab(cc)b(cc)ba->abbba->a(bbb)a->aa->(aa)->""(empty string)

Expected Time Complexity: O(|S|)
Expected Auxiliary Space: O(|S|)   

Approach: if we find string size is >0 and str.back()==s[i]
   then pop_back element, else push_back chars.
----------------------------------------------------------------------------------------------------------
//Recursively remove all adjacent duplicates 
Input: s = "abbaca"
Output: "ca"	
string removeDuplicates(string s) 
{
string str = "";
for(int i=0; i<s.length(); i++)
{
   if(str.size()>0 && str.back() == s[i])
   {
       str.pop_back();
   }
   else
   {
       str.push_back(s[i]);
   }
}
return str;

}	
