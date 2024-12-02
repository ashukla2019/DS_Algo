-------------------------------------EASY-------------------------------------
void linearSearch(int* p, int num, int len)
{
	bool flag_found = false;
	for(int i=0; i<len; i++)
	{
		if(p[i] == num)
		{
			flag_found = true;
			break;
		}
	}
	if(true == flag_found)
	{
		cout<<"number found"<<endl;
	}
	else
	{
		cout<<"number not found"<<endl;
	}
}

int main()
{
	int arr[] = {10, 30, 50, 60, 70};
	int len = sizeof(arr)/sizeof(int);
	linearSearch(arr, 11, len);
	return 0;
}
//Time complexity: o(n)
-------------------------------------------------
2. Binary search:
//Time complexity: o(logn)
void binarySearch(int arr[], int lower, int upper, int num) 
{ 
    while (lower <= upper)
	{ 
        int mid = lower + upper / 2; 
  
        // Check if num is present at mid 
        if (arr[mid] == num) 
		{
            cout<<"number found at position"<<mid<<endl; 
		}
  
        // If number greater, ignore left half 
        if (arr[mid] < num) 
		{
            lower = mid + 1; 
		}	
  
        // If number is smaller, ignore right half 
        else
		{
           upper = mid - 1; 
		} 
	} 
}
int main()
{
	int arr[] = {10, 30, 50, 60, 70};
	int len = sizeof(arr)/sizeof(int);
	binarySearch(arr, 0, 4, 60);
	return 0;
}

------------------------------------------------------------------------
3)Sorting: selection sort:
int* selection_sort(int arr[], int len)
{
    for(int i=0; i<len; i++)
    {
        for(int j=i+1; j<len; j++)
        {
            if(arr[i]>arr[j])
            {
                int temp=arr[i];
                arr[i]=arr[j];
                arr[j]=temp;
            }
        }
    }
    return arr;
}
int main()
{
	int arr[] = {15, 10, 20, 5, 9, 25};
	int len = sizeof(arr)/ sizeof(int);
    int* res= buble_sort(arr, len);
    for(int it=0; it<len; it++)
        std::cout<<arr[it]<<endl;
	return 0;
}
---------------------------------------------------------------
4) Bubble sort:
int* bubble_sort(int arr[], int len)
{
    for(int i=0; i<len; i++)
    {
        for(int j=0; j<len-i; j++)
        {
            if(arr[j]>arr[j+1])
            {
                int temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }
    return arr;
}
int main()
{
    int arr[] ={10,2,31,24}; 
    int len = sizeof(arr)/sizeof(arr[0]);
    int* res=bubble_sort(arr, len);
    for(int i=0; i<len; i++)
    {
        std::cout<<res[i]<<endl;
    }
	return 0;
}
------------------------------------MEDIUM------------------------------------------
5) Quick sort:
	//Algo steps:
	1. Choose the appropriate pivot element.
	2. Take two variables to point left and right of the list 
	excluding pivot
	3. Left points to the low index
	4. Right points to the high
	5. While value at left is less than pivot move right
	6. While value at right is greater than pivot move left
	7. If both step 5 and step 6 are done then swap both left and right element.
		Repeat above steps until, left<=right
	8. If left ≥ right, the point where they met is new pivot(At last we put pivot to correct place by putting it into high's place)

int split(int a[], int lower, int upper)
{
	int pivot = a[lower];
	int p = lower+1;
	int q = upper;
	int temp;
	while(q>=p)
	{
		while(a[p] < pivot)
		{
			p++;
		}
		while(a[q] > pivot)
		{
			q--;
		}
		//Swap element at p and q index
		if(q>p)
		{
			temp = a[p];
			a[p] = a[q];
			a[q] = temp;
		}
	}
	//swap pivot element and a[q]
	temp = a[lower];
	a[lower] = a[q];
	a[q] = temp;
	return q;
	
}
void quicksort(int a[], int lower, int upper)
{
	if(upper > lower)
	{
		int i = split(a, lower, upper);
		quicksort(a, lower, i-1);
		quicksort(a, i+1, upper);
	}
}

int main()
{
	int arr[] = {11,13,2,45,10,56,20};
	quicksort(arr, 0, 6);
	for(int i = 0; i<7; i++)
	{
		cout<<arr[i]<<endl;
	}
	return 0;
}
--------------------------------------------------------------
6) Insertion sort:
Example 1:
Input: N = 6, array[] = {13,46,24,52,20,9}
Output: 9,13,20,24,46,52
Explanation: 
After sorting the array is: 9,13,20,24,46,52

Example 2:
Input: N=5, array[] = {5,4,3,2,1}
Output: 1,2,3,4,5
Explanation: After sorting the array is: 1,2,3,4,5

#include <bits/stdc++.h>
using namespace std;

void insertion_sort(int arr[], int n) 
{
    for (int i = 0; i <= n - 1; i++) 
    {
        int j = i;
        while (j > 0 && arr[j - 1] > arr[j]) 
        {
            int temp = arr[j - 1];
            arr[j - 1] = arr[j];
            arr[j] = temp;
            j--;
        }
    }

    cout << "After Using insertion sort: " << "\n";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << "\n";
}

int main()
{
    int arr[] = {13, 46, 24, 52, 20, 9};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Before Using insertion Sort: " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    insertion_sort(arr, n);
    return 0;
}
Time complexity: O(N2)
--------------------------------------------------------------------
7) Merge sort:
Example 1:
Input: N=5, arr[]={4,2,1,6,7}
Output: 1,2,4,6,7,

