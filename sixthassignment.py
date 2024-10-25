'''
Write a Python program to store first year percentage of students in array. Write function for
sorting array of floating point numbers in ascending order using quick sort and display top
five scores.
AUTHOR -> HARDIK GUJRATHI[24117]
'''

def partition(arr,low,high):
    pivot = arr[low]
    
    s= low + 1
    
    e= high

    while True:
        while s <= e and arr[e] >= pivot:
            e = e- 1
        while s <= e and arr[s] <= pivot:
            s = s + 1
        if s <= e:
            arr[s], arr[e] = arr[e], arr[s]
        else:
            break

    arr[low], arr[e] = arr[e], arr[low]
    
    return e


def quick_sort(arr,low,high):

    if low<high:
        # Partition index
        pi = partition(arr,low,high)
        # Left sort
        quick_sort(arr,low,pi-1)
        # Right sort
        quick_sort(arr,pi+1,high)


inp_list = input("Enter the percentages seperated by comma(,) : ").split(",")
inp_list = list(map(int,inp_list))

quick_sort(inp_list,0,len(inp_list)-1)
print(inp_list)
