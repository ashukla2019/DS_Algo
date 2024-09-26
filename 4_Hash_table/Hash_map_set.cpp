Hashing is a technique or process of mapping keys, and values into the hash table by 
using a hash function. It is done for faster access to elements.

1) Hash table implementation:
class Hash
{
	int bucket;
	list<int>* table;
	public:
	 Hash(int b)
	 {
		 bucket = b;
		 table = new list<int>[bucket];
	 }
	 int hashFunction(int val)
	 {
		 return(val%bucket);
	 }
	 void insertItem(int val)
	 {
		 int index = hashFunction(val);
		 table[index].push_back(val);
	 }
	 void deleteItem(int item)
	 {
		 int index = hashFunction(item);
		 table[index].remove(item);
	 }
	 void displayHash() 
	 { 
		for (int i = 0; i < bucket; i++)
		{ 
			cout << i; 
			for (auto x : table[i]) 
			cout << " --> " << x; 
			cout << endl; 
		} 
	 }
};

int main() 
{ 
	int arr[] = {3, 10, 13, 20, 25};
	int n = sizeof(arr)/sizeof(arr[0]); 
	Hash h(7); // 7 is count of buckets in 
	// hash table 
	for (int i = 0; i < n; i++) 
	{
		h.insertItem(arr[i]); 
	}

	// delete 12 from hash table 
	h.deleteItem(20); 
	// display the Hash table 
	h.displayHash(); 
	return 0; 
}
---------------------------------------------------------------------------
2) Find whether an array is subset of another array:
Given two arrays arr1[] and arr2[] of size m and n respectively, the task is to determine
whether arr2[] is a subset of arr1[]. Both arrays are not sorted, and elements are distinct.

Examples: 
Input: arr1[] = {11, 1, 13, 21, 3, 7}, arr2[] = {11, 3, 7, 1} 
Output: Yes

Input: arr1[] = {1, 2, 3, 4, 5, 6}, arr2[] = {1, 2, 4} 
Output: Yes

Input: arr1[] = {10, 5, 2, 23, 19}, arr2[] = {19, 5, 3} 
Output: No

	Approach 1: 
	#include<bits/stdc++.h>
	using namespace std;

	// Checks if an array is a subset of another array.
	bool isSubset(vector<int> & arr1, vector<int> & arr2, int m, int n) {
	  
		// Iterate over each element in the second array
		for (int i = 0; i < n; i++) {
			bool found = false;
		  
			// Check if the element from second array exists in the first array
			for (int j = 0; j < m; j++) {
				if (arr2[i] == arr1[j]) {
					found = true;
					break;
				}
			}
		  
			// If any element from second array is not found in first array, must return false
			if (!found) return false;
		}
	  
		// If all elements are found, return true
		return true;
	}

	int main() {
		vector<int> arr1 = {11, 1, 13, 21, 3, 7};
		vector<int> arr2 = {11, 3, 7, 1};
		int m = arr1.size();
		int n = arr2.size();

		if (isSubset(arr1, arr2, m, n)) {
			cout << "Yes" << endl;
		} else {
			cout << "No" << endl;
		}

		return 0;
	}
	Time Complexity: O(m*n)
	Auxiliary Space: O(1)

	Approach 2: Using two pointers:
	#include <bits/stdc++.h>
	using namespace std;

	bool isSubset(vector<int>& arr1, vector<int>& arr2)
	{

		// Sort both arrays
		sort(arr1.begin(), arr1.end());
		sort(arr2.begin(), arr2.end());

		int i = 0, j = 0;

		// Traverse both arrays using two pointers
		while (i < arr1.size() && j < arr2.size()) {
			if (arr1[i] < arr2[j]) {
				i++;
			}
			else if (arr1[i] == arr2[j]) {
				i++;
				j++;
			}
			else {
				// If element in arr2 is not found in arr1
				return false;
			}
		}

		// If we have traversed all elements in arr2, it is a
		// subset
		return (j == arr2.size());
	}

	int main()
	{
		vector<int> arr1 = { 11, 1, 13, 21, 3, 7 };
		vector<int> arr2 = { 11, 3, 7, 1 };

		if (isSubset(arr1, arr2)) {
			cout << "Yes" << endl;
		}
		else {
			cout << "No" << endl;
		}

		return 0;
	}
	Time Complexity: O(m log m + n log n)
	Auxiliary Space: O(1)

	Approach 3: Hashing
	#include <bits/stdc++.h>
	using namespace std;

	bool isSubsetUsingHashing(const vector<int>& arr1, const vector<int>& arr2) {

		// Create a hash set and insert all elements of arr1
		unordered_set<int> hashSet(arr1.begin(), arr1.end());
		
		// Check each element of arr2 in the hash set
		for (int num : arr2) {
			if (hashSet.find(num) == hashSet.end()) {
				return false;
			}
		}
		
		// If all elements of arr2 are found in the hash set
		return true;
	}

	// Driver code
	int main() {
		vector<int> arr1 = {1, 2, 3, 4, 5, 6, 7, 8};
		vector<int> arr2 = {1, 2, 3, 1};
		
		if (isSubsetUsingHashing(arr1, arr2)) {
			cout << "Yes" << endl;
		} else {
			cout << "No" << endl;
		}
		
		return 0;
	}
	Time Complexity: O(m + n), where m and n are the size of arr1 and arr2 respectively.
	Auxiliary Space: O(m)
