// C++ program to reverse a string
#include <bits/stdc++.h>
using namespace std;
 
// Function to reverse words*/
string reverseWords(string s)
{
    stringstream str(s);
    string res;
    string ans="";
    while(str>>res)
    {
        ans=res + " " + ans;
    }
    return ans;

}
 
// Driver Code
int main()
{
    string s = "i like this program very much";
    cout<<reverseWords(s);
    return 0;
}
o/p:much very program this like i 
