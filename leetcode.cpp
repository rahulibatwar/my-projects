#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int totalProfit = 0;

        for (size_t i = 1; i < prices.size(); i++) {
            if (prices[i] > prices[i - 1]) {
                totalProfit += prices[i] - prices[i - 1];
            }
        }

        return totalProfit;
    }
};

int main() {
    Solution sol;

    vector<int> prices1 = {7, 1, 5, 3, 6, 4};
    cout << "Example 1 Output: " << sol.maxProfit(prices1) << " (Expected: 7)\n";

    vector<int> prices2 = {1, 2, 3, 4, 5};
    cout << "Example 2 Output: " << sol.maxProfit(prices2) << " (Expected: 4)\n";

    vector<int> prices3 = {7, 6, 4, 3, 1};
    cout << "Example 3 Output: " << sol.maxProfit(prices3) << " (Expected: 0)\n";

    return 0;
}