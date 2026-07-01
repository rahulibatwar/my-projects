#include <iostream>
#include <vector>
using namespace std;

// Helper function to add edges
void addEdge(vector<vector<int>>& adj, int u, int v) {
    adj[u].push_back(v);
    adj[v].push_back(u);
}

// Recursive helper function for DFS traversal
void dfsHelper(int node, const vector<vector<int>>& adj, vector<bool>& visited) {
    // 1. Current node ko visited mark karo aur print karo
    visited[node] = true;
    cout << node << " ";

    // 2. Us current node ke saare neighbors ko check karo
    for (int neighbor : adj[node]) {
        // Agar neighbor visited nahi hai, toh recursively uski depth mein jao
        if (!visited[neighbor]) {
            dfsHelper(neighbor, adj, visited);
        }
    }
}

// Main DFS Driver Function
void dfsGraph(const vector<vector<int>>& adj, int startNode, int V) {
    vector<bool> visited(V, false);
    
    cout << "DFS Traversal starting from Node " << startNode << ": ";
    // Helper function ko call kiya depth track karne ke liye
    dfsHelper(startNode, adj, visited);
    cout << endl;
}

int main() {
    cout << "--- DSA Masterclass: Depth-First Search (DFS) ---" << endl << endl;

    int V = 5; // Same 5 vertices setup (0 to 4)
    vector<vector<int>> adj(V);

    // Standard graph connections build karte hain
    addEdge(adj, 0, 1);
    addEdge(adj, 0, 4);
    addEdge(adj, 1, 2);
    addEdge(adj, 1, 3);
    addEdge(adj, 1, 4);
    addEdge(adj, 2, 3);
    addEdge(adj, 3, 4);

    // Node 0 se depth search start karte hain
    dfsGraph(adj, 0, V);

    cout << "---------------------------------------------------" << endl;
    return 0;
}