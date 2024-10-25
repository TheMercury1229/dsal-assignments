'''In second year class, group A student's play cricket, group B
students play badminton and group C students play football.
Write a Python program using functions to compute
following: - 
a) List of students who play both cricket and badminton 
b) List of students who play either cricket or badminton but not both 
c) Number of students who play neither cricket nor badminton 
d) Number of students who play cricket and football but not badminton. 
(Note- While realizing the group, duplicate entries should be avoided, Do
not use SET built-in functions)
Author: Hardik Nilesh Gujrathi
Roll No: 24117
'''

class CustomSet:
    def __init__(self):
        self.elements = []
# ADDING ELEMENTS TO THE SET
    def add(self, element):
        if element not in self.elements:
            self.elements.append(element)
# CHECKING IF THE ELEMENT IS IN THE SET
    def contains(self, element):
        return element in self.elements
# FINDING THE INTERSECTION
    def intersection(self, other_set):
        result = CustomSet()
        for element in self.elements:
            if other_set.contains(element):
                result.add(element)
        return result
# FINDING THE UNION
    def union(self, other_set):
        result = CustomSet()
        for element in self.elements:
            result.add(element)
        for element in other_set.elements:
            result.add(element)
        return result
#FINDING THE DIFFERENCE
    def difference(self, other_set):
        result = CustomSet()
        for element in self.elements:
            if not other_set.contains(element):
                result.add(element)
        return result
# PRINTING THE SET
    def __iter__(self):
        return iter(self.elements)
# LENGTH OF THE SET
    def __len__(self):
        count =0
        for element in self.elements:
            count+=1
        return count
def take_input(set,sport):
    n = int(input(f"Enter the number of students {sport}: "))
    for i in range(n):
        name = input("Enter the roll number of the student: ")
        set.add(name)
    return set
# Define the students in each group
# Cricket
group_A = take_input(CustomSet(),"Cricket")
# Badminton
group_B = take_input(CustomSet(),"Badminton")
# Football
group_C = take_input(CustomSet(),"Football")


# a) List of students who play both cricket and badminton
cricket_and_badminton = group_A.intersection(group_B)
print("Students who play both cricket and badminton are as follows:", list(cricket_and_badminton))

# b) List of students who play either cricket or badminton but not both
cricket_or_badminton = group_A.union(group_B).difference(cricket_and_badminton)
print("Students who play either cricket or badminton but not both:", list(cricket_or_badminton))

# c) Number of students who play neither cricket nor badminton
all_students = group_A.union(group_B).union(group_C)
neither_cricket_nor_badminton = all_students.difference(group_A.union(group_B))
print("Number of students who play neither cricket nor badminton:", len(neither_cricket_nor_badminton))

# d) Number of students who play cricket and football but not badminton
cricket_and_football_not_badminton = group_A.intersection(group_C).difference(group_B)
print("Number of students who play cricket and football but not badminton:", len(cricket_and_football_not_badminton))
