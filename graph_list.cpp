#include <iostream>
#include <vector>
using namespace std;

// Graph mein edge (connection) add karne ka function
void addEdge(vector<int> adj[], int u, int v) {
    adj[u].push_back(v);
    adj[v].push_back(u); // Kyunki undirected graph hai
}

// Graph ko print karne ka dynamic function
void printGraph(vector<int> adj[], int V) {
    cout << "--- Adjacency List Representation ---" << endl;
    for (int i = 0; i < V; i++) {
        cout << "Vertex " << i << " is connected to: ";
        for (int neighbor : adj[i]) {
            cout << neighbor << " ";
        }
        cout << endl;
    }
}

int main() {
    cout << "--- DSA Masterclass: Graph Adjacency List ---" << endl << endl;

    int V = 4; // Total 4 vertices (0, 1, 2, 3)
    vector<int> adj[V]; // Array of vectors

    // Connections setup karte hain
    addEdge(adj, 0, 1);
    addEdge(adj, 1, 2);
    addEdge(adj, 2, 3);
    addEdge(adj, 3, 0);

    // Print output
    printGraph(adj, V);

    cout << "-----------------------------------------------" << endl;
    return 0;
}