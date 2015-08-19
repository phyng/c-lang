
import random

def quicksort(arr):
    if not arr:
        return []

    middle = [x for x in arr if x == arr[0]]
    left = quicksort([x for x in arr if x < arr[0]])
    right = quicksort([x for x in arr if x > arr[0]])

    return left + middle + right



print quicksort([random.randrange(100) for i in range(10)])
