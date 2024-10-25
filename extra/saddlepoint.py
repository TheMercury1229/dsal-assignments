'''
Write a python program that determines the location of the saddle point of a matrix'''
def length(x):
   counter=0
   for o in x:
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

def find_saddle(x):
   row_minis=[]
   col_maxis=[]
   for i in range(length(x)):
     row_min = 10000000
#  Find row minimum
     for j in range(length(x[0])):
        if row_min>x[i][j]:
           row_min=x[i][j]
     row_minis.append(row_min)
# Find col maximum
   for k in range(length(x)):
       col_max=-1
       for m in range(length(x[0])):
          if x[m][k]>col_max:
             col_max=x[m][k]
       col_maxis.append(col_max)

   # Finding the element row and column
   for i in row_minis:
      if i in col_maxis:
         for y in range(length(x)):
            for z in range(length(x[0])):
               if i == x[y][z]:
                  return f"The saddle point is at row {y+1} and column {z+1}" 

   return "No Saddle Point"
    
# matrix 
rows_a = int(input("Enter the number of rows for matrix A: "))
cols_a = int(input("Enter the number of columns for matrix A: "))

# Read matrix A from user input
print("Matrix A")
matrix_a = get_matrix(rows_a, cols_a, 'A')

print(find_saddle(matrix_a))


