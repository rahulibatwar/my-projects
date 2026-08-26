class Solution {
public:
    bool checkStrings(string s1, string s2) {
        // Even (0, 2, 4...) aur Odd (1, 3, 5...) indices ke liye frequency tracking
        vector<int> countEven(26, 0);
        vector<int> countOdd(26, 0);

        for (int i = 0; i < s1.length(); i++) {
            if (i % 2 == 0) {
                countEven[s1[i] - 'a']++;
                countEven[s2[i] - 'a']--;
            } else {
                countOdd[s1[i] - 'a']++;
                countOdd[s2[i] - 'a']--;
            }
        }

        // Agar even aur odd positions ke characters ki count match hoti hai, to return true
        for (int i = 0; i < 26; i++) {
            if (countEven[i] != 0 || countOdd[i] != 0) {
                return false;
            }
        }

        return true;
    }
};