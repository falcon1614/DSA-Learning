//
#include<bits/stdc++.h>
using namespace std;

class Queue {
  public:
    int *arr;
   int front,rear;
   int size;

   public:

  //  Constructor
   Queue(int n){
    arr = new int[n];
    front = rear = -1;
    size = n;
  }

  // Empty
  bool Isempty(){
    return front = rear = -1;
  }

  // Full
  bool Isfull(){
    return rear = size - 1;
  }

  // Push
  void push(int x){
    // Check if queue is full
    if(Isfull()){
      cout << "Queue is full" << endl;
      return;
    }
    // If queue is empty
    if(Isempty()){
      cout << "Queue is empty" << endl;
      return;
    }

    // Increment rear and add element
    rear = rear + 1;
    arr[rear] = x;
  }

  // Pop
  void pop(){
    // Check if queue is empty
    if(Isempty()){
      cout <<"Queue Is Underflow" << endl;
      return;
    }
    else{
      // If only one element is present
      if(front == rear){
        front = rear = -1;
      }else{
        front = front + 1;
      }
    }
  }

  // Start me Kon sa element Rakaha hai
  int start(){

    if(Isempty()){
      cout << "Queue is empty" << endl;
      return -1; // or throw an exception
    } else {
      return arr[front]; // Return the front element
    }
  }
};

int main(){
  Queue q(5); // Create a queue of size 5

  q.push(10);
  q.push(20);
  q.push(30);

  cout << "Front element: " << q.start() << endl; // Should print 10

  q.pop();
  cout << "Front element after pop: " << q.start() << endl; // Should print 20

  q.pop();
  q.pop();

  cout << "Queue empty? " << (q.Isempty() ? "Yes" : "No") << endl; // Should print Yes

  return 0;
}
