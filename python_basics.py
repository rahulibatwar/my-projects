print("--- Python Interactive Program ---")

# यूजर से इनपुट लेना (Python में इनपुट हमेशा स्ट्रिंग होता है, इसलिए उम्र को int() में बदला)
user_name = input("Enter your name: ")
user_age = int(input("Enter your age: "))

print(f"\nHello {user_name}!")

# If-Else Condition
if user_age >= 18:
    print("You are eligible to vote! 🗳️")
else:
    print(f"You are minor. Wait for {18 - user_age} more years to vote.")