1. Linear search:
def linearSearch(arr: list[int], target: int):
    for num in arr:
        if num == target:
            return True

    return False

mylist = [12, 10, 32, 1]
print(linearSearch(mylist, 10))
---------------------------------------------------------------------
