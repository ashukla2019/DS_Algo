//This file is for quicksort

#include <iostream>
using namespace std;

int split(int a[], int lower, int upper)
{
	int pivot = a[lower];
	int p = lower+1;
	int q = upper;
	int temp;
	while(q>=p)
	{
		while(a[p] < pivot)
		{
			p++;
		}
		while(a[q] > pivot)
		{
			q--;
		}
		//Swap element at p and q index
		if(q>p)
		{
			temp = a[p];
			a[p] = a[q];
			a[q] = temp;
		}
	}
	//swap pivot element and a[q]
	temp = a[lower];
	a[lower] = a[q];
	a[q] = temp;
	return q;
	
}

void quicksort(int a[], int lower, int upper)
{
	if(upper > lower)
	{
		int i = split(a, lower, upper);
		quicksort(a, lower, i-1);
		quicksort(a, i+1, upper);
	}
}

int main()
{
	int arr[] = {11,13,2,45,10,56,20};
	quicksort(arr, 0, 6);
	for(int i = 0; i<7; i++)
	{
		cout<<arr[i]<<endl;
	}
	return 0;
}