Example 2:
Input: N=7,arr[]={3,2,8,5,1,4,23}
Output: 1,2,3,4,5,8,23

void merge(vector<int> &arr, int low, int mid, int high) {
    vector<int> temp; // temporary array
    int left = low;      // starting index of left half of arr
    int right = mid + 1;   // starting index of right half of arr

    //storing elements in the temporary array in a sorted manner//

    while (left <= mid && right <= high) {
        if (arr[left] <= arr[right]) {
            temp.push_back(arr[left]);
            left++;
        }
        else {
            temp.push_back(arr[right]);
            right++;
        }
    }

    // if elements on the left half are still left //

    while (left <= mid) {
        temp.push_back(arr[left]);
        left++;
    }

    //  if elements on the right half are still left //
    while (right <= high) {
        temp.push_back(arr[right]);
        right++;
    }

    // transfering all elements from temporary to arr //
    for (int i = low; i <= high; i++) {
        arr[i] = temp[i - low];
    }
}

void mergeSort(vector<int> &arr, int lower, int upper) {
    if(upper>lower)
    {
        int mid = (lower + upper) / 2 ;
        mergeSort(arr, lower, mid);  // left half
        mergeSort(arr, mid + 1, upper); // right half
        merge(arr, lower, mid, upper);  // merging sorted halves
    }
}

int main() 
{

    vector<int> arr = {9, 4, 7, 6, 3, 1, 5}  ;
    int n = 7;

    cout << "Before Sorting Array: " << endl;
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " "  ;
    }
    cout << endl;
    mergeSort(arr, 0, n - 1);
    cout << "After Sorting Array: " << endl;
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " "  ;
    }
    cout << endl;
    return 0 ;
}

Time complexity: O(nlogn) 
Reason: At each step, we divide the whole array, for that logn and we assume n steps are taken to get sorted array, so overall time complexity will be nlogn
Space complexity: O(n)  
---------------------------------------------------------------
8) Counting Sort: Counting Sort is a non-comparison-based sorting algorithm. 
It is particularly efficient when the range of input values is small compared 
to the number of elements to be sorted. The basic idea behind Counting Sort is
to count the frequency of each distinct element in the input array and use that
information to place the elements in their correct sorted positions.
Approach:
1) Find the max from the given array.
   arr = [ 2, 5, 3, 0, 2, 3, 0, 2] => max would be 5
