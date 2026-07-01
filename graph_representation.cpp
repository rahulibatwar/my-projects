#include <iostream>
#include <vector>
using namespace std;

// Function to add an edge between two nodes (u and v)
void addEdge(vector<vector<int>>& adj, int u, int v) {
    // Kyunki ye un-directed graph hai, toh rasta dono taraf se hoga
    adj[u].push_back(v);
    adj[v].push_back(u);
}

// Function to print the adjacency list representation
void printGraph(const vector<vector<int>>& adj, int V) {
    cout << "--- Adjacency List Representation of Graph ---" << endl << endl;
    for (int i = 0; i < V; i++) {
        cout << "Node " << i << " is connected to: ";
        for (int x : adj[i]) {
            cout << x << " -> ";
        }
        cout << "NULL" << endl;
    }
    cout << "-----------------------------------------------" << endl;
}

int main() {
    cout << "--- DSA Masterclass: Graph Representation ---" << endl << endl;

    int V = 5; // Maan lete hain hamare paas 5 Nodes hain (0 se 4)
    
    // 2D Vector (Array of Vectors) banaya graph store karne ke liye
    vector<vector<int>> adj(V);

    // Edges add karte hain
    addEdge(adj, 0, 1);
    addEdge(adj, 0, 4);
    addEdge(adj, 1, 2);
    adj[1].push_back(3); adj[3].push_back(1); // addEdge function jaisa hi direct logic
    addEdge(adj, 1, 4);
    addEdge(adj, 2, 3);
    addEdge(adj, 3, 4);

    // Graph ko display karte hain
    printGraph(adj, V);

    return 0;
}