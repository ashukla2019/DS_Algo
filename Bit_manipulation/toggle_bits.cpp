//Toggling a bit at nth position:
//Toggling means to turn bit ‘on'(1) if it was ‘off'(0) and to turn ‘off'(0) if it was ‘on'(1) previously.
// First step is to shift 1,Second step is to XOR with given number
void toggle(int &num, int pos)
{
	num ^= (1 << pos-1);
}
int main()
{
	int num = 4;
	int pos = 1;
	toggle(num, pos);
	cout << num << endl;
	return 0;
}