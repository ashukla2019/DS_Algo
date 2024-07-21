1) Find the Largest element in an array:
arr[] = {2,5,1,3,0}; => largest=5

	Brute Force Approach:
	We can sort the array in ascending order, hence the largest element will be at the last index of the array. 
	Sort the array in ascending order.
	Print the (size of the array -1)th index.
	largest=arr[0]
	
	Time Complexity: O(N*log(N))
	Space Complexity: O(n)
	
	Optimal Approach: We can maintain a max variable that will update whenever the current value is greater 	  than the value in the max variable. 
	Create a max variable and initialize it with arr[0].
	Use a for loop and compare it with other elements of the array
	If any element is greater than the max value, update max value with the element’s value
	Print the max variable.
	max = arr[0];
    for (i = 0; i < n; i++) 
    {
    	if (max < arr[i]) 
    	{
      		max = arr[i];
      	}
    }
    return max;
    Time Complexity: O(N)
	Space Complexity: O(1)
	
-------------------------------------------------------------------------------------------------
2) Second largest element in array:
 arr[]=[1,2,4,7,7,5]; => 5
 
 	Brute Force Approach:
 	Sort the array in ascending order
 	arr[n-1] will be largest and arr[n-2] might be second largest if no duplicate element in array
 	if duplicate elements present then need to traverse array from n-2th index to 0 to find
 	if arr[i] != largest, that would be second largest element.
	
	sort(arr,arr+n); =>O(NlogN)
	for(i=n-2; i>0; i--)
    {
    	if(arr[i] != largest)
    	{
    		secondLargest=arr[i];
    		break;
    	}
    }
    Time Complexity: O(NlogN + N), For sorting the array and iterate for second largest
	Space Complexity: O(1)
	
	Better Approach:
	Find the largest element in the array in a single traversal
	After this, we would find the largest element which is just smaller than the largest element 
	
	largest=arr[0];
	//First pass:find largest
	for(i=0; i<n; i++)
	{
		if(arr[i]>largest)
		{
			largest=arr[i];
		}
	}
	//Second pass: find second largest
	secondlargest=INT_MIN
	for(i=0; i<n; i++)
	{
		if(arr[i]>secondLargest && arr[i]!= largest)
		{
			secondLargest=arr[i];
		}
	}
	Time Complexity: O(N + N) =>O(2n)
	Space Complexity: O(1)
	
	Optimal Approach:
	If the current element is larger than ‘large’ then update second_large and large variables
	Else if the current element is larger than ‘second_large’ then we update the variable second_large.
	Once we traverse the entire array, we would find the second largest element in the variable second_large.
	Here’s a quick demonstration of the same.
	largest=arr[0], secondLargest=INT_MIN
	for(i=1; i<n; i++)
	{
		if(arr[i]>largest)
		{
			secondLargest=largest;
			largest=arr[i];
		}
		else if(arr[i]<largest && arr[i]>secondLargest)
		{
			secondLargest=arr[i];
		}
	}
	Time Complexity: O(N) 
	Space Complexity: O(1)
----------------------------------------------------------------------------------------------
3) Check if array is sorted:
array[] = {1,2,3,4,5} => yes

	for(i=1; i<n; i++)
	{
		if(arr[i]<arr[i-1])
		{
			return false;
		}
	}
	return true;
	Time Complexity: O(N) 
	Space Complexity: O(1)	
-------------------------------------------------------------------------------------------------
4) Remove duplicate in-place from sorted array:
arr[1,1,2,2,2,3,3] => arr[1,2,3,_,_,_,_]

	Brute Force Approach:
	Declare a HashSet.
	Run a for loop from starting to the end.
	Put every element of the array in the set.
	Store size of the set in a variable K.
	Now put all elements of the set in the array from the starting of the array.
	Return K.
	
	set < int > set;
  	for (i = 0; i < n; i++) =>O(nlogn)
  	{
    	set.insert(arr[i]);
  	}
  	int k = set.size();
  	int j = 0;
  	for (int x: set) => O(n)
  	{
    	arr[j++] = x;
  	}
  	return k;
  	Time complexity: O(n*log(n))+O(n)
	Space Complexity: O(n) 
	
	Optimal Approach: Using two pointers
	Take a variable i as 0;
	Use a for loop by using a variable ‘j’ from 1 to length of the array.
	If arr[j] != arr[i], increase ‘i’ and update arr[i] == arr[j].
 	After completion of the loop return i+1, i.e size of the array of unique elements.
 	
 	i = 0;
    for (j = 1; j < n; j++) 
    {
    	if (arr[i] != arr[j]) 
    	{
      		i++;
      		arr[i] = arr[j];
    	}
  	}
  	return i + 1;
  	Time Complexity: O(N)
	Space Complexity: O(1)
