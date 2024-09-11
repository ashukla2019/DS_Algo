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
--------------------------------------------------------------------------
9) Remove duplicates from Sorted Array:
Given a sorted array arr[] of size N, the task is to remove the duplicate elements from the array.

Examples: 

Input: arr[] = {2, 2, 2, 2, 2}
Output: arr[] = {2}
Explanation: All the elements are 2, So only keep one instance of 2.

Input: arr[] = {1, 2, 2, 3, 4, 4, 4, 5, 5}
Output: arr[] = {1, 2, 3, 4, 5}

Approach 1: Using set
int removeDuplicates(vector<int>& arr) {
  
	int n = arr.size();
	if (n <= 1)
		return n;

	// Insert all set elements in an array
	set<int> s(arr.begin(), arr.end());
  
	int index = 0;
	for (auto& value : s) {
		arr[index++] = value;
	}

	return s.size();
}

int main() {
	vector<int> arr = {1, 2, 2, 3, 4, 4, 4, 5, 5};
	int n = removeDuplicates(arr);
	for (int i = 0; i < n; i++) 
		cout << arr[i] << " ";
	return 0;
}
Time Complexity: O(n) 
Auxiliary Space: O(n)

Approach 2: This problem can be solved efficiently just by maintaining a separate index for 
the same array as maintained for different array in the naive method and replacing that
element with the unique element.

int removeDuplicates(std::vector<int>& arr) {
  
	if (arr.empty()) return 0;

	int j = 0; // index of distict elements
	for (int i = 0; i < arr.size() - 1; ++i) 
	  
		// We always put the last occurrence
		// of a repeating element.
		if (arr[i] != arr[i + 1]) 
			arr[j++] = arr[i];
  
	// Putting last occurrence of the last
	// element
	arr[j++] = arr.back();

	return j;
}

int main() {
	std::vector<int> arr = {1, 2, 2, 3, 4, 4, 4, 5, 5};
	int n = removeDuplicates(arr);
	for (int i = 0; i < n; ++i) 
		std::cout << arr[i] << " ";
	return 0;
}
Time Complexity: O(n) 
Auxiliary Space: O(1)
-------------------------------------------------------------------
10) Find the only repetitive element between 1 to N-1
Given an array of size N filled with numbers from 1 to N-1 in random order. The array has only one repetitive element. The task is to find the repetitive element.

Examples:
Input: a[] = {1, 3, 2, 3, 4}
Output: 3
Explanation: The number 3 is the only repeating element.

Input: a[] = {1, 5, 1, 2, 3, 4}
Output: 1	

Approach 1: Use two nested loops. The outer loop traverses through all elements and the 
inner loop check if the element picked by the outer loop appears anywhere else.

int findRepeating(int arr[], int N)
{
	for (int i = 0; i < N; i++) {
		for (int j = i + 1; j < N; j++) {
			if (arr[i] == arr[j])
				return arr[i];
		}
	}
}

// Driver's code
int main()
{
	int arr[] = { 9, 8, 2, 6, 1, 8, 5, 3, 4, 7 };
	int N = sizeof(arr) / sizeof(arr[0]);

	// Function call
	cout << findRepeating(arr, N);
	return 0;
}
Time Complexity: O(N2)
Auxiliary Space: O(1)

Approach 2: Using sorting
int findRepeating(int arr[], int N)
{
	sort(arr, arr + N); // sort array

	for (int i = 0; i < N; i++) {

		// compare array element with its index
		if (arr[i] != i + 1) {
			return arr[i];
		}
	}
	return -1;
}

// driver's code
int main()
{
	int arr[] = { 9, 8, 2, 6, 1, 8, 5, 3, 4, 7 };
	int N = sizeof(arr) / sizeof(arr[0]);

	// Function call
	cout << findRepeating(arr, N);
	return 0;
}
Time complexity: O(N * log N) 
Auxiliary Space: O(1)

Approach 3:
int findRepeating(int arr[], int N)
{
	unordered_set<int> s;
	for (int i = 0; i < N; i++) {
		if (s.find(arr[i]) != s.end())
			return arr[i];
		s.insert(arr[i]);
	}

	// If input is correct, we should
	// never reach here
	return -1;
}

// Driver's code
int main()
{
	int arr[] = { 9, 8, 2, 6, 1, 8, 5, 3, 4, 7 };
	int N = sizeof(arr) / sizeof(arr[0]);

	// Function call
	cout << findRepeating(arr, N);
	return 0;
}
Time Complexity: O(N)
Auxiliary Space: O(N)
------------------------------------------------------------------------------
11) Minimum insertions to form a palindrome with permutations allowed
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
		count[str[i] - 'a']++; 

	// To count characters with odd 
	// occurrence 
	for (int i = 0; i < 26; i++) 
		if (count[i] % 2 == 1) 
			res++; 

	// As one character can be odd return 
	// res - 1 but if string is already 
	// palindrome return 0 
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
12) Count all distinct pairs with difference equal to k:
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
#define MAX 100000
int countPairsWithDiffK(int arr[], int n, int k)
{
	int count = 0; // Initialize count

	// Initialize empty hashmap.
	bool hashmap[MAX] = {false};

	// Insert array elements to hashmap
	for (int i = 0; i < n; i++)
		hashmap[arr[i]] = true;

	for (int i = 0; i < n; i++)
	{
		int x = arr[i];
		if (x - k >= 0 && hashmap[x - k])
			count++;
		if (x + k < MAX && hashmap[x + k])
			count++;
		hashmap[x] = false;
	}
	return count;
}
Time Complexity: O(n)
Auxiliary Space: O(n)

Approach 3: Using sorting
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
13)	Longest Consecutive Subsequence:
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


int findLongestConseqSubseq(int arr[], int n)
{
	unordered_set<int> S;
	int ans = 0;

	// Hash all the array elements
	for (int i = 0; i < n; i++)
		S.insert(arr[i]);

	// check each possible sequence from
	// the start then update optimal length
	for (int i = 0; i < n; i++) {
		// if current element is the starting
		// element of a sequence
		if (S.find(arr[i] - 1) == S.end()) {
			// Then check for next elements
			// in the sequence
			int j = arr[i];
			while (S.find(j) != S.end())
				j++;

			// update  optimal length if
			// this length is more
			ans = max(ans, j - arr[i]);
		}
	}
	return ans;
}

