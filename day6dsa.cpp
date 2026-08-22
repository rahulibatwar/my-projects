#include <iostream>
#include <vector>
using namespace std;

int main()  {
  vector<int> vec; 
  vec.push_back(34);
  vec.push_back(35);
  vec.push_back(36);
  cout << "after push back size = " << vec.size() << endl;

  vec.pop_back();
  // for(int i : vec) {
  //   cout << i << endl;

  cout << vec.front() << endl; 
  cout << vec.back() << endl;
  
     return 0;
}
