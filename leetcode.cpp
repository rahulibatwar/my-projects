#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        if (n <= 1 || k == 0) return 0;

        if (k >= n / 2) {
            int maxProfitGreedy = 0;
            for (int i = 1; i < n; i++) {
                if (prices[i] > prices[i - 1]) {
                    maxProfitGreedy += prices[i] - prices[i - 1];
                }
            }
            return maxProfitGreedy;
        }

        vector<int> buy(k + 1, -1e9);
        vector<int> sell(k + 1, 0);

        for (int price : prices) {
            for (int t = 1; t <= k; t++) {
                buy[t] = max(buy[t], sell[t - 1] - price);
                sell[t] = max(sell[t], buy[t] + price);
            }
        }

        return sell[k];
    }
};

int main() {
    Solution sol;

    vector<int> prices1 = {2, 4, 1};
    cout << "Example 1 (k = 2): " << sol.maxProfit(2, prices1) << " (Expected: 2)\n";

    vector<int> prices2 = {3, 2, 6, 5, 0, 3};
    cout << "Example 2 (k = 2): " << sol.maxProfit(2, prices2) << " (Expected: 7)\n";

    vector<int> prices3 = {1, 2};
    cout << "Example 3 (k = 1): " << sol.maxProfit(1, prices3) << " (Expected: 1)\n";

    return 0;
}