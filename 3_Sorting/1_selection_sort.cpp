#include<bits/stdc++.h>
using namespace std;
 
int* selection_sort(int arr[], int len)
{
    for(int i=0; i<len; i++)
    {
        for(int j=i+1; j<len; j++)
        {
            if(arr[i]>arr[j])
            {
                int temp=arr[i];
                arr[i]=arr[j];
                arr[j]=temp;
            }
        }
    }
    return arr;
}
 
 
int main()
{
	int arr[] = {15, 10, 20, 5, 9, 25};
	int len = sizeof(arr)/ sizeof(int);
    int* res= buble_sort(arr, len);
    for(int it=0; it<len; it++)
        std::cout<<arr[it]<<endl;
	return 0;
}
