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

int main()
{
	int arr[] = {15, 10, 20, 5, 9, 25};
	int len = sizeof(arr)/ sizeof(int);

	int* s_sort = selection_sort(arr, len);
	for(int i =0; i<len; i++)
	{
		cout<<"sorted array values:"<<s_sort[i]<<endl;
	}
	return 0;
}
