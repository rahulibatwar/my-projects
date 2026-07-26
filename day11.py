# store a secret password in lower case
secret_password = "python@123" 

#ask the user to input a password
user_input = input("Please enter the password: ").lower()  # Convert input to lower

#use .strip () to remove any accidentel extra spaces from their input
user_input = user_input.strip()

#use .strip () so that even if they type PyThOn@123 or PYTHON@123 ,it still matches!

#if the claned input matches secret_password,print "access granted" otherwise print "access denied"
if user_input == secret_password:
    print("Access granted.")
else:
    print("Access denied.")
