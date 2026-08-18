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

