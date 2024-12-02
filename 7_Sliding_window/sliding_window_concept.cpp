/*
Window Sliding Technique is a computational technique which aims to reduce the use
of nested loop and replace it with a single loop, thereby reducing the time complexity.

How to use Sliding Window Technique?
	Find the size of window required 
	Compute the result for 1st window, i.e. from start of data structure
	Then use a loop to slide the window by 1, and keep computing the result window by window.
*/

/*
Example: Given an array of integers of size ‘n’, Our aim is to calculate the maximum 
sum of ‘k’ consecutive elements in the array.
Input  : arr[] = {100, 200, 300, 400}, k = 2
Output : 700

Input  : arr[] = {1, 4, 2, 10, 23, 3, 1, 0, 20}, k = 4 
Output : 39
We get maximum sum by adding subarray {4, 2, 10, 23} of size 4.

Input  : arr[] = {2, 3}, k = 3
Output : Invalid
There is no subarray of size 3 as size of whole array is 2.
*/

/*
Naive Approach: So, let’s analyze the problem with Brute Force Approach.
We start with first index and sum till k-th element. We do it for all possible 
consecutive blocks or groups of k elements. This method requires nested for loop,
the outer for loop starts with the starting element of the block of k elements and
the inner or the nested loop will add up till the k-th element.

// O(n*k) solution for finding maximum sum of
// a subarray of size k
#include <bits/stdc++.h>
using namespace std;

// Returns maximum sum in a subarray of size k.
int maxSum(int arr[], int n, int k)
{
	// Initialize result
	int max_sum = INT_MIN;

	// Consider all blocks starting with i.
	for (int i = 0; i < n - k + 1; i++) 
	{
		int current_sum = 0;
		for (int j = 0; j < k; j++)
		{
			current_sum = current_sum + arr[i + j];
		}

		// Update result if required.
		max_sum = max(current_sum, max_sum);
	}

	return max_sum;
}

// Driver code
int main()
{
	int arr[] = { 1, 4, 2, 10, 2, 3, 1, 0, 20 };
	int k = 4;
	int n = sizeof(arr) / sizeof(arr[0]);
	cout << maxSum(arr, n, k);
	return 0;
}

// This code is contributed by Aditya Kumar (adityakumar129)
*/

/*
sliding window technique:

// O(n) solution for finding maximum sum of
// a subarray of size k
#include <iostream>
using namespace std;

// Returns maximum sum in a subarray of size k.
int maxSum(int arr[], int n, int k)
{
	// n must be greater
	if (n < k) {
		cout << "Invalid";
		return -1;
	}

	// Compute sum of first window of size k
	int max_sum = 0;
	for (int i = 0; i < k; i++)
		max_sum += arr[i];

	// Compute sums of remaining windows by
	// removing first element of previous
	// window and adding last element of
	// current window.
	int window_sum = max_sum;
	for (int i = k; i < n; i++) {
		window_sum += arr[i] - arr[i - k];
		max_sum = max(max_sum, window_sum);
	}

	return max_sum;
}

// Driver code
int main()
{
	int arr[] = { 1, 4, 2, 10, 2, 3, 1, 0, 20 };
	int k = 4;
	int n = sizeof(arr) / sizeof(arr[0]);
	cout << maxSum(arr, n, k);
	return 0;
}
*/