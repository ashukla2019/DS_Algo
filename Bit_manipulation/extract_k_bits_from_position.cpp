/*Extract ‘k’ bits from a given position in a number:
Input : number = 171
             k = 5 
             p = 2
Output : The extracted number is 21

steps: 
1) Right shift number by p-1. 
2) Do bit wise AND of k set bits with the modified number. 
3) We can get k set bits by doing (1 << k) – 1.
*/
int bitExtracted(int number, int k, int p)
{
    return (((1 << k) - 1) & (number >> (p - 1)));
}
 