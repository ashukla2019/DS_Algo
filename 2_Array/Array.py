1. Linear search:
def linearSearch(arr:list[int], num):
    for i in range(0, len(arr)):
        if arr[i] == num:
            return  i

mylist = [1,2,3,4,5]
index = linearSearch(mylist, 3)
print("index where number is found", index)
---------------------------------------------------------------------
2. Second Largest in array:
def getSecondLargest(self, arr):
        firstLargest = arr[0]
        secondLargest = -1
        
        for num in arr:
            
            if num>firstLargest:
                secondLargest = firstLargest
                firstLargest = num
            elif num<firstLargest and num>secondLargest:
                secondLargest = num
        return secondLargest
-------------------------------------------------------------------------------- 
3. Check if array is sorted:
array[] = {1,2,3,4,5} => yes

for i in range(len(arr)):
    if arr[i+1]>arr[i]
  
return true;

Time Complexity: O(N) 
Space Complexity: O(1)	
    
    
