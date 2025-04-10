------------------------------------------------EASY-----------------------------------------------------------
1) Linear search:
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
-----------------------------------------------------------------------------------------------------
2) Find the Largest element in an array:
arr[] = {2,5,1,3,0}; => largest=5

	Brute Force Approach:
	We can sort the array in ascending order, hence the largest element will be at the last index of the array. 
	Sort the array in ascending order.
	Print the (size of the array -1)th index.
	largest=arr[0]
	
	Time Complexity: O(N*log(N))
	Space Complexity: O(1)
	
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
3) Second largest element in array:
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
4) Check if array is sorted:
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
5) Remove duplicate in-place from sorted array:
arr[1,1,2,2,2,3,3] => arr[1,2,3,_,_,_,_]

	Brute Force Approach:
	Declare a HashSet.
	Run a for loop from starting to the end.
	Put every element of the array in the set.
	Store size of the set in a variable K.
	Now put all elements of the set in the array from the starting of the array.
	Return K.
	
	int removeDuplicates(vector<int>& nums) {
    	set < int > myset;
    	int n = nums.size();
  	for (int i = 0; i < n; i++) 
  	{
    	myset.insert(nums[i]);
  	}
  	int k = myset.size();
  	int j = 0;
  	for (int x: myset)
  	{
    	nums[j++] = x;
  	}
  	return k;
    }
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
--------------------------------------------------------------------------------------
6) Missing Numbers:
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
----------------------------------------------------------------------------------------
7) Max. Consecutive 1's:
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
8) Find the number appeared once:
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
	
-----------------------------------------------------------------------------------
9) Leaders in an Array: Given an array, print all the elements which are leaders. 
A Leader is an element that is greater than all of the elements on its right side in the array.	
arr = [4, 7, 1, 0] => 7 1 0
	Brute Force Approach:
	vector<int> printLeadersBruteForce(int arr[], int n) {

  vector<int> ans;
  
  for (int i = 0; i < n; i++) {
    bool leader = true;

    //Checking whether arr[i] is greater than all 
    //the elements in its right side
    for (int j = i + 1; j < n; j++)
      if (arr[j] > arr[i]) {
          
        // If any element found is greater than current leader
        // curr element is not the leader.
        leader = false;
        break;
      }

    // Push all the leaders in ans array.
    if (leader)
    ans.push_back(arr[i]);

   }
  
   return ans;
   }
   Time Complexity: O(N^2) { Since there are nested loops being used, at the worst case n^2 time would be consumed }.
   Space Complexity: O(N) { There is no extra space being used in this approach. But, a O(N) of space for ans array will be used in the worst case }.
	
 	Optimal Approach:
	int currentleader =  arr[size-1]; 
  
    /* Rightmost element is always leader */
    cout << currentleader << " "; 
      
    for (int i = size-2; i >= 0; i--) 
    { 
        if (arr[i]>= currentleader)  
        {            
            currentleader = arr[i]; 
            cout << currentleader << " "; 
        } 
    }     
	Time Complexity: O(n)
	Space Compleixty: O(1)	
----------------------------------Medium-------------------------------------------------------------------
10) Find the Duplicate Number:
Given an array of integers nums containing n + 1 integers where each integer is in the range [1, n] inclusive.
There is only one repeated number in nums, return this repeated number.
You must solve the problem without modifying the array nums and uses only constant extra space.

Example 1:
Input: nums = [1,3,4,2,2]
Output: 2

Example 2:
Input: nums = [3,1,3,4,2]
Output: 3

