//Swap two numbers:
void swap(int a, int b)
{
	a = a ^ b;
	b = b ^ a; // b = b^a^b => a
	a = a ^ b; // a = a^b^a => b
}
int main()
{
	swap(4,5);
	return 0;
}