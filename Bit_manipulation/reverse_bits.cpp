/*
    Reverse bits of a given integer
    Ex. n = 10011100 -> 00111001 = 57

    Shift into result & shift out of n

    Time: O(1)
    Space: O(1)
*/

uint32_t  reverseBits(uint32_t n) 
{
    uint32_t result= 0;
    for(int i=0; i<32; i++)
    {
        int bit = n>>i &1 ;
        result |= bit<<(31-i);
    }
    
    return result;
}

