//get a bit from a variable
#define GETBIT(var, bit)	(((var) >> (bit-1)) & 1)

//set a bit to 1
#define SETBIT(var, bit)	var |= (1 << (bit-1))

//set a bit to 0
#define CLRBIT(var, bit)	var &= (~(1 << (bit-1)))
