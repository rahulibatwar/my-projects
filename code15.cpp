#include <iostream>
#include <deque>
#include <string>

using namespace std;

int main() {
    cout << "=== ENTERPRISE SLIDING WINDOW LOG SYSTEM (STL Deque) ===" << endl;

    // Deque banaya jo dono taraf se dynamic insertion support karta hai
    deque<string> serverLogs;

    // 1. Logs ko back aur front dono taraf se insert karna
    serverLogs.push_back("LOG [01]: User logged in successfully.");
    serverLogs.push_back("LOG [02]: Database query executed in 5ms.");
    
    // Maan lijiye system shuru hote hi koi critical log sabse aage lagana ho:
    serverLogs.push_front("CRITICAL [00]: Firewall initialized successfully."); 

    cout << "[SYSTEM] Initial logs captured. Active Buffer Size: " << serverLogs.size() << "\n\n";

    // Current window ko print karna
    cout << "Current Log Window:\n";
    for (const string& log : serverLogs) {
        cout << "  -> " << log << "\n";
    }
    cout << "---------------------------------------------------------\n\n";

    // 2. Sliding Window Mechanism (Buffer limits to max 3 logs)
    cout << "[NEW EVENT] High traffic incoming. Pushing new log to back...\n";
    serverLogs.push_back("LOG [03]: CPU usage peaked at 85%.");

    // Agar logs size 3 se zyada ho jaye, toh sabse purana log aage se hata do
    if (serverLogs.size() > 3) {
        cout << "[CLEANUP] Buffer full! Automatically removing oldest log from front: \n";
        cout << "          \"" << serverLogs.front() << "\"\n";
        
        serverLogs.pop_front(); // Front se remove kiya instant speed mein
    }

    // 3. Updated Sliding Window Logs ko display karna
    cout << "\nUpdated Sliding Window Logs (Latest 3):\n";
    for (const string& log : serverLogs) {
        cout << "  -> " << log << "\n";
    }
    cout << "---------------------------------------------------------\n";

    return 0;
}