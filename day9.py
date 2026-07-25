#ask the user to enter today's date
user_date = input("Please enter today's date (YYYY-MM-DD): ")
print(user_date)

#ask the user to enter a diary entry 
diary_entry = input("Please enter your diary entry for today: ")
print(diary_entry)

#open a file called diary.txt in  append mode and write the date and diary entry
with open("diary.txt", "a") as diary_file:
    diary_file.write(f"{user_date}: {diary_entry}\n")

#open diary.txt in read mode and display all past entries on the screen
with open("diary.txt", "r") as diary_file:
    print("\nPast diary entries:")
    for line in diary_file:
        print(line.strip())

        