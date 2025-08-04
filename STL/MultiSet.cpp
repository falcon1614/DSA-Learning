#include<bits/stdc++.h>
using namespace std;

// This code demonstrates the use of multiset in C++
// Contain multiple Elements
// Elements are stored in sorted order
// Duplicate elements are allowed
// Elements are stored in sorted order
int main(){
  multiset<int> ms;
  ms.insert(1);
  ms.insert(2);
  ms.insert(3);
  ms.insert(4);
  ms.insert(5);
  ms.insert(2);

  cout << "Elements in multiset: ";
  for(auto it = ms.begin(); it != ms.end(); it++){
    cout << *it << " ";
  }
  cout << endl;
}
