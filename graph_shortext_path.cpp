#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

void addEdge(vector<int> adj[], int u, int v) {
    adj[u].push_back(v);
    adj[v].push_back(u);
}

// 🎯 MAIN FUNCTION: BFS TO FIND SHORTEST DISTANCE
void findShortestPath(vector<int> adj[], int V, int src) {
    // Distance array ko infinity se initialize karein
    vector<int> dist(V, INT_MAX);
    queue<int> q;

    // Source node ki khud se doori hamesha 0 hoti hai
    dist[src] = 0;
    q.push(src);

    while (!q.empty()) {
        int node = q.front();
        q.pop();

        for (int neighbor : adj[node]) {
            // Agar padosi tak pahunchne ka ek naya chota rasta milta hai
            if (dist[node] + 1 < dist[neighbor]) {
                dist[neighbor] = dist[node] + 1;
                q.push(neighbor);
            }
        }
    }

    // Output ko clean format mein print karein
    cout << "Shortest Distance from Source (Node " << src << "):" << endl;
    for (int i = 0; i < V; i++) {
        cout << "To Node " << i << " -> " << dist[i] << " edges away" << endl;
    }
}

int main() {
    cout << "--- DSA Masterclass: Shortest Path using BFS ---" << endl << endl;

    int V = 4; // 4 nodes (0, 1, 2, 3)
    vector<int> adj[V];

    // Graph connections set karte hain
    addEdge(adj, 0, 1);
    addEdge(adj, 0, 2);
    addEdge(adj, 1, 3);
    addEdge(adj, 2, 3);

    // Node 0 se baaki sabki minimum doori nikalte hain
    findShortestPath(adj, V, 0);

    cout << "------------------------------------------------" << endl;
    return 0;
}