#include<bits/stdc++.h>
using namespace std;

int main(){

  queue<int> q;
  q.push(10);
  q.push(20);
  q.push(30);
  q.push(40);
  q.push(50);

  // Value Print Karwao
  int n = q.size();

  while(n--){
    cout << q.front() << " ";
    q.push(q.front()); // Reinsert the front element to maintain the queue
    q.pop();
  }

  cout << endl;
  cout << "Queue size after printing: " << q.size() << endl;
  return 0;
}
