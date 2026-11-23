#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <iomanip>

using namespace std;

class Solution {
private:
    double bfs(const string& start, const string& end,
               unordered_map<string, vector<pair<string, double>>>& graph) {
        if (graph.find(start) == graph.end() || graph.find(end) == graph.end()) {
            return -1.0;
        }
        if (start == end) {
            return 1.0;
        }

        queue<pair<string, double>> q;
        unordered_set<string> visited;

        q.push({start, 1.0});
        visited.insert(start);

        while (!q.empty()) {
            auto [currNode, currProduct] = q.front();
            q.pop();

            if (currNode == end) {
                return currProduct;
            }

            for (const auto& [neighbor, weight] : graph[currNode]) {
                if (visited.find(neighbor) == visited.end()) {
                    visited.insert(neighbor);
                    q.push({neighbor, currProduct * weight});
                }
            }
        }

        return -1.0;
    }

public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string, vector<pair<string, double>>> graph;

        for (size_t i = 0; i < equations.size(); i++) {
            const string& u = equations[i][0];
            const string& v = equations[i][1];
            double val = values[i];

            graph[u].push_back({v, val});
            graph[v].push_back({u, 1.0 / val});
        }

        vector<double> results;
        results.reserve(queries.size());

        for (const auto& query : queries) {
            results.push_back(bfs(query[0], query[1], graph));
        }

        return results;
    }
};

void printResults(const vector<double>& res) {
    cout << fixed << setprecision(5) << "[ ";
    for (size_t i = 0; i < res.size(); i++) {
        cout << res[i] << (i + 1 < res.size() ? ", " : " ");
    }
    cout << "]\n";
}

int main() {
    Solution sol;

    vector<vector<string>> eq1 = {{"a", "b"}, {"b", "c"}};
    vector<double> val1 = {2.0, 3.0};
    vector<vector<string>> q1 = {{"a", "c"}, {"b", "a"}, {"a", "e"}, {"a", "a"}, {"x", "x"}};
    cout << "Example 1 Output: ";
    printResults(sol.calcEquation(eq1, val1, q1)); // Expected: [ 6.00000, 0.50000, -1.00000, 1.00000, -1.00000 ][cite: 28]

    vector<vector<string>> eq2 = {{"a", "b"}, {"b", "c"}, {"bc", "cd"}};
    vector<double> val2 = {1.5, 2.5, 5.0};
    vector<vector<string>> q2 = {{"a", "c"}, {"c", "b"}, {"bc", "cd"}, {"cd", "bc"}};
    cout << "Example 2 Output: ";
    printResults(sol.calcEquation(eq2, val2, q2)); // Expected: [ 3.75000, 0.40000, 5.00000, 0.20000 ][cite: 28]

    return 0;
}