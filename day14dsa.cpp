#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
using namespace std;

// 1. Brute Force Approach: O(N^2) Time, O(1) Space
bool pairSumBrute(const vector<int>& nums, int target) {
    int n = nums.size();
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (nums[i] + nums[j] == target) return true;
        }
    }
    return false;
}

// 2. Better Approach (Hash Set): O(N) Time, O(N) Space
bool pairSumBetter(const vector<int>& nums, int target) {
    unordered_set<int> st;
    for (int num : nums) {
        int complement = target - num;
        if (st.find(complement) != st.end()) return true;
        st.insert(num);
    }
    return false;
}

// 3. Best Approach (Two Pointer Method): O(N log N) Time, O(1) Space
bool pairSumBest(vector<int> nums, int target) {
    sort(nums.begin(), nums.end()); // Array ko pehle sort karenge
    int left = 0, right = nums.size() - 1;

    while (left < right) {
        int sum = nums[left] + nums[right];
        if (sum == target) return true;
        else if (sum < target) left++;
        else right--;
    }
    return false;
}

int main() {
    vector<int> nums = {2, 7, 11, 15};
    int target = 9;

    cout << "--- Pair Sum ---" << endl;
    cout << "Brute Force Result: " << (pairSumBrute(nums, target) ? "Found" : "Not Found") << endl;
    cout << "Better (Hash Set) Result: " << (pairSumBetter(nums, target) ? "Found" : "Not Found") << endl;
    cout << "Best (Two Pointer) Result: " << (pairSumBest(nums, target) ? "Found" : "Not Found") << endl;

    return 0;
}