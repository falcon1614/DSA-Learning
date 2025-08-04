#include<bits/stdc++.h>
using namespace std;

int main(){
  queue<int> q;

  // Adding elements to the queue
  q.push(10);
  q.push(20);
  q.push(30);

  // Displaying the front element
  cout << "Front element: " << q.front() << endl;

  // Displaying the back element
  cout << "Back element: " << q.back() << endl;

  // Removing elements from the queue
  q.pop();

  cout << "After popping, front element: " << q.front() << endl;
  cout << "Size of queue: " << q.size() << endl;
}
