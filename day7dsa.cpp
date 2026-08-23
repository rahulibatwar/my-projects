#include <iostream>
#include <vector>
using namespace std;

class solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans = 0;
        for(int val : nums) {
            ans = ans ^ val;
        }
        return ans;
    }
};

int main() {
    solution sol;
    vector<int> nums = {4, 1, 2, 1, 2}; // उदाहरण के लिए एरे
    
    int result = sol.singleNumber(nums);
    cout << "The single number is: " << result << endl;
    
    return 0;
}