2) Create count array of (max+1) and initialize all elements with 0.{size => 0..max}
   0 1 2 3 4 5 (index)
   0 0 0 0 0 5 (value)
3) Update count array with frequency of elements. //Now er got elements sorted and now need to find the correct index
   of each element.
   0 1 2 3 4 5 (index)
   2 0 2 3 0 1 (value)
4) Update count array with cumulative sum. //cumulative sum of every index will give actual index of elements
   0 1 2 3 4 5 (index)
   2 2 4 7 7 8 (value)
5) Traverse array arr[] from end and update ans[ countArray[ arr[i] ] – 1] = arr[i]. 
   Also, update countArray[ arr[i] ] = countArray[ array[i] ]- – . 
   0 0 2 2 2 3 3 5
// C++ Program to implement counting sort 
#include <bits/stdc++.h> 
using namespace std; 

// counting sort function 
void count_sort(int arr[], int n) 
{ 
	// max_element() is a c++ stl function to find the 
	// maximum element from an array 
	int k = *max_element(arr, arr + n); 

	// we declare a count array and initialize the array by 
	// 0 
	int count[k + 1] = { 0 }; 

	// we count the frequency of each distinct element in 
	// the original array 
	for (int i = 0; i < n; i++) { 
		count[arr[i]]++; 
	} 

	// we perform prefix sum and update the count array 
	for (int i = 1; i <= k; i++) { 
		count[i] = count[i] + count[i - 1]; 
	} 

	// we store our answer in the ans array 
	int ans[n]; 
	for (int i = n - 1; i >= 0; i--) { 
		ans[--count[arr[i]]] = arr[i]; 
	} 

	// here we copy the contents on ans array to our 
	// original array 
	for (int i = 0; i < n; i++) { 
		arr[i] = ans[i]; 
	} 
} 

// driver code 
int main() 
{ 
	int arr[] = { 1, 3, 7, 0, 1, 1, 6, 3, 0, 3 }; 
	int n = sizeof(arr) / sizeof(arr[0]); 
	count_sort(arr, n); 

	// displaying the result 
	cout << "Array after performing count sort : " << endl; 
	for (int i = 0; i < n; i++) { 
		cout << arr[i] << " "; 
	} 
	return 0; 
}
Time Complexity:
Best case time complexity = O(n + k).
Average case time complexity = O(n + k).
Worst case time complexity = O(n + k).
Space Complexity:
The space complexity of counting sort is O(n + k).  

----------------------------------------------------------------		
9) Permute two arrays such that sum of every pair is greater or equal to K:
Given two arrays of equal size n and an integer k. The task is to permute both
arrays such that sum of their corresponding element is greater than or equal to 
k i.e a[i] + b[i] >= k. The task is to print “Yes” if any such permutation exists, 
otherwise print “No”.
Examples : 
Input : a[] = {2, 1, 3}, 
        b[] = { 7, 8, 9 }, 
        k = 10. 
Output : Yes
Permutation  a[] = { 1, 2, 3 } and b[] = { 9, 8, 7 } 
satisfied the condition a[i] + b[i] >= K.

Input : a[] = {1, 2, 2, 1}, 
        b[] = { 3, 3, 3, 4 }, 
        k = 5. 
Output : No

Approach: The idea is to sort one array in ascending order and another array in 
descending order and if any index does not satisfy the condition a[i] + b[i] >= K 
then print “No”, else print “Yes”.
If the condition fails on sorted arrays, then there exists no permutation of 
arrays that can satisfy the inequality.

// C++ program to check whether permutation of two
// arrays satisfy the condition a[i] + b[i] >= k.
#include <bits/stdc++.h>
using namespace std;

