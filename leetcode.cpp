#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> inDegree(numCourses, 0);

        for (const auto& pre : prerequisites) {
            adj[pre[1]].push_back(pre[0]);
            inDegree[pre[0]]++;
        }

        queue<int> q;
        for (int i = 0; i < numCourses; i++) {
            if (inDegree[i] == 0) {
                q.push(i);
            }
        }

        int completedCount = 0;

        while (!q.empty()) {
            int curr = q.front();
            q.pop();
            completedCount++;

            for (int neighbor : adj[curr]) {
                inDegree[neighbor]--;
                if (inDegree[neighbor] == 0) {
                    q.push(neighbor);
                }
            }
        }

        return completedCount == numCourses;
    }
};

int main() {
    Solution sol;

    vector<vector<int>> pre1 = {{1, 0}};
    cout << boolalpha;
    cout << "Example 1: " << sol.canFinish(2, pre1) << " (Expected: true)" << endl;

    vector<vector<int>> pre2 = {{1, 0}, {0, 1}};
    cout << "Example 2: " << sol.canFinish(2, pre2) << " (Expected: false)" << endl;

    return 0;
}