-------------------------------------------------------------------------------------------
5) Left rotate an array by one index:
 N = 5, array[] = {1,2,3,4,5} => {2,3,4,5,1};
 	Optimal Approach:
 	At first, we have to shift the array towards the left so, we store the value of the first index in a    	variable (temp).
	Then we iterate the array from the 0th index to the n-1th index(why n-1 i will explain it below)
	And then store the value present in the next index to the current index like this :
	arr[i] = arr[i+1]
	At last, put the value of variable x in the last index of the array.
	
	temp = arr[0]; // storing the first element of array in a variable
    for (i = 0; i < n - 1; i++) 
    {
    	arr[i] = arr[i + 1];
  	}
  	arr[n - 1] = temp; // 
 	Time Complexity: O(n), as we iterate through the array only once.
	Space Complexity: O(1) as no extra space is used
------------------------------------------------------------------------------------
6) Left rotate an array by d places:
Input: N = 7, array[] = {1,2,3,4,5,6,7} , d = 3, Output: 4 5 6 7 1 2 3	

	Brute Force Approach:
	First, we will perform (d%n) to get the effective number of rotations.
	Copying first d elements, in the temporary array
	Shift last (n-d) elements to the left by d places in the given array
	Place the elements of the temporary array in the last d places of the given array
	
	d = d % n;
    //checking if d is a multiple of n:
    if (d == 0) return;

    int temp[d]; // temporary array

    //step 1: Copying first d elements
    // in the temporary array:
    for (int i = 0; i < d; i++) {
        temp[i] = arr[i];
    }

    // step 2: Shift last (n-d) elements
    // to the left by d places in the given array:
    for (int i = d; i < n; i++) {
        arr[i - d] = arr[i];
    }

    //step 3: Place the elements of the temporary
    // array in the last d places of the given array:
    for (int i = n - d; i < n; i++) {
        arr[i] = temp[i - (n - d)];
    }
	Time Complexity: O(d)+O(n-d)+O(d) = O(n+d), where n = size of the array, d = the number of rotations. Each 		term represents each loop used in the code.
	Space Complexity: O(d) extra space as we are using a temporary array of size d.
 	
	Optimal Approach:
	Step 1: Reverse the subarray with the first d elements (reverse(arr, arr+d)).
	Step 2: Reverse the subarray with the last (n-d) elements (reverse(arr+d, arr+n)).
	Step 3: Finally reverse the whole array (reverse(arr, arr+n)).
	
	reverse(arr, arr + d); => {3,2,1}
    reverse(arr + d, arr + n); => {7,6,5,4}
    reverse(arr, arr + n); => 4,5,6,7,1,2,3
    
    Time Complexity: O(d)+O(n-d)+O(n) = O(2*n), where n = size of the array, d = the number of rotations. Each 		term corresponds to each reversal step.
	Space Complexity: O(1) since no extra space is required.
	
---------------------------------------------------------------------------------------
7) Move zeros to end of the array:
 arr[]=1 ,0 ,2 ,3 ,0 ,4 ,0 ,1, Output: 1 ,2 ,3 ,4 ,1 ,0 ,0 ,0	

	Brute Force Approach:
	Create temporary array to store non zero elements
	copy non-zero elements from original -> temp array
	number of non-zero elements(nz = temp.size())
	copy elements from temp fill first nz fields of original array
	fill rest of the cells with 0
	//temporary array:
    vector<int> temp;
    //copy non-zero elements
    //from original -> temp array:
    for (int i = 0; i < n; i++) {
        if (a[i] != 0)
            temp.push_back(a[i]);
    }

    // number of non-zero elements.
    int nz = temp.size();

    //copy elements from temp
    //fill first nz fields of
    //original array:
    for (int i = 0; i < nz; i++) {
        a[i] = temp[i];
    }

    //fill rest of the cells with 0:
    for (int i = nz; i < n; i++) {
        a[i] = 0;
    }
    return a; 
 	Time Complexity: O(N) + O(X) + O(N-X) ~ O(2*N), where N = total no. of elements,
	X = no. of non-zero elements, and N-X = total no. of zeros.
	Reason: O(N) for copying non-zero elements from the original to the temporary array. O(X) for again 	   		copying it back from the temporary to the original array. O(N-X) for filling zeros in the original array. 		So, the total time complexity will be O(2*N).

	Space Complexity: O(N), as we are using a temporary array to solve this problem and the maximum size of 	the array can be N in the worst case.
	Reason: The temporary array stores the non-zero elements. In the worst case, all the given array elements 		will be non-zero.
	
	Optimal Approach:
	count=0;
    for(i=0; i<n; j++)
    {
    	if(a[i] !=0) //Checking non_zero element and storing in array with new index count.
    	{
			arr[count++]=arr[i];
    	}
    }
    while(count<n) //count upto n value will have zeros so store them
    {
    	a[count++] = 0;
    }
    return a;
    
	Time Complexity: O(N), N = size of the array.
	Space Complexity: O(1) as we are not using any extra space to solve this problem. 
	
