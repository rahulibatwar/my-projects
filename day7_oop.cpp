#include <iostream>
using namespace std;

// Parent Class 1: Academic Marks
class Academic {
public:
    float theoryMarks;

    void setAcademicMarks(float m) {
        theoryMarks = m;
    }
};

// Parent Class 2: Sports Score
class Sports {
public:
    float sportsScore;

    void setSportsScore(float s) {
        sportsScore = s;
    }
};

// Child Class: 2 Parents से inherit कर रही है
class StudentResult : public Academic, public Sports {
public:
    string name;

    void displayResult(string n) {
        name = n;
        float total = theoryMarks + sportsScore;
        
        cout << "Student Name : " << name << endl;
        cout << "Theory Marks : " << theoryMarks << endl;
        cout << "Sports Score : " << sportsScore << endl;
        cout << "Total Marks  : " << total << endl;
    }
};

int main() {
    cout << "=== MULTIPLE INHERITANCE DEMO ===" << endl;

    // Child Class का Object
    StudentResult res;

    // Parent Class 1 का Function Call
    res.setAcademicMarks(85.5);

    // Parent Class 2 का Function Call
    res.setSportsScore(10.0);

    cout << "\n--- Final Result Details ---" << endl;
    res.displayResult("Rahul");

    return 0;
}