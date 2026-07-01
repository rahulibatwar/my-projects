#include <iostream>
#include <vector>
using namespace std;

// Function to perform Optimized Bubble Sort
void bubbleSort(vector<int>& arr) {
    int n = arr.size();
    bool swapped;

    // n-1 passes chalenge
    for (int i = 0; i < n - 1; i++) {
        swapped = false;

        // Aakhiri ke i elements pehle hi sahi jagah settle ho chuke hain
        for (int j = 0; j < n - i - 1; j++) {
            // Agar padosi element bada hai, toh swap karo
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                swapped = true; // Swap hua hai tracking set karein
            }
        }

        // Optimization: Agar pure pass mein ek bhi swap nahi hua, toh array already sorted hai!
        if (!swapped) {
            break;
        }
    }
}

// Helper function to print the array
void printArray(const vector<int>& arr) {
    for (int x : arr) {
        cout << x << " ";
    }
    cout << endl;
}

int main() {
    cout << "--- DSA Masterclass: Optimized Bubble Sort ---" << endl << endl;

    vector<int> arr = {5, 1, 4, 2, 8};

    cout << "Original Array: ";
    printArray(arr);

    // Bubble Sort execute karte hain
    bubbleSort(arr);

    cout << "Sorted Array:   ";
    printArray(arr);

    cout << "-----------------------------------------------" << endl;
    return 0;
}