# day one ask the user for the total bill amount 
total_bill = float(input("Please enter the total bill amount: "))
# 2. ask how many people are sharing the bill
number_of_people = int(input("Please enter the number of people sharing the bill: "))
# 3. calculate how much each person needs to pay
amount_per_person = total_bill / number_of_people
# 4. print the result!
print("Each person needs to pay: $" + str(amount_per_person))