// Driver code
int main()
{
	int arr[] = { 1, 9, 3, 10, 4, 20, 2 };
	int n = sizeof arr / sizeof arr[0];
	cout << "Length of the Longest contiguous subsequence "
			"is "
		 << findLongestConseqSubseq(arr, n);
	return 0;
}
Time complexity: O(N), Only one traversal is needed and the time complexity is O(N) 
under the assumption that hash insert and search takes O(1) time.
Auxiliary space: O(N),
----------------------------------------------------------------------
15) Print all pairs with given sum
Given an array of integers, and a number ‘sum’, print all unique pairs in the array whose sum is 
equal to ‘sum’.

Examples :
Input : arr[] = {1, 5, 7, -1, 5}, sum = 6
Output : (1, 5), (7, -1)

Input : arr[] = {2, 5, 17, -1} sum = 7
Output : (2, 5)

Approach 1: A simple solution is to traverse each element and check if there’s another 
number in the array which can be added to it to give sum, using set to handle duplicate pairs.

int printPairs(int arr[], int n, int sum)
{
	int count = 0; // Initialize result
	  set<pair<int,int>> dup;
	// Consider all possible pairs and check
	// their sums
	for (int i = 0; i < n; i++)
		for (int j = i + 1; j < n; j++)
			if (arr[i] + arr[j] == sum)
			{
				  if(dup.find({arr[i],arr[j]})==dup.end() && dup.find({arr[j],arr[i]})==dup.end())
				{
				  cout << "(" << arr[i] << ", " << arr[j]
					 << ")" << endl;
				  dup.insert({arr[i],arr[j]});
				}
			  
			}
			  
}

// Driver function to test the above function
int main()
{
	int arr[] = { 1, 5, 7, -1, 5 };
	int n = sizeof(arr) / sizeof(arr[0]);
	int sum = 6;
	printPairs(arr, n, sum);
	return 0;
}
Time Complexity: O(N2 logN) where N is the number of elements.
Auxiliary Space: O(N)

Approach 2: Using two pointers:
void pairedElements(int arr[], int sum, int n)
{
	// Initialize pointers
	int low = 0;
	int high = n - 1;

	// Map to track unique pairs
	unordered_map<int, int> m;

	// Iterate with two pointers
	while (low < high) {
		// Check if sum equals the target
		if (arr[low] + arr[high] == sum) {
			// Print pair if elements are not already in the map
			if(m.find(arr[low]) == m.end() || m.find(arr[high])==m.end())
			{
			  cout << "The pair is : (" << arr[low] << ", "
				 << arr[high] << ")" << endl;
			  m[arr[low]]++;
			  m[arr[high]]++;
			}
			low++;
			high--;
		}
		// Adjust pointers based on sum comparison
		else if (arr[low] + arr[high] > sum) {
			high--;
		}
		else {
			low++;
		}
	}
}

// Driver code
int main()
{
	int arr[] = { 2, 3, 4, -2, 6, 8, 3, 3 };
	int n = sizeof(arr) / sizeof(arr[0]);

	// Sort the array
	sort(arr, arr + n);

	// Call the pairedElements function
	pairedElements(arr, 6, n);
}
Time Complexity: O(N*logN) where N is the number of elements
Auxiliary Space: O(N)

Approach 3: using hashing 
void printPairs(int arr[], int n, int sum) {
	// Store counts of all elements in map m
	unordered_map<int, int> m;

	// Traverse through all elements
	for (int i = 0; i < n; i++) {
		// Search if a pair can be formed with arr[i].
		int rem = sum - arr[i];
		if (rem == arr[i]) {
			// Check if the complement is in the map and occurs only once
			if (m.find(rem) != m.end() && m[rem] == 1) {
				cout << "(" << rem << ", " << arr[i] << ")" << endl;
			}
		} else if (m.find(rem) != m.end() && m.find(arr[i]) == m.end()) {
			// Check if the complement is in the map and the current element is not in the map
			cout << "(" << rem << ", " << arr[i] << ")" << endl;
		}
		m[arr[i]]++; // Update the map with the current element's count
	}
}

// Driver function to test the above function
int main() {
	int arr[] = {1, 5, 7, -1, 5, 3, 3, 3};
	int n = sizeof(arr) / sizeof(arr[0]);
	int sum = 6;
	printPairs(arr, n, sum);
	return 0;
}
---------------------------------------------------------------------------------
16) Find the first repeating element in an array of integers	
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
void firstRepeating(int arr[], int n) {
	
		int max = -1;
		//Finding max
		for(int i = 0 ; i<n;i++){
		if(max<arr[i]){
			max = arr[i];
		}
		}
		
		//Creating array
		int hash[max+1]={0};
		
		//Mapping/counting 
		for(int i =0;i<n; i++){
			hash[arr[i]]++;
		}
		//Variable for storing ans
		int repeating=INT_MIN;
		//Checking repeatibng element
		for(int i =0;i<n; i++){
			if(hash[arr[i]]>1){
				repeating=arr[i];
				break;
			}
		}
		if(repeating==INT_MIN){
		cout << "There are no repeating elements";
		}
		else{
		cout << "The first repeating element is : "
			<<repeating;
		}
	}

// Driver method to test above method
int main()
{
	int arr[] = { 10, 5, 3, 4, 3, 5, 6 };

	int N = sizeof(arr) / sizeof(arr[0]);
	firstRepeating(arr, N);
}
Time Complexity: O(N).
Auxiliary Space: O(N)
--------------------------------------------------------------------------------
17) Majority Element:
Find the majority element in the array. A majority element in an array A[] of size n is an element that appears more than n/2 times (and hence there is at most one such element). 

Examples : 
Input : arr[] = {3, 9, 2, 9, 2, 9, 9}
Output : 9
Explanation: n = 7. Note that 9 appear more 4 times which is more than 7/2 times 

Input : arr[] = {3}
Output : 3
Explanation: Appears more than n/2 times

Input : A[] = {3, 3, 4, 2, 4, 4, 2, 4}
Output : No Majority Element
Explanation: There is no element whose frequency is greater than the half of the size of the array size.	

Approach 1: 
The basic solution is to have two loops and keep track of the maximum count for all different
elements. If the maximum count becomes greater than n/2 then break the loops and return the 
element having the maximum count. If the maximum count doesn’t become more than n/2 then 
the majority element doesn’t exist.

