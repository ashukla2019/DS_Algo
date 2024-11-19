// C++ implementation to check if a number 
// has bits in alternate pattern 

#Given an integer n > 0, the task is to find whether this integer has an alternate pattern in its bits representation. For example- 5 has an alternate pattern i.e. 101. 
Print “Yes” if it has an alternate pattern otherwise “No”. Here alternate patterns can be like 0101 or 1010. 

<bits/stdc++.h> 
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


