#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

// Weighted Graph ke liye hum pair use karenge: {neighbor_node, weight}
void addEdge(vector<pair<int, int>> adj[], int u, int v, int weight) {
    adj[u].push_back({v, weight});
    adj[v].push_back({u, weight}); // Undirected graph
}

void dijkstra(vector<pair<int, int>> adj[], int V, int src) {
    // Min-Heap priority queue: hamesha minimum distance wali node top par rahegi
    // Format: pair<distance, node>
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    vector<int> dist(V, INT_MAX);

    // Source node setup
    dist[src] = 0;
    pq.push({0, src});

    while (!pq.empty()) {
        int d = pq.top().first;
        int node = pq.top().second;
        pq.pop();

        // Agar hume isse behtar rasta pehle hi mil chuka hai, toh skip karein
        if (d > dist[node]) continue;

        // Padosiyo ko check karein
        for (auto edge : adj[node]) {
            int neighbor = edge.first;
            int weight = edge.second;

            // Relaxation condition
            if (dist[node] + weight < dist[neighbor]) {
                dist[neighbor] = dist[node] + weight;
                pq.push({dist[neighbor], neighbor});
            }
        }
    }

    // Output Print karein
    cout << "Dijkstra Shortest Distance from Source (Node " << src << "):" << endl;
    for (int i = 0; i < V; i++) {
        cout << "To Node " << i << " -> Minimum Cost: " << dist[i] << endl;
    }
}

int main() {
    cout << "--- DSA Masterclass: Dijkstra's Algorithm ---" << endl << endl;

    int V = 4;
    vector<pair<int, int>> adj[V];

    // Connections with weights: addEdge(adj, u, v, weight)
    addEdge(adj, 0, 1, 4); // 0 se 1 jaane ka karcha 4 hai
    addEdge(adj, 0, 2, 1); // 0 se 2 jaane ka karcha 1 hai
    addEdge(adj, 2, 1, 2); // 2 se 1 jaane ka karcha 2 hai
    addEdge(adj, 1, 3, 3); // 1 se 3 jaane ka karcha 3 hai
    addEdge(adj, 2, 3, 8); // 2 se 3 jaane ka karcha 8 hai

    dijkstra(adj, V, 0);

    cout << "---------------------------------------------" << endl;
    return 0;
}