void findMajority(const vector<int>& arr) {
	int n = arr.size();
	int maxCount = 0;
	int index = -1; // sentinels
	for (int i = 0; i < n; i++) {
		int count = 0;
		for (int j = 0; j < n; j++) {
			if (arr[i] == arr[j])
				count++;
		}

		// update maxCount if count of
		// current element is greater
		if (count > maxCount) {
			maxCount = count;
			index = i;
		}
	}

	// if maxCount is greater than n/2, 
	// return the corresponding element
	if (maxCount > n / 2)
		cout << arr[index] << endl;
	else
		cout << "No Majority Element" << endl;
}

// Driver code
int main() {
	vector<int> arr = {1, 1, 2, 1, 3, 5, 1};

	// Function calling
	findMajority(arr);

	return 0;
}
Time Complexity: O(n*n), A nested loop is needed where both the loops traverse the array from
start to end.
Auxiliary Space: O(1)

Approach 2: Using Moore’s Voting Algorithm
Loop through each element and maintains a count of the majority element, and a majority index, maj_index
If the next element is the same then increment the count if the next element is not the same then decrement the count.
if the count reaches 0 then change the maj_index to the current element and set the count again to 1.
Now again traverse through the array and find the count of the majority element found.
If the count is greater than half the size of the array, print the element
Else print that there is no majority element

int findCandidate(const vector<int>& arr) {
	int maj_index = 0, count = 1;
	int size = arr.size();
	for (int i = 1; i < size; i++) {
		if (arr[maj_index] == arr[i])
			count++;
		else
			count--;
		if (count == 0) {
			maj_index = i;
			count = 1;
		}
	}
	return arr[maj_index];
}

/* Function to check if the candidate occurs 
   more than n/2 times */
bool isMajority(const vector<int>& arr, int cand) {
	int count = 0;
	int size = arr.size();
	for (int i = 0; i < size; i++) {
		if (arr[i] == cand)
			count++;
	}
	return (count > size / 2);
}

/* Function to print Majority Element */
void printMajority(const vector<int>& arr) {
  
	/* Find the candidate for Majority */
	int cand = findCandidate(arr);

	/* Print the candidate if it is Majority */
	if (isMajority(arr, cand))
		cout << " " << cand << " ";
	else
		cout << "No Majority Element";
}

/* Driver code */
int main() {
	vector<int> arr = { 1, 3, 3, 1, 2 };

	// Function calling
	printMajority(arr);

	return 0;
}
Time Complexity: O(n), As two traversal of the array, is needed, so the time complexity is linear.
Auxiliary Space: O(1)

Approach 3: using Hashing 
void findMajority(const vector<int>& arr) {
  
	// Find frequencies
	unordered_map<int, int> m;
	for (int num : arr)
		m[num]++; 

	// Find max Frequency item
	int maxFreq = 0;
	int res = -1;
	for (auto i : m) {
		if (i.second > maxFreq) {
		   maxFreq = i.second;
		   res = i.first;
		}
	}  

	// Check for majority
	if (maxFreq > arr.size() / 2) 
		cout << "Majority found: " << res << endl; 
	else
		cout << "No Majority element" << endl; 
}

int main() {
	vector<int> arr = {2, 1, 2, 3, 3, 3, 3}; 

	findMajority(arr);

	return 0;
}

Approach 4: Using Sorting
int majorityElement(vector<int>& arr) {
	int n = arr.size();
	if (n == 1) return arr[0];    
	int cnt = 1;
  
	// sort the array, O(n log n)
	sort(arr.begin(), arr.end());
	for (int i = 1; i < n; i++) {
		if (arr[i - 1] == arr[i]) {
			cnt++;
		} else {
			if (cnt > n / 2) {
				return arr[i - 1];
			}
			cnt = 1;
		}
	}
	// Check the last element
	if (cnt > n / 2) {
		return arr[n - 1];
	}
	// if no majority element, return -1
	return -1;
}

// Driver code
int main() {
	vector<int> arr = {1, 1, 2, 1, 3, 5, 1};
	
	// Function calling 
	cout << majorityElement(arr);

	return 0;
}

Time Complexity: O(n log n), Sorting requires O(n log n) time complexity.
Auxiliary Space: O(1)
------------------------------------------------------------------------------
18) Subarray with Given Sum
Given a 1-based indexing array arr[] of integers and an integer sum. You mainly need to return the left and right indexes(1-based indexing) of that subarray. In case of multiple subarrays, return the subarray indexes which come first on moving from left to right. If no such subarray exists return an array consisting of element -1.

Examples: 
Input: arr[] = { 15, 2, 4, 8, 9, 5, 10, 23}, sum = 23
Output: 2 5
Explanation: Sum of elements between indices 2 and 5 is 2 + 4 + 8 + 9 = 23

Input: arr[] = {1, 4, 0, 0, 3, 10, 5}, sum = 7
Output: 2 5
Explanation: Sum of elements between indices 1 and 4 is 4 + 0 + 0 + 3 = 7

Input: arr[] = {1, 4}, sum = 0
Output: -1
Explanation: There is no subarray with 0 sum	

Approach 1: 
The very basic idea is to use a nested loop where the outer loop picks a starting element, 
and the inner loop calculates the cumulative sum of elements starting from this element.

vector<int> subarraySum(vector<int> arr, int sum)
{
	// To store the result
	vector<int> res;
	int n = arr.size();

	// Pick a starting point for a 
	// subarray
	for (int s = 0; s < n; s++)
	{
		int curr = 0;
	  
		// Consider all ending points
		// for the picked starting point 
		for (int e = s; e < n; e++)
		{
			curr += arr[e];
			if (curr == sum)
			{
				res.push_back(s + 1);
				res.push_back(e + 1);
				return res;
			}
		}
	}
	return {-1}; // If no subarray is found
}

// Driver Code
int main()
{
	vector<int> arr = {15, 2, 4, 8, 9, 5, 10, 23};
	int sum = 23;
	vector<int> result = subarraySum(arr, sum);
	for (auto i : result)
		cout << i << " ";
	return 0;
}
Time Complexity: O(N2), Trying all subarrays from every index, used nested loop for the same
Auxiliary Space: O(1)

Approach 2:  Using Sliding Window
vector<int> subarraySum(vector<int>& arr, int sum) {
  
	int s = 0, e = 0;  // Initialize window
  
	vector<int> res;

	int curr = 0;
	for (int i = 0; i < arr.size(); i++) {
		curr += rr[i];

		// If current sum becomes more or equal,
		// set end and try adjusting start
		if (curr >= sum) {
			e = i;

			// While current sum is more
			// remove, starting elements of
			// current window
			while (curr > sum && s < e) {
				curr -= arr[s];
				++s;
			}

			// If we found a subraay
			if (curr == sum) {
				res.push_back(s + 1);
				res.push_back(e + 1);
				return res;
			}
		}
	}

	return {-1}; // Never found a subarray
}

