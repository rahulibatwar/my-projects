#include <iostream>
#include <vector>
#include <climits> // INT_MIN के लिए

using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int currSum = 0;
        int maxSum = INT_MIN;
        
        for(int val : nums) {
            currSum += val;
            maxSum = max(currSum, maxSum);
            
            if(currSum < 0) {
                currSum = 0;
            }
        }
        return maxSum;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    
    int result = sol.maxSubArray(nums);
    cout << "Maximum Subarray Sum is: " << result << endl;
    
    return 0;
}