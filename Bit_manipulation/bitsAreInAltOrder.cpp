// C++ implementation to check if a number 
// has bits in alternate pattern 
#include <bits/stdc++.h> 

using namespace std; 

// function to check if all the bits are set or not 
// in the binary representation of 'n' 
bool allBitsAreSet(unsigned int n) 
{ 
	// if true, then all bits are set 
	if (((n + 1) & n) == 0) 
		return true; 
	// else all bits are not set 
	return false; 
} 

// function to check if a number has bits in alternate 
// pattern 
bool bitsAreInAltOrder(unsigned int n) 
{ 
	unsigned int num = n ^ (n >> 1); 
	// to check if all bits are set in 'num' 
	return allBitsAreSet(num); 
} 

// Driver program to test above 
int main() 
{ 
	unsigned int n = 10; 
	if (bitsAreInAltOrder(n)) 
		cout << "Yes"; 
	else
		cout << "No"; 
	return 0; 
} 

// This code is contributed by Sania Kumari Gupta (kriSania804)
