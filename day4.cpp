#include <iostream>
#include <string>

using namespace std;
int main() {
    int number;
    cout << "Enter a number: ";
    cin >> number;
    if (number % 2 == 0) {
        cout << "The number is even." << endl;
    } else {
        cout << "The number is odd." << endl;
    }
    // ask the user for a number multiple times and print the sum of all the numbers entered
    int sum = 0;
    char choice;
    do {
        cout << "Enter a number to add to the sum: ";
        cin >> number;
        sum += number;
        cout << "Do you want to enter another number? (y/n): ";
        cin >> choice;
    } while (choice == 'y' || choice == 'Y');
    cout << "The sum of all entered numbers is: " << sum << endl;

    return 0;
}