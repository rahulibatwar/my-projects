#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

// 1. Brute Force Approach: O(N^2) Time, O(1) Space
int majorityElementBrute(vector<int>& nums) {
    int n = nums.size();
    for (int i = 0; i < n; i++) {
        int count = 0;
        for (int j = 0; j < n; j++) {
            if (nums[j] == nums[i]) count++;
        }
        if (count > n / 2) return nums[i];
    }
    return -1;
}

// 2. Better Approach (Sorting): O(N log N) Time, O(1) Space
int majorityElementBetter(vector<int> nums) {
    sort(nums.begin(), nums.end());
    return nums[nums.size() / 2];
}

// 3. Best Approach (Moore's Voting Algorithm): O(N) Time, O(1) Space
int majorityElementBest(vector<int>& nums) {
    int candidate = 0, count = 0;

    // Step 1: Candidate Selection
    for (int num : nums) {
        if (count == 0) {
            candidate = num;
        }
        if (num == candidate) count++;
        else count--;
    }

    return candidate;
}

int main() {
    vector<int> nums = {2, 2, 1, 1, 1, 2, 2};

    cout << "--- Majority Element ---" << endl;
    cout << "Brute Force Result: " << majorityElementBrute(nums) << endl;
    cout << "Better (Sorting) Result: " << majorityElementBetter(nums) << endl;
    cout << "Best (Moore's Voting) Result: " << majorityElementBest(nums) << endl;

    return 0;
}