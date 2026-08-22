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
   cout << vec.at(0) << endl;
   cout << vec.at(1) << endl;
  
  
     return 0;
}
