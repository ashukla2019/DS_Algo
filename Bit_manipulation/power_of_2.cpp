//Check if number is power of 2:
//Ex: n = 4 => binary(00000100)
//n-1 => binary(00000011)
//n&(n1) => 00000000
bool isPowerOfTwo(int n) 
{
	return n>0  && !(n & n - 1); //if n = 0 then need to check if n>0 as well
}