// Check whether any permutation exists which
// satisfy the condition.
bool isPossible(int a[], int b[], int n, int k)
{
    // Sort the array a[] in increasing order.
    sort(a, a + n);

    // Sort the array b[] in decreasing order.
    sort(b, b + n, greater<int>());

    // Checking condition on each index.
    for (int i = 0; i < n; i++)
        if (a[i] + b[i] < k)
            return false;

    return true;
}

// Driven Program
int main()
{
    int a[] = { 2, 1, 3 };
    int b[] = { 7, 8, 9 };
    int k = 10;
    int n = sizeof(a) / sizeof(a[0]);

    isPossible(a, b, n, k) ? cout << "Yes" : cout << "No";
    return 0;
}

Time Complexity: O(n log n).
Auxiliary Space: O(1)
--------------------------------------------------------------------
10)Product of Array except itself
Given an array arr[] of n integers, construct a Product Array prod[] (of the same size) such that prod[i] is equal to the product of all the elements of arr[] except arr[i]. 

Note: Solve it without the division operator in O(n) time.

Example : 

Input: arr[]  = {10, 3, 5, 6, 2}
Output: prod[]  = {180, 600, 360, 300, 900}
3 * 5 * 6 * 2 product of other array 
elements except 10 is 180
10 * 5 * 6 * 2 product of other array 
elements except 3 is 600
10 * 3 * 6 * 2 product of other array 
elements except 5 is 360
10 * 3 * 5 * 2 product of other array 
elements except 6 is 300
10 * 3 * 6 * 5 product of other array 
elements except 2 is 900


Input: arr[]  = {1, 2, 3, 4, 5}
Output: prod[]  = {120, 60, 40, 30, 24 }
2 * 3 * 4 * 5  product of other array 
elements except 1 is 120
1 * 3 * 4 * 5  product of other array 
elements except 2 is 60
1 * 2 * 4 * 5  product of other array 
elements except 3 is 40
1 * 2 * 3 * 5  product of other array 
elements except 4 is 30
1 * 2 * 3 * 4  product of other array 
elements except 5 is 24

// C++ implementation of above approach 
#include <bits/stdc++.h> 
using namespace std; 

/* Function to print product array 
for a given array arr[] of size n */
void findproduct(int arr[], int product[],int n)
{
    int prefix[n];
    prefix[0]=1; // since first element can have no prefix
    for(int i=1;i<n;i++)
    {
        prefix[i]=prefix[i-1]*arr[i-1];
    }
    int suffixproduct=1;
    // Building Product array and maintaining suffix product
    for(int i=n-1;i>=0;i--)
    {
        product[i]=suffixproduct*prefix[i];
        suffixproduct*=arr[i];
    }
}
// Driver Code
int main()
{
    int arr[] = { 1 , 4 , 6 , 2 , 3};
    int n = sizeof(arr)/sizeof(arr[0]);
    int product[n];
    findproduct(arr,product,n);
 
    cout << "The product of array Except itself is: ";
    for(int i=0;i<n;i++)
    {
        cout<<product[i]<<", "; 
    }
    cout<<endl;
 
    return 0;
}

Time Complexity: O(n). 
The original array needs to be traversed only once, so the time complexity is constant.
Auxiliary Space: O(n). 
Even though the extra arrays are removed, the space complexity remains O(n), as the product array is still needed.
------------------------------------------------------------------
11)Make all array elements equal with minimum cost
Given an array which contains integer values, we need to make all values of this array equal to some integer value with minimum cost where the cost of changing an array value x to y is abs(x-y). 
Examples : 
Input  : arr[] = [1, 100, 101]
Output : 100
We can change all its values to 100 with minimum cost,
|1 - 100| + |100 - 100| + |101 - 100| = 100
Input  : arr[] = [4, 6]
Output : 2
We can change all its values to 5 with minimum cost,
|4 - 5| + |5 - 6| = 2