---------------------------------------------------------------------------
3) Frequency of each character in a String using unordered_map in C++
Input: str = “geeksforgeeks” 
Output: 
r 1 
e 4 
s 2 
g 2 
k 2 
f 1 
o 1
Approach: Hashing:
void printFrequency(string str)
{
	// Define an unordered_map
	unordered_map<char, int> M;
	for (int i = 0; str[i]; i++) 
	{
		M[str[i]]++;
	}
	// Traverse the map to print the frequency
	for (auto& it : M) 
	{
		cout << it.first << ' ' << it.second << '\n';
	}
}
// Driver Code
int main()
{
	string str = "geeksforgeeks";
	// Function call
	printFrequency(str);
	return 0;
}	
------------------------------------------------------------------------------
4) Find first non-repeating character of given String:
Given a string S of lowercase English letters, the task is to find the index of the first non-repeating character. If there is no such character, return -1.

Examples: 
Input: S = “geeksforgeeks”
Output: 5
Explanation: ‘f’ is the first character in the string which does not repeat.
Approach 1: Using Two Nested Loops – O(n^2) time and O(1) auxiliary space.
int firstUniqChar(string s)
{
	int n = s.length();
	// Step 1: Iterate over each character in the string
	for (int i = 0; i < n; ++i) {
	bool found = true;
	// Step 2: Check if the character repeats in the
		// rest of the string
		for (int j = 0; j < n; ++j) {
			if (i != j && s[i] == s[j]) {
				found = false;
				break;
			}
		}

		// Step 3: If character does not repeat, return its
		// index
		if (found) {
			return i;
		}
	}

	// Step 4: If no such character is found, return -1
	return -1;
}

// Driver code
int main()
{
	string s = "geeksforgeeks";

	cout << firstUniqChar(s);

	return 0;
}
Time Complexity: O(n2)
Auxiliary Space: O(1)
Approach 2: Hashing 

int firstUniqChar(string s)
{
	// Step 1: Initialize frequency array for 26 lowercase
	// letters
	int freq[26] = { 0 };

	// Step 2: Populate the frequency array
	for (char c : s) {
		freq[c - 'a']++;
	}

	// Step 3: Find the first character with frequency 1
	for (int i = 0; i < s.length(); ++i) {
		if (freq[s[i] - 'a'] == 1) {
			return i;
		}
	}

	return -1;
}

// Driver code
int main()
{
	string s = "geeksforgeeks";
	cout << firstUniqChar(s);

	return 0;
}
Time Complexity: O(n), where n is the length of given string
Auxiliary Space: O(1)
----------------------------------------------------------------------
5) Find missing elements of a range:
Given an array, arr[0..n-1] of distinct elements and a range [low, high], find all numbers
that are in a range, but not the array. The missing elements should be printed in sorted order.

Examples:  
Input: arr[] = {10, 12, 11, 15}, 
       low = 10, high = 15
Output: 13, 14
Input: arr[] = {1, 14, 11, 51, 15}, 
       low = 50, high = 55
Output: 50, 52, 53, 54 55	

Approach 1: wo nested loops: one to traverse numbers from low to high and other one to traverse
entire array to find out whether the element of the outer  loop exists in the array or not.
If it doesn’t exist we will print it else continue to next iteration.

void findMissing(int arr[], int n, int low, int high) {
	// Loop through the range of numbers from low to high
	for (int i = low; i <= high; i++) {
		bool found = false;
	
		// Loop through the array to check if i exists in it
		for (int j = 0; j < n; j++) {
			if (arr[j] == i) {
				found = true;
				break;
			}
		}
	
		// If i is not found in the array, print it
		if (!found) {
			cout << i << " ";
		}
	}
}

// Driver's code
int main() {
	// Input array
	int arr[] = { 1, 3, 5, 4 };
	int n = sizeof(arr) / sizeof(arr[0]);
	int low = 1, high = 10;

	// Function call
	findMissing(arr, n, low, high);
	return 0;
}
Time Complexity: O( n * (high-low+1) ) as two nested for loops are executing with outer one from low to high and 
inner one from 1 to n where n is size of the input array.
Space Complexity: O(1) as no extra space has been taken.

Approach 2: Use Hashing
void printMissing(int arr[], int n, int low,
				int high)
{
	// Insert all elements of arr[] in set
	unordered_set<int> s;
	for (int i = 0; i < n; i++)
		s.insert(arr[i]);

	// Traverse through the range an print all
	// missing elements
	for (int x = low; x <= high; x++)
		if (s.find(x) == s.end())
			cout << x << " ";
}

// Driver program
int main()
{
	int arr[] = { 1, 3, 5, 4 };
	int n = sizeof(arr) / sizeof(arr[0]);
	int low = 1, high = 10;
	printMissing(arr, n, low, high);
	return 0;
}
Time Complexity: O(n + (high-low+1))
Auxiliary Space: O(n)
---------------------------------------------------------------------------------------
6) Count Distinct ( Unique ) elements in an array
Given an array arr[] of length N, The task is to count all distinct elements in arr[].

Examples: 
Input: arr[] = {10, 20, 20, 10, 30, 10}
Output: 3
Explanation: There are three distinct elements 10, 20, and 30.

Input: arr[] = {10, 20, 20, 10, 20}
Output: 2
Approach 1: Using two nested loops:
int countDistinct(int arr[], int n)
{
	int res = 1;

	// Pick all elements one by one
	for (int i = 1; i < n; i++) {
		int j = 0;
		for (j = 0; j < i; j++)
			if (arr[i] == arr[j])
				break;

		// If not printed earlier, then print it
		if (i == j)
			res++;
	}
	return res;
}

// Driver program to test above function
int main()
{
	int arr[] = { 12, 10, 9, 45, 2, 10, 10, 45 };
	int n = sizeof(arr) / sizeof(arr[0]);
	cout << countDistinct(arr, n);
	return 0;
}
Time Complexity: O(n2)
Auxiliary Space: O(1)

Approach 2: Using sorting:Sort the array so that all occurrences of every element become
consecutive. Once the occurrences become consecutive, then traverse the sorted array and 
count distinct elements by comparing the consecutive elements.

