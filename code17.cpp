#include <iostream>
#include <vector>
#include <algorithm> // Iske andar std::binary_search hota hai

using namespace std;

int main() {
    cout << "=== ENTERPRISE SECURITY ACCESS REGISTRY (Binary Search) ===" << endl;

    // Rule: Data sorted hona chahiye. Humne unique Employee IDs ko pehle se sorted rakha hai
    vector<int> authorizedIDs = {1002, 2005, 3044, 4500, 5122, 6001, 7789};

    cout << "[INITIALIZED] Security registry loaded with " << authorizedIDs.size() << " sorted IDs.\n\n";

    // CASE 1: Ek valid Employee ID dhoondna
    int searchID1 = 4500;
    cout << "[SCANNING] Scanning badge for Employee ID: " << searchID1 << "...\n";

    // binary_search(start, end, value) -> agar mil gaya toh true (1) return karega, nahi toh false (0)
    if (binary_search(authorizedIDs.begin(), authorizedIDs.end(), searchID1)) {
        cout << "[ACCESS GRANTED] ID " << searchID1 << " verified! Door unlocking...\n\n";
    } else {
        cout << "[ACCESS DENIED] Intruder Alert! ID " << searchID1 << " not found!\n\n";
    }

    // CASE 2: Ek invalid ID dhoondna (Jo security list mein nahi hai)
    int searchID2 = 9999;
    cout << "[SCANNING] Scanning badge for Employee ID: " << searchID2 << "...\n";

    if (binary_search(authorizedIDs.begin(), authorizedIDs.end(), searchID2)) {
        cout << "[ACCESS GRANTED] ID " << searchID2 << " verified!\n\n";
    } else {
        cout << "[ACCESS DENIED] Threat Detected! ID " << searchID2 << " is not registered in our system!\n\n";
    }

    cout << "---------------------------------------------------------\n";
    return 0;
}