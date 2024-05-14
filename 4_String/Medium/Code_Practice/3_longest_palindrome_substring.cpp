Given a string str, the task is to find the longest substring which is a palindrome.

Examples:
Input: str = “forgeeksskeegfor” 
Output: “geeksskeeg”
Explanation: There are several possible palindromic substrings like “kssk”, “ss”, “eeksskee” etc. But the substring “geeksskeeg” is the longest among all.

Input: str = “Geeks” 
Output: “ee”
---------------------------------------------------------------------------------------------- 
string longestPalindrome(string s) 
{
        int n = s.size();
        int start = 0;
        int maxLen = 1;

        for(int i=0; i<n; i++) 
        {
            //Even length palindrome
            int low = i-1;
            int high = i;

            //Check if it's in boundary(lower and upper) and chars are matching
            while(low>=0 && high<n && s[low]==s[high]) 
            {
                //If high-low+1(curent length) > maxLen: update maxLen and update start
                if(high-low+1 >  maxLen) 
                {
                    maxLen = high-low+1;
                    start = low;
                }
                low--; high++;
            }
            //Odd length palindrome
            low = i-1;
            high = i+1;

            //Check if it's in boundary(lower and upper) and chars are matching 
            while(low>=0 && high<n && s[low]==s[high]) 
            {
                //If high-low+1(curent length) > maxLen: update maxLen and update start
                if(high-low+1 >  maxLen) 
                {
                    maxLen = high-low+1;
                    start = low;
                }
                low--; high++;
            }
        } 
        //return substring which starts from start value and upto maxLen
        return s.substr(start, maxLen);
    }  
  
