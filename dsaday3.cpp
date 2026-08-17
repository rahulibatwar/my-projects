#include  <bits/stdc++.h>
using namespace std;

int main() { 


       int a[7] = {2,5,6,12,54,3,7}; //

       int mx = a[0]; //initialization

       int count = 0;

       for (int i=0; i<7; i++)
       {
        //check if the current element a[i] is even
        if(a[i]%2 == 0)
        {
            count = count+1;
        }
       
}

cout << "the number of even elements = " << count << endl;

}