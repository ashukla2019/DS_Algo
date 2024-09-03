1) //Reverse String: 
/*Write a function that reverses a string. The input string is given as an array of characters s.
Input: s = ["h","e","l","l","o"]
Output: ["o","l","l","e","h"]
*/
void reverseString(vector<char>& s) 
{
	int n = s.size();
	for(int i=0; i<n/2; i++)
	{
		char temp = s[i];
		s[i] = s[n-1-i];
		s[n-1-i] = temp;
	}
}
Time Complexity: O(n)
Auxiliary Space: O(1)  
-------------------------------------------------------------------------------
2) Remove duplicates from string:
Given a string S which may contain lowercase and uppercase characters. The task is to remove all duplicate
characters from the string and find the resultant string.

Note: The order of remaining characters in the output should be the same as in the original string.
Example:

Input: Str = geeksforgeeks
Output: geksfor
Explanation: After removing duplicate characters such as e, k, g, s, we have string as “geksfor”.
// C++ program to create a unique string using unordered_map

/* access time in unordered_map on is O(1) generally if no
collisions occur and therefore it helps us check if an
element exists in a string in O(1) time complexity with
constant space. */

#include <bits/stdc++.h>
using namespace std;
string removeDuplicates(string s, int n)
{
	unordered_map<char, int> exists;
	string ans = "";
	for (int i = 0; i < n; i++) {
		if (exists.find(s[i]) == exists.end()) {
			ans.push_back(s[i]);
			exists[s[i]]++;
		}
	}
	return ans;
}

// driver code
int main()
{
	string s = "geeksforgeeks";
	int n = s.size();
	cout << removeDuplicates(s, n) << endl;
	return 0;
}
Time Complexity: O(n)
Auxiliary Space: O(n)  
--------------------------------------------------------------------------
3) Reverse words in given string:
Given an input string s, reverse the order of the words.
A word is defined as a sequence of non-space characters. The words in s will be separated by at
least one space.
Return a string of the words in reverse order concatenated by a single space.
Note that s may contain leading or trailing spaces or multiple spaces between two words. The returned string should only have a single space separating the words. Do not include any extra spaces.

Example 1:
Input: s = "the sky is blue"
Output: "blue is sky the"

Example 2:
Input: s = "  hello world  "
Output: "world hello"
Explanation: Your reversed string should not contain leading or trailing spaces.

Example 3:
Input: s = "a good   example"
Output: "example good a"
Explanation: You need to reduce multiple spaces between two words to a single space in the reversed string.

#include <bits/stdc++.h>
using namespace std;
 

string reverseWords(string &s){
	stringstream ss(s);
	string word, ans;
	while(ss >> word){
		ans = word + " " + ans;
	}
	return ans.substr(0, ans.size()-1);;     
}

// Driver Code
int main()
{
    string s = "i like this program very much";
    cout<<reverseWords(s);
    return 0;
}
----------------------------------------------------------------------- 
4) //Implement strstr:
/*Input: haystack = "hello", needle = "ll"
Output: 2
*/
int strStr(string haystack, string needle) 
 {
	int m = haystack.size(), n = needle.size();
	for (int i = 0; i <= m - n; i++) 
	{
		int j = 0;
		for (; j < n; j++)
		{
			if (haystack[i + j] != needle[j]) 
			{
				break;
			}
		}
		if (j == n) 
		{
			return i;
		}
	}
	return -1;
}
--------------------------------------------------------------------------
5) Given two strings. The task is to check whether the given strings are anagrams of each other or not. 
An anagram of a string is another string that contains the same characters, only the order of characters 
can be different. For example, “abcd” and “dabc” are an anagram of each other.

Examples:
Input: str1 = “listen”  str2 = “silent”
Output: “Anagram”
Explanation: All characters of “listen” and “silent” are the same.

Input: str1 = “gram”  str2 = “arm”
Output: “Not Anagram”

/* function to check whether two strings are anagram of
each other */
bool areAnagram(string str1, string str2)
{
	// Get lengths of both strings
	int n1 = str1.length();
	int n2 = str2.length();

	// If length of both strings is not same, then they
	// cannot be anagram
	if (n1 != n2)
		return false;

	// Sort both the strings
	sort(str1.begin(), str1.end());
	sort(str2.begin(), str2.end());

	// Compare sorted strings
	for (int i = 0; i < n1; i++)
		if (str1[i] != str2[i])
			return false;

	return true;
}

