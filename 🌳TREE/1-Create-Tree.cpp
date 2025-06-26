#include<iostream>
#include<queue>
using namespace std;
// Create Node For Tree
class Node{
    public:
    int data;
    Node *left, *right;
    Node(int val){
      data = val;
      left = right = NULL;
    }
};


int main(){
  int X;
  cout<<"Enter The Root Element"<<" : ";
  cin>>X;
  int first,second;
  queue <Node*>q;
  Node* root = new Node(X);

  q.push(root);

  // Build The Binary Tree
  while(!q.empty()){
    Node *temp = q.front();
    q.pop();
    cout<<"Enter The Left Child of "<<temp->data<<" : ";
    cin>>first; // Left Node Ki Value
    // Left Node
    if(first != -1){

      temp->left = new Node(first);
      q.push(temp->left);
    }
    // Right Node
    cout<<"Enter The Right Child of "<<temp->data<<" : ";
    cin>>second;
    if(second!= -1){

      temp->right = new Node(second);
      q.push(temp->right);
    }
  }
}
