#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// Directed Graph ke liye edge (u -> v)
void addDirectedEdge(vector<int> adj[], int u, int v) {
    adj[u].push_back(v); // Sirf u se v tak ka rasta hai
}

void topologicalSort(vector<int> adj[], int V) {
    vector<int> indegree(V, 0);

    // 1. Har node ki indegree calculate karein
    for (int i = 0; i < V; i++) {
        for (int neighbor : adj[i]) {
            indegree[neighbor]++;
        }
    }

    // 2. Jiski indegree 0 hai, use Queue mein daalein
    queue<int> q;
    for (int i = 0; i < V; i++) {
        if (indegree[i] == 0) {
            q.push(i);
        }
    }

    vector<int> topoOrder;

    // 3. Standard BFS Mode
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        topoOrder.push_back(node);

        // Padosiyo ki dependency kam karein
        for (int neighbor : adj[node]) {
            indegree[neighbor]--;
            
            // Agar indegree 0 ho jaye, toh queue mein push karein
            if (indegree[neighbor] == 0) {
                q.push(neighbor);
            }
        }
    }

    // Output ko print karein
    cout << "Topological Sort Order (Job/Course Scheduling):" << endl;
    for (int node : topoOrder) {
        cout << node << " -> ";
    }
    cout << "END" << endl;
}

int main() {
    cout << "--- DSA Masterclass: Topological Sort (Kahn's Algo) ---" << endl << endl;

    int V = 5; // 5 Nodes (0, 1, 2, 3, 4)
    vector<int> adj[V];

    // Edges direction ke sath setup karte hain
    addDirectedEdge(adj, 0, 2); // 0 khatam hoga tabhi 2 shuru ho sakta hai
    addDirectedEdge(adj, 1, 2); // 1 khatam hoga tabhi 2 shuru ho sakta hai
    addDirectedEdge(adj, 2, 3);
    addDirectedEdge(adj, 2, 4);
    addDirectedEdge(adj, 3, 4);

    topologicalSort(adj, V);

    cout << "--------------------------------------------------------" << endl;
    return 0;
}