Approach: This problem can be solved by observing the cost while changing the 
target equal value, i.e. we will see the change in cost when target equal value
is changed. It can be observed that, as we increase the target equal value the
total cost decreases up to a limit and then starts increasing i.e. the cost
graph with respect to target equal value is of U-shape and as cost graph is in
U-shape, the ternary search can be applied to this search space and our goal is
to get that bottom most point of the curve which will represent the smallest cost.
 We will make smallest and largest value of the array as the limit of our search 
 space and then we will keep skipping 1/3 part of the search space until we reach
 to the bottom most point of our U-curve. 
 
 // C++ program to find minimum cost to
// make all elements equal
#include <bits/stdc++.h>
using namespace std;

// Utility method to compute cost, when
// all values of array are made equal to X
int computeCost(int arr[], int N, int X)
{
	int cost = 0;
	for (int i = 0; i < N; i++)
		cost += abs(arr[i] - X);
	return cost;
}

// Method to find minimum cost to make all
// elements equal
int minCostToMakeElementEqual(int arr[], int N)
{
	int low, high;
	low = high = arr[0];

	// setting limits for ternary search by
	// smallest and largest element
	for (int i = 0; i < N; i++) {
		if (low > arr[i])
			low = arr[i];
		if (high < arr[i])
			high = arr[i];
	}

	/* loop until difference between low and high
	become less than 3, because after that
	mid1 and mid2 will start repeating
	*/
	while ((high - low) > 2) {

		// mid1 and mid2 are representative array
		// equal values of search space
		int mid1 = low + (high - low) / 3;
		int mid2 = high - (high - low) / 3;

		int cost1 = computeCost(arr, N, mid1);
		int cost2 = computeCost(arr, N, mid2);

		// if mid2 point gives more total cost,
		// skip third part
		if (cost1 < cost2)
			high = mid2;

		// if mid1 point gives more total cost,
		// skip first part
		else
			low = mid1;
	}

	// computeCost gets optimum cost by sending
	// average of low and high as X
	return computeCost(arr, N, (low + high) / 2);
}

// Driver code to test above method
int main()
{
	int arr[] = { 1, 100, 101 };
	int N = sizeof(arr) / sizeof(int);
	cout << minCostToMakeElementEqual(arr, N);
	return 0;
}
Time Complexity: O(NlogN)
Auxiliary Space: O(1)
-------------------------------------------------------------------
12) Find Peak Element:
A peak element is an element that is strictly greater than its neighbors.
Given a 0-indexed integer array nums, find a peak element, and return its index. If the array contains multiple peaks, return the index to any of the peaks.
You may imagine that nums[-1] = nums[n] = -∞. In other words, an element is always considered to be strictly greater than a neighbor that is outside the array.
You must write an algorithm that runs in O(log n) time.

Example 1:
Input: nums = [1,2,3,1]
Output: 2
Explanation: 3 is a peak element and your function should return the index number 2.

Example 2:
Input: nums = [1,2,1,3,5,6,4]
Output: 5
Explanation: Your function can return either index number 1 where the peak element is 2, or index number 5 where the peak element is 6.

int findPeakElement(vector<int> &arr) {
    int n = arr.size(); //Size of array.

    // Edge cases:
    if (n == 1) return 0;
    if (arr[0] > arr[1]) return 0;
    if (arr[n - 1] > arr[n - 2]) return n - 1;

    int low = 1, high = n - 2;
    while (low <= high) {
        int mid = (low + high) / 2;

        //If arr[mid] is the peak:
        if (arr[mid - 1] < arr[mid] && arr[mid] > arr[mid + 1])
            return mid;

        // If we are in the left:
        if (arr[mid] > arr[mid - 1]) low = mid + 1;

        // If we are in the right:
        // Or, arr[mid] is a common point:
        else high = mid - 1;
    }
    // Dummy return statement
    return -1;
}

