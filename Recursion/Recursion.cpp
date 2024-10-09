Recursion: When function makes call to itself until it mets basic condition.Base condition is required
to break the infinite loop.

Problems on Recursion:
1) printing name N times 
	void func( i, n )
	{
		if(i>n) 
			return;
		print(“Ankit”);
		func( i+1,N );
	}
	main()
	{
		int n;
		cin>>n;
		func(1,n);
	}
	Time Complexity: O(N) { Since the function is being called n times, and for each function, we have only one printable line that takes O(1) time, so the cumulative time complexity would be O(N) }
	Space Complexity: O(N) { In the worst case, the recursion stack space would be full with all the function calls waiting to get completed and that would make it an O(N) recursion stack space }.
-----------------------------------------------------------------------------------------------
2) Print N to 1 using Recursion
	void func( i, n )
	{
		if(i<1) return;
		print(i);
		func( i-1,N );
	}
	main()
	{
		int n;
		input(n);
		func(n,n);
	}
	Time Complexity: O(N) 
	Space Complexity: O(N)
-----------------------------------------------------------------------------------------------
3) Alternate Approach for printing integers from N to 1 (using Backtracking)	
	void func( i, n )
	{
		if(i>n) return;
		f( i+1,N );
		print(i);

	}
	main()
	{
		int n;
		cin>>n;
		f(1,n);
	}
	o/p: 3,2,1
	Recursion tree:
			f(1,3)
		f(2,3)
	f(3,3)	
	Time Complexity: O(N) 
	Space Complexity: O(N)
-----------------------------------------------------------------------------------
4) Sum of first N numbers
	f(i,sum) //f(3,0), next call: f(2,3), next call: f(1,5), f(0,6)
	{
		if(i<1) //f(0,6) => it will be executed and will print sum and return from recursion
		{
			cout<<sum<<endl;
			return;
		}
		f(i-1, sum+i); //f(2, 3) next call: f(1, 3+2), f(0,5+1)
	}
	main()
	{
		int n;
		cin>>n;
		f(3,0) //let's assume n=3 and initially sum is passed with value 0
	}
	O/P: 6
------------------------------------------------------------------------------------
5) Factorial Number: fact(3) = 3*fact(2) => 2*fact(1) =>3*2*1=6

	int fact(int n)
	{
		if(n==0)
			return 1;
		return n*fact(n-1);
	}
	int main()
	{
		cout<<fact(4);
	}
	O/P:24
	Time Complexity: O(N) 
	Space Complexity: O(N)
------------------------------------------------------------------------------------
6) Reverse array:
arr[]={1,2,3,4,5} => {5,4,3,2,1}
	void reverse(int i, int arr[], int n)
	{
		if(i>=n/2)
			return;
		swap(arr[i], arr[n-1-i]);
		reverse(i+1,arr,n);
	}
	int main()
	{
		int arr[]={1,2,3,4,5};
		reverse(0,arr,5);
		for(auto it: arr)
		{
			cout<<it<<endl;
		}
	
	}
	Time Complexity: O(N) 
	Space Complexity: O(N)
----------------------------------------------------------------------------------------	
7) Fibonacci series: 0,1,1,2,3,5,8,13......

	int fib(int n)
	{
		if(n<2)
			return n;
		return fib(n-1)+fib(n-2);
	}
	int main()
	{
		cout<<fib(6);
	}
	O/P:8
	Time Complexity: O(2^N) { This problem involves two function calls for each iteration which further expands to 4 function calls and so on which makes worst-case time complexity to be exponential in nature }.
	Space Complexity: O(N) { At maximum there could be N function calls waiting in the recursion stack since we need to calculate the Nth Fibonacci number for which we also need to calculate (N-1) Fibonacci numbers before it }.
------------------------------------------------------------------------------------------	
8) Print all subsequences:Contiguous or non contiguous sequences which follows the order but subarray is contiguous.
arr[]={3,1,2}
subsequences: {3},{1},{2}, {3,1}, {1,2}, {3,2}->this one is non contiguous, {3,1,2}
	void printSubArray(int index, vector<int>&ds, int arr[], int n)
	{
		//Base case: Starting picking and non picking of element from 0th index and will reach till n-1th
		//we should return back when reached to nth index 
		if(index ==n)
		{
			for(auto it: ds)
			{
				cout<<it<<endl;
			}
			return;
		}
		//Not pick:
		printSubArray(index+1, ds, arr, n);
		
		//Pick:
		ds.push_back(arr[index]);
		printSubArray(index+1, ds, arr, n)
		ds.pop_back();
	}
	int main()
	{
		int arr[]={3,1,2};
		vector<int>ds;
		printSubArray(i,ds,arr, n);
	}
	Time Complexity: O(2^N) { This problem involves two function calls for each iteration which further expands to 4 function calls and so on which makes worst-case time complexity to be exponential in nature }.
	Space Complexity: O(N) 
---------------------------------------------------------------------------	
9) Print subsequences whose sum is k:
arr[]={1,2,1};
	
	void printSubArrayWithGivenSum(int index, int arr[], int n, vector<int>& ds, int givenSum, int sum)
	{
		//base case:
		if(index==n)
		{
			if(sum==givenSum)
			{
				for(auto it: ds)
				{
					cout<<it<<endl;
				}
			}
			return;
		}
		
		//Not pick:
		printSubArrayWithGivenSum(index+1, arr, n, ds, givenSum, sum);
		
		//pick:
		ds.push_back(arr[index]);
		sum += arr[index];
		printSubArrayWithGivenSum(index+1, arr, n, ds, givenSum, sum);
		sum -= arr[index];
		ds.pop_back();
	}
	int main()
	{
		int arr[]={1,2,1};
		int n=3;
		int givenSum=2;
		vector<int>ds;
		int sum=0;
		printSubArrayWithGivenSum(0, arr, n, ds, givenSum, sum);
	}
	Time Complexity: O(2^N)
	Space Complexity: O(N)
-----------------------------------------------------------------------------	
10) Count the subsequences with sum k
	int countSubArrayWithGivenSum(int index, int arr[], int n, int givenSum, int sum)
	{
		//base case:
		if(index==n)
		{
			if(sum==givenSum)
			{
				return 1;
			}
			return 0;
		}
		
		//Not pick:
		int l = countSubArrayWithGivenSum(index+1, arr, n, ds, givenSum, sum);
		
		//pick:
		sum += arr[index];
		int r= countSubArrayWithGivenSum(index+1, arr, n, ds, givenSum, sum);
		sum -= arr[index];
		
		return l+r;
		
	}
	int main()
	{
		int arr[]={1,2,1};
		int n=3;
		int givenSum=2;
		int sum=0;
		cout<<countSubArrayWithGivenSum(0, arr, n, givenSum, sum)<<endl;
	}
	Time Complexity: O(2^N)
	Space Complexity: O(N)
---------------------------------------------------------------------------------
11) Merge Sort:



---------------------------------------------------------------------------------
12) Quick sort:	


---------------------------------------------------------------------------------
13) Combination Sum-I:
Input: array = [2,3,6,7], target = 7
Output: [[2,2,3],[7]]
Explanation: 2 and 3 are candidates, and 2 + 2 + 3 = 7. Note that 2 can be used multiple times.
             7 is a candidate, and 7 = 7.
             These are the only two combinations.
			 
			 
------------------------------------------------------------------------------------
14) Combination Sum-II			 



--------------------------------------------------------------------------------------
15) Subset Sum-I 



-------------------------------------------------------------------------------------
16) Subset Sum-II




------------------------------------------------------------------------------------------
