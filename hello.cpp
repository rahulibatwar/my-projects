#include <iostream>
#include <fstream>  // फाइल हैंडलिंग के लिए ज़रूरी है
#include <string>

using namespace std;

class Student {
public:
    int rollNo;
    string name;
    float marks;

    void addRecord() {
        cout << "Enter Roll Number: ";
        cin >> rollNo;
        cout << "Enter Name: ";
        cin.ignore();
        getline(cin, name);
        cout << "Enter Marks: ";
        cin >> marks;
    }

    void displayRecord() {
        cout << "\nRoll No: " << rollNo;
        cout << "\nName: " << name;
        cout << "\nMarks: " << marks;
        cout << "\n-------------------" << endl;
    }
};

// फाइल में डेटा सेव करने का फंक्शन
void saveToFile(Student s) {
    // ios::app का मतलब है नया डेटा पुरानी फाइल के नीचे जुड़ता जाएगा (Append)
    ofstream outFile("students.txt", ios::app); 
    if (outFile.is_open()) {
        outFile << s.rollNo << " " << s.name << " " << s.marks << endl;
        outFile.close();
        cout << "Record saved successfully to file!\n";
    } else {
        cout << "Error opening file!\n";
    }
}

int main() {
    Student s1;
    
    cout << "--- Enter New Student Details ---\n";
    s1.addRecord();   // यूजर से इनपुट लेगा
    
    saveToFile(s1);   // डेटा को students.txt फाइल में सेव कर देगा

    cout << "\n--- Displaying Entered Details ---\n";
    s1.displayRecord(); // स्क्रीन पर दिखाएगा

    return 0;
}