int main() {
	vector<int> arr = {15, 2, 4, 8, 9, 5, 10, 23};
	int sum = 23;
	vector<int> res = subarraySum(arr, sum);
	for (auto i : res)
		cout << i << " ";
	return 0;
}
Time Complexity: O(N), where N is the length of input array
Auxiliary Space: O(1)
-----------------------------------------------------------------------
19) Given a sequence of words, print all anagrams together
Input : {“cat”, “dog”, “tac”, “god”, “act”}
Output : {“cat”, “tac”, “act”, ‘”dog”, “god”}	
	Approach: HashMap with O(NM) Solution
void solver(vector<string> my_list)
{
	
	// Inner hashmap counts frequency
	// of characters in a string.
	// Outer hashmap for if same
	// frequency characters are present in
	// in a string then it will add it to
	// the vector.
	map<map<char, int>, vector<string>> my_map;
	
	// Loop over all words
	for(string str : my_list)
	{
		
		// Counting the frequency of the
		// characters present in a string
		map<char, int> temp_map;
		vector<string> temp_my_list;
		for(int i = 0; i < str.length(); ++i) 
		{
			++temp_map[str[i]];
		}
		
		// If the same frequency of characters
		// are already present then add that
		// string into that arraylist otherwise
		// created a new arraylist and add that
		// string
		auto it = my_map.find(temp_map);
		if (it != my_map.end())
		{
			it->second.push_back(str);
		}
		else
		{
			temp_my_list.push_back(str);
			my_map.insert({ temp_map, temp_my_list });
		}
	}
	
	// Stores the result in a vector
	vector<vector<string>> result;

	for(auto it = my_map.begin();
			 it != my_map.end(); ++it)
	{
		result.push_back(it->second);
	}

	for(int i = 0; i < result.size(); ++i) 
	{
		  cout << "[";
		for(int j = 0; j < result[i].size()-1; ++j) 
		{
			cout << result[i][j] << ", ";
		}
			cout<< result[i][result[i].size()-1];
		  cout << "]";
	}
}

// Driver code
int main()
{
	vector<string> my_list = { "cat", "dog", "ogd",
							   "god", "atc" };
	solver(my_list);
	return 0;
}
---------------------------------------------------------------------------------
20) Longest sub-array having sum k
Given an array arr[] of size n containing integers. The problem is to find the length of the longest sub-array having sum equal to the given value k.

Examples: 
Input: arr[] = { 10, 5, 2, 7, 1, 9 }, k = 15
Output: 4
Explanation: The sub-array is {5, 2, 7, 1}.

Input: arr[] = {-5, 8, -14, 2, 4, 12}, k = -5
Output: 5	

Approach 1: Consider the sum of all the sub-arrays and return the length of the longest 
sub-array having the sum ‘k’. Time Complexity is of O(n^2).

int lenOfLongSubarr(int arr[], int N, int K)
{

	// Variable to store the answer
	int maxlength = 0;

	for (int i = 0; i < N; i++) {

		// Variable to store sum of subarrays
		int Sum = 0;
	  
		// if maximum possible subarray length from i is equal to maxLength
		if( maxlength == N - i )
		  break;
	  
		for (int j = i; j < N; j++) {

			// Storing sum of subarrays
			Sum += arr[j];

			// if Sum equals K
			if (Sum == K) {

				// Update maxLength
				maxlength = max(maxlength, j - i + 1);
			}
		}
	}

	// Return the maximum length
	return maxlength;
}

// Driver Code
int main()
{

	// Given input
	int arr[] = { 10, 5, 2, 7, 1, 9 };
	int n = sizeof(arr) / sizeof(arr[0]);
	int k = 15;

	// Function Call
	cout << "Length = " << lenOfLongSubarr(arr, n, k);

	return 0;
}
Time Complexity: O(N2), for calculating the sum of all subarrays.
Auxiliary Space: O(1)

Approach 2: Hashmap and Prefix Sum Technique
	
int lenOfLongSubarr(vector<int>& A, int N, int K)
{
	unordered_map<int, int> sum_index_map;
	int maxLen = 0;
	int prefix_sum = 0;

	for (int i = 0; i < N; ++i) {
		prefix_sum += A[i];

		if (prefix_sum == K) {
			maxLen = i + 1;
		}

		else if (sum_index_map.find(prefix_sum - K) != sum_index_map.end()) {
			maxLen = max(maxLen, i - sum_index_map[prefix_sum - K]);
		}

		if (sum_index_map.find(prefix_sum) == sum_index_map.end()) {
			sum_index_map[prefix_sum] = i;
		}
	}

	return maxLen;
}

int main()
{
	vector<int> arr = { 10, 5, 2, 7, 1, 9 };
	int n = arr.size();
	int k = 15;
	cout << "Length = " << lenOfLongSubarr(arr, n, k)
		 << endl;
	return 0;
}
Time Complexity: O(N), where N is the length of the given array.
Auxiliary Space: O(N) We are using Hash Table for storing prefix sums
--------------------------------------------------------------------------------
21)Largest subarray with 0 sum: Given an array containing both positive and negative integers,
we have to find the length of the longest subarray with the sum of all elements equal to zero.
Example 1:
Input Format
: N = 6, array[] = {9, -3, 3, -1, 6, -5}
Result
: 5
Explanation
: The following subarrays sum to zero:
{-3, 3} , {-1, 6, -5}, {-3, 3, -1, 6, -5}
Since we require the length of the longest subarray, our answer is 5!

Example 2:
Input Format:
 N = 8, array[] = {6, -2, 2, -8, 1, 7, 4, -10}
Result
: 8
Subarrays with sum 0 : {-2, 2}, {-8, 1, 7}, {-2, 2, -8, 1, 7}, {6, -2, 2, -8, 1, 7, 4, -10}
Length of longest subarray = 8

Example 3:
Input Format:
 N = 3, array[] = {1, 0, -5}
Result
: 1
Subarray : {0}
Length of longest subarray = 1

Example 4:
Input Format:
 N = 5, array[] = {1, 3, -5, 6, -2}
