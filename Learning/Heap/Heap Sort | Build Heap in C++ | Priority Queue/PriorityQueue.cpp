#include<bits/stdc++.h>
using namespace std;
int main(){
  priority_queue<int>p;

  p.push(10);
  p.push(20);
  p.push(30);
  p.push(40);

  cout<<p.top()<<" ";

  priority_queue<int, vector<int>, greater<int> > pq; // Min Heap
  
  return 0;
}
