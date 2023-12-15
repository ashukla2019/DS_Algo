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
