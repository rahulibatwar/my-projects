#include <iostream>
#include <string>


using namespace std;

int main() {
   // task 1: ask the user to enter their favorite food and print it
    string food;
    cout << "What is your favorite food? ";
    getline(cin, food);
    cout << "Your favorite food is: " << food << endl;
// task 2: ask the user to enter two numbers and perform addition, multiplication, and subtraction
    double num1, num2;
    cout << "Enter first number: ";
    cin >> num1;
    cout << "Enter second number: ";
    cin >> num2;

    double sum = num1 + num2;
    double product = num1 * num2;
    double difference = num1 - num2;

    cout << "Sum: " << sum << endl;
    cout << "Product: " << product << endl;
    cout << "Difference: " << difference << endl;

    return 0;
}