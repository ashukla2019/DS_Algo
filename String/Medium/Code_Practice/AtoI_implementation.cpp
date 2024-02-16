String num="-12345"
Approach:
1) Check first digit/char is minus(-) or not, if yes then increment i++
2) Iterate through all characters: 12345= 0*10+1 1*10+2 12*10+3 .... convert char to num: str[i]-'0'	
-----------------------------------------------------------------------------------------------------
// A C++ program for
// implementation of atoi
#include <bits/stdc++.h>
using namespace std;

// A simple atoi() function
int myAtoi(char* str)
{
	// Initialize result
	int res = 0;

	// Initialize sign as positive
	int sign = 1;

	// Initialize index of first digit
	int i = 0;

	// If number is negative,
	// then update sign
	if (str[0] == '-') {
		sign = -1;

		// Also update index of first digit
		i++;
	}

	// Iterate through all digits
	// and update the result
	for (; str[i] != '\0'; i++)
		res = res * 10 + str[i] - '0';

	// Return result with sign
	return sign * res;
}

// Driver code
int main()
{
	char str[] = "-123";

	// Function call
	int val = myAtoi(str);
	cout << val;
	return 0;
}

// This is code is contributed by rathbhupendra
