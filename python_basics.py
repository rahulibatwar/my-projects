print("\n--- Python Dictionary & Functions ---")

# 1. एक फ़ंक्शन बनाते हैं जो स्टूडेंट का डेटा प्रिंट करेगा
def display_student_info(student):
    print(f"Student Name: {student['name']}")
    print(f"Enrollment ID: {student['id']}")
    print(f"Technical Skills: {', '.join(student['skills'])}")

# 2. एक डिक्शनरी (Key-Value) तैयार करते हैं
student_data = {
    "name": "Rahul",
    "id": 101,
    "skills": ["C++", "Data Structures", "Python"]
}

# 3. फ़ंक्शन को कॉल करते हैं
display_student_info(student_data)