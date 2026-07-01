#include <iostream>
using namespace std;

int main() {
    int arr[5] = {64, 34, 25, 12, 22};
    int n = 5;
    int temp;

    // Outer loop for number of passes
    for (int i = 0; i < n-1; i++) {
        // Inner loop for comparisons
        for (int j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                // SWAP logic
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }

    cout << "Sorted array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}