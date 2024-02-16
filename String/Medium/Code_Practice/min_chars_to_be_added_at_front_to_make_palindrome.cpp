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
  
