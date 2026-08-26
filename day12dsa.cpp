#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int subarraySum(vector<int>& nums, int k) {
    unordered_map<int, int> prefixMap;
    prefixMap[0] = 1; // Base case: 0 sum pehle se 1 baar dekha gaya hai
    
    int curr_sum = 0, count = 0;
    for (int num : nums) {
        curr_sum += num;
        
        // Agar (curr_sum - k) pehle map mein hai, toh wahan se k sum ban raha hai
        if (prefixMap.find(curr_sum - k) != prefixMap.end()) {
            count += prefixMap[curr_sum - k];
        }
        
        prefixMap[curr_sum]++;
    }
    return count;
}

int main() {
    vector<int> nums = {1, 1, 1};
    int k = 2;
    cout << "Subarrays with sum " << k << ": " << subarraySum(nums, k) << endl; // Output: 2
    return 0;
}