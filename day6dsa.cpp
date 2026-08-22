#include <iostream>
#include <vector>
using namespace std;

int main()  {
  vector<char> vec = {'a', 'b', 'c', 'd', 'e', 'f'}; 

  cout << "size = " << vec.size() << endl;
  vec.push_back(34);
  cout << "after push back size = " << vec.size() << endl;
  for(char i : vec) {
    cout << i << endl;
  }
     return 0;
}
