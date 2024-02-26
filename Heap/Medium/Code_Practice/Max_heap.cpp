/*
1. maxHeapify():
MaxHeapify is the function responsible for restoring the property of the Max Heap. It arranges the node i, and its subtrees accordingly so that the heap property is maintained.

The following steps explain the function in detail:
Suppose we have given an array, ‘ARR’ representing the complete binary tree.
We set the index of the current element, ‘i’, as the ‘LARGEST’.
If ARR[2 * i + 1] > ARR[i], i.e., the left child is larger than the current value, it is set as ‘LARGEST’.
Similarly if ARR[2 * i + 2] > ARR[i], i.e., the right child is larger than the current value, it is set as ‘LARGEST’.
Swap the ‘LARGEST’ with the current element.
Repeat steps 1-4 till the property of the heap is restored.
Let us dry run the above steps using an example:
 
2. insertKey():
While insertion, the new element is appended at the end of the heap and becomes the last element of the array. If the newly added element is smaller than the parent, nothing has to be done. Otherwise, the values are swapped until the property of the heap is restored.

3. increaseKey():
Increases the value of a key at a particular index to some value. If this new value is smaller than the parent node, nothing has to be done. Otherwise, the property of the heap is violated and swaps are made to restore it.

4. getMax():
Returns the maximum element stored at the root node of the Max heap.

5. removeMax():
Removes the maximum element of the heap stored at the root and calls maxHeapify() to restore the property of the Max heap.

6. deletekey():
The element that has to be deleted is first replaced with positive infinity by calling increaseKey() and then we call removeMax() to remove this element from the heap.

*/


// A C++ program to demonstrate common Binary Heap Operations 
#include<iostream> 
#include<climits> 
using namespace std; 

// Prototype of a utility function to swap two integers 
void swap(int *x, int *y); 

// A class for Min Heap 
class MinHeap 
{ 
	int *harr; // pointer to array of elements in heap 
	int capacity; // maximum possible size of min heap 
	int heap_size; // Current number of elements in min heap 
public: 
	// Constructor 
	MinHeap(int capacity); 

	// to heapify a subtree with the root at given index 
	void MinHeapify(int i); 

	int parent(int i) { return (i-1)/2; } 

	// to get index of left child of node at index i 
	int left(int i) { return (2*i + 1); } 

	// to get index of right child of node at index i 
	int right(int i) { return (2*i + 2); } 

	// to extract the root which is the minimum element 
	int extractMin(); 

	// Decreases key value of key at index i to new_val 
	void decreaseKey(int i, int new_val); 

	// Returns the minimum key (key at root) from min heap 
	int getMin() { return harr[0]; } 

	// Deletes a key stored at index i 
	void deleteKey(int i); 

	// Inserts a new key 'k' 
	void insertKey(int k); 
}; 

// Constructor: Builds a heap from a given array a[] of given size 
MinHeap::MinHeap(int cap) 
{ 
	heap_size = 0; 
	capacity = cap; 
	harr = new int[cap]; 
} 

// Inserts a new key 'k' 
void MinHeap::insertKey(int k) 
{ 
	if (heap_size == capacity) 
	{ 
		cout << "\nOverflow: Could not insertKey\n"; 
		return; 
	} 

	// First insert the new key at the end 
	harr[heap_size++]=k; 
	int i = heap_size - 1; 

	// Fix the min heap property if it is violated 
	while (i != 0 && harr[parent(i)] > harr[i]) 
	{ 
	 swap(&harr[i], &harr[parent(i)]); 
	 i = parent(i); 
	} 
} 

// Decreases value of key at index 'i' to new_val. It is assumed that 
// new_val is smaller than harr[i]. 
void MinHeap::decreaseKey(int i, int new_val) 
{ 
	harr[i] = new_val; 
	while (i != 0 && harr[parent(i)] > harr[i]) 
	{ 
	    swap(&harr[i], &harr[parent(i)]); 
	    i = parent(i); 
	} 
} 

// Method to remove minimum element (or root) from min heap 
int MinHeap::extractMin() 
{ 
	if (heap_size <= 0) 
		return INT_MAX; 
	if (heap_size == 1) 
	{ 
		heap_size--; 
		return harr[0]; 
	} 

	// Store the minimum value, and remove it from heap 
	int root = harr[0]; 
	harr[0] = harr[heap_size-1]; 
	heap_size--; 
	MinHeapify(0); 

	return root; 
} 


// This function deletes key at index i. It first reduced value to minus 
// infinite, then calls extractMin() 
void MinHeap::deleteKey(int i) 
{ 
	 decreaseKey(i, INT_MIN); 
 	extractMin(); 
} 

// A recursive method to heapify a subtree with the root at given index 
// This method assumes that the subtrees are already heapified 
void MinHeap::MinHeapify(int i) 
{ 
	 int l = left(i); 
	 int r = right(i); 
	 int smallest = i; 
	 if (l < heap_size && harr[l] < harr[i]) 
		 smallest = l; 
	 if (r < heap_size && harr[r] < harr[smallest]) 
		 smallest = r; 
	 if (smallest != i) 
	 { 
		 swap(&harr[i], &harr[smallest]); 
		 MinHeapify(smallest); 
	 } 
} 

// A utility function to swap two elements 
void swap(int *x, int *y) 
{ 
	 int temp = *x; 
	 *x = *y; 
	 *y = temp; 
} 

// Driver program to test above functions 
int main() 
{ 
	MinHeap h(11); 
	h.insertKey(3); 
	h.insertKey(2); 
	h.deleteKey(1); 
	h.insertKey(15); 
	h.insertKey(5); 
	h.insertKey(4); 
	h.insertKey(45); 
	cout << h.extractMin() << " "; 
	cout << h.getMin() << " "; 
	h.decreaseKey(2, 1); 
	cout << h.getMin(); 
	return 0; 
} 