Result
: 0
Subarray: There is no subarray that sums to zero
int maxLen(int A[], int n)
{
    // Your code here
    unordered_map<int,int> mpp; 
    int maxi = 0;
    int sum = 0; 
    for(int i = 0;i<n;i++) {
        sum += A[i]; 
        if(sum == 0) {
            maxi = i + 1; 
        }
        else {
            if(mpp.find(sum) != mpp.end()) {
                maxi = max(maxi, i - mpp[sum]); 
            }
            else {
                mpp[sum] = i;
            }
        }   
    }

    return maxi; 
	Time Complexity: O(N), as we are traversing the array only once
	Space Complexity: O(N), in the worst case we would insert all array elements prefix sum into our hashmap
-------------------------------------------------------------------------------------
22) Largest subarray with equal number of 0s and 1s:
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

int findSubArray(int arr[], int n)
{
	int sum = 0;
	int maxsize = -1, startindex;

	// Pick a starting point as i
	for (int i = 0; i < n - 1; i++) {
		sum = (arr[i] == 0) ? -1 : 1;

		// Consider all subarrays starting from i
		for (int j = i + 1; j < n; j++) {
			(arr[j] == 0) ? (sum += -1) : (sum += 1);

			// If this is a 0 sum subarray, then
			// compare it with maximum size subarray
			// calculated so far
			if (sum == 0 && maxsize < j - i + 1) {
				maxsize = j - i + 1;
				startindex = i;
			}
		}
	}
	if (maxsize == -1)
		cout << "No such subarray";
	else
		cout << startindex << " to "
			 << startindex + maxsize - 1;

	return maxsize;
}

/* Driver code*/
int main()
{
	int arr[] = { 1, 0, 0, 1, 0, 1, 1 };
	int size = sizeof(arr) / sizeof(arr[0]);

	findSubArray(arr, size);
	return 0;
}
Time Complexity: O(n^2). 
As all the possible sub-arrays are generated using a pair of nested loops.
Auxiliary Space: O(1). 
As no extra data structure is used which takes auxiliary space.

Approach 2: Using Hashmap and Prefix Sum Technique

int maxLen(int arr[], int n)
{
	// Creates an empty hashMap hM

	unordered_map<int, int> hM;

	int sum = 0; // Initialize sum of elements
	int max_len = 0; // Initialize result
	int ending_index = -1;

	for (int i = 0; i < n; i++)
		arr[i] = (arr[i] == 0) ? -1 : 1;

	// Traverse through the given array

	for (int i = 0; i < n; i++) {
		// Add current element to sum

		sum += arr[i];

		// To handle sum=0 at last index

		if (sum == 0) {
			max_len = i + 1;
			ending_index = i;
		}

		// If this sum is seen before, then update max_len
		// if required

		if (hM.find(sum) != hM.end()) {
			if (max_len < i - hM[sum]) {
				max_len = i - hM[sum];
				ending_index = i;
			}
		}
		else // Else put this sum in hash table
			hM[sum] = i;
	}

	for (int i = 0; i < n; i++)
		arr[i] = (arr[i] == -1) ? 0 : 1;

	printf("%d to %d\n",
		   ending_index - max_len + 1, ending_index);

	return max_len;
}

// Driver method

int main()
{
	int arr[] = { 1, 0, 0, 1, 0, 1, 1 };
	int n = sizeof(arr) / sizeof(arr[0]);

	maxLen(arr, n);
	return 0;
}
Time Complexity: O(n). 
Auxiliary Space: O(n). 
-----------------------------------------------------------------------
23) Print all subarrays with 0 sum
Given an array arr[] of size n, the task is to print all subarrays in the array which has sum 0.

Examples: 
Input: arr = [6, 3, -1, -3, 4, -2, 2, 4, 6, -12, -7]
Output:

Subarray found from Index 2 to 4
Subarray found from Index 2 to 6
Subarray found from Index 5 to 6
Subarray found from Index 6 to 9
Subarray found from Index 0 to 10
Input: arr = [1, 2, -3, 3, -1, -1]
Output:

Subarray found from Index 0 to 2
Subarray found from Index 2 to 3
Subarray found from Index 3 to 5

Approach 1: 
vector<pair<int, int> > findSubArrays(int arr[], int n)
{

	// Array to store all the start and end
	// indices of subarrays with 0 sum
	vector<pair<int, int> > output;
	for (int i = 0; i < n; i++) {
		int prefix = 0;
		for (int j = i; j < n; j++) {
			prefix += arr[j];
			if (prefix == 0)
				output.push_back({ i, j });
		}
	}

	return output;
}

// Function to print all subarrays with 0 sum
void print(vector<pair<int, int> > output)
{
	for (auto it = output.begin(); it != output.end(); it++)
		cout << "Subarray found from Index " << it->first
			 << " to " << it->second << endl;
}

// Driver code
int main()
{

	// Given array
	int arr[] = { 6, 3, -1, -3, 4, -2, 2, 4, 6, -12, -7 };
	int n = sizeof(arr) / sizeof(arr[0]);

	// Function Call
	vector<pair<int, int> > output = findSubArrays(arr, n);

	// if we didn’t find any subarray with 0 sum,
	// then subarray doesn’t exists
	if (output.size() == 0) {
		cout << "No subarray exists";
	}
	else {
		print(output);
	}
	return 0;
}
O/P:
Subarray found from Index 0 to 10
Subarray found from Index 2 to 4
Subarray found from Index 2 to 6
Subarray found from Index 5 to 6
Subarray found from Index 6 to 9
Time Complexity: O(N2) since we are using 2 loops.
Auxiliary Space: O(1), as constant extra space is required.

Approach 2: using hashing
vector<pair<int, int> > findSubArrays(int arr[], int n)
{
	// create an empty map
	unordered_map<int, vector<int> > map;

	// create an empty vector of pairs to store
	// subarray starting and ending index
	vector<pair<int, int> > out;

	// Maintains sum of elements so far
	int sum = 0;

	for (int i = 0; i < n; i++) {
		// add current element to sum
		sum += arr[i];

		// if sum is 0, we found a subarray starting
		// from index 0 and ending at index i
		if (sum == 0)
			out.push_back(make_pair(0, i));

		// If sum already exists in the map there exists
		// at-least one subarray ending at index i with
		// 0 sum
		if (map.find(sum) != map.end()) {
			// map[sum] stores starting index of all
			// subarrays
			vector<int> vc = map[sum];
			for (auto it = vc.begin(); it != vc.end(); it++)
				out.push_back(make_pair(*it + 1, i));
		}

		// Important - no else
		map[sum].push_back(i);
	}

	// return output vector
	return out;
}