int countDistinct(int arr[], int n)
{
	// First sort the array so that all
	// occurrences become consecutive
	sort(arr, arr + n);

	// Traverse the sorted array
	int res = 0;
	for (int i = 0; i < n; i++) {

		// Move the index ahead while
		// there are duplicates
		while (i < n - 1 && arr[i] == arr[i + 1])
			i++;

		res++;
	}

	return res;
}

// Driver program to test above function
int main()
{
	int arr[] = { 6, 10, 5, 4, 9, 120, 4, 6, 10 };
	int n = sizeof(arr) / sizeof(arr[0]);
	cout << countDistinct(arr, n);
	return 0;
}
Time Complexity: O(n logn)
Auxiliary Space: O(1)

Approach 3: Using Hashing

int countDistinct(int arr[], int n)
{
	// Creates an empty hashset
	unordered_set<int> s;

	// Traverse the input array
	int res = 0;
	for (int i = 0; i < n; i++) {

		// If not present, then put it in
		// hashtable and increment result
		if (s.find(arr[i]) == s.end()) {
			s.insert(arr[i]);
			res++;
		}
	}

	return res;
}

// Driver Code
int main()
{
	int arr[] = { 6, 10, 5, 4, 9, 120, 4, 6, 10 };
	int n = sizeof(arr) / sizeof(arr[0]);
	cout << countDistinct(arr, n);
	return 0;
}
Time complexity: O(n)
Auxiliary Space: O(n)
-----------------------------------------------------------------------------
7) Count number of Distinct Substring in a String:
Input : abcd
Output : abcd abc ab a bcd bc b cd c d
All Elements are Distinct

Input : aaa
Output : aaa aa a aa a a
All elements are not Distinct

Approach 1: // C++ program to count all distinct substrings in a string
int distinctSubstring(string str)
{
	// Put all distinct substring in a HashSet
	set<string> result ;

	// List All Substrings
	for (int i = 0; i <= str.length(); i++)
	{
		for (int j = 1; j <= str.length()-i; j++)
		{

			// Add each substring in Set
			result.insert(str.substr(i, j));
		}
	}

	// Return size of the HashSet
	return result.size();
}

// Driver Code
int main()
{
	string str = "aaaa";
	cout << (distinctSubstring(str));
}

Time Complexity: O(n3logn)
Auxiliary Space: O(n)

Approach 2: Using hashing
void printSubstrings(string s)
{

	// To store distinct output substrings
	unordered_set<string> us;

	// Traverse through the given string and
	// one by one generate substrings beginning
	// from s[i].
	for (int i = 0; i < s.size(); ++i) {

		// One by one generate substrings ending
		// with s[j]
		string ss = "";
		for (int j = i; j < s.size(); ++j) {

			ss = ss + s[j];
			us.insert(ss);
		}
	}

	// Print all substrings one by one
	for (auto s : us)
		cout << s << " ";
}

// Driver code
int main()
{
	string str = "aaabc";
	printSubstrings(str);
	return 0;
}
Time Complexity: O(n2)
Auxiliary Space: O(n)
------------------------------------------------------------------
8) Write a function that takes a String as an argument and prints all unique words in it.

Examples:
Input: Java is great. Grails is also great
Output: Java
Grails
also

Approach: Using hashing

void printWords(const std::vector<std::string>& words) {
	std::unordered_set<std::string> uniqueWords;

	// For loop for iterating
	for (const std::string& word : words) {
		// Check if the word has been printed before
		if (uniqueWords.find(word) == uniqueWords.end()) {
			std::cout << word << std::endl;
			uniqueWords.insert(word);
		}
	}
}

int main() {
	// Input string
	std::string str = "geeks for geeks";

	// Storing string in the form of a vector of words
	std::vector<std::string> wordVector;
	std::istringstream iss(str);
	std::string word;
	while (iss >> word) {
		wordVector.push_back(word);
	}

	// Passing vector to print words function
	printWords(wordVector);

	return 0;
}
Time Complexity: O(n)
Auxiliary Space: O(n)
------------------------------------------------------------------------------
9) Minimum insertions to form a palindrome with permutations allowed
Given a string of lowercase letters. Find minimum characters to be inserted in the string so that it can become palindrome. We can change the positions of characters in the string.

Examples: 
Input : geeksforgeeks
Output : 2
geeksforgeeks can be changed as:
geeksroforskeeg
geeksorfroskeeg
and many more

Input : aabbc
Output : 0
aabbc can be changed as:
abcba
bacab	

Approach 1:
int minInsertion(string str) 
{ 
	// To store string length 
	int n = str.length(); 

	// To store number of characters 
	// occurring odd number of times 
	int res = 0; 

	// To store count of each 
	// character 
	int count[26] = { 0 }; 

	// To store occurrence of each 
	// character 
	for (int i = 0; i < n; i++) 
		count[str[i] - 'a']++; //count[g - 'a'] = count[6]

	// To count characters with odd 
	// occurrence 
	for (int i = 0; i < 26; i++) 
		if (count[i] % 2 == 1) //Checking the number of characters coming odd times
			res++; 

	// As one character can be odd return 
	// res - 1 but if string is already 
	// palindrome return 0 
	//res will be 3: means we need 3-1 =2 chars => 1 char would be always part of palindrome
	return (res == 0) ? 0 : res - 1; 
} 

// Driver program 
int main() 
{ 
	string str = "geeksforgeeks"; 
	cout << minInsertion(str); 

	return 0; 
} 
Time Complexity: O(n) 
Auxiliary Space: O(1)
----------------------------------------------------------------------
10) Count all distinct pairs with difference equal to k:
Given an integer array and a positive integer k, count all distinct pairs with differences equal to k. 

