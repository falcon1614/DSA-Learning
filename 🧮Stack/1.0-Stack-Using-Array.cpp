// Implement Stack Using Array
#include<iostream>
using namespace std;

class Stack {
  int *arr;
  int top;
  int size;

  public:
  bool flag;
  // constructor
  Stack(int siz) {
    size = siz;
    top = -1;
    arr = new int[size];
  }
  // Push Function
  void push(int data){
    if(top==size-1){
      cout<<"Stack Over Flow"<<" "<<endl;
    }else{
      top++;
      arr[top] = data;
      cout<<"Element Push"<<" "<<arr[top]<<endl;
    }
  }
  // Pop Operation
  void pop(){
    if(top==-1){
      cout<<"Stack Under Flow"<<" "<<endl;
    }else{
      top--;
    }
  }
  // Peek Element
  int peek(){
    if(top==-1){
      cout<<"Stack IS Empty"<<endl;
      return -1;
    }else{
      return arr[top];
    }
  }
  // IsEmpty Operation
  bool isEmpty(){
    if(top==-1){
      return true;
    }else{
      return false;
    }
  }
  // ISSize Operation
  int ISSize(){
    return top+1;
  }
};
int main(){
  Stack s(5);
  s.push(1);
  s.push(2);
  s.push(3);
  s.push(4);
  s.push(5);
  cout<<s.peek()<<" "<<endl;
  return 0;
}
