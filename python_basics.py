print("--- Python Lists & Loops ---")

# एक लिस्ट बनाते हैं मार्क्स की
marks = [75, 82, 90, 45, 60]

# 1. लिस्ट में एक नया मार्क जोड़ना (C++ के push_back की तरह)
marks.append(95)
print(f"Updated Marks List: {marks}")

# 2. लूप चलाकर चेक करना कि कौन पास हुआ (Pass mark = 50)
print("\nStudent Results:")
for m in marks:
    if m >= 50:
        print(f"Score {m}: PASSED 🎉")
    else:
        print(f"Score {m}: FAILED ❌")