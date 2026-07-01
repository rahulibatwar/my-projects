#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// Function to add an edge to our undirected graph
void addEdge(vector<vector<int>>& adj, int u, int v) {
    adj[u].push_back(v);
    adj[v].push_back(u);
}

// Core BFS Algorithm Function
void bfsGraph(const vector<vector<int>>& adj, int startNode, int V) {
    // 1. Ek boolean array banayein tracked vertices ke liye (Sab shuru mein false hain)
    vector<bool> visited(V, false);
    
    // 2. BFS ke liye ek standard queue banayein
    queue<int> q;

    // 3. Start node ko visited mark karein aur queue mein push karein
    visited[startNode] = true;
    q.push(startNode);

    cout << "BFS Traversal starting from Node " << startNode << ": ";

    while (!q.empty()) {
        // Queue ke samne wale element ko nikalie
        int curr = q.front();
        q.pop();
        
        cout << curr << " ";

        // Us current node ke saare neighbors ko check karein
        for (int neighbor : adj[curr]) {
            // Agar neighbor abhi tak visited nahi hai, toh use queue mein daalein
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }
    cout << endl;
}

int main() {
    cout << "--- DSA Masterclass: Breadth-First Search (BFS) ---" << endl << endl;

    int V = 5; // 5 Nodes (0 se 4)
    vector<vector<int>> adj(V);

    // Graph exact pichle setup jaisa hi build karte hain
    addEdge(adj, 0, 1);
    addEdge(adj, 0, 4);
    addEdge(adj, 1, 2);
    addEdge(adj, 1, 3);
    addEdge(adj, 1, 4);
    addEdge(adj, 2, 3);
    addEdge(adj, 3, 4);

    // Node 0 ko starting point banakar BFS traverse karte hain
    bfsGraph(adj, 0, V);

    cout << "---------------------------------------------------" << endl;
    return 0;
}