int main()
{
    vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8, 5, 1};
    int ans = findPeakElement(arr);
    cout << "The peak is at index: " << ans << "\n";
    return 0;
}

Time Complexity: O(logN), N = size of the given array.
Reason: We are basically using binary search to find the minimum.

Space Complexity: O(1)
----------------------------------------------------------
13) Allocate minimum pages:
Problem Statement: Given an array ‘arr of integer numbers, ‘ar[i]’ represents the number of pages in the ‘i-th’ book. There are a ‘m’ number of students, and the task is to allocate all the books to the students.
Allocate books in such a way that:

Each student gets at least one book.
Each book should be allocated to only one student.
Book allocation should be in a contiguous manner.
You have to allocate the book to ‘m’ students such that the maximum number of pages assigned to a student is minimum. If the allocation of books is not possible. return -1

Example 1:
Input Format:
 n = 4, m = 2, arr[] = {12, 34, 67, 90}
Result:
 113
Explanation:
 The allocation of books will be 12, 34, 67 | 90. One student will get the first 3 books and the other will get the last one.

Example 2:
Input Format:
 n = 5, m = 4, arr[] = {25, 46, 28, 49, 24}
Result:
 71
Explanation: The allocation of books will be 25, 46 | 28 | 49 | 24.

We can allocate books in several ways but it is clearly said in the question that we have to allocate the books in such a way that the maximum number of pages received by a student should be minimum.

Assume the given array is {25 46 28 49 24} and number of students, M = 4. Now, we can allocate these books in different ways. Some of them are the following:

25 | 46 | 28 | 49, 24  → Maximum no. of pages a student receive = 73
25 | 46 | 28, 49 | 24  → Maximum no. of pages a student receive = 77
25 | 46, 28 | 49 | 24  → Maximum no. of pages a student receive = 74
25, 46 | 28 | 49 | 24  → Maximum no. of pages a student receive = 71
From the above allocations, we can clearly observe that the minimum possible maximum number of pages is 71.

When it is impossible to allocate books:

When the number of books is lesser than the number of students, we cannot allocate books to all the students even if we give only a single book to each student. So, if m > n, we should return -1.



#include <bits/stdc++.h>
using namespace std;

int countStudents(vector<int> &arr, int pages) {
    int n = arr.size(); //size of array.
    int students = 1;
    long long pagesStudent = 0;
    for (int i = 0; i < n; i++) {
        if (pagesStudent + arr[i] <= pages) {
            //add pages to current student
            pagesStudent += arr[i];
        }
        else {
            //add pages to next student
            students++;
            pagesStudent = arr[i];
        }
    }
    return students;
}

int findPages(vector<int>& arr, int n, int m) {
    //book allocation impossible:
    if (m > n) return -1;

    int low = *max_element(arr.begin(), arr.end());
    int high = accumulate(arr.begin(), arr.end(), 0);
    while (low <= high) {
        int mid = (low + high) / 2;
        int students = countStudents(arr, mid);
        if (students > m) {
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }
    return low;
}

int main()
{
    vector<int> arr = {25, 46, 28, 49, 24};
    int n = 5;
    int m = 4;
    int ans = findPages(arr, n, m);
    cout << "The answer is: " << ans << "\n";
    return 0;
}
Time Complexity: O(N * log(sum(arr[])-max(arr[])+1)), where N = size of the array, sum(arr[]) = sum of all array elements, max(arr[]) = maximum of all array elements.
Reason: We are applying binary search on [max(arr[]), sum(arr[])]. Inside the loop, we are calling the countStudents() function for the value of ‘mid’. Now, inside the countStudents() function, we are using a loop that runs for N times.
Space Complexity:  O(1) as we are not using any extra space to solve this problem

-------------------------------------------------------------
14) Minimum number of swaps required to sort an array
You are given an unordered array consisting of consecutive integers [1, 2, 3, ..., n] without any duplicates. You are allowed to swap any two elements. Find the minimum number of swaps required to sort the array in ascending order
Ex:
Input:
nums = {2, 8, 5, 4}
Output:
1
Explaination:
swap 8 with 4.

