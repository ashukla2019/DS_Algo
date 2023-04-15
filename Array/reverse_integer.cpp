/*Reverse Integer:Given a signed 32-bit integer x, return x with 
//its digits reversed. If reversing x causes the value to go outside the signed 32-bit integer 
//range [-231, 231 - 1], then return 0.
/*
Input: x = 123
Output: 321
*/
int reverse(int x)
{
	long result = 0;
	while(x != 0)
	{
		result = result*10 + x % 10;
		x /= 10;
	}
	return (result > INT_MAX || result < INT_MIN)? 0 : result;
}