------------------------------------------------------------------------------------------------
8) Linear search:
Input: arr[]= 1 2 3 4 5, num = 3, Output: 2, Explanation: 3 is present in the 2nd index	
	for i=0;i<n;i++){
        
        if(arr[i] == element){
            
            // Return index, if the given element 
            // matches with any element of array.
            return i;
        }
    }
    
    // If the given number not found.
    return -1; 
	Time Complexity: O(N) { At the worst case, the whole array would be traversed i.e N elements }.
	Space Complexity: O(1) { There is no extra space being used in this approach }.
-------------------------------------------------------------------------------------------
9) Union of Two Sorted Arrays:
n = 5,m = 5. arr1[] = {1,2,3,4,5} , arr2[] = {2,3,4,4,5} , Output: {1,2,3,4,5}	
	Brute Force Approach:
	set<int>st;
	vector<int>Union;
	for(i=0; i<n; i++) =>O(nlogn)
	{
		st.insert(arr[i])
	}
	for(i=0; i<m; i++) =>O(mlogm)
	{
		st.insert(arr[i])
	}
	for (auto & it: s)
    	Union.push_back(it);
    return Union;
	Time Compleixty : O( (m+n)log(m+n) ) . Inserting an element in a set takes logN time, where N is no of 		elements in the set. At max set can store m+n elements {when there are no common elements and elements in 		arr,arr2 are distntict}. So Inserting m+n th element takes log(m+n) time. Upon approximation across 	      inserting all elements in worst, it would take O((m+n)log(m+n) time.

	Using HashSet also takes the same time, On average insertion in unordered_set takes O(1) time but sorting 		the union vector takes O((m+n)log(m+n))  time. Because at max union vector can have m+n elements.

	Space Complexity : O(m+n) {If Space of Union ArrayList is considered} 	
	
	Optimal Approach:Two Pointers
	
	Let’s traverse the arr1 and arr2 using pointers i and j and insert the distinct elements found into the 	union vector.
	While traversing we may encounter three cases.

	case-1:arr1[ i ] == arr2[ j ] 
	Here we found a common element, so insert only one element in the union. Let’s insert arr[i] in union and 		increment i.

	NOTE: There may be cases like the element to be inserted is already present in the union, in that case, we 		are inserting duplicates which is not desired. So while inserting always check whether the last element in 		the union vector is equal or not to the element to be inserted. If equal we are trying to insert 		    	duplicates, so don’t insert the element, else insert the element in the union. This makes sure 		that we are not inserting any duplicates in the union because we are inserting elements in sorted order.
	case-2:arr1[ i ]  < arr2[ j ]
	arr1[ i ] < arr2[ j ] so we need to insert arr1[ i ] in union.IF last element in  union vector is not 		equal to arr1[ i ],then insert in union else don’t insert. After checking Increment i.
	case-3:arr1[ i ] > arr2[ j ]
	arr1[ i ] > arr2[ j ] so we need to insert arr2[ j ] in union. IF the last element in the union vector is 		not equal to arr2[ j ], then insert in the union, else don’t insert. After checking Increment j. After 		traversing if any elements are left in arr1 or arr2 check for condition and insert in the union.
	
	vector < int > Union; // Uninon vector
  	while (i < n && j < m) 
  	{
    	if (arr1[i] <= arr2[j]) // Case 1 and 2
    	{
      		if (Union.size() == 0 || Union.back() != arr1[i])
        		Union.push_back(arr1[i]);
      			i++;
    	} 
    	else // case 3
    	{
      		if (Union.size() == 0 || Union.back() != arr2[j])
        		Union.push_back(arr2[j]);
      			j++;
    	}
  	}
  	while (i < n) // IF any element left in arr1
  	{
    	if (Union.back() != arr1[i])
      		Union.push_back(arr1[i]);
    	i++;
  }
  while (j < m) // If any elements left in arr2
  {
    if (Union.back() != arr2[j])
    	Union.push_back(arr2[j]);
    	j++;
  }
  return Union;
  Time Complexity: O(m+n), Because at max i runs for n times and j runs for m times. When there are no common 	elements in arr1 and arr2 and all elements in arr1, arr2 are distinct. 

  Space Complexity : O(m+n) {If Space of Union ArrayList is considered}
  
 ------------------------------------------------------------------------------------
 10) Missing Numbers:
 Input Format: N = 5, array[] = {1,2,4,5}, Result: 3
 	Brute Force Approach:
 	We will run a loop(say i) from 1 to N.
	For each integer, i, we will try to find it in the given array using linear search.
	For that, we will run another loop to iterate over the array and consider a flag variable to indicate if 		the element exists in the array. Flag = 1 means the element is present and flag = 0 means the element is 		missing.
	Initially, the flag value will be set to 0. While iterating the array, if we find the element, we will set 		the flag to 1 and break out from the loop.
	Now, for any number i, if we cannot find it, the flag will remain 0 even after iterating the whole array 		and we will return the number.
 	 // Outer loop that runs from 1 to N:
    for (int i = 1; i <= N; i++) {

        // flag variable to check
        //if an element exists
        int flag = 0;

        //Search the element using linear search:
        for (int j = 0; j < N - 1; j++) {
            if (a[j] == i) {

                // i is present in the array:
                flag = 1;
                break;
            }
        }

        // check if the element is missing
        //i.e flag == 0:

        if (flag == 0) return i;
    }
    Time Complexity: O(N2), where N = size of the array+1.
	Reason: In the worst case i.e. if the missing number is N itself, the outer loop will run for N times, and 		for every single number the inner loop will also run for approximately N times. So, the total time 		    	complexity will be O(N2).

    Space Complexity: O(1)  as we are not using any extra space.
    
    Better Approach: Using hashing
    The range of the number is 1 to N. So, we need a hash array of size N+1 (as we want to store the frequency 		of N as well).
	Now, for each element in the given array, we will store the frequency in the hash array.
	After that, for each number between 1 to N, we will check the frequencies. And for any number, if the 		frequency is 0, we will return it.
	int hash[N + 1] = {0}; //hash array

    // storing the frequencies:
    for (int i = 0; i < N - 1; i++)
        hash[a[i]]++;

    //checking the freqencies for numbers 1 to N:
    for (int i = 1; i <= N; i++) {
        if (hash[i] == 0) {
            return i;
        }
    }

    // The following line will never execute.
    // It is just to avoid warnings.
    return -1;
	Time Complexity: O(N) + O(N) ~ O(2*N),  where N = size of the array+1.
	Reason: For storing the frequencies in the hash array, the program takes O(N) time complexity and for 		checking the frequencies in the second step again O(N) is required. So, the total time complexity is O(N) 		+ O(N).

	Space Complexity: O(N), where N = size of the array+1. Here we are using an extra hash array of size N+1.
	
	Optimal Approach:
	Sum of first N numbers(S1) = (N*(N+1))/2
	Sum of all array elements(S2) = i = 0n-2a[i]
	The missing number = S1-S2
	
	 //Summation of first N numbers:
    int sum = (N * (N + 1)) / 2;

    //Summation of all array elements:
    int s2 = 0;
    for (int i = 0; i < N - 1; i++) {
        s2 += a[i];
    }

    int missingNum = sum - s2;
    return missingNum;
	Time Complexity: O(N), where N = size of array+1.
	Reason: Here, we need only 1 loop to get the sum of the array elements. The loop runs for approx. N times. 		So, the time complexity is O(N).

	Space Complexity: O(1) as we are not using any extra space.
