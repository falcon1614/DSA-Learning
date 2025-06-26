#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node *left, *right;

    Node(int val) {
        data = val; 
        left = right = NULL;
    }
};

// Recursive function to return size of the binary tree
int Size(Node *root) {
    if (root == NULL) return 0;

    return (1 + Size(root->left) + Size(root->right));
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

    int totalSize = Size(root);

    cout << "Size of the binary tree: " << totalSize << endl;

    return 0;
}
