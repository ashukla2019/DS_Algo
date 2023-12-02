// A function to check if a string str is palindrome
string isPalindrome(string S)
{
	int length = S.length();
    // Iterate over the range [0, N/2]
    for (int i = 0; i < length / 2; i++) 
	{
 
        // If S[i] is not equal to
        // the S[N-i-1]
        if (S[i] != S[length - i - 1]) 
		{
            // Return No
            return "No";
        }
    }
    // Return "Yes"
    return "Yes";
}