Input:
nums = {2,4,5,1,3}
Output:
3
This can be easily done by visualizing the problem as a graph.
We will have N nodes and an edge directed from node i to node j if the element 
at the i’th index must be present at the j’th index in the sorted array.

The graph will now contain many non-intersecting cycles. Now a cycle with 2 
nodes will only require 1 swap to reach the correct ordering, similarly, a 
cycle with 3 nodes will only require 2 swaps to do so. 

Follow the below steps to solve the problem:
Create an array of pairs arrPos to store the input array elements along with their index
Sort arrPos and run a loop for i [0, N]
If the current element is already visited or it is at its correct position then continue
Else calculate the cycle size from the current element using a while loop
Declare an integer j equal to i and in the while loop set j equal to the index of arrPos[j] and increase cycle size while the element at jth position is not visited
Increase the answer by the size of the current cycle – 1
Return answer

// C++ program to find
// minimum number of swaps
// required to sort an array
#include <bits/stdc++.h>
using namespace std;

// Function returns the
// minimum number of swaps
// required to sort the array
int minSwaps(int arr[], int n)
{
    // Create an array of
    // pairs where first
    // element is array element
    // and second element
    // is position of first element
    pair<int, int> arrPos[n];
    for (int i = 0; i < n; i++) {
        arrPos[i].first = arr[i];
        arrPos[i].second = i;
    }

    // Sort the array by array
    // element values to
    // get right position of
    // every element as second
    // element of pair.
    sort(arrPos, arrPos + n);

    // To keep track of visited elements.
    // Initialize
    // all elements as not visited or false.
    vector<bool> vis(n, false);

    // Initialize result
    int ans = 0;

    // Traverse array elements
    for (int i = 0; i < n; i++) {
        // already swapped and corrected or
        // already present at correct pos
        if (vis[i] || arrPos[i].second == i)
            continue;

        // find out the number of  node in
        // this cycle and add in ans
        int cycle_size = 0;
        int j = i;
        while (!vis[j]) {
            vis[j] = 1;

            // move to next node
            j = arrPos[j].second;
            cycle_size++;
        }

        // Update answer by adding current cycle.
        if (cycle_size > 0) {
            ans += (cycle_size - 1);
        }
    }

    // Return result
    return ans;
}

// Driver code
int main()
{
    int arr[] = { 1, 5, 4, 3, 2 };
    int n = (sizeof(arr) / sizeof(int));
    cout << minSwaps(arr, n);
    return 0;
}
Time Complexity: O(N * Log N) 
Auxiliary Space: O(N)

--------------------------------------------------------------
15) Aggressive cows: Problem Statement: You are given an array 'arr' of size 'n' which denotes the position of stalls.
You are also given an integer 'k' which denotes the number of aggressive cows.
You are given the task of assigning stalls to 'k' cows such that the minimum distance between any two of them is the maximum possible.
Find the maximum possible minimum distance.

Example 1:
Input Format:
 N = 6, k = 4, arr[] = {0,3,4,7,10,9}
Result:
 3
Explanation:
 The maximum possible minimum distance between any two cows will be 3 when 4 cows are placed at positions {0, 3, 7, 10}. Here the distances between cows are 3, 4, and 3 respectively. We cannot make the minimum distance greater than 3 in any ways.

Example 2:
Input Format:
 N = 5, k = 2, arr[] = {4,2,1,3,6}
Result:
 5
Explanation:
The maximum possible minimum distance between any two cows will be 5 when 2 cows are placed at positions {1, 6}. 

#include <bits/stdc++.h>
using namespace std;

