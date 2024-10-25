'''Write a Python program to store first year percentage of students in array. Write function for
sorting array of floating point numbers in ascending order using
a) Selection Sort
b) Bubble sort and display top five scores.
AUTHOR - HARDIK GUJRATHI [24117]'''


def selection_sort(arr):
    for i in range(len(arr)):
        minIndex =i
        for j in range(i,len(arr)):
            if arr[minIndex]>arr[j]:
                minIndex=j
        arr[minIndex],arr[i]=arr[i],arr[minIndex]
    return arr
def bubble_sort(my_array):
    n = len(my_array)
    for i in range(n-1):
      for j in range(n-i-1):
        if my_array[j] > my_array[j+1]:
            my_array[j], my_array[j+1] = my_array[j+1], my_array[j]
    return my_array

first_year_percentages = input("Enter the percentages seperated by comma[,] :").split(",")
first_year_percentages = list(map(float,first_year_percentages))
while True:

    choice = int(input("Enter Your Choice : \n1->Bubble Sort \n2->Selection Sort \n3->Exit \n "))
    match(choice):
       case 1:
            bubble_sorted_list= bubble_sort(first_year_percentages)
            print("The sorted array of percentages is: ",bubble_sorted_list)
            
       case 2:
            selection_sorted_list = selection_sort(first_year_percentages)
            print("The sorted array of percentages is :",selection_sorted_list)
            
       case 3:
            print("Quiting ....")
            exit(0)
           
       case default:
            print("Enter A Valid Choice")