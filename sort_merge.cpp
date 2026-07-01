#include <iostream>
#include <vector>
using namespace std;

// Two sorted sub-arrays ko aapas mein merge karne ka function
void merge(vector<int>& arr, int left, int mid, int right) {
    int n1 = mid - left + 1; // Left sub-array ka size
    int n2 = right - mid;    // Right sub-array ka size

    // Temporary arrays data store karne ke liye
    vector<int> L(n1), R(n2);

    // Data ko temporary arrays mein copy karte hain
    for (int i = 0; i < n1; i++) L[i] = arr[left + i];
    for (int j = 0; j < n2; j++) R[j] = arr[mid + 1 + j];

    // Initial indexes of first and second sub-arrays
    int i = 0, j = 0;
    int k = left; // Main array ka shuruati index

    // Dono sub-arrays se elements ko compare karke main array mein daalein
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // Agar Left array mein kuch elements bach gaye hon, toh copy karein
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    // Agar Right array mein kuch elements bach gaye hon, toh copy karein
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

// Core Merge Sort function (Recursive)
void mergeSort(vector<int>& arr, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2; // Overflow se bachne ke liye mid calculation

        // 1. Left half ko divide karein
        mergeSort(arr, left, mid);

        // 2. Right half ko divide karein
        mergeSort(arr, mid + 1, right);

        // 3. Sorted halves ko aapas mein merge karein
        merge(arr, left, mid, right);
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
    cout << "--- DSA Masterclass: Merge Sort (Divide & Conquer) ---" << endl << endl;

    vector<int> arr = {38, 27, 43, 3, 9, 82, 10};

    cout << "Original Array: ";
    printArray(arr);

    // Merge Sort invoke karte hain: mergeSort(array, start_index, end_index)
    mergeSort(arr, 0, arr.size() - 1);

    cout << "Sorted Array:   ";
    printArray(arr);

    cout << "------------------------------------------------------" << endl;
    return 0;
}