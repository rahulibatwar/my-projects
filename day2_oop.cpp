#include <iostream>
using namespace std;

class Student {
private:
    // Private: ये डायरेक्ट main() से चेंज नहीं हो सकते
    int rollNo;
    float percentage;

public:
    string name;

    // Data set करने के लिए Member Function (Setter)
    void setData(int r, float p) {
        rollNo = r;
        percentage = p;
    }

    // Data display करने के लिए Member Function (Getter)
    void displayDetails() {
        cout << "\n--- Student Details ---" << endl;
        cout << "Name: " << name << endl;
        cout << "Roll No: " << rollNo << endl;
        cout << "Percentage: " << percentage << "%" << endl;
    }
};

int main() {
    Student s1;
    Student s2;
    Student s3;

    
    // Public Variable को सीधे एक्सेस कर सकते हैं
    s1.name = "Rahul"; 
    s2.name = "Priya";
    s3.name = "Amit";

    // s1.rollNo = 101; // <-- अगर इस लाइन से कमेंट हटायेंगे तो ERROR आयेगा!

    // Private variables में वैल्यू डालने के लिए function का इस्तेमाल करेंगे
    s1.setData(101, 88.5);
    s1.displayDetails();
    
    s2.setData(102, 92.0);
    s2.displayDetails();

    s3.setData(103, 78.5);
    s3.displayDetails();

    return 0;
}