#include <iostream>
#include <vector>

using namespace std;

#define V 4 // Total Vertices

bool isSafe(int v, vector<vector<int>>& graph, vector<int>& color, int c) {
    for (int i = 0; i < V; i++) {
        if (graph[v][i] && c == color[i]) return false;
    }
    return true;
}

bool graphColoringUtil(vector<vector<int>>& graph, int m, vector<int>& color, int v) {
    if (v == V) return true;

    for (int c = 1; c <= m; c++) {
        if (isSafe(v, graph, color, c)) {
            color[v] = c;
            if (graphColoringUtil(graph, m, color, v + 1)) return true;
            color[v] = 0; // Backtrack
        }
    }
    return false;
}

int main() {
    cout << "--- DSA Masterclass: Graph Coloring (C++) ---" << endl << endl;

    vector<vector<int>> graph = {
        {0, 1, 1, 1},
        {1, 0, 1, 0},
        {1, 1, 0, 1},
        {1, 0, 1, 0}
    };
    int m = 3; // Colors available
    vector<int> color(V, 0);

    if (!graphColoringUtil(graph, m, color, 0)) {
        cout << "Solution does not exist" << endl;
    } else {
        cout << "Graph Vertex Coloring Scheme (C++):" << endl;
        for (int i = 0; i < V; i++) {
            cout << " -> Vertex " << i << " -> Color ID: " << color[i] << endl;
        }
    }
    return 0;
}