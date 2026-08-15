#include <bits/stdc++.h>
using namespace std;

int main() {
    int a[5] = {4, 1, 7, 5, 10};
    
    int sum = 0;

    for(int i=0;i<5;i++)
    {
        sum = sum + a[i];
    }
    cout << "Sum of array elements= "<< sum << endl;
    return 0;
}