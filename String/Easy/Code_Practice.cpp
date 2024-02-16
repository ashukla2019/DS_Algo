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
---------------------------------------------------------------------------------
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
