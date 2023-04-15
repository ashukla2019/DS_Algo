#include <iostream>
using namespace std;

int* selection_sort(int*p, int len)
{
	for(int i =0; i<len-1; i++)
	{
		for(int j = i+1; j<len-1; j++)
		{
			if(p[i]>p[j])
			{
				int temp = p[i];
				p[i] = p[j];
				p[j] = temp;
			}
		}
	}
	return p;
}

int* bubble_sort(int*p, int len)
{
	for(int i =0; i<len-1; i++)
	{
		for(int j = 0; j<=len-i-1; j++)
		{
			if(p[j]>p[j+1])
			{
				int temp = p[j];
				p[j] = p[j+1];
				p[j+1] = temp;
			}
		}
	}
	return p;
}

int main()
{
	int arr[] = {15, 10, 20, 5, 9, 25};
	int len = sizeof(arr)/ sizeof(int);
#if 0
	int* s_sort = selection_sort(arr, len);
	for(int i =0; i<len; i++)
	{
		cout<<"sorted array values:"<<s_sort[i]<<endl;
	}
#endif
	int* b_sort = bubble_sort(arr, len);
	for(int i =0; i<len; i++)
	{
		cout<<"sorted array values:"<<b_sort[i]<<endl;
	}	
	return 0;
}
