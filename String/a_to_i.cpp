//Convert string to int:
int myAtoi(string s) 
{
	int res =0;
	int sign =1;
	int i=0;

	if(s[0] == '-')
	{
		sign = -1;
		i++;
	}
	for(; s[i] != '\0'; ++i)
	{
		res = res*10 + s[i] - '0'; // s[i] - '0' -> convert character into num
	}
	return (sign*res);
}

int main()
{
    char str[] = "-123";
 
    // Function call
    int val = myAtoi(str);
    cout << val;
    return 0;
}
