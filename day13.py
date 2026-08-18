print("check your eligibility")

age = int(input("Enter your age  : "))

if age >= 18:
    id_no=int(input("Enter your ID number: "))
    if id_no == 14367:
        print("you can enter'")
    else:
        print("wrong ID number")    
else:
    print("you are not eligible to enter")

# multiple conditions (AND operator)
age = int(input("Enter your age  : "))
residence = input(" are you indian? (yes/no) : ")
if age >= 18 and residence.lower() == "yes":
    print(" eligible to drive")
else:
    print(" not eligible to drive") 

##multiple conditions (OR operator)
age = int(input("Enter your age  : "))  
residence = input(" do you have a license? (yes/no) : ")
if age >= 18 or residence.lower() == "yes":
    print(" eligible to register")
else:
    print(" not eligible to register")




