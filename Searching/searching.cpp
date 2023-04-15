#include<iostream>
using namespace std;

//complexity: o(logn)
void binarySearch(int arr[], int lower, int upper, int num) 
{ 
    while (lower <= upper)
	{ 
        int mid = lower + upper / 2; 
  
        // Check if num is present at mid 
        if (arr[mid] == num) 
		{
            cout<<"number found at position"<<mid<<endl; 
		}
  
        // If number greater, ignore left half 
        if (arr[mid] < num) 
		{
            lower = mid + 1; 
		}	
  
        // If number is smaller, ignore right half 
        else
		{
           upper = mid - 1; 
		} 
	} 
}

//complexity: o(n)
void linearSearch(int* p, int num, int len)
{
	bool flag_found = false;
	for(int i=0; i<len; i++)
	{
		if(p[i] == num)
		{
			flag_found = true;
			break;
		}
	}
	if(true == flag_found)
	{
		cout<<"number found"<<endl;
	}
	else
	{
		cout<<"number not found"<<endl;
	}
}

int main()
{
	int arr[] = {10, 30, 50, 60, 70};
	int len = sizeof(arr)/sizeof(int);
	//linearSearch(arr, 11, len);
	binarySearch(arr, 0, 4, 50);
	return 0;
}