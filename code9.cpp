#include <iostream>
#include <vector> // Required for using STL Vectors
#include <string>

using namespace std;

int main() {
    vector<string> serverCluster;

    cout << "--- ENTERPRISE SERVER CLUSTER MANAGEMENT ---" << endl;

    // 1. Adding elements dynamically
    serverCluster.push_back("Mumbai-Node-01");
    serverCluster.push_back("Bangalore-Node-02");
    serverCluster.push_back("Chennai-Node-03");

    cout << "[INITIALIZED] Active servers in cluster: " << serverCluster.size() << endl;

    // 2. Displaying elements
    cout << "\nListing Active Nodes:" << endl;
    for (const string& server : serverCluster) {
        cout << " -> " << server << " [ONLINE]" << endl;
    }

    // 3. Removing the last server
    cout << "\n[MAINTENANCE] Deactivating the last node..." << endl;
    serverCluster.pop_back();

    // 4. Checking updated status
    cout << "\nUpdated Active Nodes:" << endl;
    for (size_t i = 0; i < serverCluster.size(); i++) {
        cout << " -> Index [" << i << "]: " << serverCluster[i] << " [RUNNING]" << endl;
    }

    cout << "--------------------------------------------" << endl;
    return 0;
}
