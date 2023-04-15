//Check if adjacent bits are set in the binary representation of a number:
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