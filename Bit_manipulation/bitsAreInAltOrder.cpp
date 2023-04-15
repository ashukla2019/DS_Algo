// function to check if a number has bits in alternate pattern then all will be 1 
//for n and n>>1. pattern: we know xor of 0 and 1 will be 1, if alternate bits are
bool bitsAreInAltOrder(unsigned int n)
{
    unsigned int num = n ^ (n >> 1); 
    // to check if all bits are set in 'num'
    return allBitsAreSet(num);
}