Example 3:
Input: nums = [3,3,3,3,3]
Output: 3
	Approach 1: Using hashmap:
	vector<int> findDuplicate(vector<int>& arr)
	{
		vector<int>ans;
		unordered_map<int, int>dup;
		for (int i=0; i<arr.size(); i++)
		{
			dup[arr[i]]++;
		}
		for (int i = 0; i < arr.size(); i++)
		{
			if (dup[arr[i]] > 1)
				ans.push_back(arr[i]);
		}
		//If dupArray.size() == 0, then push -1
		ans.push_back(-1);
		return ans;
	}

	int main() {
		long long a[] = {1, 6, 5, 2, 3, 3, 2};
		int n = sizeof(a) / sizeof(a[0]);
		
		vector<int> duplicates_found = duplicates(a, n);
		
		cout << "Duplicate elements: ";
		for (int element : duplicates_found) {
			cout << element << " ";
		}
		cout << endl;
		
		return 0;
	}
	Time Complexity: O(n Log n), Two traversals are needed. And then sorting. We can avoid sorting and have the time complexity as O(n) if order is not required.
	Auxiliary Space: O(n), The extra space is used for the hash and array to be returned.

	Approach 2: Linked List cycle method
	int findDuplicate(vector < int > & nums) {
  int slow = nums[0];
  int fast = nums[0];
  do {
    slow = nums[slow];
    fast = nums[nums[fast]];
  } while (slow != fast);
  fast = nums[0];
  while (slow != fast) {
    slow = nums[slow];
    fast = nums[fast];
  }
  return slow;
}
int main() {
  vector < int > arr;
  arr = {1,3,4,2,3};
  cout << "The duplicate element is " << findDuplicate(arr) << endl;
}
Time complexity: O(N). Since we traversed through the array only once.
Space complexity: O(1).	

-----------------------------------------------------------------------
11) Find All Duplicates in an Array	
Given an integer array nums of length n where all the integers of nums are in the range [1, n] and each integer appears once or twice, return an array of all the integers that appears twice.
You must write an algorithm that runs in O(n) time and uses only constant auxiliary space, excluding the space needed to store the output
Example 1:

Input: nums = [4,3,2,7,8,2,3,1]
Output: [2,3]
Example 2:

Input: nums = [1,1,2]
Output: [1]
Example 3:

Input: nums = [1]
Output: []

	Approach 1: Using map
	vector<int> findDuplicates(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> duplicates;
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] == nums[i - 1]) {
                duplicates.push_back(nums[i]);
        }
    }
        return duplicates;
    }
	TC = O(n) 
	SC = O(n)
	
	Approach 2: Using sorting
	vector<int> findDuplicates(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> duplicates;
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] == nums[i - 1]) {
                duplicates.push_back(nums[i]);
        }
    }
        return duplicates;
    }
    TC = O(n log n) 
	SC = 0(1)
	
	Appraoch 3: Using pointers:
	vector<int> findDuplicates(vector<int>& nums) {
        vector<int> ans; // The space required by the result vector is proportional to the number of duplicates found, which can be at most n/2.
        //However, since we are not counting the space used by the input array itself, the space complexity is considered to be constant, O(1).
        for (int i = 0 ;i<nums.size();i++ ){
            int k = abs(nums[i])-1;  //doing -1 because length = n => index from 0 to n-1  and range of numbers = [1,n] 
            if(nums[k]<0){ //if value at the index is negative => already visited
                ans.push_back(abs(nums[i]));
            } 
            else{
                nums[k]*= -1; //marking as visited
            }
        }
        return ans;
    }
	TC = O(n)
	SC = O(1)
-------------------------------------------------------------------------------------------
12) Left rotate an array by one index:
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
13) Left rotate an array by d places:
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
	void leftRotate(int arr[], int d)
	{
		int n = 7;
		reverse(arr, arr + d);
		reverse(arr + d, arr + n);
		reverse(arr, arr + n);
	
		for (int  i=0; i<n; i++)
		{
			cout << arr[i] << endl;
		}
		
	}
    Time Complexity: O(d)+O(n-d)+O(n) = O(2*n), where n = size of the array, d = the number of rotations. Each 		term corresponds to each reversal step.
     Space Complexity: O(1) since no extra space is required.
	
