#include <iostream>
#include <vector>
using namespace std;

// Core Binary Search Function (Iterative Framework)
int binarySearch(const vector<int>& arr, int target) {
    int low = 0;
    int high = arr.size() - 1;

    while (low <= high) {
        // Overflow protect karne ke liye mid formula
        int mid = low + (high - low) / 2;

        // Check if target is present at mid
        if (arr[mid] == target) {
            return mid; // Element mil gaya, index return karein
        }

        // Agar target bada hai, toh left half ko ignore karein
        if (arr[mid] < target) {
            low = mid + 1;
        } 
        // Agar target chota hai, toh right half ko ignore karein
        else {
            high = mid - 1;
        }
    }

    return -1; // Element pooray array mein nahi mila
}

int main() {
    cout << "--- DSA Masterclass: Binary Search (Sorted Vectors) ---" << endl << endl;

    // Binary search ke liye array mandatory SORTED hona chahiye
    vector<int> arr = {2, 5, 8, 12, 16, 23, 38, 56, 72, 91};
    int target = 23;

    cout << "Array Elements: ";
    for (int x : arr) cout << x << " ";
    cout << endl << "Target Element to Find: " << target << endl << endl;

    // Search invoke karte hain
    int result = binarySearch(arr, target);

    if (result != -1) {
        cout << "Success! Element " << target << " found at Array Index: " << result << endl;
    } else {
        cout << "Element " << target << " not found in the array." << endl;
    }

    cout << "--------------------------------------------------------" << endl;
    return 0;
}