bool canWePlace(vector<int> &stalls, int dist, int cows) {
    int n = stalls.size(); //size of array
    int cntCows = 1; //no. of cows placed
    int last = stalls[0]; //position of last placed cow.
    for (int i = 1; i < n; i++) {
        if (stalls[i] - last >= dist) {
            cntCows++; //place next cow.
            last = stalls[i]; //update the last location.
        }
        if (cntCows >= cows) return true;
    }
    return false;
}
int aggressiveCows(vector<int> &stalls, int k) {
    int n = stalls.size(); //size of array
    //sort the stalls[]:
    sort(stalls.begin(), stalls.end());

    int low = 1, high = stalls[n - 1] - stalls[0];
    //apply binary search:
    while (low <= high) {
        int mid = (low + high) / 2;
        if (canWePlace(stalls, mid, k) == true) {
            low = mid + 1;
        }
        else high = mid - 1;
    }
    return high;
}

int main()
{
    vector<int> stalls = {0, 3, 4, 7, 10, 9};
    int k = 4;
    int ans = aggressiveCows(stalls, k);
    cout << "The maximum possible minimum distance is: " << ans << "\n";
    return 0;
}
Time Complexity: O(NlogN) + O(N * log(max(stalls[])-min(stalls[]))), where N = size of the array, max(stalls[]) = maximum element in stalls[] array, min(stalls[]) = minimum element in stalls[] array.
Reason: O(NlogN) for sorting the array. We are applying binary search on [1, max(stalls[])-min(stalls[])]. Inside the loop, we are calling canWePlace() function for each distance, ‘mid’. Now, inside the canWePlace() function, we are using a loop that runs for N times.
Space Complexity: O(1) as we are not using any extra space to solve this problem

-------------------------------------------------------------
16) Search in Rotated Sorted Array:
Problem Statement: Given an integer array arr of size N, sorted in ascending 
order (with distinct values) and a target value k. Now the array is rotated at 
some pivot point unknown to you. Find the index at which k is present and if 
k is not present return -1.
Example 1:
Input Format: arr = [4,5,6,7,0,1,2,3], k = 0
Result: 4
Explanation: Here, the target is 0. We can see that 0 is present in the given rotated sorted array, nums. Thus, we get output as 4, which is the index at which 0 is present in the array.

Example 2:
Input Format: arr = [4,5,6,7,0,1,2], k = 3
Result: -1
Explanation: Here, the target is 3. Since 3 is not present in the given rotated sorted array. Thus, we get the output as -1.


#include <bits/stdc++.h>
using namespace std;

int search(vector<int>& arr, int n, int k) {
    int low = 0, high = n - 1;
    while (low <= high) {
        int mid = (low + high) / 2;

        //if mid points the target
        if (arr[mid] == k) return mid;

        //if left part is sorted:
        if (arr[low] <= arr[mid]) {
            if (arr[low] <= k && k <= arr[mid]) {
                //element exists:
                high = mid - 1;
            }
            else {
                //element does not exist:
                low = mid + 1;
            }
        }
        else { //if right part is sorted:
            if (arr[mid] <= k && k <= arr[high]) {
                //element exists:
                low = mid + 1;
            }
            else {
                //element does not exist:
                high = mid - 1;
            }
        }
    }
    return -1;
}

int main()
{
    vector<int> arr = {7, 8, 9, 1, 2, 3, 4, 5, 6};
    int n = 9, k = 1;
    int ans = search(arr, n, k);
    if (ans == -1)
        cout << "Target is not present.\n";
    else
        cout << "The index is: " << ans << "\n";
    return 0;
}
Time Complexity: O(logN), N = size of the given array.
Reason: We are using binary search to search the target.
Space Complexity: O(1)
Reason: We have not used any extra data structures, this makes space complexity, even in the worst case as O(1).

--------------------------------------------------------------
-------------------------Hard----
16) Count of Smaller Numbers After Self

--------------------------------------------------------------
17) Split Array Largest Sum
