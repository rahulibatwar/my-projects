#include <iostream>
#include <vector>

using namespace std;

// Number of vertices in the graph
#define V 4

// Function to check if the current color assignment is safe for vertex v
bool isSafe(int v, vector<vector<int>>& graph, vector<int>& color, int c) {
    for (int i = 0; i < V; i++) {
        // If there is an edge and the adjacent vertex has the same color, it's not safe
        if (graph[v][i] && c == color[i]) {
            return false;
        }
    }
    return true;
}

// Recursive utility function to solve graph coloring problem using Backtracking
bool graphColoringUtil(vector<vector<int>>& graph, int m, vector<int>& color, int v) {
    // Base Case: If all vertices are assigned a color
    if (v == V) return true;

    // Consider this vertex v and try different colors from 1 to m
    for (int c = 1; c <= m; c++) {
        // Check if assignment of color c to v is fine
        if (isSafe(v, graph, color, c)) {
            color[v] = c; // Assign color c to vertex v

            // Recur to assign colors to the rest of the vertices
            if (graphColoringUtil(graph, m, color, v + 1)) return true;

            // BACKTRACK: If assigning color c doesn't lead to a solution, remove it
            color[v] = 0;
        }
    }

    return false; // If no color can be assigned to this vertex
}

int main() {
    cout << "--- DSA Masterclass: Graph Coloring (Backtracking) ---" << endl << endl;

    /* Adjacency Matrix representation of the graph:
       (0)---(1)
        | \   |
        |  \  |
        |   \ |
       (3)---(2) */
    vector<vector<int>> graph = {
        {0, 1, 1, 1},
        {1, 0, 1, 0},
        {1, 1, 0, 1},
        {1, 0, 1, 0}
    };

    int m = 3; // Number of available colors (1, 2, or 3)
    vector<int> color(V, 0); // Initialize all vertices with color 0 (uncolored)

    cout << "Number of Vertices: " << V << endl;
    cout << "Available Colors Count: " << m << endl << endl;

    // Running the Backtracking engine
    if (!graphColoringUtil(graph, m, color, 0)) {
        cout << "Solution does not exist with " << m << " colors." << endl;
    } else {
        // Printing the final allocated color configuration
        cout << "--------------------------------------------------------" << endl;
        cout << "Graph Vertex Coloring Scheme successfully allocated:" << endl;
        for (int i = 0; i < V; i++) {
            cout << " -> Vertex " << i << " Assigned Color ID: " << color[i] << endl;
        }
        cout << "--------------------------------------------------------" << endl;
    }

    return 0;
}