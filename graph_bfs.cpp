#include <iostream>
#include <vector>
using namespace std;

// Graph mein undirected edge jodne ke liye
void addEdge(vector<int> adj[], int u, int v) {
    adj[u].push_back(v);
    adj[v].push_back(u);
}

// 🎯 RECURSIVE HELPER FUNCTION FOR DFS
void dfsHelper(int currentNode, vector<int> adj[], vector<bool>& visited) {
    // Current node ko visit mark karein aur print karein
    visited[currentNode] = true;
    cout << currentNode << " ";

    // Uske saare padosiyo ko check karein
    for (int neighbor : adj[currentNode]) {
        // Agar padosi visited nahi hai, toh turant uske andar (depth mein) chalein jayein
        if (!visited[neighbor]) {
            dfsHelper(neighbor, adj, visited);
        }
    }
}

// MAIN DFS FUNCTION
void dfsTraversal(vector<int> adj[], int V, int startNode) {
    vector<bool> visited(V, false); // Sabko shuruat mein unvisited mark kiya
    
    cout << "DFS Traversal Order: ";
    dfsHelper(startNode, adj, visited);
    cout << endl;
}

int main() {
    cout << "--- DSA Masterclass: Graph Depth-First Search (DFS) ---" << endl << endl;

    int V = 5; // Total 5 nodes (0, 1, 2, 3, 4)
    vector<int> adj[V];

    // Same wahi graph jo BFS mein use kiya tha
    addEdge(adj, 0, 1);
    addEdge(adj, 0, 2);
    addEdge(adj, 1, 3);
    addEdge(adj, 1, 4);
    addEdge(adj, 2, 4);

    // Node 0 se depth mein chalna shuru karte hain
    dfsTraversal(adj, V, 0);

    cout << "--------------------------------------------------------" << endl;
    return 0;
}