--------------------------------------------------------------------------------------------
11) Max. Consecutive 1's:
Input: prices = {1, 1, 0, 1, 1, 1}, Output: 3	

	Approach:
	We maintain a variable count that keeps a track of the number of consecutive 1’s while traversing the 		array. The other variable max_count maintains the maximum number of 1’s, in other words, it maintains the 		answer.

	We start traversing from the beginning of the array. Since we can encounter either a 1 or 0 there can be 		two situations:-

	If  the value at the current index is equal to 1 we increase the value of count by one. After updating  	the count variable if it becomes more than the max_count  update the max_count.
	If the value at the current index is equal to zero we make the variable count as 0 since there are no more 		consecutive ones.

	 int cnt = 0;
      int maximum = 0;
      for (int i = 0; i < nums.size(); i++) 
      {
        if (nums[i] == 1) 
        {
        
          cnt++;
        } else 
        {
          cnt = 0;
        }

        maximum = max(maximum, cnt);
      }
      return maxi;
    }
    Time Complexity: O(N) since the solution involves only a single pass.
	Space Complexity: O(1) because no extra space is used.
------------------------------------------------------------------------------------------
12) Find the number appeared once:
arr[] = {2,2,1}, Result: 1
	Better Approach:Using Hashing
	First, we will find the maximum element(say maxElement) to know the size of the hash array.
	Then we will declare a hash array of size maxElement+1.
	Now, using another loop we will store the elements of the array along with their frequency in the hash 		array. (i.e. hash[arr[i]]++)
	After that, using another loop we will iterate over the hash array, and try to find the element for which 		the frequency is 1, and finally, we will return that particular element.
	//size of the array:
    int n = arr.size();

    // Declare the hashmap.
    // And hash the given array:
    map<int, int> mpp;
    for (int i = 0; i < n; i++) {
        mpp[arr[i]]++;
    }

    //Find the single element and return the answer:
    for (auto it : mpp) {
        if (it.second == 1)
            return it.first;
    }

    //This line will never execute
    //if the array contains a single element.
    return -1;
	Time Complexity: O(N*logM) + O(M), where M = size of the map i.e. M = (N/2)+1. N = size of the array.
	Reason: We are inserting N elements in the map data structure and insertion takes logM time(where M = size 		of the map). So this results in the first term O(N*logM). The second term is to iterate the map and search 		the single element. In Java, HashMap generally takes O(1) time complexity for insertion and search. In 		that case, the time complexity will be O(N) + O(M).

	Note: The time complexity will be changed depending on which map data structure we are using. If we use 	unordered_map in C++, the time complexity will be O(N) for the best and average case instead of O(N*logM). 		But in the worst case(which rarely happens), it will be nearly O(N2).
	Space Complexity: O(M) as we are using a map data structure. Here M = size of the map i.e. M = (N/2)+1.
	
	Optimal Approach: Using XOR: 
	Assume the given array is: [4,1,2,1,2]
	XOR of all elements = 4^1^2^1^2
      = 4 ^ (1^1) ^ (2^2)
      = 4 ^ 0 ^ 0 = 4^0 = 4
	Hence, 4 is the single element in the array.
	 int n = arr.size();

    // XOR all the elements:
    int xorr = 0;
    for (int i = 0; i < n; i++) {
        xorr = xorr ^ arr[i];
    }
    return xorr;
	Time Complexity: O(N), where N = size of the array.
	Reason: We are iterating the array only once.
	Space Complexity: O(1) as we are not using any extra space.
