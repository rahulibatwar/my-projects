# write a function calculate_square(number) that takes a number as input and returns the square of that number
def calculate_square(number):
    return number ** 2
# write a funcation calculate_cube(number) that takes a number as input and returns the cube of that number
def calculate_cube(number):
    return number ** 3  
# ask the user for a number
number = int(input("Please enter a number: "))
print(f"The square of {number} is {calculate_square(number)}")
# call bothfunctions and print the calculated square and cube!

print(f"The cube of {number} is {calculate_cube(number)}")
