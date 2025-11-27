#include<bits/stdc++.h>
using namespace std;

//

int main(){
  list<int> l1;

  l1.push_back(1);
  l1.push_back(2);
  l1.push_back(3);
  l1.push_back(4);
  l1.push_back(5);
  l1.push_back(6);
  l1.push_front(0);

  cout<<"Front Element: "<<l1.front()<<endl;
  cout<<"Back Element: "<<l1.back()<<endl;
  cout<<"Size of List: "<<l1.size()<<endl;

  cout<<"Elements of List: ";
  for(auto it = l1.begin(); it != l1.end(); it++){
    cout<<*it<<" ";
  }
  cout<<endl;

  // Print in reverse
  cout<<"Element Of List In Reverse";
  for(list<int>::reverse_iterator it = l1.rbegin(); it!= l1.rend(); it++){
    cout<<*it<<" ";
  }
}