---------------------------------------------------------------------------------------------------
13) Longest subarray with K sum:
Input Format: N = 3, k = 5, array[] = {2,3,5}, Result: 2, Explanation: The longest subarray with sum 5 is {2, 3}. And its length is 2.
	Subarray: Contiguous part of array Ex:{2,3}, {3,5}, {2,3,5}
	Subsequence: {2,5}
	Brute Force Approach:
	First, we will run a loop(say i) that will select every possible starting index of the subarray. The 		possible starting indices can vary from index 0 to index n-1(n = size of the array).
	Inside the loop, we will run another loop(say j) that will signify the ending index of the subarray. For 	every subarray starting from the index i, the possible ending index can vary from index i to n-1(n = size 	of the array).
	After that for each subarray starting from index i and ending at index j (i.e. arr[i….j]), we will run 		another loop to calculate the sum of all the elements(of that particular subarray).
	If the sum is equal to k, we will consider its length i.e. (j-i+1). Among all such subarrays, we will 		consider the maximum length by comparing all the lengths.
	int len = 0;
    for (int i = 0; i < n; i++) { // starting index
        for (int j = i; j < n; j++) { // ending index
            // add all the elements of
            // subarray = a[i...j]:
            long long s = 0;
            for (int K = i; K <= j; K++) {
                s += a[K];
            }

            if (s == k)
                len = max(len, j - i + 1);
        }
    }
    return len;
	Time Complexity: O(N3) approx., where N = size of the array.
	Reason: We are using three nested loops, each running approximately N times.
	Space Complexity: O(1) as we are not using any extra space.
 
	