// Utility function to print all subarrays with sum 0
void print(vector<pair<int, int> > out)
{
	for (auto it = out.begin(); it != out.end(); it++)
		cout << "Subarray found from Index " << it->first
			 << " to " << it->second << endl;
}

// Driver code
int main()
{
	int arr[] = { 6, 3, -1, -3, 4, -2, 2, 4, 6, -12, -7 };
	int n = sizeof(arr) / sizeof(arr[0]);

	vector<pair<int, int> > out = findSubArrays(arr, n);

	// if we didn’t find any subarray with 0 sum,
	// then subarray doesn’t exists
	if (out.size() == 0)
		cout << "No subarray exists";
	else
		print(out);

	return 0;
}
Time Complexity: O(n), where n is the number of elements in the array.
Auxiliary Space: O(n)
----------------------------------------------------------------------------
24) Sort an array according to the order defined by another array
Given two arrays arr1[] and arr2[] of size m and n, the task is to sort arr1[] such that the relative order among the elements matches the order in arr2[]. For elements not present in arr2[], append them at the end in sorted order.

Example: 
Input: arr1[] = {2, 1, 2, 5, 7, 1, 9, 3, 6, 8, 8}
           arr2[] = {2, 1, 8, 3}
Output: arr1[] = {2, 2, 1, 1, 8, 8, 3, 5, 6, 7, 9}

Input: arr1[] = {4, 5, 1, 1, 3, 2}
           arr2[] = {3, 1}
Output: arr1[] = {3, 1, 1, 2, 4, 5}	

Approach:
void relativeSort(vector<int>& arr1, vector<int>& arr2)
{
	int m = arr1.size(), n = arr2.size();
	unordered_map<int, int> freq;

	// Count frequency of each element in A1
	for (int i = 0; i < m; i++) {
		freq[arr1[i]]++;
	}

	int index = 0;

	// Place elements of A2 in A1 based on frequency
	for (int i = 0; i < n; i++) {
		while (freq[arr2[i]]) {
			arr1[index++] = arr2[i];
			freq[arr2[i]]--;
		}
		freq.erase(arr2[i]);
	}

	// Collect remaining elements and sort them
	vector<int> remaining;
	for (auto& pair : freq) {
		while (pair.second--) {
			remaining.push_back(pair.first);
		}
	}
	sort(remaining.begin(), remaining.end());

	// Append remaining elements to A1
	for (int i : remaining) {
		arr1[index++] = i;
	}
}

void printArray(vector<int> & arr)
{
	for (int i = 0; i < arr.size(); i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
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
----------------------------------------------------------------------
25) Range Queries for Frequencies of array elements
Given an array of n non-negative integers. The task is to find frequency of a particular element in the arbitrary range of array[]. The range is given as positions (not 0 based indexes) in array. There can be multiple queries of given type.

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
---------------------------------------------------------------------------
26) Count subarrays having total distinct elements same as original array
Given an array of n integers. Count the total number of sub-arrays having total distinct elements, the same as that of the total distinct elements of the original array. 

Examples:  

Input  : arr[] = {2, 1, 3, 2, 3}
Output : 5
Total distinct elements in array is 3
Total sub-arrays that satisfy the condition 
are:  Subarray from index 0 to 2
      Subarray from index 0 to 3
      Subarray from index 0 to 4
      Subarray from index 1 to 3
      Subarray from index 1 to 4

Input  : arr[] = {2, 4, 5, 2, 1}
Output : 2

Input  : arr[] = {2, 4, 4, 2, 4}
Output : 9 

Approach 1: 
int countDistictSubarray(int arr[], int n)
{
	unordered_set<int> unst1;
	for (int i = 0; i < n; i++)
		unst1.insert(arr[i]);

	int totalDist = unst1.size();
	int count = 0;

	for (int i = 0; i < n; i++) {
		unordered_set<int> unst;
		for (int j = i; j < n; j++) {
			unst.insert(arr[j]);
			if (unst.size() == totalDist)
				count++;
		}
	}

	return count;
}

// Driver code
int main()
{
	int arr[] = { 2, 1, 3, 2, 3 };
	int n = sizeof(arr) / sizeof(arr[0]);

	cout << countDistictSubarray(arr, n) << endl;
	return 0;
}
Time Complexity: O(n*n)
Auxiliary Space: O(n)

Approach 2: Sliding window:
int countDistictSubarray(int arr[], int n)
{
	// Count distinct elements in whole array
	unordered_map<int, int> vis;
	for (int i = 0; i < n; ++i)
		vis[arr[i]] = 1;
	int k = vis.size();

	// Reset the container by removing all elements
	vis.clear();

	// Use sliding window concept to find
	// count of subarrays having k distinct
	// elements.
	int ans = 0, right = 0, window = 0;
	for (int left = 0; left < n; ++left)
	{
		while (right < n && window < k)
		{
			++vis[ arr[right] ];

			if (vis[ arr[right] ] == 1)
				++window;

			++right;
		}

		// If window size equals to array distinct 
		// element size, then update answer
		if (window == k)
			ans += (n - right + 1);

		// Decrease the frequency of previous element
		// for next sliding window
		--vis[ arr[left] ];

		// If frequency is zero then decrease the
		// window size
		if (vis[ arr[left] ] == 0)
				--window;
	}
	return ans;
}

// Driver code
int main()
{
	int arr[] = {2, 1, 3, 2, 3};
	int n = sizeof(arr) / sizeof(arr[0]);

	cout << countDistictSubarray(arr, n) <<"n";
	return 0;
}
Time complexity: O(n) 
Auxiliary space: O(n)
-------------------------------------------------------------------------
27) All unique triplets that sum up to a given value
Given an array and a sum value, find all possible unique triplets in that array whose sum is equal to the given sum value. If no such triplets can be formed from the array, then print “No triplets can be formed”, else print all the unique triplets. For example, if the given array is {12, 3, 6, 1, 6, 9} and the given sum is 24, then the unique triplets are (3, 9, 12) and (6, 6, 12) whose sum is 24.

Examples: 
Input : array = {12, 3, 6, 1, 6, 9} sum = 24
Output : [[3, 9, 12], [6, 6, 12]]

Input : array = {-2, 0, 1, 1, 2} sum = 0
Output : [[-2, 0, 2], [-2, 1, 1]]

Input : array = {-2, 0, 1, 1, 2} sum = 10
Output : No triplets can be formed	

