//First Unique Character in a String:
/*Given a string s, find the first non-repeating character in it and return
//its index. If it does not exist, return -1.
*/
int firstUniqChar(string s)
{
	unordered_map<char, int> m;
	for (char& c : s) 
	{
		m[c]++;
	}
	for (int i = 0; i < s.size(); i++) 
	{
		if (m[s[i]] == 1) return i;
	}
	return -1;
}



