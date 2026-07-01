#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Edge ko structure format mein store karenge taaki sorting aasan ho
struct Edge {
    int src, dest, weight;
};

// Custom comparator function: Edges ko weight ke basis par sort karne ke liye
bool compareEdges(Edge a, Edge b) {
    return a.weight < b.weight;
}

// 🎯 DSU (DISJOINT SET UNION) CLASS FOR FAST CYCLE DETECTION
class DisjointSet {
    vector<int> parent;
public:
    DisjointSet(int n) {
        parent.resize(n);
        for (int i = 0; i < n; i++) parent[i] = i; // Shuruat mein sab khud ke parent hain
    }

    // Find operation with path compression
    int findParent(int node) {
        if (node == parent[node]) return node;
        return parent[node] = findParent(parent[node]); // Path compression trick
    }

    // Union operation: Returns true agar successfully join ho gaya bina cycle ke
    bool unionSets(int u, int v) {
        int rootU = findParent(u);
        int rootV = findParent(v);

        if (rootU != rootV) {
            parent[rootU] = rootV;
            return true; // No cycle, nodes are successfully connected
        }
        return false; // Cycle detected!
    }
};

void kruskalMST(vector<Edge>& edges, int V) {
    // 1. Edges ko chote se bade weight mein sort karein
    sort(edges.begin(), edges.end(), compareEdges);

    DisjointSet dsu(V);
    int mstWeight = 0;
    int edgeCount = 0;

    cout << "Edges included in the Minimum Spanning Tree (MST):" << endl;

    // 2. Greedy tareeqe se har edge ko check karein
    for (auto edge : edges) {
        // Agar dono nodes ko jodne par cycle nahi banti, toh MST mein add karein
        if (dsu.unionSets(edge.src, edge.dest)) {
            cout << edge.src << " -- " << edge.dest << " == Weight: " << edge.weight << endl;
            mstWeight += edge.weight;
            edgeCount++;

            // Spanning tree mein exact V-1 edges hote hain
            if (edgeCount == V - 1) break;
        }
    }

    cout << endl << "Total Minimum Cost of MST: " << mstWeight << endl;
}

int main() {
    cout << "--- DSA Masterclass: Kruskal's Minimum Spanning Tree ---" << endl << endl;

    int V = 4; // 4 Nodes (0, 1, 2, 3)
    vector<Edge> edges;

    // Edges format: {src, dest, weight}
    edges.push_back({0, 1, 10});
    edges.push_back({0, 2, 6});
    edges.push_back({0, 3, 5});
    edges.push_back({1, 3, 15});
    edges.push_back({2, 3, 4});

    kruskalMST(edges, V);

    cout << "--------------------------------------------------------" << endl;
    return 0;
}