Approach
Sort the input array.
For the first element iterate i from 0 to n-2.
For each iteration we will have two indexes starts and end where the start would be equal to i+1 and end would be equal to n-1.
Now we will look for a target whose value is sum-a[i] in the range from start to end using two pointer techniques.
In this we will look for the previous elements if they are the same then we would not work for them to find all unique duplicates.
If we found target==a[start]+a[end] then we would print it and increment start and decrement end.
If target>a[start]+a[end] then we would increment start.
Else we would decrement end

void findTriplets(int a[], int n, int sum)
{
	int i;

	// Sort the input array
	sort(a, a + n);

	// For handling the cases when no such 
	// triplets exits.
	bool flag = false;

	// Iterate over the array from start to n-2.
	for (i = 0; i < n - 2; i++)
	{
		if (i == 0 || a[i] > a[i - 1])
		{
			// Index of the first element in 
			// remaining range.
			int start = i + 1;

			// Index of the last element
			int end = n - 1;

			// Setting our new target
			int target = sum - a[i];

			while (start < end) 
			{
				// Checking if current element 
				// is same as previous
				if (start > i + 1
					&& a[start] == a[start - 1]) 
				{
					start++;
					continue;
				}

				// Checking if current element is 
				// same as previous
				if (end < n - 1 
					&& a[end] == a[end + 1]) 
				{
					end--;
					continue;
				}

				// If we found the triplets then print it
				// and set the flag
				if (target == a[start] + a[end]) 
				{
					cout << "[" << a[i] 
						<< "," << a[start]
						<< "," << a[end] << "] ";
					flag = true;
					start++;
					end--;
				}
				// If target is greater then
				// increment the start index
				else if (target > (a[start] + a[end]))
				{
					start++;
				}
				// If target is smaller than 
				// decrement the end index
				else {
					end--;
				}
			}
		}
	}

	// If no such triplets found
	if (flag == false) {
		cout << "No Such Triplets Exist"
			<< "\n";
	}
}

// Driver code
int main()
{
	int a[] = { 12, 3, 6, 1, 6, 9 };
	int n = sizeof(a) / sizeof(a[0]);
	int sum = 24;

	// Function call
	findTriplets(a, n, sum);
	return 0;
}
Output
[3,9,12] [6,6,12]
Complexity Analysis:
Time Complexity: O(n2).
Since two nested loops is required, so the time complexity is O(n2).
Auxiliary Space: O(1).
Since we need no extra space for solving this.
-------------------------------------------------------------------
28) Smallest subarray with k distinct numbers	
We are given an array consisting of n integers and an integer k. We need to find the minimum range in array [l, r] (both l and r are inclusive) such that there are exactly k different numbers. If such subarray doesn’t exist print “Invalid k”.
Examples: 
Input : arr[] = { 1, 1, 2, 2, 3, 3, 4, 5} 
            k = 3
Output : 5 7

Input : arr[] = { 1, 2, 2, 3} 
            k = 2
Output : 0 1

Input : arr[] = {1, 1, 2, 1, 2}
            k = 3
Output : Invalid k

Approach 1: The simplest approach in this problem is, try to generate all the subarrays
and check for which subarray the size is k. But there are some points we need to take care
void minRange(int arr[], int n, int k)
{
	// Starting and ending index of resultant subarray
	int start = 0, end = n;

	// Selecting each element as the start index for
	// subarray
	for (int i = 0; i < n; i++) {
		// Initialize a set to store all distinct elements
		unordered_set<int> set;

		// Selecting the end index for subarray
		int j;
		for (j = i; j < n; j++) {
			set.insert(arr[j]);

			/*
			If set contains exactly k elements,
			then check subarray[i, j] is smaller in size
			than the current resultant subarray
			*/
			if (set.size() == k) {
				if (j - i < end - start) {
					start = i;
					end = j;
				}

				// There are already k distinct elements
				// now, no need to consider further elements
				break;
			}
		}

		// If there are no k distinct elements
		// left in the array starting from index i we will
		// break
		if (j == n) {
			break;
		}
	}

	// If no window found then print -1
	if (start == 0 && end == n)
		cout << "Invalid k";

	else
		cout << start << " " << end;
}

// Driver code for above function.
int main()
{
	int arr[] = { 1, 2, 3, 4, 5 };
	int n = sizeof(arr) / sizeof(arr[0]);
	int k = 3;
	minRange(arr, n, k);
	return 0;
}
Output
0 2
Time Complexity : O(N^2) ,where N is the number of elements in the array. Every time picking the end points of the subarray using two nested loops(one inside another) makes the time complexity O(N^2).
Space Complexity :  O(N)

Approach 2: Sliding Window:
Optimization is get rid of the repeated work while making all subarray, all subarray will not
help to find the resultant. The approach is –
Steps :
Initialize a map to store the frequencies of each element.
Taking two variables as taken before : start and end of the required subarray.
And here we are using i and j as the starting and ending index of the window respectively, initializing as i = 0 and j = 0.
Will traverse the array while the ending pointer of our window reach the end of given array. i.e.  while( j < n)
Add the current element to the map map[ arr[j] ]++ and make j pointing to the next index
Consider the window [ i, j-1 ] (reason for ‘j-1’ is as we incremented the value of ‘j’ just after insertion in last step) check whether its size is equal to k
If window size is lesser than k then continue
But if window size == k, then check its length whether it is the resultant subarray or not. 
After that we need to move our window, but in order to move our window, we have to check the starting element of our current window (i.e. i-th). If the i-th element is having a frequency of 1 then erase it from the map and else decrease its frequency by 1. And increase the i-value. Make i to point to the next element

void minRange(int arr[], int n, int k)
{
	/*
		start = starting index of resultant subarray
		end = ending index of resultant subarray
	*/
	int start = 0, end = n;

	unordered_map<int, int> map;

	/*
		i = starting index of the window (on left side)
		j = ending index of the window (on right side)
	*/
	int i = 0, j = 0;

	while (j < n) {
		// Add the current element to the map
		map[arr[j]]++;
		j++;

		// Nothing to do when having less element
		if (map.size() < k)
			continue;

		/*
				If map contains exactly k elements,
				consider subarray[i, j - 1] keep removing
				left most elements
		*/

		while (map.size() == k) {
			// as considering the (j-1)th and i-th index
			int windowLen = (j - 1) - i + 1;
			int subArrayLen = end - start + 1;

			if (subArrayLen > windowLen) {
				start = i;
				end = j - 1;
			}

			// Remove elements from left

			// If freq == 1 then totally erase
			if (map[arr[i]] == 1)
				map.erase(arr[i]);

			// decrease freq by 1
			else
				map[arr[i]]--;

			// move the starting index of window
			i++;
		}
	}

	if (start == 0 && end == n)
		cout << "Invalid k" << endl;

	else
		cout << start << " " << end << endl;
}