// Driver code
int main()
{
	string str1 = "gram";
	string str2 = "arm";

	// Function Call
	if (areAnagram(str1, str2))
		cout << "The two strings are anagram of each other";
	else
		cout << "The two strings are not anagram of each "
				"other";

	return 0;
}
----------------------------------------------------------------- 
6) Valid palindrome:
A phrase is a palindrome if, after converting all uppercase letters into lowercase letters and 
removing all non-alphanumeric characters, it reads the same forward and backward. 
Alphanumeric characters include letters and numbers.
Given a string s, return true if it is a palindrome, or false otherwise.
Input: s = "A man, a plan, a canal: Panama"
Output: true
Explanation: "amanaplanacanalpanama" is a palindrome.
*/
bool isPalindrome(string s) 
{
	int start=0, end=s.length()-1;
	while(start<end) 
	{
		if (!isalnum(s[start]))
		{
			start++;
		}
		else if (!isalnum(s[end])) 
		{
			end--;
		}
		else 
		{
			if (tolower(s[start++])!=tolower(s[end--])) 
			{
				return false;
			}
		}
	}
	return true;
}
-------------------------------------------------------------------- 
7) //Permutations of a given string :
Input: ABC
Output: ABC ACB BAC BCA CAB CBA
vector<string>find_permutation(string str)
{
     vector<string> s;
     sort(str.begin(), str.end());  
     do
     {
     	s.push_back(str);
     }while(next_permutation(str.begin(),str.end()));
     return s;
}
---------------------------------------------------------------------------
8) Recursively remove all adjacent duplicate:
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
----------------------------------------------------------------------------------
9) Given a Roman numeral, the task is to find its corresponding decimal value.

Example : 
Input: IX
Output: 9
Explanation: IX is a Roman symbol which represents 9

Input: XL
Output: 40
Explanation: XL is a Roman symbol which represents 40
 
// This function returns value
// of a Roman symbol
int value(char r)
{
	if (r == 'I')
		return 1;
	if (r == 'V')
		return 5;
	if (r == 'X')
		return 10;
	if (r == 'L')
		return 50;
	if (r == 'C')
		return 100;
	if (r == 'D')
		return 500;
	if (r == 'M')
		return 1000;

	return -1;
}

// Returns decimal value of
// roman numaral
int romanToDecimal(string& str)
{
	// Initialize result
	int res = 0;

	// Traverse given input
	for (int i = 0; i < str.length(); i++) {
		// Getting value of symbol s[i]
		int s1 = value(str[i]);

		if (i + 1 < str.length()) {
			// Getting value of symbol s[i+1]
			int s2 = value(str[i + 1]);

			// Comparing both values
			if (s1 >= s2) {
				// Value of current symbol
				// is greater or equal to
				// the next symbol
				res = res + s1;
			}
			else {
				// Value of current symbol is
				// less than the next symbol
				res = res + s2 - s1;
				i++;
			}
		}
		else {
			res = res + s1;
		}
	}
	return res;
}

// Driver Code
int main()
{
	// Considering inputs given are valid
	string str = "MCMIV";
	cout << "Integer form of Roman Numeral is "
		<< romanToDecimal(str) << endl;

	return 0;
}
Time Complexity: O(n), where n is the length of the string. 
Only one traversal of the string is required.
Auxiliary Space: O(1), As no extra space is required.  
-------------------------------------------------------------------------------
10) String to Integer (atoi):
Implement the myAtoi(string s) function, which converts a string to a 32-bit signed integer.
The algorithm for myAtoi(string s) is as follows:

Whitespace: Ignore any leading whitespace (" ").
Signedness: Determine the sign by checking if the next character is '-' or '+', assuming positivity is neither present.
Conversion: Read the integer by skipping leading zeros until a non-digit character is encountered or the end of the string is reached. If no digits were read, then the result is 0.
Rounding: If the integer is out of the 32-bit signed integer range [-231, 231 - 1], then round the integer to remain in the range. Specifically, integers less than -231 should be rounded to -231, and integers greater than 231 - 1 should be rounded to 231 - 1.
Return the integer as the final result.

Example 1:
Input: s = "42"
Output: 42
Explanation:
The underlined characters are what is read in and the caret is the current reader position.
Step 1: "42" (no characters read because there is no leading whitespace)
         ^
Step 2: "42" (no characters read because there is neither a '-' nor '+')
         ^
Step 3: "42" ("42" is read in)
           ^
Example 2:
Input: s = " -042"
Output: -42
Explanation:

Step 1: "   -042" (leading whitespace is read and ignored)
            ^
Step 2: "   -042" ('-' is read, so the result should be negative)
             ^
Step 3: "   -042" ("042" is read in, leading zeros ignored in the result)
               ^
Example 3:
Input: s = "1337c0d3"
Output: 1337
Explanation:
Step 1: "1337c0d3" (no characters read because there is no leading whitespace)
         ^
Step 2: "1337c0d3" (no characters read because there is neither a '-' nor '+')
         ^
Step 3: "1337c0d3" ("1337" is read in; reading stops because the next character is a non-digit)
             ^
Example 4:
Input: s = "0-1"
Output: 0
Explanation:

Step 1: "0-1" (no characters read because there is no leading whitespace)
         ^
Step 2: "0-1" (no characters read because there is neither a '-' nor '+')
         ^
Step 3: "0-1" ("0" is read in; reading stops because the next character is a non-digit)
          ^
