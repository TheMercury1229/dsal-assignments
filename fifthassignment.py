'''
Write a Python program to store second year percentages of students in a array
Write a function to store aray of floating-point numbers in ascending order using
a)Insertion sort b)Shell sort and display the top five scores

AUTHOR -> HARDIK GUJRATHI [24117]
'''

def length(x):
    count =0
    for i in x:
        count+=1
    return count
def insertion_sort(arr):

 
    for i in range(1, len(arr)):
        key = arr[i]
        j = i-1
        while j >= 0 and key < arr[j] :
                arr[j + 1] = arr[j]
                j -= 1
        arr[j + 1] = key

def top_scores(arr):
    return arr[len(arr)-5:]

def shell_sort(arr):
    n = length(arr)
    gap = int(n/2)
    while gap>0:
        j=gap
        while j<n:
            i=j-gap
            while i>=0:
                if arr[i+gap]>arr[i]:
                    break
                else:
                    arr[i+gap],arr[i]=arr[i],arr[i+gap]

                i=i-gap
            j+=1
        gap=int(gap/2)
ls = list(input("Enter The Percentages seperated by commas :").split(","))
convert_to_float = lambda x : float(x)
ls = list(map(convert_to_float,ls))
while True:
    choice = input("Enter Your Choice :\nA -> Insertion Sort \nB -> Shell Sort \nC -> Quit\n")
    if choice == 'A':
        insertion_sort(ls)
        print("The sorted list is : ",ls)
        print("The top five scores are :",top_scores(ls))
    elif choice == 'B':
        shell_sort(ls)
        print("The sorted list is : ",ls)
        print("The top five scores are :",top_scores(ls))
    elif choice == 'C':
        break
    else:
        print("Enter a valid choice")

