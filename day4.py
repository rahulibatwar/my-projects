# ask the user for a number
number = int(input("Please enter a number: "))

# using a for loop, print the multiplication table for that number from 1 to 10
for i in range(1, 11):
    print(f"{number} x {i} = {number * i}") 
