//convert number into bits
void convertBin(int num)
{
	// Size of an integer is assumed to be 32 bits 
    for (int i = 31; i >= 0; i--) { 
        int k = 1 << i; 
        if (k & num) 
            std::cout << "1"; 
        else
            std::cout << "0"; 
    } 
}
int main(int argc, char* argv[])
{
	convertBin(3);
	return 0;
}