---------------------------------------------------------------------------------------
14) Move zeros to end of the array:
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
	
------------------------------------------------------------------------------------------
15) Union of Two Sorted Arrays:
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
  
--------------------------------------------------------------------------------------------------
16) Sort an array of 0,1 &2/sort colors:
nums = [2,0,2,1,1,0] => [0,0,1,1,2,2]

	Brute Force Approach:
	Sorting ( even if it is not the expected solution here but it can be considered as one of 
	the approaches). Since the array contains only 3 integers, 0, 1, and 2. Simply sorting the 
	array would arrange the elements in increasing order.
	Time Complexity: O(N*logN)
	Space Complexity: O(1)
	
	Better Approach:
	Take 3 variables to maintain the count of 0, 1 and 2.
	Travel the array once and increment the corresponding counting variables
	( let's consider count_0 = a, count_1 = b, count_2 = c )
	In 2nd traversal of array, we will now over write the first ‘a’ indices / positions in array with ’0’, 
	the next ‘b’ with ‘1’ and the remaining ‘c’ with ‘2’.
	
	int cnt0 = 0, cnt1 = 0, cnt2 = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] == 0) cnt0++;
        else if (arr[i] == 1) cnt1++;
        else cnt2++;
    }

    //Replace the places in the original array:
    for (int i = 0; i < cnt0; i++) arr[i] = 0; // replacing 0's
    for (int i = cnt0; i < cnt0 + cnt1; i++) arr[i] = 1; // replacing 1's
    for (int i = cnt0 + cnt1; i < n; i++) arr[i] = 2; // replacing 2's
	
	Time Complexity: O(N) + O(N), where N = size of the array. First O(N) for counting the number of 0’s, 1’s, 2’s, and second O(N) for placing them correctly in the original array.
	Space Complexity: O(1) as we are not using any extra space.
	
	Optimal Approach:
	First, we will run a loop that will continue until mid <= high.
	There can be three different values of mid pointer i.e. arr[mid]
	If arr[mid] == 0, we will swap arr[low] and arr[mid] and will increment both low and mid. Now the subarray from index 0 to (low-1) only contains 0.
	If arr[mid] == 1, we will just increment the mid pointer and then the index (mid-1) will point to 1 as it should according to the rules.
	If arr[mid] == 2, we will swap arr[mid] and arr[high] and will decrement high. Now the subarray from index high+1 to (n-1) only contains 2.
	In this step, we will do nothing to the mid-pointer as even after swapping, the subarray from mid to high(after decrementing high) might be unsorted. So, we will check the value of mid again in the next iteration.
	Finally, our array should be sorted.
	[0 ... low-1] --> 0 extreme left
	[low ... mid-1] --> 1 
	[mid ... high-1] --> 2 extreme right
	
	void sortNumber(vector<int>&arr)
{
	int n = arr.size();
	int low=0, mid = 0;
	int high = n - 1;
	while (mid <= high)
	{
		if (arr[mid] == 0)
		{
			swap(arr[mid], arr[low]);
			mid++;
			low++;
		}
		else if (arr[mid] == 1)
			mid++;
		else
		{
			swap(arr[mid], arr[high]);
			high--;
		}
	}
}

	Time Complexity: O(N), where N = size of the given array.
	Space Complexity: O(1) as we are not using any extra space.
