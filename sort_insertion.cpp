#include <iostream>
#include <vector>
using namespace std;

// Function to perform Insertion Sort
void insertionSort(vector<int>& arr) {
    int n = arr.size();

    // Loop 1 se shuru hogi kyunki index 0 ko hum already sorted maante hain
    for (int i = 1; i < n; i++) {
        int key = arr[i]; // Current element jise sahi jagah insert karna hai
        int j = i - 1;

        // Sorted part ke elements ko tab tak aage shift karein jab tak woh key se bade hain
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j]; // Shifting one position ahead
            j--;
        }

        // Sahi jagah milte hi key ko khali spot par insert karein
        arr[j + 1] = key;
    }
}

// Helper function to print array
void printArray(const vector<int>& arr) {
    for (int x : arr) {
        cout << x << " ";
    }
    cout << endl;
}

int main() {
    cout << "--- DSA Masterclass: Insertion Sort ---" << endl << endl;

    vector<int> arr = {12, 11, 13, 5, 6};

    cout << "Original Array: ";
    printArray(arr);

    // Insertion Sort invoke karte hain
    insertionSort(arr);

    cout << "Sorted Array:   ";
    printArray(arr);

    cout << "---------------------------------------" << endl;
    return 0;
}