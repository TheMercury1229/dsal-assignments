'''a) Write a Python program to store names and mobile numbers of your friends in sorted
order on names. Search your friend from list using binary search (recursive and non-
recursive).Insert friend if not present in phonebook

b) Write a Python program to store names and mobile numbers of your friends in sorted
order on names. Search your friend from list using Fibonacci search. Insert friend if not
present in phonebook
'''
# Binary Search non-recursive
def binary_non_recursive(x,target):
    asc=[]
    for i in x:
        asciiLine = ord(i[0])
        asc.append(asciiLine)
    target_zero = ord(target[0])

    start = 0
    end = len(x)-1

    mid = int(start +((end-start)/2))

    while start <= end:
        if asc[mid] == target_zero:
            return mid
        elif asc[mid] > target_zero:
            end = mid -1
        else:
            start = mid+1
        mid = int(start +((end-start)/2))
    return -1

def binary_recursive(x,target):
    asc=[]
    for i in x:
        asciiLine = ord(i[0])
        asc.append(asciiLine)
    target_zero = ord(target[0])

    start = 0
    end = len(x)-1
    if start >end:
        return -1

    mid = int(start +((end-start)/2))
    if asc[mid] == target_zero:
        return mid
    elif asc[mid] > target_zero:
        binary_recursive(x[:mid-1],target)
    else:
        binary_recursive(x[mid+1:],target)
   
    return -1

        
        
    


address_book={}

n = int(input("Enter The Number Of Friends :"))
for i in range(n):
    name = input("Enter Friend Name : ")
    phone = input("Enter The Phone Number : ")
    address_book[name] = phone

# Extracting names from the address book dictionary
name_list = list(address_book.keys())
name_list.sort()


print(binary_non_recursive(name_list,"Hards"))
print(binary_recursive(name_list,"Hards"))