----------------------------------------------------------------------------------------
17) Majority Element(N/2)
N = 3, nums[] = {3,2,3}, Result: 3
	Brute Force Approach:
	We will run a loop that will select the elements of the array one by one.
	Now, for each element, we will run another loop and count its occurrence in the given array.
	If any element occurs more than the floor of (N/2), we will simply return it.
	
	int n = v.size();
    for (int i = 0; i < n; i++) {
        //selected element is v[i]
        int cnt = 0;
        for (int j = 0; j < n; j++) {
            // counting the frequency of v[i]
            if (v[j] == v[i]) {
                cnt++;
            }
        }

        // check if frquency is greater than n/2:
        if (cnt > (n / 2))
            return v[i];
    }

    return -1;
	Time Complexity: O(N2), where N = size of the given array. 
	Space Complexity: O(1) as we use no extra space.
	
	Better Approach:
	Use a hashmap and store as (key, value) pairs. (Can also use frequency array based on the size of nums) 
	Here the key will be the element of the array and the value will be the number of times it occurs. 
	Traverse the array and update the value of the key. Simultaneously check if the value is greater than the floor of N/2. 
	If yes, return the key 
	Else iterate forward.
	
	int majorityElement(vector<int> v) {
	//size of the given array: 
    int n = v.size();

    //declaring a map:
    map<int, int> mpp;

    //storing the elements with its occurnce:
    for (int i = 0; i < n; i++) {
        mpp[v[i]]++;
    }

    //searching for the majority element:
    for (auto it : mpp) {
        if (it.second > (n / 2)) {
            return it.first;
        }
    }

    return -1;
	Time Complexity: O(N*logN) + O(N), where N = size of the given array.
	Reason: We are using a map data structure. Insertion in the map takes logN time. And we are doing it for N elements. So, it results in the first term O(N*logN). The second O(N) is for checking which element occurs more than floor(N/2) times. If we use unordered_map instead, the first term will be O(N) for the best and average case and for the worst case, it will be O(N2).
	Space Complexity: O(N) as we are using a map data structure.
	
	Optimal Approach:Moore's voting Algo
	Initialize 2 variables:
	Count –  for tracking the count of element
	Element – for which element we are counting
	Traverse through the given array.
	If Count is 0 then store the current element of the array as Element.
	If the current element and Element are the same increase the Count by 1.
	If they are different decrease the Count by 1.
	The integer present in Element should be the result we are expecting 
	
	int majorityElement(vector<int> v) {

    //size of the given array: nums[] = {2,2,1,1,1,2,2}, Result: 2
    int n = v.size();
    int cnt = 0; // count
    int el; // Element

    //applying the algorithm:
    for (int i = 0; i < n; i++) {
        if (cnt == 0) {
            cnt = 1;
            el = v[i];
        }
        else if (el == v[i]) cnt++;
        else cnt--;
    }

    //checking if the stored element
    // is the majority element:
    int cnt1 = 0;
    for (int i = 0; i < n; i++) {
        if (v[i] == el) cnt1++;
    }

    if (cnt1 > (n / 2)) return el;
    return -1;
	}
	Time Complexity: O(N) + O(N), where N = size of the given array.
	Reason: The first O(N) is to calculate the count and find the expected majority element. The second one is to check if the expected element is the majority one or not.
	Note: If the question states that the array must contain a majority element, in that case, we do not need the second check. Then the time complexity will boil down to O(N).
	Space Complexity: O(1) as we are not using any extra space.
-----------------------------------------------------------------------------------------
18) Maximum subarray sum(kadane's algo)
arr = [-2,1,-3,4,-1,2,1,-5,4], Output: 6 
	Brute Force Approach:
	First, we will run a loop(say i) that will select every possible starting index of the subarray. The possible starting indices can vary from index 0 to index n-1(n = size of the array).
	Inside the loop, we will run another loop(say j) that will signify the ending index of the subarray. For every subarray starting from the index i, the possible ending index can vary from index i to n-1(n = size of the array).
	After that for each subarray starting from index i and ending at index j (i.e. arr[i….j]), we will run another loop to calculate the sum of all the elements(of that particular subarray).
	
	int maxSubarraySum(int arr[], int n) {
    int maximum = INT_MIN; // maximum sum

    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            // subarray = arr[i.....j]
            int sum = 0;

            //add all the elements of subarray:
            for (int k = i; k <= j; k++) {
                sum += arr[k];
            }

            maximum = max(maximum, sum);
        }
    }

    return maximum;
	}
	Time Complexity: O(N3), where N = size of the array.
	Reason: We are using three nested loops, each running approximately N times.
	Space Complexity: O(1) as we are not using any extra space.
	
	Better Approach:
	First, we will run a loop(say i) that will select every possible starting index of the subarray. The possible starting indices can vary from index 0 to index n-1(n = array size).
	Inside the loop, we will run another loop(say j) that will signify the ending index as well as the current element of the subarray. For every subarray starting from index i, the possible ending index can vary from index i to n-1(n = size of the array).
	Inside loop j, we will add the current element to the sum of the previous subarray i.e. sum = sum + arr[j]. Among all the sums the maximum one will be the answer.
	
	int maxSubarraySum(int arr[], int n) {
    int maximum = INT_MIN; // maximum sum

    for (int i = 0; i < n; i++) {
        int sum = 0;
        for (int j = i; j < n; j++) {
            // current subarray = arr[i.....j]

            //add the current element arr[j]
            // to the sum i.e. sum of arr[i...j-1]
            sum += arr[j];

            maximum = max(maximum, sum); // getting the maximum
        }
    }

    return maximum;
	}
	Time Complexity: O(N2), where N = size of the array.
	Reason: We are using two nested loops, each running approximately N times.
	Space Complexity: O(1) as we are not using any extra space.
	
	Optimal Approach:
	We will run a loop(say i) to iterate the given array.
	Now, while iterating we will add the elements to the sum variable and consider the maximum one.
	If at any point the sum becomes negative we will set the sum to 0 as we are not going to consider it as a part of our answer.
	Note: In some cases, the question might say to consider the sum of the empty subarray while solving this problem. So, in these cases, before returning the answer we will compare the maximum subarray sum calculated with 0(i.e. The sum of an empty subarray is 0). And after that, we will return the maximum one.
	For e.g. if the given array is {-1, -4, -5}, the answer will be 0 instead of -1 in this case.
		
	long long maxSubarraySum(int arr[], int n) {
    long long maximum = LONG_MIN; // maximum sum
    long long sum = 0;

    for (int i = 0; i < n; i++) {

        sum += arr[i];

        if (sum > maximum) {
            maximum = sum;
        }

        // If sum < 0: discard the sum calculated
        if (sum < 0) {
            sum = 0;
        }
    }

    // To consider the sum of the empty subarray
    // uncomment the following check:

    //if (maxi < 0) maxi = 0;

    return maximum;
	}
	Time Complexity: O(N), where N = size of the array.
	Reason: We are using a single loop running N times.
	Space Complexity: O(1) as we are not using any extra space.
