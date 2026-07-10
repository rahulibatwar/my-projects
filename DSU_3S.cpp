#include <iostream>
#include <vector>

using namespace std;

class DisjointSet {
    vector<int> parent;

public:
    // Constructor: शुरुआत में हर एलिमेंट खुद का पैरेंट/बॉस होता है
    DisjointSet(int n) {
        parent.resize(n);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    // Find Operation (with Path Compression Optimization)
    int find(int i) {
        if (parent[i] == i)
            return i;
        
        // Path Compression
        return parent[i] = find(parent[i]);
    }

    // Union Operation
    void unionSets(int i, int j) {
        int root_i = find(i);
        int root_j = find(j);

        if (root_i != root_j) {
            parent[root_i] = root_j;
            cout << "[SUCCESS] Joined group of " << i << " and " << j << "\n";
        } else {
            cout << "[INFO] " << i << " and " << j << " are already in the same group.\n";
        }
    }
};

int main() {
    int n = 5;
    DisjointSet dsu(n); // 0 से 4 तक 5 एलिमेंट्स बनाए

    cout << "--- DSU Operations ---" << endl;
    dsu.unionSets(0, 2);
    dsu.unionSets(4, 2);
    dsu.unionSets(3, 1);

    cout << "\n--- Checking Connections ---" << endl;
    // चेक करते हैं कि 0 और 4 एक ही ग्रुप में हैं या नहीं
    if (dsu.find(0) == dsu.find(4)) {
        cout << "0 and 4 are in the same group!\n";
    } else {
        cout << "0 and 4 are in different groups.\n";
    }

    return 0;
}