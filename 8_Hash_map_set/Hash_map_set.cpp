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
2) Frequency of each character in a String using unordered_map in C++
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

		// Traverse string str check if
		// current character is present
		// or not
		for (int i = 0; str[i]; i++) 
		{
			// If the current characters
			// is not found then insert
			// current characters with
			// frequency 1
			if (M.find(str[i]) == M.end()) 
			{
				M.insert(make_pair(str[i], 1));
			}

			// Else update the frequency
			else
			{
				M[str[i]]++;
			}
		}

		// Traverse the map to print the
		// frequency
		for (auto& it : M) {
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
3) Find first non-repeating character of given String:
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
4) Find missing elements of a range:
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
-----------------------------------------------------------------------------
5) Pair with given Sum (Two Sum)
Given an array A[] of n numbers and another number x, the task is to check whether or not there 
exist two elements in A[] whose sum is exactly x. 

Examples: 
Input: arr[] = {0, -1, 2, -3, 1}, x= -2
Output: Yes
Explanation: If we calculate the sum of the output,1 + (-3) = -2

Input: arr[] = {1, -2, 1, 0, 5}, x = 0
Output: No

	Approach 1: using two nested loops:
	bool chkPair(int A[], int size, int x)
	{
		for (int i = 0; i < (size - 1); i++) {
			for (int j = (i + 1); j < size; j++) {
				if (A[i] + A[j] == x) {
					return 1;
				}
			}
		}

		return 0;
	}

	// Driver code
	int main()
	{
		int A[] = { 0, -1, 2, -3, 1 };
		int x = -2;
		int size = sizeof(A) / sizeof(A[0]);

		if (chkPair(A, size, x)) {
			cout << "Yes" << endl;
		}
		else {
			cout << "No" << x << endl;
		}

		return 0;
	}
	Time Complexity: O(N2), Finding pair for every element in the array of size N.
	Auxiliary Space: O(1)
	
	Approach 2: Two Sum using Hashing
	void printPairs(int arr[], int arr_size, int sum)
	{
		unordered_set<int> s;
		for (int i = 0; i < arr_size; i++) {
			int temp = sum - arr[i];

			if (s.find(temp) != s.end()) {
				cout << "Yes" << endl;
				return;
			}
			s.insert(arr[i]);
		}
		cout << "No" << endl;
	}

	/* Driver Code */
	int main()
	{
		int A[] = { 1, 4, 45, 6, 10, 8 };
		int n = 16;
		int arr_size = sizeof(A) / sizeof(A[0]);

		// Function calling
		printPairs(A, arr_size, n);

		return 0;
	}
	Time Complexity: O(N), As the whole array is needed to be traversed only once.
	Auxiliary Space: O(N), A hash map has been used to store array elements.
	
	Approach 3: Using two pointers:
	bool hasArrayTwoCandidates(int A[], int arr_size, int sum)
	{
		int l, r;

		/* Sort the elements */
		sort(A, A + arr_size);

		/* Now look for the two candidates in
		   the sorted array*/
		l = 0;
		r = arr_size - 1;
		while (l < r) {
			if (A[l] + A[r] == sum)
				return 1;
			else if (A[l] + A[r] < sum)
				l++;
			else // A[l] + A[r] > sum
				r--;
		}
		return 0;
	}

	/* Driver program to test above function */
	int main()
	{
		int A[] = { 1, 4, 45, 6, 10, -8 };
		int n = 16;
		int arr_size = sizeof(A) / sizeof(A[0]);

		// Function calling
		if (hasArrayTwoCandidates(A, arr_size, n))
			cout << "Yes";
		else
			cout << "No";

		return 0;
	}
	Time Complexity: O(NlogN), Time complexity for sorting the array
	Auxiliary Space: O(1)
	
	Approach 4: Two Sum using Binary Search
	
	bool binarySearch(int A[], int low, int high, int searchKey)
	{

		while (low <= high) {
			int m = low + (high - low) / 2;

			// Check if searchKey is present at mid
			if (A[m] == searchKey)
				return true;

			// If searchKey greater, ignore left half
			if (A[m] < searchKey)
				low = m + 1;

			// If searchKey is smaller, ignore right half
			else
				high = m - 1;
		}

		// if we reach here, then element was
		// not present
		return false;
	}

	bool checkTwoSum(int A[], int arr_size, int sum)
	{
		int l, r;

		/* Sort the elements */
		sort(A, A + arr_size);

		// Traversing all element in an array search for
		// searchKey
		for (int i = 0; i < arr_size - 1; i++) {

			int searchKey = sum - A[i];
			// calling binarySearch function
			if (binarySearch(A, i + 1, arr_size - 1, searchKey)
				== true) {
				return true;
			}
		}
		return false;
	}

	/* Driver program to test above function */
	int main()
	{
		int A[] = { 1, 4, 45, 6, 10, -8 };
		int n = 14;
		int arr_size = sizeof(A) / sizeof(A[0]);

		// Function calling
		if (checkTwoSum(A, arr_size, n))
			cout << "Yes";
		else
			cout << "No";

		return 0;
	}
	Time Complexity: O(NlogN)
	Auxiliary Space: O(1)
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
	
	



		

		
		
		


