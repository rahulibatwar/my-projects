#include <iostream>
using namespace std;

void changeArr(int arr[], int size) {
    cout << "in function\n";
    for(int i = 0; i < size; i++){
        arr[i] = 2 * arr[i];
    }
} 

int linearsearch(int arr[], int sz, int target) {
   for(int i=0; i<sz; i++){
        if(arr[i] == target) {
          return i;

        }
   }   
   return -1; 
}
int main () {
    int arr [] = {4, 6, 7, 9, 3, 10, 8};
    int sz = 7;
    int target = 6;

    cout  << linearsearch(arr, sz, target )  << endl; 
    return 0;

}