'''
In second year ,computer engineering class group A plays cricket.,group B play badminton and group C plays football
.Write a python program to compute the following
a)List of student who play both cricket and badminton 
b)List of students who either play cricket or badminton but not both
c)Number of students playing all games
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
    def printSet(self):
        for i in self.elements:
            print(i,end=",")
        print(" ")
# LENGTH OF THE SET
    def __len__(self):
        count =0
        for element in self.elements:
            count+=1
        return count
    
def take_input(sport):
    n=int(input(f"Enter the number of students playing {sport} : "))
    player_set=CustomSet()
    for i in range(n):
        no= int(input(f'Enter the roll number of Player -{i+1}: '))
        player_set.add(no)
    return player_set


cricket_players=take_input("Cricket")
football_players=take_input("Football")
badminton_players=take_input("Badminton")

both_cricket_and_badminton=cricket_players.intersection(badminton_players)
either_cricket_or_badminton=cricket_players.union(badminton_players)
no_of_students_playing_all_games = len(cricket_players.union(badminton_players).union(football_players))



print("The players playing both cricket and badminton -> ", end=" ")
both_cricket_and_badminton.printSet()

print("The players playing either cricket or badminton -> ", end=" ")
either_cricket_or_badminton.printSet()

print("The number of players playing all the three games -> ",no_of_students_playing_all_games)
