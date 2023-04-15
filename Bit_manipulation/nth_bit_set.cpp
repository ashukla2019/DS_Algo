//Checking if bit at nth position is set or unset: 
//Left shift ‘1’ to given position and then ‘AND'(‘&’)
bool at_position(int num,int pos)
{
	bool bit = num & (1<<pos-1);
	return bit;
}
int main()
{
	int num = 5;
	int pos = 0;
	bool bit = at_position(num, pos);
	cout << bit << endl;
	return 0;
}