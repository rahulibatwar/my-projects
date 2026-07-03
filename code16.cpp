#include <iostream>
#include <vector>
#include <algorithm> // Sabse important header aaj ke liye!
#include <string>

using namespace std;

// Server performance track karne ke liye structure
struct ServerNode {
    string serverName;
    int latencyMs; // Speed delay in milliseconds
};

// Custom Comparator Function: Yeh batayega ki sorting kis basis par karni hai
bool compareLatency(const ServerNode& a, const ServerNode& b) {
    return a.latencyMs < b.latencyMs; // Choti latency (fast server) pehle aayegi
}

int main() {
    cout << "=== ENTERPRISE SERVER ANALYTICS ENGINE (STL Algorithms) ===" << endl;

    // Alag-alag servers ka data ek vector mein store kiya
    vector<ServerNode> cluster = {
        {"Mumbai-Edge-03", 45},
        {"Pune-Core-01", 12},
        {"Bangalore-DB-02", 88},
        {"Delhi-Backup-04", 120}
    };

    cout << "[BEFORE SORTING] Raw server cluster latency logs loaded.\n\n";

    // 1. STL std::sort ka kamaal!
    // Yeh pure cluster ko quick-sort algorithm ke zariye automatic sort kar dega
    sort(cluster.begin(), cluster.end(), compareLatency);

    cout << "[OPTIMIZED] Servers sorted by lowest latency (Fastest First):\n";
    cout << "---------------------------------------------------------\n";
    for (const auto& server : cluster) {
        cout << "  -> " << server.serverName << " | Latency: " << server.latencyMs << "ms";
        if (server.latencyMs < 20) cout << " [⚡ ULTRA FAST]";
        cout << "\n";
    }
    cout << "---------------------------------------------------------\n\n";

    // 2. STL std::reverse ka use karke order ulta karna (Slowest First)
    cout << "[MAINTENANCE] Reversing order to find slowest servers:\n";
    reverse(cluster.begin(), cluster.end());

    for (const auto& server : cluster) {
        cout << "  -> " << server.serverName << " | Latency: " << server.latencyMs << "ms\n";
    }
    cout << "---------------------------------------------------------\n";

    return 0;
}