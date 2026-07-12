print("--- Python Object-Oriented Programming (OOPs) ---")

class Student:
    # Constructor (पाइथन में इसे __init__ कहते हैं)
    def __init__(self, name, roll_no):
        self.name = name          # Instance Variable
        self.roll_no = roll_no    # Instance Variable

    # एक सिंपल Method (फ़ंक्शन)
    def introduce(self):
        print(f"Hi, I am {self.name} and my Roll Number is {self.roll_no}.")

# Object बनाना (पाइथन में new कीवर्ड की कोई जरूरत नहीं होती)
student1 = Student("Rahul", 101)
student2 = Student("Soham", 102)

# Methods को कॉल करना
student1.introduce()
student2.introduce()