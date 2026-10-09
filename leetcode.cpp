#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        vector<pair<int, int>> events;

        for (const auto& b : buildings) {
            events.push_back({b[0], -b[2]});
            events.push_back({b[1], b[2]});
        }

        sort(events.begin(), events.end());

        multiset<int> heights = {0};
        vector<vector<int>> result;
        int prevMax = 0;

        for (const auto& e : events) {
            int x = e.first;
            int h = e.second;

            if (h < 0) {
                heights.insert(-h);
            } else {
                heights.erase(heights.find(h));
            }

            int currentMax = *heights.rbegin();

            if (currentMax != prevMax) {
                result.push_back({x, currentMax});
                prevMax = currentMax;
            }
        }

        return result;
    }
};

int main() {
    Solution sol;

    vector<vector<int>> buildings = {
        {2, 9, 10}, {3, 7, 15}, {5, 12, 12}, {15, 20, 10}, {19, 24, 8}
    };

    vector<vector<int>> skyline = sol.getSkyline(buildings);

    cout << "Skyline Key Points:\n";
    for (const auto& pt : skyline) {
        cout << "[" << pt[0] << ", " << pt[1] << "] ";
    }
    cout << "\n";

    return 0;
}