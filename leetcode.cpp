#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int totalSurplus = 0;
        int currentTank = 0;
        int startIndex = 0;

        for (int i = 0; i < gas.size(); i++) {
            int diff = gas[i] - cost[i];
            totalSurplus += diff;
            currentTank += diff;

            if (currentTank < 0) {
                startIndex = i + 1;
                currentTank = 0;
            }
        }

        return (totalSurplus >= 0) ? startIndex : -1;
    }
};

int main() {
    Solution sol;

    vector<int> gas1 = {1, 2, 3, 4, 5};
    vector<int> cost1 = {3, 4, 5, 1, 2};
    cout << "Example 1 Output: " << sol.canCompleteCircuit(gas1, cost1) << " (Expected: 3)\n";[cite: 25]

    vector<int> gas2 = {2, 3, 4};
    vector<int> cost2 = {3, 4, 3};
    cout << "Example 2 Output: " << sol.canCompleteCircuit(gas2, cost2) << " (Expected: -1)\n";[cite: 25]

    return 0;
}