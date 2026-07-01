#include <iostream>
#include <vector>
#include <queue>
#include <climits> // INT_MAX (Infinity) ke liye
using namespace std;

// Weighted graph ke liye edge representation
struct Edge {
    int target;
    int weight;
};

// Function to add a weighted undirected edge
void addEdge(vector<vector<Edge>>& adj, int u, int v, int w) {
    adj[u].push_back({v, w});
    adj[v].push_back({u, w}); // Undirected framework
}

// Core Dijkstra's Algorithm Function
void dijkstra(const vector<vector<Edge>>& adj, int source, int V) {
    // 1. Distance array ko Infinity (INT_MAX) se initialize karein
    vector<int> dist(V, INT_MAX);
    
    // Min-Heap priority queue: pair<distance, node> store karega
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    // Source node ka distance hamesha 0 hoga
    dist[source] = 0;
    pq.push({0, source});

    while (!pq.empty()) {
        int d = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        // Agar hume isse bhi behtar raasta pehle hi mil chuka hai, toh skip karein
        if (d > dist[u]) continue;

        // Current node ke saare neighbors ko relax karein
        for (const auto& edge : adj[u]) {
            int v = edge.target;
            int weight = edge.weight;

            // Relaxation Formula check
            if (dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                pq.push({dist[v], v});
            }
        }
    }

    // Shortest paths output print karein
    cout << "Shortest Distances from Source Node " << source << ":" << endl;
    for (int i = 0; i < V; i++) {
        cout << "To Node " << i << " -> Minimum Cost: " << dist[i] << endl;
    }
}

int main() {
    cout << "--- DSA Masterclass: Dijkstra's Shortest Path ---" << endl << endl;

    int V = 5; // 5 Nodes (0 se 4)
    vector<vector<Edge>> adj(V);

    // Weighted connections setup: addEdge(graph, node1, node2, weight)
    addEdge(adj, 0, 1, 9);
    addEdge(adj, 0, 2, 6);
    addEdge(adj, 0, 3, 5);
    addEdge(adj, 0, 4, 3);
    addEdge(adj, 2, 1, 2);
    addEdge(adj, 2, 3, 4);

    // Source Node 0 se poore network ka short path nikalte hain
    dijkstra(adj, 0, V);

    cout << "-------------------------------------------------" << endl;
    return 0;
}