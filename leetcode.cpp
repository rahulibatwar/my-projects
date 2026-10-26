#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string getPermutation(int n, int k) {
        int fact = 1;
        vector<int> numbers;

        for (int i = 1; i < n; i++) {
            fact *= i;
            numbers.push_back(i);
        }
        numbers.push_back(n);

        string result = "";
        k = k - 1;

        while (true) {
            int index = k / fact;
            result += to_string(numbers[index]);
            numbers.erase(numbers.begin() + index);

            if (numbers.empty()) {
                break;
            }

            k %= fact;
            fact /= numbers.size();
        }

        return result;
    }
};

int main() {
    Solution sol;

    cout << "Example 1 (n=3, k=3): " << sol.getPermutation(3, 3) << " (Expected: 213)\n";
    cout << "Example 2 (n=4, k=9): " << sol.getPermutation(4, 9) << " (Expected: 2314)\n";
    cout << "Example 3 (n=3, k=1): " << sol.getPermutation(3, 1) << " (Expected: 123)\n";

    return 0;
}