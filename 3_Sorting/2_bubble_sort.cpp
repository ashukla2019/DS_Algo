#include<bits/stdc++.h>
using namespace std;
 
int* bubble_sort(int arr[], int len)
{
    for(int i=0; i<len; i++)
    {
        for(int j=0; j<len-i; j++)
        {
            if(arr[j]>arr[j+1])
            {
                int temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }
    return arr;
}
 
 
int main()
{
    int arr[] ={10,2,31,24}; 
    int len = sizeof(arr)/sizeof(arr[0]);
    int* res=bubble_sort(arr, len);
    for(int i=0; i<len; i++)
    {
        std::cout<<res[i]<<endl;
    }
	return 0;
}