Example 5:
Input: s = "words and 987"
Output: 0
Explanation:
Reading stops at the first non-digit character 'w'.


    int myAtoi(string s) {
        int n = s.length();
        int i = 0;
        int sign = 1;
        long long ans = 0;
        //Ignoring whitespaces
        while(i < s.length() && s[i] == ' '){
            i++;
        }
        // checking the signedness
        if((s[i] == '-' || s[i] == '+') && i < s.length()){
            sign = (s[i] == '-') ? -1 : 1;
            i++;
        }
        // skipping the leading zeroes
        while(i < s.length() && s[i] == '0'){
            i++;
        }
        // adding the all reaming values
        while(i < s.length() && (s[i] >= '0' && s[i] <= '9')){
            ans = ans * 10 + (s[i] - '0');
            if(ans * sign >= INT_MAX) return INT_MAX;
            if(ans * sign <= INT_MIN) return INT_MIN;
            i++;
        }
        return ans*sign;
    }
--------------------------------------------------------------------------
11) Longest common prefix:
Write a function to find the longest common prefix string amongst an array of strings.
If there is no common prefix, return an empty string "".

Example 1:

Input: strs = ["flower","flow","flight"]
Output: "fl"
Example 2:

Input: strs = ["dog","racecar","car"]
Output: ""
Explanation: There is no common prefix among the input strings.
 ===========================================================================
string longestCommonPrefix(vector<string>& strs) {
        string lcp = "";
        // sort strs
        sort(strs.begin(), strs.end()); 
        
        string first_str = strs[0];
        string last_str = strs[strs.size() - 1];

        for (int i=0; i< first_str.size(); i++) {
            if (first_str[i] == last_str[i])
                lcp += first_str[i];
            else
                break;
        }

        return lcp;
    }
----------------------------------------------------------------------
12) Longest palindrome substring:
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
 ---------------------------------------------------------------------- 
13) Count & say problem"
Find the n’th term in Look-and-say (Or Count and Say) Sequence. The look-and-say sequence is the sequence
of the below integers: 
1, 11, 21, 1211, 111221, 312211, 13112221, 1113213211, … 

How is the above sequence generated? 
n’th term is generated by reading (n-1)’th term.

The first term is "1"
Second term is "11", generated by reading first term as "One 1" 
(There is one 1 in previous term)
Third term is "21", generated by reading second term as "Two 1"
Fourth term is "1211", generated by reading third term as "One 2 One 1" 
and so on

// Returns n'th term in look-and-say sequence
string countnndSay(int n)
{
	// Base cases
	if (n == 1)	 return "1";
	if (n == 2)	 return "11";

	// Find n'th term by generating all terms from 3 to
	// n-1. Every term is generated using previous term
	string str = "11"; // Initialize previous term
	for (int i = 3; i<=n; i++)
	{
		// In below for loop, previous character
		// is processed in current iteration. That
		// is why a dummy character is added to make
		// sure that loop runs one extra iteration.
		str += '$';
		int len = str.length();

		int cnt = 1; // Initialize count of matching chars
		string tmp = ""; // Initialize i'th term in series

		// Process previous term to find the next term
		for (int j = 1; j < len; j++)
		{
			// If current character doesn't match
			if (str[j] != str[j-1])
			{
				// Append count of str[j-1] to temp
				tmp += cnt + '0';

				// Append str[j-1]
				tmp += str[j-1];

				// Reset count
				cnt = 1;
			}

			// If matches, then increment count of matching
			// characters
			else cnt++;
		}

		// Update str
		str = tmp;
	}

	return str;
}

// Driver program
int main()
{
	int N = 3;
	cout << countnndSay(N) << endl;
	return 0;
}
 --------------------------------------------------------------------- 
14) Longest substring without repeating characters:
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
---------------------------------------------------------------------------
15) min chars to be added at front to make palindrome:
Given string str we need to tell minimum characters to be added in front of the string to make string 
palindrome.

Examples: 
Input  : str = "ABC"
Output : 2
We can make above string palindrome as "CBABC"
by adding 'B' and 'C' at front.
Input  : str = "AACECAAAA";
Output : 2
We can make above string palindrome as AAAACECAAAA
by adding two A's at front of string.
----------------------------------------------------------------------------------------------------  
#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
	int addMinChar(string str1) {
		int n = str1.length();
		int start = 0;
		int end = n - 1;
		int res = 0;
		while (start < end) { // While the pointers have not met in the middle of the string
			if (str1[start] == str1[end]) { // If the characters at the start and end pointers are equal
				start++; // Move the start pointer to the right
				end--; // Move the end pointer to the left
			}
			else {
				res++; // Increment the count of characters to be added
				start = 0; // Reset the start pointer to the beginning of the string
				end = n - res - 1; // Reset the end pointer to the end of the string with a reduced number of characters
			}
		}
		return res; // Return the count of characters to be added
	}
};

int main() 
{
	Solution sol;
	string str = "AACECAAAA";
	cout << sol.addMinChar(str) << endl;
	return 0;
}
 ---------------------------------------------------------------------
16) 7-z algo:
/*
Example:
Index            0   1   2   3   4   5   6   7   8   9  10  11 
Text             a   a   b   c   a   a   b   x   a   a   a   z
Z values         X   1   0   0   3   1   0   0   2   2   1   0 
*/


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
-------------------------------------------------------------------------- 
17)  
 
