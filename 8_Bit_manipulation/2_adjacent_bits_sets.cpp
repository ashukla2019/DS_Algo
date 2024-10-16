Given a number you have to check whether there is pair of adjacent set bit or not.

Input : N = 67
Output : Yes
There is a pair of adjacent set bit
The binary representation is 100011


//The expression n & (n << 1) or n & (n >> 1) returns true if n contains any 
//pair whose adjacent bits are 1
// Returns true if adjacent bits are set in a binary representation of `n`
/*

00101101    &               (n)
01011010                    left shift n by 1
~~~~~~~~
00001000                    (n & (n << 1))

*/
bool check(int n) 
{
    return n & (n << 1);
}