// Driver code for above function.
int main()
{
	int arr[] = { 1, 1, 2, 2, 3, 3, 4, 5 };
	int n = sizeof(arr) / sizeof(arr[0]);
	int k = 3;
	minRange(arr, n, k);
	return 0;
}

Time Complexity : O(N) ,where N is the number of elements in the array. In the worst case, each element will be added once and removed once from the map.
Space Complexity :  O(K)
-------------------------------------------------------------------------------
29) Maximum possible difference of two subsets of an array
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
	int result = 0; 

	// sort the array 
	sort(arr, arr + n); 

	// calculate the result 
	for (int i = 0; i < n - 1; i++) { 
		if (arr[i] != arr[i + 1]) 
			result += abs(arr[i]); 
		else
			i++; 
	} 

	// check for last element 
	if (arr[n - 2] != arr[n - 1]) 
		result += abs(arr[n - 1]); 

	// return result 
	return result; 
} 

// driver program 
int main() 
{ 
	int arr[] = { 4, 2, -3, 3, -2, -2, 8 }; 
	int n = sizeof(arr) / sizeof(arr[0]); 
	cout << "Maximum Difference = " << maxDiff(arr, n); 
	return 0; 
} 
Time Complexity: O(n log n)
Auxiliary Space: O(1)
---------------------------------------------------------------------------
30) Find the length of largest subarray with 0 sum
Input: arr[] = {15, -2, 2, -8, 1, 7, 10, 23}
Output: 5
Explanation: The longest sub-array with elements summing up-to 0 is {-2, 2, -8, 1, 7}

Input: arr[] = {1, 2, 3}
Output: 0
Explanation: There is no subarray with 0 sum

Input:  arr[] = {1, 0, 3}
Output:  1
Explanation: The longest sub-array with elements summing up-to 0 is {0}

Approach 1: 
Consider all sub-arrays one by one and check the sum of every sub-array. If the sum of
the current subarray is equal to zero then update the maximum length accordingly. After 
iterating over all the subarrays, return the maximum length.

int maxLen(int arr[], int N)
{
	// Initialize result
	int max_len = 0; 

	// Pick a starting point
	for (int i = 0; i < N; i++) {

		// Initialize curr_sum for
		// every starting point
		int curr_sum = 0;

		// Try all subarrays starting with 'i'
		for (int j = i; j < N; j++) {
			curr_sum += arr[j];

			// If curr_sum becomes 0, 
			// then update max_len
			// if required
			if (curr_sum == 0)
				max_len = max(max_len, j - i + 1);
		}
	}
	return max_len;
}

// Driver's Code
int main()
{
	int arr[] = {15, -2, 2, -8, 1, 7, 10, 23};
	int N = sizeof(arr) / sizeof(arr[0]);
  
  // Function call
	cout << "Length of the longest 0 sum subarray is "
		 << maxLen(arr, N);
	return 0;
}
Output
Length of the longest 0 sum subarray is 5
Time Complexity: O(N2)
Auxiliary Space: O(1)

Approach 2: Using Hashmap and Prefix Sum
	
int maxLen(int arr[], int N)
{
	// Map to store the previous sums
	unordered_map<int, int> presum;

	int sum = 0; // Initialize the sum of elements
	int max_len = 0; // Initialize result

	// Traverse through the given array
	for (int i = 0; i < N; i++) {

		// Add current element to sum
		sum += arr[i];
		if (sum == 0)
			max_len = i + 1;

		// Look for this sum in Hash table
		if (presum.find(sum) != presum.end()) {

			// If this sum is seen before, then update
			// max_len
			max_len = max(max_len, i - presum[sum]);
		}
		else {
			// Else insert this sum with index
			// in hash table
			presum[sum] = i;
		}
	}

	return max_len;
}

// Driver's Code
int main()
{
	int arr[] = { 15, -2, 2, -8, 1, 7, 10, 23 };
	int N = sizeof(arr) / sizeof(arr[0]);

	// Function call
	cout << "Length of the longest 0 sum subarray is "
		 << maxLen(arr, N);

	return 0;
}
Time Complexity: O(N), where N is the number of elements in the array.
Auxiliary Space: O(N)
--------------------------------------------------------------------------
31)Find Itinerary from a given list of tickets
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

	// To fill reverse map, iterate through the given map 
	for (it = dataSet.begin(); it!=dataSet.end(); it++) 
		reversemap[it->second] = it->first; 

	// Find the starting point of itinerary 
	string start; 

	for (it = dataSet.begin(); it!=dataSet.end(); it++) 
	{ 
		if (reversemap.find(it->first) == reversemap.end()) 
		{ 
			start = it->first; 
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
-------------------------------------------------------------------------
32) Find all pairs (a, b) in an array such that a % b = k	
Given an array with distinct elements, the task is to find the pairs in the array such that a % b = k, where k is a given integer.

Examples : 
Input  :  arr[] = {2, 3, 5, 4, 7}   
             k = 3
Output :  (7, 4), (3, 4), (3, 5), (3, 7)
7 % 4 = 3
3 % 4 = 3
3 % 5 = 3
3 % 7 = 3

Approach 1: 

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
-----------------------------------------------------------------------------
33) Count the number of subarrays having a given XOR
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
			  
int subarrayXor(int arr[], int n, int m)
{
	//declaring the hashtable
	//and initializing it with a count of 1 
	//for 0
	unordered_map <int, int> HashTable;
	HashTable[0] = 1;
	int count = 0, curSum = 0;
	for (int i = 0; i < n; i++)
	{
		curSum ^= arr[i];
		if (HashTable[curSum ^ m] > 0)
			count += HashTable[curSum ^ m];
		HashTable[curSum]++;
	}
	return(count);
}
		

// Driver program to test above function 
int main()
{
	int arr[] = { 5, 6, 7, 8, 9 }; 
	int n = sizeof(arr) / sizeof(arr[0]);
	int m = 5;
	
	//Function call
	cout << "Number of subarrays having given XOR is " << subarrayXor(arr, n, m);
}
Output: Number of subarrays having given XOR is 2
Time Complexity: O(n)
Auxiliary Space: O(n)
---------------------------------------------------------------------------








		
		
		


