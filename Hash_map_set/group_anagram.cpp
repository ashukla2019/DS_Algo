/*
    Given array of strings, group anagrams together (same letters diff order)
    Ex. strs = ["eat","tea","tan","ate","nat","bat"] -> [["bat"],["nat","tan"],["ate","eat","tea"]]

    Count chars, for each string use total char counts (naturally sorted) as key

    Time: O(n x l) -> n = length of strs, l = max length of a string in strs
    Space: O(n x l)
*/

vector<vector<string>> groupAnagrams(vector<string>& strs) 
{
	vector<vector<string>>ans;
	//actually, key with value problem: input string will be key and corresponding
	//vector of anagram string will be value.
	map<string, vector<string>>mp;
	for(string s: strs)
	{
		string t = s; 
		sort(t.begin(), t.end());
		mp[t].push_back(s);
	}
	for(auto i: mp)
	{
		ans.push_back(i.second); //map's second will have group of anagram....
	}
	return ans;
}