Examples: 
Input: arr[] = {1, 5, 3, 4, 2}, k = 3
Output: 2
There are 2 pairs with difference 3, the pairs are {1, 4} and {5, 2} 

Input: arr[] = {8, 12, 16, 4, 0, 20}, k = 4
Output: 5
There are 5 pairs with difference 4, the pairs are {0, 4}, {4, 8}, 
{8, 12}, {12, 16} and {16, 20} 	

Approach 1: using two nested loops
int countPairsWithDiffK(int arr[], int n, int k)
{
	int count = 0;

	// Pick all elements one by one
	for (int i = 0; i < n; i++) {
		// See if there is a pair of this picked element
		for (int j = i + 1; j < n; j++)
			if (arr[i] - arr[j] == k
				|| arr[j] - arr[i] == k)
				count++;
	}
	return count;
}

// Driver program to test above function
int main()
{
	int arr[] = { 1, 5, 3, 4, 2 };
	int n = sizeof(arr) / sizeof(arr[0]);
	int k = 3;
	cout << "Count of pairs with given diff is "
		<< countPairsWithDiffK(arr, n, k);
	return 0;
}
Time Complexity: O(n2)
Auxiliary Space: O(1)

Approach 2: using hashing
int findPairs(vector<int>& nums, int k) 
{
	//the least time complexity is O(n) comes when we use map
	//map is the only data structure that searches in O(1) time complexity
	int n=nums.size();
	map<int,int> mp;
	for(auto p:nums) mp[p]++;
	int ans=0;
	for(auto p:mp)
	{
		//If k==0, then if p.second>1 means we have got element with same value in array
		//If k>0, then mp.count will check if p.first+k exists
    		if((k==0 && p.second>1) || (k!=0 && mp.count(p.first+k))) ans++;
	}
        return ans;
    }
Time Complexity: O(n)
Auxiliary Space: O(n)

Approach 3: Using sorting
Take two pointers l&r, set them at starting index.
run while(r<n)
case1: if(arr[r] - arr[l] == k), increment counter, l and r 
case 2: if(arr[r] - arr[l] > k), increment l sothat we can reduce the difference to reach k
case 3: if(arr[r] - arr[l] < k), increment r sothat we can increase the difference to reach k

int countPairsWithDiffK(int arr[], int n, int k)
{
	int count = 0;
	sort(arr, arr+n); // Sort array elements

	int l = 0;
	int r = 0;
	while(r < n)
	{
		if(arr[r] - arr[l] == k)
		{
			count++;
			l++;
			r++;
		}
		else if(arr[r] - arr[l] > k)
			l++;
		else // arr[r] - arr[l] < sum
			r++;
	} 
	return count;
}

// Driver program to test above function
int main()
{
	int arr[] = {1, 5, 3, 4, 2};
	int n = sizeof(arr)/sizeof(arr[0]);
	int k = 3;
	cout << "Count of pairs with given diff is "
		<< countPairsWithDiffK(arr, n, k);
	return 0;
}
Time Complexity: O(nlogn)
Auxiliary Space: O(1)
-----------------------------------------------------------------------------
------------------Medium--------------------------------
11)Longest Consecutive Subsequence:
Given an array of integers, find the length of the longest sub-sequence such that elements 
in the subsequence are consecutive integers, the consecutive numbers can be in any order. 

Examples:  
Input: arr[] = {1, 9, 3, 10, 4, 20, 2}
Output: 4
Explanation: The subsequence 1, 3, 4, 2 is the longest subsequence of consecutive elements

Input: arr[] = {36, 41, 56, 35, 44, 33, 34, 92, 43, 32, 42}
Output: 5
Explanation: The subsequence 36, 35, 33, 34, 32 is the longest subsequence of consecutive elements.

Approach 1: Intialise ans and countConsecutive with 0.
Sort the arr[].
Store the distinct elements in dist[] array by traversing over the arr[].
Now, traverse on the dist[] array to find the count of consecutive elements and maintain the 
answer variable.

int findLongestConseqSubseq(int arr[], int n)
{
	int ans = 0, count = 0;

	// sort the array
	sort(arr, arr + n);

	vector<int> v;
	v.push_back(arr[0]);

	// insert repeated elements only once in the vector
	for (int i = 1; i < n; i++) {
		if (arr[i] != arr[i - 1])
			v.push_back(arr[i]);
	}
	// find the maximum length
	// by traversing the array
	for (int i = 0; i < v.size(); i++) {

		// Check if the current element is equal
		// to previous element +1
		if (i > 0 && v[i] == v[i - 1] + 1)
			count++;
		// reset the count
		else
			count = 1;

		// update the maximum
		ans = max(ans, count);
	}
	return ans;
}

// Driver code
int main()
{
	int arr[] = { 1, 2, 2, 3 };
	int n = sizeof arr / sizeof arr[0];
	cout << "Length of the Longest contiguous subsequence "
			"is "
		 << findLongestConseqSubseq(arr, n);
	return 0;
}
Time complexity: O(Nlog(N)), Time to sort the array is O(Nlog(N)).
Auxiliary space: O(N).

Approach 2: Using Hashing
int longestSuccessiveElements(vector<int>&a) {
    int n = a.size();
    if (n == 0) return 0;

    int longest = 1;
    unordered_set<int> st;
    //put all the array elements into set:
    for (int i = 0; i < n; i++) {
        st.insert(a[i]);
    }

    //Find the longest sequence:
    for (auto it : st) {
        //if 'it' is a starting number:
        if (st.find(it - 1) == st.end()) {
            //find consecutive numbers:
            int cnt = 1;
            int x = it;
            while (st.find(x + 1) != st.end()) {
                x = x + 1;
                cnt = cnt + 1;
            }
            longest = max(longest, cnt);
        }
    }
    return longest;

}

