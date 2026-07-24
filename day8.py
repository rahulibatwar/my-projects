# ask the user for tow numbers
num1 = float(input("Enter first number: "))
num2 = float(input("Enter second number: "))

#handle value error (if user enters text instead of numbers).
try:
    num1 = float(input("Enter first number: "))
    num2 = float(input("Enter second number: "))
    result = num1 / num2
except ValueError:
    print("Error: Please enter valid numbers.")
    exit()

#handle zerodivision error (if user tries to divide by zero).
if num2 == 0:
    print("Error: Division by zero is not allowed.")
else:
    result = num1 / num2
    print(f"The result of dividing {num1} by {num2} is: {result}")
