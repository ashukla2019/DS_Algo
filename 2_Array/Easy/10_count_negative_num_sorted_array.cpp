Count the negative numbers in sorted array: 
vector<int>arr[-3,-2,-1,0,1,2,3]
O/P: 3
-------------------------------------------------------------------------------------------------------------
Analysis
Time Complexity: O(n)
Space Complexity: O(1)

int getNegativeNumbersCount(vector<int> &arr) 
{
   int countNegative = 0;
   for (int i = 0; i < arr.size(); i++) 
   {
       if (arr[i] < 0) 
       {
           countNegative++;
       }
   }
   return countNegative;
}  

---------------------------------------------------------------------------------------------------------- 
Analysis
Time Complexity: O(log(n))
Space Complexity: O(1)

int binarySearch (vector<int> arr, int low, int high) 
{
   if (high > low) 
   {
       int mid = (high + low) / 2;
       if (arr[mid] < 0 && arr[mid + 1] >= 0) 
       {
           return mid;
       } else if (arr[mid] >= 0 && arr[mid + 1] >= 0) 
       {
           return binarySearch(arr, 0, mid);
       } else 
       {
           return binarySearch(arr, mid + 1, high);
       }
   }
   return -1;
}
int getNegativeNumbersCount(vector<int> &arr) 
{
   if (arr[0] >= 0) 
   {
		return 0;
	}
   if (arr[arr.size()-1] < 0) 
   {
		return arr.size();
	}
   return binarySearch (arr, 0, arr.size() - 1) + 1; //index + 1
}  
  