---------------------------------------------------------------------------------------
19) Rearrange Array Elements by Sign: There’s an array ‘A’ of size ‘N’ with an equal number of positive
and negative elements. Without altering the relative order of positive and negative elements, 
you must return an array of alternately positive and negative values.
arr[] = {1,2,-4,-5}, N = 4, Output:1 -4 2 -5

Explanation: 
Positive elements = 1,2
Negative elements = -4,-5
To maintain relative ordering, 1 must occur before 2, and -4 must occur before -5.

	Brute Force Approach:
	vector<int> RearrangebySign(vector<int>A, int n){
    
	  // Define 2 vectors, one for storing positive 
	  // and other for negative elements of the array.
	  vector<int> pos;
	  vector<int> neg;
	  
	  // Segregate the array into positives and negatives.
	  for(int i=0;i<n;i++){
		  
		  if(A[i]>0) pos.push_back(A[i]);
		  else neg.push_back(A[i]);
	  }
	  
	  // Positives on even indices, negatives on odd.
	  for(int i=0;i<n/2;i++){
		  
		  A[2*i] = pos[i];
		  A[2*i+1] = neg[i];
	  }
	  
	  
	  return A;
		
	}
	Time Complexity: O(N+N/2) { O(N) for traversing the array once for segregating positives and negatives and another O(N/2) for adding those elements alternatively to the array, where N = size of the array A}.
	Space Complexity:  O(N/2 + N/2) = O(N) { N/2 space required for each of the positive and negative element arrays, where N = size of the array A}.
	
	Better Approach:
	vector<int> RearrangebySign(vector<int>A){
    
  int n = A.size();
  
  // Define array for storing the ans separately.
  vector<int> ans(n,0);
  
  // positive elements start from 0 and negative from 1.
  int posIndex = 0, negIndex = 1;
  for(int i = 0;i<n;i++){
      
      // Fill negative elements in odd indices and inc by 2.
      if(A[i]<0){
          ans[negIndex] = A[i];
          negIndex+=2;
      }
      
      // Fill positive elements in even indices and inc by 2.
      else{
          ans[posIndex] = A[i];
          posIndex+=2;
      }
    }
  
    return ans;
    
    }
	Time Complexity: O(N) { O(N) for traversing the array once and substituting positives and negatives simultaneously using pointers, where N = size of the array A}.
	Space Complexity:  O(N) { Extra Space used to store the rearranged elements separately in an array, where N = size of array A}.
