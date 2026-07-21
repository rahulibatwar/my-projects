# collage result calculator
# ask the user to enter their marks
marks = float(input("enter your marks: "))

if marks >= 90:
    # notice the 4 space indent!
    print("grade A")
elif marks >= 80:
    print("grade B")
elif marks >= 70:
    print("grade C")
elif marks >= 60:
    print("grade D")
else:
    print("fail")
