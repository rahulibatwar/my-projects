#include <iostream>
#include <vector>
using namespace std;

void addEdge(vector<int> adj[], int u, int v) {
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void dfsHelper(int currentNode, vector<int> adj[], vector<bool>& visited) {
    visited[currentNode] = true;
    cout << currentNode << " ";

    for (int neighbor : adj[currentNode]) {
        if (!visited[neighbor]) {
            dfsHelper(neighbor, adj, visited);
        }
    }
}

void dfsTraversal(vector<int> adj[], int V, int startNode) {
    vector<bool> visited(V, false);
    cout << "DFS Traversal Order: ";
    dfsHelper(startNode, adj, visited);
    cout << endl;
}

int main() {
    cout << "--- DSA Masterclass: Graph Depth-First Search (DFS) ---" << endl << endl;
    int V = 5;
    vector<int> adj[V];

    addEdge(adj, 0, 1);
    addEdge(adj, 0, 2);
    addEdge(adj, 1, 3);
    addEdge(adj, 1, 4);
    addEdge(adj, 2, 4);

    dfsTraversal(adj, V, 0);
    cout << "--------------------------------------------------------" << endl;
    return 0;
}