class Student:
    # The __init__ method is the 'Constructor'
    # It initializes the object's properties when it is created
    def __init__(self, name, age, grade):
        self.name = name
        self.age = age
        self.grade = grade

    # A custom method (action) inside the class
    def introduce(self):
        print(f"Hi, I'm {self.name}, {self.age} years old, in Grade {self.grade}.")


# Creating Object 1 from the Student blueprint
student1 = Student("Alex", 15, "10th")

# Creating Object 2
student2 = Student("Rahul", 16, "11th")

# Calling methods on objects
student1.introduce()  # Output: Hi, I'm Alex, 15 years old, in Grade 10th.
student2.introduce()  # Output: Hi, I'm Rahul, 16 years old, in Grade 11th.