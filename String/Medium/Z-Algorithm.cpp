#include<bits/stdc++.h>
using namespace std;

/*
Input:
S = "batmanandrobinarebat", pat = "bat"
Output: 1 18
Explanation: The string "bat" occurs twice
in S, one starts are index 1 and the other
at index 18. 
*/

vector<int> search(string s, string pattern) 
{
    int patLen = pattern.length();
    int txtLen = s.length();
    vector<int>ans;
    string newString = pattern + "#" + s; //bat#batmanandrobinarebat(appended pattern#string)
    vector<int>z;
    int i=0;
    while(i<newString.length())
    {
        if(i<=patLen)//push 0 to z array until we reach to actual string's starting point(bat#batmanandrobinarebat)
        {
            z.push_back(0);
        }
        else
        {
		    //Now we put left and right index at zero
            int left= 0;
            int right= 0;
			//compare pattern with actual string. i is now at 4th position which is startig point of
			//actual string and left at starting point of pattern. We check if both char is same
			//then put right index at ith place.
            if(newString[left]==newString[i])
            {
                right =i;
				//if characters are matching then go ahead and increase left and right index.
                while(newString[left]==newString[right] && right<newString.length())
                {
                    left++;
                    right++;
                }
            }
			//Now we got left index value increased..may be same as pattern or less than that if less character matched..
            z.push_back(left);
        }
		//Now increase i value
        i++;
    }
    for(int i=0; i<newString.length(); i++)
    {
         if(z[i]==patLen)
        {
            ans.push_back(i-patLen);
        }
    }
    return ans;
}


