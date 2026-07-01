#include <iostream>
#include <vector>
using namespace std;

// Function to perform Selection Sort
void selectionSort(vector<int>& arr) {
    int n = arr.size();

    // Ek ek karke unsorted sub-array ki boundary badhate hain
    for (int i = 0; i < n - 1; i++) {
        // Maan lete hain ki current index wala element hi sabse chota hai
        int min_idx = i;

        // Bache hue array mein dhoondte hain ki koi isse bhi chota hai kya
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j; // Naya minimum index mil gaya
            }
        }

        // Agar naya minimum mila hai, toh use current position wale se swap (exchange) karo
        if (min_idx != i) {
            swap(arr[i], arr[min_idx]);
        }
    }
}

// Helper function to display array elements
void printArray(const vector<int>& arr) {
    for (int x : arr) {
        cout << x << " ";
    }
    cout << endl;
}

int main() {
    cout << "--- DSA Masterclass: Selection Sort ---" << endl << endl;

    vector<int> arr = {64, 25, 12, 22, 11};

    cout << "Original Array: ";
    printArray(arr);

    // Sorting perform karte hain
    selectionSort(arr);

    cout << "Sorted Array:   ";
    printArray(arr);

    cout << "---------------------------------------" << endl;
    return 0;
}