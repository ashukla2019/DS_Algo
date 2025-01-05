1. Linear search:
def linearSearch(arr: list[int], target: int):
    for num in arr:
        if num == target:
            return True

    return False

mylist = [12, 10, 32, 1]
print(linearSearch(mylist, 10))
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
    
    
