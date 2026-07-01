#include <iostream>
#include <vector>
using namespace std;

void addEdge(vector<int> adj[], int u, int v) {
    adj[u].push_back(v);
    adj[v].push_back(u);
}

// 🎯 RECURSIVE DFS FUNCTION TO DETECT CYCLE
bool isCycleDFS(int node, int parent, vector<int> adj[], vector<bool>& visited) {
    visited[node] = true;

    for (int neighbor : adj[node]) {
        // Agar neighbor visited nahi hai, toh aage depth mein check karein
        if (!visited[neighbor]) {
            if (isCycleDFS(neighbor, node, adj, visited)) 
                return true;
        }
        // Agar neighbor already visited hai AUR woh hamara parent NAHI hai -> Cycle Detected!
        else if (neighbor != parent) {
            return true;
        }
    }
    return false;
}

// Main helper function to check cycle in whole graph
bool detectCycle(vector<int> adj[], int V) {
    vector<bool> visited(V, false);

    // Yeh loop isliye taaki agar disconnected components hon, toh sab check ho sakein
    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            // Shuruat mein startNode ka parent -1 hota hai
            if (isCycleDFS(i, -1, adj, visited)) 
                return true;
        }
    }
    return false;
}

int main() {
    cout << "--- DSA Masterclass: Cycle Detection in Graph ---" << endl << endl;

    int V = 4;
    vector<int> adj[V];

    // Ek cyclic graph banate hain (0-1, 1-2, 2-3, 3-0)
    addEdge(adj, 0, 1);
    addEdge(adj, 1, 2);
    addEdge(adj, 2, 3);
    addEdge(adj, 3, 0); // Yeh edge ek cycle (loop) bana raha hai

    if (detectCycle(adj, V)) {
        cout << "Result: Yes, this graph contains a Cycle! 🔁" << endl;
    } else {
        cout << "Result: No, this graph has no Cycle. 🌲" << endl;
    }

    cout << "-------------------------------------------------" << endl;
    return 0;
}