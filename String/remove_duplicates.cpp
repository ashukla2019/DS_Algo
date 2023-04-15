//Remove duplicates from string:
Input: S = "zvvo"
Output: "zvo"
Explanation: Only keep the first occurrence

string removeDups(string s) 
{
    string str="";
for(int i=0;i<s.length();i++)
{
    if(str.find(s[i])==-1) //if str[i] reaches to -1, means character not found.
    {
		str=str+s[i];
    }
    else
    {
	//continue;
    }
}
return str;


