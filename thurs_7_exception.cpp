#include <iostream>
#include <string>
#include <stdexcept> // Required for standard exceptions

using namespace std;

// Custom Exception Class for Server Failures
class DatabaseTimeoutException : public runtime_error {
public:
    // Passing error message to the base runtime_error class
    DatabaseTimeoutException(const string& msg) : runtime_error(msg) {}
};

class EnterpriseDatabase {
public:
    void connectToServer(int pingRate) {
        cout << "[CONNECTING] Accessing Mainframe Database..." << endl;
        
        // Simulating a network failure if ping is too high
        if (pingRate > 200) {
            throw DatabaseTimeoutException("CRITICAL ERROR: Database response timed out! Ping is above 200ms.");
        }
        
        cout << "[SUCCESS] Secure connection established with Database." << endl;
    }
};

int main() {
    EnterpriseDatabase db;
    int currentPing = 350; // Simulating poor network condition

    // 'try' block contains the code that might throw an error
    try {
        cout << "--- STARTING BANKING DATABASE SYSTEM ---" << endl;
        db.connectToServer(currentPing);
    }
    // 'catch' block handles the specific exception thrown
    catch (const DatabaseTimeoutException& e) {
        cout << "\n[ALERT-CAUGHT] " << e.what() << endl;
        cout << "[FALLBACK ROUTINE] Activating Backup Local Storage Mirror Node..." << endl;
    }
    catch (const exception& e) {
        // Catch-all for any other generic standard exceptions
        cout << "[GENERIC ERROR] " << e.what() << endl;
    }

    cout << "\n[STATUS] System running smoothly in Fallback Mode. Program did not crash!" << endl;
    cout << "----------------------------------------" << endl;

    return 0;
}