int main()
{
    vector<int> a = {100, 200, 1, 2, 3, 4};
    int ans = longestSuccessiveElements(a);
    cout << "The longest consecutive sequence is " << ans << "\n";
    return 0;
}

Time complexity: O(N), Only one traversal is needed and the time complexity is O(N) 
under the assumption that hash insert and search takes O(1) time.
Auxiliary space: O(N),
----------------------------------------------------------------------
12) Find the first repeating element in an array of integers	
Given an array of integers arr[], The task is to find the index of first repeating element in it i.e. the element that occurs more than once and whose index of the first occurrence is the smallest. 

Examples: 
Input: arr[] = {10, 5, 3, 4, 3, 5, 6}
Output: 5 
Explanation: 5 is the first element that repeats

Input: arr[] = {6, 10, 5, 4, 9, 120, 4, 6, 10}
Output: 6 
Explanation: 6 is the first element that repeats	
	
Approach 1: Using nested loops:
int firstRepeatingElement(int arr[], int n)
{
	// Nested loop to check for repeating elements
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			// If a repeating element is found, return its
			// index
			if (arr[i] == arr[j]) {
				return i;
			}
		}
	}
	// If no repeating element is found, return -1
	return -1;
}

// Driver code
int main()
{
	// Initializing an array and its size
	int arr[] = { 10, 5, 3, 4, 3, 5, 6 };
	int n = sizeof(arr) / sizeof(arr[0]);
	// Finding the index of first repeating element
	int index = firstRepeatingElement(arr, n);

	// Checking if any repeating element is found or not
	if (index == -1) {
		cout << "No repeating element found!" << endl;
	}
	else {
		// Printing the first repeating element and its
		// index
		cout << "First repeating element is " << arr[index]
			<< endl;
	}

	return 0;
}
Time Complexity: O(N2)
Auxiliary Space: O(1)

Approach 2: Using Hashing:
will travese array from end and will add element to set.
if elementis present in set and then update min with current index value(repeating case)
At last, will print arr[min], that would be first repeating char.
void printFirstRepeating(int arr[], int n)
{
    // Initialize index of first repeating element
    int min = -1;
 
    // Creates an empty hashset
    set<int> myset;
 
    // Traverse the input array from right to left
    for (int i = n - 1; i >= 0; i--) {
        // If element is already in hash set, update min
        if (myset.find(arr[i]) != myset.end())
            min = i;
 
        else // Else add element to hash set
            myset.insert(arr[i]);
    }
 
    // Print the result
    if (min != -1)
        cout << "The first repeating element is "
             << arr[min];
    else
        cout << "There are no repeating elements";
}
 
// Driver Code
int main()
{
    int arr[] = { 10, 5, 3, 4, 3, 5, 6 };
 
    int n = sizeof(arr) / sizeof(arr[0]);
    printFirstRepeating(arr, n);
}
Time Complexity: O(N).
Auxiliary Space: O(N)
--------------------------------------------------------------------------------
13) Given a sequence of words, print all anagrams together
Input : {“cat”, “dog”, “tac”, “god”, “act”}
Output : {“cat”, “tac”, “act”, ‘”dog”, “god”}	
	Approach: HashMap with O(NM) Solution
 vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;
        
        for(auto x: strs){
            string word = x;
            sort(word.begin(), word.end());
            mp[word].push_back(x);
        }
        
        vector<vector<string>> ans;
        for(auto x: mp){
            ans.push_back(x.second);
        }
        return ans;
    }
---------------------------------------------------------------------------------
14) Largest subarray with equal number of 0s and 1s:
Given an array containing only 0s and 1s, find the largest subarray which contains equal no of 0s and 1s. The expected time complexity is O(n). 

Examples: 
Input: arr[] = {1, 0, 1, 1, 1, 0, 0}
Output: 1 to 6
(Starting and Ending indexes of output subarray)

Input: arr[] = {1, 1, 1, 1}
Output: No such subarray

Input: arr[] = {0, 0, 1, 1, 0}
Output: 0 to 3 Or 1 to 4	

Approach 1:
The brute force approach is to generate all the possible sub-arrays. Then firstly 
check whether the sub-array has equal number of 0’s and 1’s or not. To make this process
easy take cumulative sum of the sub-arrays taking 0’s as -1 and 1’s as it is. The point
where cumulative sum = 0 will signify that the sub-array from starting till that point has 
equal number of 0’s and 1’s. Now as this is a valid sub-array, compare it’s size with the
maximum size of such sub-array found till now. 

int findSubArray(int nums[], int n) {
  int sum = 0;
  int maxlen = -1, startindex;

  // Pick a starting point as i
  for (int i = 0; i < n - 1; i++) {
    sum = (nums[i] == 0) ? -1 : 1;

    // Consider all subarrays starting from i
    for (int j = i + 1; j < n; j++) {
      (nums[j] == 0) ? (sum += -1) : (sum += 1);

      // If this is a 0 sum subarray, then
      // compare it with maximum size subarray
      if (sum == 0 && maxlen < j - i + 1) {
        maxlen = j - i + 1;
        startindex = i;
      }
    }
  }
  if (maxlen == -1)
    cout << "No such subarray";
  else
    cout << "The length of the longest subarray is: " << maxlen;
}

/* Driver code*/
int main() {
  int arr[] = { 1, 0, 0, 1, 0, 0, 1 };
  int size = sizeof(arr) / sizeof(arr[0]);

  findSubArray(arr, size);
  return 0;
}
Output: The length of the longest s
Time Complexity: O(n^2). 
As all the possible sub-arrays are generated using a pair of nested loops.
Auxiliary Space: O(1). 
As no extra data structure is used which takes auxiliary space.

