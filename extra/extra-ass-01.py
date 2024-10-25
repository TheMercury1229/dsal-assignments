'''Write a Python program to store marks scored in subject “Fundamental of Data Structure” by
N students in the class. Write functions to compute following:
a) The average score of class
b) Highest score and lowest score of class
c) Count of students who were absent for the test
d) Display mark with highest frequency'''

def avg_class(lt):
    total=0
    count =0
    for i in lt:
        total+=i
        count+=1
    avg = total/count
    return avg

def highest(lt):
    maxi=-1
    for i in lt:
        if i>maxi:
            maxi=i
    return maxi
    
def lowest(lt):
    mini=101
    for i in lt:
        if i<mini:
            mini=i
    return mini
    
def highest_freq(lt):
    marks_freq={}       
    for i in lt:
        if i in marks_freq.keys():
            marks_freq[i]+=1
        else:
            marks_freq[i]=1
    max_freq=highest(marks_freq.values())
    for key,value in marks_freq.items():
        if value == max_freq:
            return key
   


# Inputing the list
marks_inp = input("Enter Marks of Students seperated by commas: ")
marks_inp = list(map(int,marks_inp.split(",")))

# The average score of class
print("The average of the class is: ",avg_class(marks_inp))

# Highest score and lowest score of class
print("The Highest Score in the class is: ",highest(marks_inp))
print("The Lowest Score in the class is: ",lowest(marks_inp))

# The score with highest frequency in the class

print("The Score with highest frequency in class is",highest_freq
      (marks_inp))