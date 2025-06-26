#include<iostream>
#include<vector>
using namespace std;

class Node{
  public:
  int data;
  Node * left;
  Node * right;
  Node(int value){
    data = value;
    left=right=NULL;
  }
};

//  InOrder --> Left--(Node)--Right
vector<int> inOrder(Node * root){
  vector<int> ans;
  while(root->left){

    
  }
}

int main(){

  return 0;
}