---------------------------------------------------------------------------------------------------
20) Best Time to Buy and Sell Stock:
arr[] = {7,1,5,3,6,4};
	Ex: If we buy stock on 2nd day means in 1 rs, then sell it on 5th day(6rs), profit would be(6-1=5)
	For max profit, buy when it is min and sell when it is max.
	
	minimum=arr[0], maxprofit=0
	for(i=0; i<n; i++)
	{
		profit = max(maxprofit, arr[i]-min);
		minimum = min(minimum, arr[i]);
	}
	return maxprofit;
	
----------------------------------------------------------------------
21) Best Time to Buy and Sell Stock II
You are given an integer array prices where prices[i] is the price of a given stock on the ith day.
On each day, you may decide to buy and/or sell the stock. You can only hold at most one share of the stock at any time. However, you can buy it then immediately sell it on the same day.
Find and return the maximum profit you can achieve.
Example 1:
Input: prices = [7,1,5,3,6,4]
Output: 7
Explanation: Buy on day 2 (price = 1) and sell on day 3 (price = 5), profit = 5-1 = 4.
Then buy on day 4 (price = 3) and sell on day 5 (price = 6), profit = 6-3 = 3.
Total profit is 4 + 3 = 7.

Example 2:
Input: prices = [1,2,3,4,5]
Output: 4
Explanation: Buy on day 1 (price = 1) and sell on day 5 (price = 5), profit = 5-1 = 4.
Total profit is 4.

Example 3:
Input: prices = [7,6,4,3,1]
Output: 0
Explanation: There is no way to make a positive profit, so we never buy the stock to achieve the maximum profit of 0.

int maxProfit(vector<int>& nums) {
        int n = nums.size();
        int ans=0;
        int mx=nums[0];
        int mn=nums[0];

        for(int i=1;i<n;){
            while(i<n && nums[i]>=nums[i-1]){
                mx=nums[i];
                i++;
            }
            ans+=mx-mn;
            while(i<n && nums[i]<=nums[i-1]){
                mn=nums[i];
                i++;
            }
        }
        return ans;
    }
	Time complexity: O(n)
	Space complexity: O(1) 	
-----------------------------------------------------------------------------------------------------
22) Chocolate Distribution Problem:
Given an array of N integers where each value represents the number of chocolates
in a packet. Each packet can have a variable number of chocolates. 
There are m students, the task is to distribute chocolate packets such that: 

Each student gets one packet.
The difference between the number of chocolates in the packet with maximum chocolates and the packet with minimum chocolates given to the students is minimum.
Examples:

Input : arr[] = {7, 3, 2, 4, 9, 12, 56} , m = 3 
Output: Minimum Difference is 2 
Explanation:
We have seven packets of chocolates and we need to pick three packets for 3 students 
If we pick 2, 3 and 4, we get the minimum difference between maximum and minimum packet sizes.

