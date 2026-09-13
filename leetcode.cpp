#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int left = 0;
        int right = letters.size() - 1;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (letters[mid] <= target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        return letters[left % letters.size()];
    }
};

int main() {
    Solution sol;

    vector<char> letters1 = {'c', 'f', 'j'};
    cout << "Target 'a': " << sol.nextGreatestLetter(letters1, 'a') << " (Expected: c)" << endl;
    cout << "Target 'c': " << sol.nextGreatestLetter(letters1, 'c') << " (Expected: f)" << endl;

    vector<char> letters2 = {'x', 'x', 'y', 'y'};
    cout << "Target 'z': " << sol.nextGreatestLetter(letters2, 'z') << " (Expected: x)" << endl;

    return 0;
}