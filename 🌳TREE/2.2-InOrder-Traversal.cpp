// Method 2
#include<iostream>
using namespace std;

class Node{
  public:
    int data;
    Node *left, *right;
    Node(int val){
      data = val;
      left = right = NULL;
    }
};

Node * BinaryTree(){
  int x;
  cin>>x;
  if(x==-1) return NULL;

  Node * temp = new Node(x);
  // Left Side Jao
  cout<<"Enter The Left Child of Tree "<<x<<" : ";
  temp->left = BinaryTree();
  // Right Side Jao
  cout<<"Enter The Right Child Of Tree "<<x<<" : ";
  temp->right = BinaryTree();
  return temp;
}

void InOrder(Node *root){
  if(root==NULL) return;

  // Left
  InOrder(root->left);
  // Node
  cout<<"In Order IS "<<root->data<<" ";
  // Right
  InOrder(root->right);
}
int main(){

  cout <<" Enter the root Node: ";
  Node *root;
  root = BinaryTree();

  InOrder(root);
  return 0;
}
