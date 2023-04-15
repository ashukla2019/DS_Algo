//Number of 1 Bits is also known as hammingWeight:
int hammingWeight(uint32_t n) 
{
	int sum = 0;
	for(int i=0; i<=31; i++)
	{
		int k = 1<<i;
		if(n & k)
		{
			sum += 1;
		}
	}
	return sum;
}
