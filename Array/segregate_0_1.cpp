#include <iostream>
using namespace std;

/*
Segregate 0s and 1s in an array:
Input array   =  [0, 1, 0, 1, 0, 0, 1, 1, 1, 0] 
Output array =  [0, 0, 0, 0, 0, 1, 1, 1, 1, 1]
*/

void sortarr(int arr[], int length)
{

	int j= 0;
	for(int i=0; i< 10; i++) //O(n)
	{
		if(arr[i] == 1)
		{
			//count++;
		}
		else
		{
			arr[j++] = arr[i];
		}
	}
	for(int k=j; k<10; k++)//O(n)
	{
		arr[k] = 1;
	}
	for(int i=0; i<10; i++)
	{
	    cout<<arr[i]<<endl;   
	}
	
}


int main()
{
	int arr[] = {0, 1, 0, 1, 0, 0, 1, 1, 1, 0};
	int length = sizeof(arr)/sizeof(int);
	cout<<"length"<<length<<endl;
	sortarr(arr, length);
	return 0;
}

