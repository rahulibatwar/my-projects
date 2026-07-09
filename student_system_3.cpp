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

    void input() {
        cout << "Enter Roll Number: ";
        cin >> rollNo;
        cout << "Enter Name: ";
        cin.ignore();
        getline(cin, name);
        cout << "Enter Marks: ";
        cin >> marks;
    }

    void displayRow() const {
        cout << left << setw(10) << rollNo 
             << setw(25) << name 
             << setw(10) << fixed << setprecision(2) << marks << endl;
    }
};

// ==========================================
// 2. REPOSITORY LAYER (डेटाबेस हैंडलिंग)
// ==========================================
class StudentRepository {
private:
    const string fileName = "database.txt";

public:
    // CREATE: नया रिकॉर्ड जोड़ें
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

    // READ: सभी रिकॉर्ड्स दिखाएं
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

    // UPDATE: रोल नंबर के आधार पर डेटा बदलें
    void updateStudent(int targetRoll) {
        ifstream inFile(fileName);
        if (!inFile.is_open()) {
            cout << "\n[ERROR] Database not found!\n";
            return;
        }

        ofstream tempFile("temp.txt"); // बदलावों को स्टोर करने के लिए टेम्पररी फ़ाइल
        string line;
        bool found = false;

        while (getline(inFile, line)) {
            if (line.empty()) continue;
            size_t pos1 = line.find(',');
            int roll = stoi(line.substr(0, pos1));

            if (roll == targetRoll) {
                found = true;
                cout << "\n[MATCH FOUND] Enter New Details for Roll No " << targetRoll << ":\n";
                Student newDetails;
                newDetails.rollNo = targetRoll; // रोल नंबर वही रहेगा
                cout << "Enter New Name: ";
                cin.ignore();
                getline(cin, newDetails.name);
                cout << "Enter New Marks: ";
                cin >> newDetails.marks;

                // टेम्पररी फ़ाइल में नया डेटा लिखें
                tempFile << newDetails.rollNo << "," << newDetails.name << "," << newDetails.marks << endl;
            } else {
                // बाकी स्टूडेंट्स का पुराना डेटा वैसा ही रहेगा
                tempFile << line << endl;
            }
        }

        inFile.close();
        tempFile.close();

        // पुरानी फ़ाइल हटाकर टेम्पररी फ़ाइल का नाम बदलें
        remove(fileName.c_str());
        rename("temp.txt", fileName.c_str());

        if (found) cout << "\n[SUCCESS] Record updated successfully!\n";
        else cout << "\n[INFO] Student with Roll No " << targetRoll << " not found.\n";
    }

    // DELETE: रोल नंबर के आधार पर रिकॉर्ड हटाएं
    void deleteStudent(int targetRoll) {
        ifstream inFile(fileName);
        if (!inFile.is_open()) {
            cout << "\n[ERROR] Database not found!\n";
            return;
        }

        ofstream tempFile("temp.txt");
        string line;
        bool found = false;

        while (getline(inFile, line)) {
            if (line.empty()) continue;
            size_t pos1 = line.find(',');
            int roll = stoi(line.substr(0, pos1));

            if (roll == targetRoll) {
                found = true; // इस स्टूडेंट की लाइन को टेम्पररी फ़ाइल में नहीं लिखेंगे (यानी डिलीट)
                continue;
            }
            tempFile << line << endl;
        }

        inFile.close();
        tempFile.close();

        remove(fileName.c_str());
        rename("temp.txt", fileName.c_str());

        if (found) cout << "\n[SUCCESS] Record deleted successfully!\n";
        else cout << "\n[INFO] Student with Roll No " << targetRoll << " not found.\n";
    }
};

// ==========================================
// 3. PRESENTATION LAYER (यूजर इंटरफेस)
// ==========================================
int main() {
    StudentRepository repo;
    int choice;

    do {
        cout << "\n*** ARCHITECT LEVEL CRUD SYSTEM ***\n";
        cout << "1. Add New Student Record (Create)\n";
        cout << "2. View All Student Records (Read)\n";
        cout << "3. Update Student Record (Update)\n";
        cout << "4. Delete Student Record (Delete)\n";
        cout << "5. Exit Application\n";
        cout << "Enter your choice (1-5): ";

        if (!(cin >> choice)) {
            cout << "\n[ERROR] Please enter a valid number!\n";
            cin.clear();          
            cin.ignore(1000, '\n'); 
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
                cout << "\nEnter Roll Number to UPDATE: ";
                cin >> roll;
                repo.updateStudent(roll);
                break;
            }
            case 4: {
                int roll;
                cout << "\nEnter Roll Number to DELETE: ";
                cin >> roll;
                repo.deleteStudent(roll);
                break;
            }
            case 5:
                cout << "\nShutting down system. Thank you!\n";
                break;
            default:
                cout << "\n[WARNING] Invalid choice! Please select between 1-5.\n";
        }
    } while (choice != 5);

    return 0;
}