Input : arr[] = {3, 4, 1, 9, 56, 7, 9, 12} , m = 5 
Output: Minimum Difference is 6 

Input : arr[] = {12, 4, 7, 9, 2, 23, 25, 41, 30, 40, 28, 42, 30, 44, 48, 43, 50} , m = 7 
Output: Minimum Difference is 10 

// C++ program to solve chocolate distribution
// problem
#include <bits/stdc++.h>
using namespace std;

// arr[0..n-1] represents sizes of packets
// m is number of students.
// Returns minimum difference between maximum
// and minimum values of distribution.
int findMinDiff(int arr[], int n, int m)
{
	// if there are no chocolates or number
	// of students is 0
	if (m == 0 || n == 0)
		return 0;

	// Sort the given packets
	sort(arr, arr + n);

	// Number of students cannot be more than
	// number of packets
	if (n < m)
		return -1;

	// Largest number of chocolates
	int min_diff = INT_MAX;

	// Find the subarray of size m such that
	// difference between last (maximum in case
	// of sorted) and first (minimum in case of
	// sorted) elements of subarray is minimum.

	for (int i = 0; i + m - 1 < n; i++) {
		int diff = arr[i + m - 1] - arr[i];
		if (diff < min_diff)
			min_diff = diff;
	}
	return min_diff;
}

int main()
{
	int arr[] = { 12, 4, 7, 9, 2, 23, 25, 41, 30,
				40, 28, 42, 30, 44, 48, 43, 50 };
	int m = 7; // Number of students
	int n = sizeof(arr) / sizeof(arr[0]);
	cout << "Minimum difference is "
		<< findMinDiff(arr, n, m);
	return 0;
}
Time Complexity: O(N*log(N))
Auxiliary Space: O(1)
----------------------------------------------------------------------------------------
23) Set Matrix Zero:
matrix= [1,1,1]               [1,0,1]
		[1,0,1]     =>        [0,0,0] 
		[1,1,1]               [1,0,1]
	Brute Force Appraoch:
	First, we will use two loops(nested loops) to traverse all the cells of the matrix.
	If any cell (i,j) contains the value 0, we will mark all cells in row i and column j with -1 except those which contain 0.
	We will perform step 2 for every cell containing 0.
	Finally, we will mark all the cells containing -1 with 0.
	Thus the given matrix will be modified according to the question.
	
	void markRow(vector<vector<int>> &matrix, int n, int m, int i) {
    // set all non-zero elements as -1 in the row i:
    for (int j = 0; j < m; j++) {
        if (matrix[i][j] != 0) {
            matrix[i][j] = -1;
        }
    }
	}
	void markCol(vector<vector<int>> &matrix, int n, int m, int j) {
    // set all non-zero elements as -1 in the col j:
    for (int i = 0; i < n; i++) {
        if (matrix[i][j] != 0) {
            matrix[i][j] = -1;
        }
    }
	}

    vector<vector<int>> zeroMatrix(vector<vector<int>> &matrix, int n, int m) {

    // Set -1 for rows and cols
    // that contains 0. Don't mark any 0 as -1:

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (matrix[i][j] == 0) {
                markRow(matrix, n, m, i);
                markCol(matrix, n, m, j);
            }
        }
    }

    // Finally, mark all -1 as 0:
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (matrix[i][j] == -1) {
                matrix[i][j] = 0;
            }
        }
    }

    return matrix;
	}
	Time Complexity: O((N*M)*(N + M)) + O(N*M), where N = no. of rows in the matrix and M = no. of columns in the matrix.
	Reason: Firstly, we are traversing the matrix to find the cells with the value 0. It takes O(N*M). Now, whenever we find any such cell we mark that row and column with -1. This process takes O(N+M). So, combining this the whole process, finding and marking, takes O((N*M)*(N + M)).
	Another O(N*M) is taken to mark all the cells with -1 as 0 finally.
	Space Complexity: O(1) as we are not using any extra space.
	
	Better Approach:
	vector<vector<int>> zeroMatrix(vector<vector<int>> &matrix, int n, int m) {

    int row[n] = {0}; // row array
    int col[m] = {0}; // col array

    // Traverse the matrix:
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (matrix[i][j] == 0) {
                // mark ith index of row wih 1:
                row[i] = 1;

                // mark jth index of col wih 1:
                col[j] = 1;
            }
        }
    }

    // Finally, mark all (i, j) as 0
    // if row[i] or col[j] is marked with 1.
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (row[i] || col[j]) {
                matrix[i][j] = 0;
            }
        }
    }

    return matrix;
    }
	Time Complexity: O(2*(N*M)), where N = no. of rows in the matrix and M = no. of columns in the matrix.
	Reason: We are traversing the entire matrix 2 times and each traversal is taking O(N*M) time complexity.
	Space Complexity: O(N) + O(M), where N = no. of rows in the matrix and M = no. of columns in the matrix.
	Reason: O(N) is for using the row array and O(M) is for using the col array.
	
