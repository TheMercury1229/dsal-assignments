"""
a) Write a Python program to store roll numbers of students in an array who attended
   a training program in random order. Write functions for searching whether a particular
   student attended the training program or not, using Linear search and Sentinel search.

b) Write a Python program to store roll numbers of students in an array who attended a 
   training program in sorted order. Write functions for searching whether a particular 
   student attended the training program or not, using Binary search and Fibonacci search.

AUTHOR -> HARDIK GUJRATHI [24117]
"""

def convert_to_int(x):
    return int(x)

def linear_search(arr, target):
    for i in arr:
        if i == target:
            return arr.index(i)
    return -1

def sentinel_search(arr, target):
    last = arr[-1]
    arr[-1] = target
    i = 0
    while arr[i] != target:
        i += 1

    arr[-1] = last
    if i < len(arr) - 1 or arr[-1] == target:
        return i
    else:
        return -1

def binary_search(arr, target):
    start = 0
    end = len(arr) - 1
    while start <= end:
        mid = (start + end) // 2
        if arr[mid] == target:
            return mid
        elif arr[mid] > target:
            end = mid - 1
        else:
            start = mid + 1
    return -1

def fibonacci_search(arr, target):
    n = len(arr)
    fibMMm2 = 0  # (m-2)'th Fibonacci No.
    fibMMm1 = 1  # (m-1)'th Fibonacci No.
    fibM = fibMMm2 + fibMMm1  # m'th Fibonacci No.

    while fibM < n:
        fibMMm2 = fibMMm1
        fibMMm1 = fibM
        fibM = fibMMm2 + fibMMm1

    offset = -1

    while fibM > 1:
        i = min(offset + fibMMm2, n - 1)

        if arr[i] < target:
            fibM = fibMMm1
            fibMMm1 = fibMMm2
            fibMMm2 = fibM - fibMMm1
            offset = i

        elif arr[i] > target:
            fibM = fibMMm2
            fibMMm1 = fibMMm1 - fibMMm2
            fibMMm2 = fibM - fibMMm1

        else:
            return i

    if fibMMm1 and offset + 1 < n and arr[offset + 1] == target:
        return offset + 1

    return -1


while True:
    print("\nMenu:")
    print("1. Linear Search")
    print("2. Sentinel Search")
    print("3. Binary Search")
    print("4. Fibonacci Search")
    print("5. Exit")

    choice = int(input("Enter your choice: "))

    if choice == 5:
        break

    arr_input = input("Enter the list of roll numbers separated by commas: ")
    arr = list(map(convert_to_int, arr_input.split(',')))
    target = int(input("Enter the target roll number: "))

    is_sorted = input("Are the roll numbers sorted? (yes/no): ").strip().lower()

    if is_sorted == 'no':
        if choice in [3, 4]:
            print("Sorting the array as it is required for Binary and Fibonacci search.")
            arr.sort()

    if choice == 1:
        result = linear_search(arr, target)
    elif choice == 2:
        result = sentinel_search(arr, target)
    elif choice == 3:
        result = binary_search(arr, target)
    elif choice == 4:
        result = fibonacci_search(arr, target)
    else:
        print("Invalid choice. Please try again.")
        continue

    if result != -1:
        print(f"Roll number {target} found at index {result}.")
    else:
        print(f"Roll number {target} not found.")

