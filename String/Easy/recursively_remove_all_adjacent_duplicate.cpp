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

