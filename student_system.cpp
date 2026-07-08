#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;

// ==========================================
// 1. MODEL LAYER (डेटा का ढांचा)
// ==========================================
class Student {
public:
    int rollNo;
    string name;
    float marks;

    // डेटा इनपुट लेने के लिए
    void input() {
        cout << "Enter Roll Number: ";
        cin >> rollNo;
        cout << "Enter Name: ";
        cin.ignore();
        getline(cin, name);
        cout << "Enter Marks: ";
        cin >> marks;
    }

    // डेटा को टेबल फॉर्मेट में दिखाने के लिए
    void displayRow() const {
        cout << left << setw(10) << rollNo 
             << setw(25) << name 
             << setw(10) << fixed << setprecision(2) << marks << endl;
    }
};

// ==========================================
// 2. ARCHITECT / REPOSITORY LAYER (डेटाबेस हैंडलिंग)
// ==========================================
class StudentRepository {
private:
    const string fileName = "database.txt";

public:
    // नया रिकॉर्ड फाइल में जोड़ने के लिए (Create)
    void addStudent(const Student& s) {
        ofstream outFile(fileName, ios::app);
        if (outFile.is_open()) {
            outFile << s.rollNo << "," << s.name << "," << s.marks << endl;
            outFile.close();
            cout << "\n[SUCCESS] Record saved successfully!\n";
        } else {
            cout << "\n[ERROR] Database file could not be opened!\n";
        }
    }

    // सभी रिकॉर्ड्स को फाइल से पढ़कर दिखाने के लिए (Read)
    void displayAll() {
        ifstream inFile(fileName);
        if (!inFile.is_open()) {
            cout << "\n[INFO] No records found. Add a student first!\n";
            return;
        }

        string line;
        cout << "\n==================================================\n";
        cout << left << setw(10) << "Roll No" << setw(25) << "Name" << setw(10) << "Marks" << endl;
        cout << "==================================================\n";

        while (getline(inFile, line)) {
            if (line.empty()) continue;
            
            // CSV Parsing (कोमा से डेटा अलग करना)
            size_t pos1 = line.find(',');
            size_t pos2 = line.rfind(',');

            if (pos1 != string::npos && pos2 != string::npos && pos1 != pos2) {
                Student s;
                s.rollNo = stoi(line.substr(0, pos1));
                s.name = line.substr(pos1 + 1, pos2 - pos1 - 1);
                s.marks = stof(line.substr(pos2 + 1));
                s.displayRow();
            }
        }
        cout << "==================================================\n";
        inFile.close();
    }

    // किसी खास रोल नंबर को सर्च करने के लिए (Search)
    void searchByRoll(int targetRoll) {
        ifstream inFile(fileName);
        if (!inFile.is_open()) {
            cout << "\n[ERROR] No database found!\n";
            return;
        }

        string line;
        bool found = false;

        while (getline(inFile, line)) {
            size_t pos1 = line.find(',');
            int roll = stoi(line.substr(0, pos1));

            if (roll == targetRoll) {
                size_t pos2 = line.rfind(',');
                cout << "\n[MATCH FOUND]:\n";
                cout << "Roll No: " << roll << "\nName: " << line.substr(pos1 + 1, pos2 - pos1 - 1) 
                     << "\nMarks: " << line.substr(pos2 + 1) << endl;
                found = true;
                break;
            }
        }
        if (!found) cout << "\n[INFO] Student with Roll No " << targetRoll << " not found.\n";
        inFile.close();
    }
};

// ==========================================
// 3. PRESENTATION LAYER (यूजर इंटरफेस / मेनू)
// ==========================================
int main() {
    StudentRepository repo;
    int choice;

    do {
        cout << "\n*** ARCHITECT LEVEL STUDENT SYSTEM ***\n";
        cout << "1. Add New Student Record\n";
        cout << "2. View All Student Records\n";
        cout << "3. Search Student by Roll Number\n";
        cout << "4. Exit Application\n";
        cout << "Enter your choice (1-4): ";
if (!(cin >> choice)) {
    cout << "\n[ERROR] Please enter a valid number!\n";
    cin.clear();          // cin की एरर स्टेट को साफ़ करेगा
    cin.ignore(1000, '\n'); // खराब इनपुट बफ़र को डिलीट करेगा
    continue;
}

        switch (choice) {
            case 1: {
                Student s;
                cout << "\n--- Enter Details ---\n";
                s.input();
                repo.addStudent(s);
                break;
            }
            case 2:
                repo.displayAll();
                break;
            case 3: {
                int roll;
                cout << "\nEnter Roll Number to search: ";
                cin >> roll;
                repo.searchByRoll(roll);
                break;
            }
            case 4:
                cout << "\nShutting down system. Thank you!\n";
                break;
            default:
                cout << "\n[WARNING] Invalid choice! Please select between 1-4.\n";
        }
    } while (choice != 4);

    return 0;
}