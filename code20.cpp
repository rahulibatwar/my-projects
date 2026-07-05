#include <iostream>
#include <vector>
#include <algorithm> // Iske andar std::find hota hai
#include <string>

using namespace std;

int main() {
    cout << "=== ENTERPRISE SESSION THREAT DETECTOR (STL Find) ===" << endl;

    // Server par chal rahe live and unsorted active session tokens
    vector<string> activeSessions = {"ST-9942", "ST-1102", "ST-5581", "ST-8821", "ST-3341"};

    cout << "[SYSTEM] Total active sessions in buffer: " << activeSessions.size() << "\n\n";

    // CASE 1: Ek valid active token ko dhoondna
    string targetSession1 = "ST-5581";
    cout << "[SCANNING] Verification request for token: " << targetSession1 << "...\n";

    // std::find(start, end, target_value)
    // Yeh element milne par uska iterator (pointer) return karega. Agar nahi mila, toh vector ke end() par rukega.
    auto it1 = find(activeSessions.begin(), activeSessions.end(), targetSession1);

    if (it1 != activeSessions.end()) {
        // distance() function se hum pata karte hain ki element kis index par mila hai
        int index = distance(activeSessions.begin(), it1);
        cout << "[SUCCESS] Token verified! Session is alive at Index [" << index << "].\n";
        cout << "          Access granted to the secure network.\n\n";
    } else {
        cout << "[SECURITY ALERT] Token not found! Access Denied.\n\n";
    }

    // CASE 2: Ek fake/expired token ko dhoondna
    string targetSession2 = "ST-0000";
    cout << "[SCANNING] Verification request for token: " << targetSession2 << "...\n";

    auto it2 = find(activeSessions.begin(), activeSessions.end(), targetSession2);

    if (it2 != activeSessions.end()) {
        cout << "[SUCCESS] Token verified!\n\n";
    } else {
        cout << "[SECURITY ALERT] Threat Detected! Token \"" << targetSession2 << "\" is invalid or expired!\n";
        cout << "                 IP address logged for auditing.\n";
    }

    cout << "---------------------------------------------------------\n";
    return 0;
}
