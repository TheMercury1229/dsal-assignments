'''Write a Python program to compute following operations on String:
a) To display word with the longest length
b) To determines the frequency of occurrence of particular character in the string
c) To check whether given string is palindrome or not
d) To display index of first appearance of the substring
e) To count the occurrences of each word in a given string

AUTHOR->Hardik Gujrathi [24117]
'''

def find_length(x):
    count = 0
    for i in x:
        count+=1

    return count

def find_longest_word(words):
    maxi = -1
    longest_word = ""
    for i in words:
        if find_length(i)>maxi:
          maxi = find_length(i)
          longest_word = i

    return longest_word

def find_character_frequency(str,char):
    count =0
    for i in str:
        if i == char:
            count+=1
    return count

def check_palindrome(str):
    if str==str[::-1]:
        return  "Entered string is a palindrome"
    else:
        return "Entered string is not a palindrome"

def find_first_index_of_substr(str,sub_str):
    for i in str:
        if sub_str in str:
            return str.index(sub_str)

def find_occurences_of_each_word(words_list):
    words={}
    for i in words_list:
        i= i.lower()
        if i in words.keys():
            words[i]+=1
        else:
            words[i] = 1

    return words
inp = input("Enter The String : ")
word_list = inp.split(" ")

# a)Word with longest length
longest_word = find_longest_word(word_list)
print(f"The longest word in the string is {longest_word}")

# b) To determines the frequency of occurrence of particular character in the string
char = input("Enter the character whose frequency is to be checked :")[0]
char_frequency = find_character_frequency(inp,char)
print("The frequency of character is :",char_frequency)
# c) To check whether given string is palindrome or not
palindrome=input("Enter the string for palindrome check :")
result = check_palindrome(palindrome)
print(result)

# d) To display index of first appearance of the substring
sub_str=input("Enter the substring to be searched :")
sub_str_index = find_first_index_of_substr(inp,sub_str)
print(f"The sub-string first occures at index {sub_str_index}")

# e) To count the occurrences of each word in a given string
words_frequency = find_occurences_of_each_word(word_list)
print("The frequncy of each word in the string is as follows : ")
for (key,value) in words_frequency.items():
    print(f"{key} -> {value}")




