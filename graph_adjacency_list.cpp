#include <iostream>
#include <vector>
using namespace std;

// Graph class dynamically adjacency list handle karne ke liye
class Graph {
    int V; // Number of Vertices
    vector<vector<int>> adj; // Vector of vectors (Adjacency List)

public:
    // Constructor
    Graph(int vertices) {
        V = vertices;
        adj.resize(vertices);
    }

    // Function to add an edge (Undirected Graph)
    void addEdge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u); // Kyunki yeh undirected hai, toh dono taraf link banega
    }

    // Function to print the complete adjacency list layout
    void printGraph() {
        cout << "--- Adjacency List Representation ---" << endl;
        for (int i = 0; i < V; i++) {
            cout << "Node " << i << " is connected to: ";
            for (int neighbor : adj[i]) {
                cout << neighbor << " -> ";
            }
            cout << "NULL" << endl;
        }
    }
};

int main() {
    cout << "--- DSA Masterclass: Graph Framework Development ---" << endl << endl;

    // 5 vertices wala graph banate hain (Nodes: 0, 1, 2, 3, 4)
    Graph g(5);

    // Edges setup karte hain
    g.addEdge(0, 1);
    g.addEdge(0, 4);
    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 4);
    g.addEdge(2, 3);
    g.addEdge(3, 4);

    // Graph configuration print karte hain
    g.printGraph();

    cout << "-----------------------------------------------------" << endl;
    return 0;
}