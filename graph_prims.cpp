#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// Weighted edge structure
struct Edge {
    int target;
    int weight;
};

// Function to add a weighted undirected edge
void addEdge(vector<vector<Edge>>& adj, int u, int v, int w) {
    adj[u].push_back({v, w});
    adj[v].push_back({u, w});
}

// Core Prim's Algorithm Function
void primsMST(const vector<vector<Edge>>& adj, int V) {
    // Priority Queue to store pair <weight, node>
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    
    // Track visited nodes which are included in MST
    vector<bool> inMST(V, false);
    
    int mst_weight = 0; // Total cost of MST

    // Node 0 se shuru karte hain. Shuruati cost 0 hoga.
    pq.push({0, 0});

    cout << "--- Edges Included in the Minimum Spanning Tree ---" << endl;

    while (!pq.empty()) {
        int w = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        // Agar node pehle se MST ka hissa hai, toh skip karein
        if (inMST[u]) continue;

        // Node ko MST mein shamil karein aur cost add karein
        inMST[u] = true;
        mst_weight += w;

        if (w != 0) {
            cout << "Included Edge with weight: " << w << " (Reached Node " << u << ")" << endl;
        }

        // Neighbors ko check karein
        for (const auto& edge : adj[u]) {
            int v = edge.target;
            int weight = edge.weight;

            // Agar neighbor abhi tak MST mein nahi hai, toh queue mein daalein
            if (!inMST[v]) {
                pq.push({weight, v});
            }
        }
    }

    cout << endl << "Total Weight of the Minimum Spanning Tree: " << mst_weight << endl;
    cout << "---------------------------------------------------" << endl;
}

int main() {
    cout << "--- DSA Masterclass: Prim's Minimum Spanning Tree ---" << endl << endl;

    int V = 4; // 4 Nodes (0 se 3)
    vector<vector<Edge>> adj(V);

    // Graph setup (Connecting nodes with weights)
    addEdge(adj, 0, 1, 10);
    addEdge(adj, 0, 2, 6);
    addEdge(adj, 0, 3, 5);
    addEdge(adj, 1, 3, 15);
    addEdge(adj, 2, 3, 4);

    // Call Prim's Algorithm
    primsMST(adj, V);

    return 0;
}