# 1. Create an empty dictionary
contact = {}

# 2. Ask user for input
contact["Name"] = input("Enter Name: ")
contact["Age"] = int(input("Enter Age: "))
contact["Gender"] = input("Enter Gender: ")
contact["Phone"] = input("Enter Phone: ")
contact["Email"] = input("Enter Email: ")
contact["Address"] = input("Enter Address: ")


# 3. Print the contact card using a loop
print("\n--- Contact Card ---")
for key, value in contact.items():
    print(f"{key}: {value}")