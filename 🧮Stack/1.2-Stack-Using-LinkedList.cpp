// Stack Implement Using Linked  List
#include<iostream>
using namespace std;

class Node{
  public:
  int data;
  Node* next;
  // Constructor
  Node(int value){
    data = value;
    next = NULL;
  }
};
// Create Stack
class Stack{
  Node *top;
  int size;

  public:
  Stack(){
    top = NULL;
    size = 0;
  }
  // Push Operation
  void push(int value){
    Node *temp = new Node(value);
    if(temp==NULL){
      cout<<"Over Flow"<<" ";
      return;
    }else{
      temp->next = top;
      top = temp;
      cout<<" Element Pushed"<<" "<<top->data<<endl;
      size++;
    }
  }
  // Pop Operation
  void pop(){
    if(top==NULL){
      cout<<"Stack Under Flow"<<" ";
      return;
    }else{
      Node *temp = top;
      cout<<top->data<<"Cout Pop Data";
      top = top->next;
      delete temp;
    }
  }
  // Peak
  int peek(){
    if(top==NULL){
      cout<<"Stack Is Empty"<<endl;
      return -1;
    }else{
      return top->data;
    }
  }
  // ISEmpty
  bool isEmpty(){
    if(top==NULL){
      return true;
    }else{
      return false;
    }
  }
  // ISSize
  int isSize(){
    return size;
  }
};

int main(){
  Stack s;
  s.push(2);
  s.push(3);
  s.push(5);
  
  // int a = 1;
  // while(1){
  //   s.push(a);
  //   a++;
  // }
  return 0;
}
