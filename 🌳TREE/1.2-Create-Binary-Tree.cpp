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

int main(){

  cout <<" Enter the root Node: ";
  Node *root;
  root = BinaryTree();

  
  return 0;
}
