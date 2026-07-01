#include <iostream>
#include <vector>
using namespace std;

// Core Linear Search Function
int linearSearch(const vector<int>& arr, int target, int& comparisons) {
    comparisons = 0;
    int n = arr.size();

    // Poore array ko sequentially loop se check karte hain
    for (int i = 0; i < n; i++) {
        comparisons++;
        if (arr[i] == target) {
            return i; // Target mil gaya, index return karein
        }
    }

    return -1; // Target nahi mila
}

int main() {
    cout << "--- DSA Masterclass: Linear Search Sequential Scan ---" << endl << endl;

    // Unsorted array bhi perfectly valid hai linear search ke liye
    vector<int> arr = {45, 12, 89, 23, 7, 56, 34, 91};
    int target = 56;
    int comparisons = 0;

    cout << "Array Elements: ";
    for (int x : arr) cout << x << " ";
    cout << endl << "Target Element to Find: " << target << endl << endl;

    // Linear Search execute karte hain
    int result = linearSearch(arr, target, comparisons);

    if (result != -1) {
        cout << "Success! Element found at Array Index: " << result << endl;
        cout << "Total Sequential Comparisons made: " << comparisons << endl;
    } else {
        cout << "Element not found in the array." << endl;
        cout << "Total Sequential Comparisons made: " << comparisons << endl;
    }

    cout << "--------------------------------------------------------" << endl;
    return 0;
}