Approach 2: Using Hashmap
Start with two vars: maxlen and count 
count will store the cumulative sum{we will check array element if it's 1 then add 1 else add -1}
if count or cumulative sum becomes 0 means we got equal number of 0s and 1s in subarray.
store if count value is not present in map with index i. If count value is found in map then it got 
the cumulative sum 0 and need to 
int findMaxLength(vector<int>& nums) 
{
        unordered_map<int,int> mp; //stores [cumSum->index]
        mp[0]=-1;
        int maxLength=0, cumSum=0; //cummulativeSum
        for(int i=0;i<nums.size();i++)
        {
            cumSum+=(nums[i]==0)?-1:1; //we are using prefix sum algo, so converting all 0's to -1 to create 0 sum
            if(mp.find(cumSum)!=mp.end()) 
                maxLength=max(maxLength, i-mp[cumSum]);
            else 
                mp[cumSum]=i;
        }
        return maxLength;
    }
/* Driver code*/
int main() {
  int arr[] = { 1, 0, 0, 1, 0, 0, 1 };
  int size = sizeof(arr) / sizeof(arr[0]);
  findMaxLength(arr, size);
  return 0;
}
Time Complexity: O(n). 
Auxiliary Space: O(n). 
----------------------------------------------------------------------------
15) Range Queries for Frequencies of array elements
Given an array of n non-negative integers. The task is to find frequency of a particular element in the arbitrary range of array[]. 
The range is given as positions (not 0 based indexes) in array. There can be multiple queries of given type.

Examples: 
Input  : arr[] = {2, 8, 6, 9, 8, 6, 8, 2, 11};
         left = 2, right = 8, element = 8
         left = 2, right = 5, element = 6      
Output : 3
         1
The element 8 appears 3 times in arr[left-1..right-1]
The element 6 appears 1 time in arr[left-1..right-1]	

Approach 1: is to traverse from left to right and update count variable whenever we find the element. 
int findFrequency(int arr[], int n, int left, 
						int right, int element) 
{ 
	int count = 0; 
	for (int i=left-1; i<=right; ++i) 
		if (arr[i] == element) 
			++count; 
	return count; 
} 

// Driver Code 
int main() 
{ 
	int arr[] = {2, 8, 6, 9, 8, 6, 8, 2, 11}; 
	int n = sizeof(arr) / sizeof(arr[0]); 

	// Print frequency of 2 from position 1 to 6 
	cout << "Frequency of 2 from 1 to 6 = "
		<< findFrequency(arr, n, 1, 6, 2) << endl; 

	// Print frequency of 8 from position 4 to 9 
	cout << "Frequency of 8 from 4 to 9 = "
		<< findFrequency(arr, n, 4, 9, 8); 

	return 0; 
} 
Output
Frequency of 2 from 1 to 6 = 1
Frequency of 8 from 4 to 9 = 2
Time complexity of this approach is O(right – left + 1) or O(n) 
Auxiliary space: O(1)

Approach 2: using Hashing
unordered_map< int, vector<int> > store; 

// Returns frequency of element in arr[left-1..right-1] 
int findFrequency(int arr[], int n, int left, 
					int right, int element) 
{ 
	// Find the position of first occurrence of element 
	int a = lower_bound(store[element].begin(), 
						store[element].end(), 
						left) 
			- store[element].begin(); 

	// Find the position of last occurrence of element 
	int b = upper_bound(store[element].begin(), 
						store[element].end(), 
						right) 
			- store[element].begin(); 

	return b-a; 
} 

// Driver code 
int main() 
{ 
	int arr[] = {2, 8, 6, 9, 8, 6, 8, 2, 11}; 
	int n = sizeof(arr) / sizeof(arr[0]); 

	// Storing the indexes of an element in the map 
	for (int i=0; i<n; ++i) 
		store[arr[i]].push_back(i+1); //starting index from 1 

	// Print frequency of 2 from position 1 to 6 
	cout << "Frequency of 2 from 1 to 6 = "
		<< findFrequency(arr, n, 1, 6, 2) <<endl; 

	// Print frequency of 8 from position 4 to 9 
	cout << "Frequency of 8 from 4 to 9 = "
		<< findFrequency(arr, n, 4, 9, 8); 

	return 0; 
} 
Frequency of 2 from 1 to 6 = 1
Frequency of 8 from 4 to 9 = 2
This approach will be beneficial if we have a large number of queries of an arbitrary range asking the total frequency of particular element.
Time complexity: O(log N) for single query.
Auxiliary Space: O(N)
-------------------------------------------------------------------------
16) Find all pairs (a, b) in an array such that a % b = k	
Given an array with distinct elements, the task is to find the pairs in the array such that a % b = k, where k is a given integer.

Examples : 
Input  :  arr[] = {2, 3, 5, 4, 7}   
             k = 3
Output :  (7, 4), (3, 4), (3, 5), (3, 7)
7 % 4 = 3
3 % 4 = 3
3 % 5 = 3
3 % 7 = 3

Approach 1: Using nested loops:

bool printPairs(int arr[], int n, int k) 
{ 
	bool isPairFound = true; 

	// Consider each and every pair 
	for (int i = 0; i < n; i++) { 
		for (int j = 0; j < n; j++) { 
			// Print if their modulo equals to k 
			if (i != j && arr[i] % arr[j] == k) { 
				cout << "(" << arr[i] << ", "
					<< arr[j] << ")"
					<< " "; 
				isPairFound = true; 
			} 
		} 
	} 

	return isPairFound; 
} 

// Driver program 
int main() 
{ 
	int arr[] = { 2, 3, 5, 4, 7 }; 
	int n = sizeof(arr) / sizeof(arr[0]); 
	int k = 3; 

	if (printPairs(arr, n, k) == false) 
		cout << "No such pair exists"; 

	return 0; 
} 
Output
(3, 5) (3, 4) (3, 7) (7, 4) 
Time Complexity : O(n2)
Auxiliary Space: O(1)
//Need to find optimal solution.........
-----------------------------------------------------------------------------
17) Count the number of subarrays having a given XOR
Given an array of integers arr[] and a number m, count the number of subarrays having XOR of their elements as m.
Examples: 

