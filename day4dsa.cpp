#include <iostream>
using namespace std;

int main() {
    int marks[5] = {85, 90, 78, 92, 88};
    marks[1] = 95; // Update the second element to 95

    cout << marks[0] << endl;   
    cout << marks[1] << endl;
    cout << marks[2] << endl;
    cout << marks[3] << endl;
    cout << marks[4] << endl;


    return 0;

}