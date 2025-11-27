#include<iostream>
using namespace std;

class Node{
  public:
    int data;
    Node *left,*right;
    Node(int val){
      data = val;
      left = right = NULL;
    }
};
// Size
void Size(Node *root, int &count){
  if(root==NULL) return;

  count++;
  // Left
  Size(root->left,count);
  // Right
  Size(root->right,count);
}

int main() {
    // Constructing a sample binary tree:
    /*
            1
           / \
          2   3
         / \
        4   5
    */
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    int count = 0;
    Size(root, count);

    cout << "Size of the binary tree: " << count << endl;

    return 0;
}
