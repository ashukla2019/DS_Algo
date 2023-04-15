//Hamming Distance:
Input: x = 1, y = 4
Output: 2
Explanation:
1   (0 0 0 1)
4   (0 1 0 0)
       ↑   ↑
The above arrows point to positions where the corresponding bits are different.

int hammingDistance(int x, int y) 
{
   int res =0;
   for(int i=0; i<32; ++i) 
   {
	   if((x &(1<<i) ^ (y &(1<<i))) !=0)
	   {
		   res++;
	   }
   }
	return res;
   
}