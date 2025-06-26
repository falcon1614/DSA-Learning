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

int NonLeaf(Node * root){
  if(root == NULL) return 0;

  if(!root->left&&!root->right->right){
    return 0;
  }

  return (1+NonLeaf(root->left)+NonLeaf(root->right));
}

int main(){

  return 0;
}
