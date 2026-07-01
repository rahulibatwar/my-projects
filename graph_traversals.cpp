#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Graph {
    int V;
    vector<vector<int>> adj;

public:
    Graph(int vertices) {
        V = vertices;
        adj.resize(vertices);
    }

    void addEdge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u); // Undirected link
    }

    // 1. BFS Traversal Engine
    void BFS(int startNode) {
        vector<bool> visited(V, false);
        queue<int> q;

        visited[startNode] = true;
        q.push(startNode);

        while (!q.empty()) {
            int curr = q.front();
            q.pop();
            cout << curr << " ";

            // Saare adjacent neighbors ko queue mein daalo agar visited nahi hain
            for (int neighbor : adj[curr]) {
                if (!visited[neighbor]) {
                    visited[neighbor] = true;
                    q.push(neighbor);
                }
            }
        }
        cout << endl;
    }

    // Helper function for DFS recursion
    void DFSUtil(int node, vector<bool>& visited) {
        visited[node] = true;
        cout << node << " ";

        // Gehrai mein jao recursion ke saath
        for (int neighbor : adj[node]) {
            if (!visited[neighbor]) {
                DFSUtil(neighbor, visited);
            }
        }
    }

    // 2. DFS Traversal Engine
    void DFS(int startNode) {
        vector<bool> visited(V, false);
        DFSUtil(startNode, visited);
        cout << endl;
    }
};

int main() {
    cout << "--- DSA Masterclass: Graph Traversals (BFS & DFS) ---" << endl << endl;

    Graph g(5);
    // Same previous graph graph configuration setup karte hain
    g.addEdge(0, 1);
    g.addEdge(0, 4);
    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 4);
    g.addEdge(2, 3);
    g.addEdge(3, 4);

    cout << "BFS Traversal starting from Node 0: " << endl;
    g.BFS(0);

    cout << endl << "DFS Traversal starting from Node 0: " << endl;
    g.DFS(0);

    cout << "-----------------------------------------------------" << endl;
    return 0;
}