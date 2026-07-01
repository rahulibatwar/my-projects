#include <iostream>
#include <vector>
using namespace std;

// Partition function jo pivot ko uski sahi jagah par set karta hai
int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[high]; // Last element ko pivot maana
    int i = low - 1;       // Smaller element ka index tracking

    for (int j = low; j < high; j++) {
        // Agar current element pivot se chota ya barabar hai
        if (arr[j] <= pivot) {
            i++; // Smaller element ka index badhao
            swap(arr[i], arr[j]);
        }
    }
    // Pivot element ko uski sahi correct sorted position par swap karein
    swap(arr[i + 1], arr[high]);
    return (i + 1); // Pivot ka right index return karein
}

// Core Quick Sort function
void quickSort(vector<int>& arr, int low, int high) {
    if (low < high) {
        // pi = Partition Index, arr[pi] ab sahi jagah par hai
        int pi = partition(arr, low, high);

        // Pivot ke left aur right waale hisson ko alag-alag sort karein
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
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
    cout << "--- DSA Masterclass: Quick Sort (Partition Engine) ---" << endl << endl;

    vector<int> arr = {10, 7, 8, 9, 1, 5};

    cout << "Original Array: ";
    printArray(arr);

    // Quick Sort call karte hain: quickSort(array, start_index, end_index)
    quickSort(arr, 0, arr.size() - 1);

    cout << "Sorted Array:   ";
    printArray(arr);

    cout << "------------------------------------------------------" << endl;
    return 0;
}