-----------------------------------------------------------------------------------------
24) Rotate Matrix/Image by 90 Degrees:
[1,2,3]     [7,4,1]
[4,5,6] =>  [8,5,2]
[7,8,9]     [9,6,3]
	Brute Force Approach:
	vector < vector < int >> rotate(vector < vector < int >> & matrix) {
    int n = matrix.size();
    vector < vector < int >> rotated(n, vector < int > (n, 0));
    for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
        rotated[j][n - i - 1] = matrix[i][j];
    }
    }
    return rotated;
	Time Complexity: O(N*N) to linearly iterate and put it into some other matrix.
	Space Complexity: O(N*N) to copy it into some other matrix.
	
	Optimal Approach:
	void rotate(vector < vector < int >> & matrix) {
    int n = matrix.size();
    //transposing the matrix: row will become column
    for (int i = 0; i < n; i++) {
    for (int j = 0; j < i; j++) {
        swap(matrix[i][j], matrix[j][i]);
    }
    }
    //reversing each row of the matrix
    for (int i = 0; i < n; i++) {
    reverse(matrix[i].begin(), matrix[i].end());
    }
	}
	Time Complexity: O(N*N) + O(N*N).One O(N*N) is for transposing the matrix and the other is for reversing the matrix.
	Space Complexity: O(1).
-------------------------------------------------------------------------------
25) Spiral Traversal of a Matrix:
Input: Matrix[][] = 
1, 2,  3,  4 
5, 6,  7,  8   =>  1, 2, 3, 4, 8, 12, 16, 15, 14, 13, 9, 5, 6, 7, 11, 10
9, 10, 11, 12
13,14, 15, 16 

------------------------------------------------------------------------
26) Game of Life:


-----------------------------------------------------------------------------------------
Hard problems pending	
-----------------------Reverse Pairs:
27) Given an integer array nums, return the number of reverse pairs in the array.
Example 1:

Input: nums = [1,3,2,3,1]
Output: 2
Explanation: The reverse pairs are:
(1, 4) --> nums[1] = 3, nums[4] = 1, 3 > 2 * 1
(3, 4) --> nums[3] = 3, nums[4] = 1, 3 > 2 * 1
Example 2:

Input: nums = [2,4,3,5,1]
Output: 3
Explanation: The reverse pairs are:
(1, 4) --> nums[1] = 4, nums[4] = 1, 4 > 2 * 1
(2, 4) --> nums[2] = 3, nums[4] = 1, 3 > 2 * 1
(3, 4) --> nums[3] = 5, nums[4] = 1, 5 > 2 * 1




------------------------------------------------------------
28) Max Value of Equation:





------------------------------------------------------------- 
Insert Delete GetRandom O(1) - Duplicates allowed
