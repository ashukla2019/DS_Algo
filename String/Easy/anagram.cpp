/*
    Given 2 strings, return true if anagrams (same letters diff order)
    Ex. s = "anagram" & t = "nagaram" -> true, s = "rat" & t = "car" -> false

    Count chars, strings should have same # of chars if anagram

    Time: 
    Space: 
*/

bool isAnagram(string s, string t)
{
    sort(s.begin(), s.end());
    sort(t.begin(), t.end());
    
    return s == t;
}