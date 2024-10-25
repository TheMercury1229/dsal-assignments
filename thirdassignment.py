''' Write a Python program to compute following computation on matrix:
a) Addition of two matrices
b) Subtraction of two matrices
c) Multiplication of two matrices
d) Transpose of a matrix 

Author: Hardik Nilesh Gujrathi
Roll No: 24117
'''
def length(x):
    counter=0
    for i in x:
        counter+=1
    return counter
def get_matrix(rows, cols, name):
    """Reads a matrix from user input."""
    print(f"Enter the elements of matrix {name}:")
    matrix = []
    for i in range(rows):
        row = list(map(int, input(f"Row {i+1}: ").split()))
        if length(row) != cols:
            raise ValueError(f"Expected {cols} elements in row {i+1}, but got {length(row)}")
        matrix.append(row)
    return matrix

def add(a, b):
    if length(a) != length(b) or length(a[0]) != length(b[0]):
        raise ValueError("Matrices are not of the same order for addition")
    
    ans = []
    for i in range(length(a)):
        row = []
        for j in range(length(a[0])):
            row.append(a[i][j] + b[i][j])
        ans.append(row)
    return ans

def minus(a, b):
    if length(a) != length(b) or length(a[0]) != length(b[0]):
        raise ValueError("Matrices are not of the same order for subtraction")
    
    ans = []
    for i in range(length(a)):
        row = []
        for j in range(length(a[0])):
            row.append(a[i][j] - b[i][j])
        ans.append(row)
    return ans

def multiply(a, b):
    if length(a[0]) != length(b):
        raise ValueError("Number of columns in matrix A must be equal to the number of rows in matrix B for multiplication")
    
    ans = []
    for i in range(length(a)):
        row = []
        for j in range(length(b[0])):
            product = 0
            for k in range(length(b)):
                product += a[i][k] * b[k][j]
            row.append(product)
        ans.append(row)
    return ans

def transpose(a):
    ans = []
    for i in range(length(a[0])):
        row = []
        for j in range(length(a)):
            row.append(a[j][i])
        ans.append(row)
    return ans

# Read number of rows and columns for matrix A
rows_a = int(input("Enter the number of rows for matrix A: "))
cols_a = int(input("Enter the number of columns for matrix A: "))

# Read matrix A from user input
print("Matrix A")
matrix_a = get_matrix(rows_a, cols_a, 'A')

# Read number of rows and columns for matrix B
rows_b = int(input("Enter the number of rows for matrix B: "))
cols_b = int(input("Enter the number of columns for matrix B: "))

# Read matrix B from user input
print("Matrix B")
matrix_b = get_matrix(rows_b, cols_b, 'B')

# Perform and print matrix operations
print("Addition of Matrices A and B:")
try:
    result_add = add(matrix_a, matrix_b)
    for row in result_add:
        print(row)
except ValueError as e:
    print(e)

print("Subtraction of Matrices A and B:")
try:
    result_subtract = minus(matrix_a, matrix_b)
    for row in result_subtract:
        print(row)
except ValueError as e:
    print(e)

print("Multiplication of Matrices A and B:")
try:
    result_multiply = multiply(matrix_a, matrix_b)
    for row in result_multiply:
        print(row)
except ValueError as e:
    print(e)

print("Transpose of Matrix A:")
result_transpose = transpose(matrix_a)
for row in result_transpose:
    print(row)