Input : arr[] = {4, 2, 2, 6, 4}, m = 6
Output : 4
Explanation : The subarrays having XOR of 
              their elements as 6 are {4, 2}, 
              {4, 2, 2, 6, 4}, {2, 2, 6},
               and {6}

Input : arr[] = {5, 6, 7, 8, 9}, m = 5
Output : 2
Explanation : The subarrays having XOR of
              their elements as 5 are {5}
              and {5, 6, 7, 8, 9}
			  
	int subarraysWithXorK(vector<int> a, int k) {
    int n = a.size(); //size of the given array.
    int cnt = 0;

    // Step 1: Generating subarrays:
    for (int i = 0; i < n; i++) {
        int xorr = 0;
        for (int j = i; j < n; j++) {

            //step 2:calculate XOR of all
            // elements:
            xorr = xorr ^ a[j];

            // step 3:check XOR and count:
            if (xorr == k) cnt++;
        }
    }
    return cnt;
}

int main()
{
    vector<int> a = {4, 2, 2, 6, 4};
    int k = 6;
    int ans = subarraysWithXorK(a, k);
    cout << "The number of subarrays with XOR k is: "
         << ans << "\n";
    return 0;
}

Approach2: using Hashing	
--------->XR(till 3rd index)
4, 2, 2, 6, 4
x  ------>k

Assume XOR from 0th index till 3rd index is XR, 
XOR from 1st index to 3rd index is k(6)
assume XOR at 0th index is X 
then=> X^k = XR (till 3rd index), which means we need X which will be required.
Before dryRun:
XR=0, cnt=0, mpp[0]->1{when we get XOR equal to k without X, we will increment count}
Iteration 1, val=4:
i=0, XR=4, X=2, , cnt =0 (mpp[2]=0), mpp[4]->1

Iteration 2,val=2:
i=1, XR=6, X=0, , cnt =0+1 (mpp[0]=1), mpp[4]->1,mpp[6]->1  -->Here we don't need X value, since XR became 6, will just increment count.

Iteration 3,val=2:
i=2, XR=4, X=2, , cnt = 1 (mpp[2]=0), mpp[4]->2,mpp[6]->1  -->No count will be incremented

Iteration 4,val=6:
i=3, XR=2, X=4, , cnt = 1+2 (mpp[4]=2), mpp[2]->1,mpp[4]->2,mpp[6]->1  

Iteration 5,val=4:
i=4, XR=6, X=0, , cnt = 1+2+1 (mpp[4]=2), mpp[2]->1,mpp[4]->2,mpp[6]->1  

int subarraysWithXorK(vector<int> a, int k) {
    int n = a.size(); //size of the given array.
    int xr = 0;
    map<int, int> mpp; //declaring the map.
    mpp[xr]++; //setting the value of 0{0->1}
    int cnt = 0;

    for (int i = 0; i < n; i++) {
        // prefix XOR till index i:
        xr = xr ^ a[i];

        //By formula: x = xr^k:
        int x = xr ^ k; 

        // add the occurrence of xr^k
        // to the count:
        cnt += mpp[x];

        // Insert the prefix xor till index i
        // into the map:
        mpp[xr]++;
    }
    return cnt;
}

int main()
{
    vector<int> a = {4, 2, 2, 6, 4};
    int k = 6;
    int ans = subarraysWithXorK(a, k);
    cout << "The number of subarrays with XOR k is: "
         << ans << "\n";
    return 0;
}
Output: Number of subarrays having given XOR is 2
Time Complexity: O(n)
Auxiliary Space: O(n)
---------------------------------------------------------------------------
18) Maximum possible difference of two subsets of an array
Input : arr[] = {5, 8, -1, 4}
Output : Maximum Difference = 18
Explanation : 
Let Subset A = {5, 8, 4} & Subset B = {-1}
Sum of elements of subset A = 17, of subset B = -1
Difference of Sum of Both subsets = 17 - (-1) = 18

Input : arr[] = {5, 8, 5, 4}
Output : Maximum Difference = 12
Explanation : 
Let Subset A = {5, 8, 4} & Subset B = {5}
Sum of elements of subset A = 17, of subset B = 5
Difference of Sum of Both subsets = 17 - 5 = 12

Approach 1: 
int maxDiff(int arr[], int n) 
{ 
	int SubsetSum_1 = 0, SubsetSum_2 = 0; 
	for (int i = 0; i <= n - 1; i++) { 

		bool isSingleOccurrence = true; 
		for (int j = i + 1; j <= n - 1; j++) { 

			// if frequency of any element is two 
			// make both equal to zero 
			if (arr[i] == arr[j]) { 
				isSingleOccurrence = false; 
				arr[i] = arr[j] = 0; 
				break; 
			} 
		} 
		if (isSingleOccurrence) { 
			if (arr[i] > 0) 
				SubsetSum_1 += arr[i]; 
			else
				SubsetSum_2 += arr[i]; 
		} 
	} 
	return abs(SubsetSum_1 - SubsetSum_2); 
} 

// driver program 
int main() 
{ 
	int arr[] = { 4, 2, -3, 3, -2, -2, 8 }; 
	int n = sizeof(arr) / sizeof(arr[0]); 
	cout << "Maximum Difference = " << maxDiff(arr, n); 
	return 0; 
} 
Output
Maximum Difference = 20
Time Complexity O(n2)
Auxiliary Space: O(1)

