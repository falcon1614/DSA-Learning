#include <iostream>
using namespace std;

struct Node {
    int key;
    Node* left;
    Node* right;

    Node(int value) {
        key = value;
        left = right = nullptr;
    }
};

// Insert a node in BST
Node* insert(Node* root, int key) {
    if (!root) return new Node(key);

    if (key < root->key)
        root->left = insert(root->left, key);
    else if (key > root->key)
        root->right = insert(root->right, key);

    return root;
}

// Inorder Traversal (Left, Root, Right)
void inorder(Node* root) {
    if (!root) return;
    inorder(root->left);
    cout << root->key << " ";
    inorder(root->right);
}

// Preorder Traversal (Root, Left, Right)
void preorder(Node* root) {
    if (!root) return;
    cout << root->key << " ";
    preorder(root->left);
    preorder(root->right);
}

// Postorder Traversal (Left, Right, Root)
void postorder(Node* root) {
    if (!root) return;
    postorder(root->left);
    postorder(root->right);
    cout << root->key << " ";
}

int main() {
    Node* root = nullptr;

    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 70);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 60);
    root = insert(root, 80);

    cout << "Inorder Traversal: ";
    inorder(root);
    cout << endl;

    cout << "Preorder Traversal: ";
    preorder(root);
    cout << endl;

    cout << "Postorder Traversal: ";
    postorder(root);
    cout << endl;

    return 0;
}