Approach 2: 
int maxDiff(int arr[], int n) 
{ 
	unordered_map<int, int> hashPositive; 
	unordered_map<int, int> hashNegative; 

	int SubsetSum_1 = 0, SubsetSum_2 = 0; 

	// construct hash for positive elements 
	for (int i = 0; i <= n - 1; i++) 
		if (arr[i] > 0) 
			hashPositive[arr[i]]++; 

	// calculate subset sum for positive elements 
	for (int i = 0; i <= n - 1; i++) 
		if (arr[i] > 0 && hashPositive[arr[i]] == 1) 
			SubsetSum_1 += arr[i]; 

	// construct hash for negative elements 
	for (int i = 0; i <= n - 1; i++) 
		if (arr[i] < 0) 
			hashNegative[abs(arr[i])]++; 

	// calculate subset sum for negative elements 
	for (int i = 0; i <= n - 1; i++) 
		if (arr[i] < 0 && 
			hashNegative[abs(arr[i])] == 1) 
			SubsetSum_2 += arr[i]; 

    return abs(SubsetSum_1 - SubsetSum_2); 
} 

// driver program 
int main() 
{ 
	int arr[] = { 4, 2, -3, 3, -2, -2, 8 }; 
	int n = sizeof(arr) / sizeof(arr[0]); 
	cout << "Maximum Difference = " << maxDiff(arr, n); 
	return 0; 
} 
Time Complexity: O(n )
Auxiliary Space: O(n)
---------------------------------------------------------------------------
19)Find Itinerary from a given list of tickets
Given a list of tickets, find itinerary in order using the given list.

Example: 
Input:
"Chennai" -> "Banglore"
"Bombay" -> "Delhi"
"Goa"    -> "Chennai"
"Delhi"  -> "Goa"

Output: 
Bombay->Delhi, Delhi->Goa, Goa->Chennai, Chennai->Banglore,	

void printItinerary(map<string, string> dataSet) 
{ 
	// To store reverse of given map 
	map<string, string> reversemap; 
	map<string, string>::iterator it; 

	// To fill reverse map, iterate through the given map :
	
	for (it = dataSet.begin(); it!=dataSet.end(); it++) 
		reversemap[it->second] = it->first; 
	/*
	reversemap["Banglore"] = "Chennai"; 
	reversemap["Delhi"] = "Bombay"; 
	reversemap["Chennai"] = "Goa"; 
	reversemap["Goa"] = "Delhi";
	*/

	// Find the starting point of itinerary 
	string start; 

	for (it = dataSet.begin(); it!=dataSet.end(); it++) 
	{ 
		if (reversemap.find(it->first) == reversemap.end()) 
		{ 
			start = it->first; //This will be Bombay
			break; 
		} 
	} 

	// If we could not find a starting point, then something wrong with input 
	if (start.empty()) 
	{ 
		cout << "Invalid Input" << endl; 
		return; 
	} 

	// Once we have starting point, we simple need to go next, 
	//next of next using given hash map 
	it = dataSet.find(start); 
	while (it != dataSet.end()) 
	{ 
		cout << it->first << "->" << it->second << endl; 
		it = dataSet.find(it->second); 
	} 

} 

int main() 
{ 
	map<string, string> dataSet; 
	dataSet["Chennai"] = "Banglore"; 
	dataSet["Bombay"] = "Delhi"; 
	dataSet["Goa"] = "Chennai"; 
	dataSet["Delhi"] = "Goa"; 

	printItinerary(dataSet); 

	return 0; 
} 
Time Complexity: O(n).
Auxiliary Space: O(n)
----------------------------------------------------------------------------------------------
20) Relative Sort Array: Sort an array according to the order defined by another array
Given two arrays arr1[] and arr2[] of size m and n, the task is to sort arr1[] such that the relative order among the elements matches the order in arr2[]. 
For elements not present in arr2[], append them at the end in sorted order.

Example: 
Input: arr1[] = {2, 1, 2, 5, 7, 1, 9, 3, 6, 8, 8}
           arr2[] = {2, 1, 8, 3}
Output: arr1[] = {2, 2, 1, 1, 8, 8, 3, 5, 6, 7, 9}

Input: arr1[] = {4, 5, 1, 1, 3, 2}
           arr2[] = {3, 1}
Output: arr1[] = {3, 1, 1, 2, 4, 5}	

Approach:
1) Create map to store array data, Iterate through arr1 and store element with frequency.
2) Check arr2 if elements of arr2 is present in map where we have stored elements of arr1.
3) If element of arr2 is found then calcuate the count of it.
4) push_back that element(count times) to ans vector and decrease the count of element of arr2 in map.
5) Now we are left with remaining elements of arr1, will iterate in map for ramianing elements:
we can check while(it.second), push_back to ans and also decrement it.second.
vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        int n=arr1.size(), m=arr2.size();
        map<int,int> mp;
        for(int i=0; i<n; i++)
		{
			mp[arr1[i]]++;
		}
        vector<int> ans;
        for(int i=0; i<m; i++)
        {
			if(mp.find(arr2[i])!=mp.end())
            {
                int t=mp[arr2[i]];
                while(t--)
                {
                    ans.push_back(arr2[i]);
                    mp[arr2[i]]--;
                }
            }
        }
        for(auto it:mp)
        {
            while(it.second)
            {
                ans.push_back(it.first);
                it.second--;
            }
        }
        return ans;
    }
// Driver code
int main()
{
	vector<int> arr1 = { 2, 1, 2, 5, 7, 1, 9, 3, 6, 8, 8 };
	vector<int> arr2 = { 2, 1, 8, 3 };

	relativeSort(arr1, arr2);

	printArray(arr1);

	return 0;
}
Output: 2 2 1 1 8 8 3 5 6 7 9 
Time complexity: O(m log m + n), where m is the size of arr1 and n is the size of arr2.
Auxiliary Space: O(m)







		
		
		
