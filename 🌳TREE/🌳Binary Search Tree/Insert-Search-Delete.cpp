#include<iostream>
using namespace std;

class Node {
public:
    int data;
    Node *left, *right;
    Node(int value) {
        data = value;
        left = right = NULL;
    }
};

// Insert a new node with given data into the binary tree
Node* insert(Node* root, int target) {
    if (!root) {
        return new Node(target);
    }
    if (target < root->data) {
        root->left = insert(root->left, target);
    } else {
        root->right = insert(root->right, target);
    }
    return root;
}

// Inorder Traversal
void inorder(Node* root) {
    if (!root) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

// Search in BST and print address
void search(Node* root, int target) {
    if (!root) {
        cout << "Element " << target << " Not Present" << endl;
        return;
    }

    if (target == root->data) {
        cout << "Element " << target << " is Present at address: " << root << endl;
        return;
    }

    if (target < root->data) {
        search(root->left, target);
    } else {
        search(root->right, target);
    }
}

// Function to delete a node from BST.
    Node *deleteNode(Node *root, int target) {
        // your code goes here

        // Base Condition
            if(root == NULL) return NULL;

            if(root->data>target){
                root->left = deleteNode(root->left,target);
                return root;
            }
            else if(root->data<target){
                root->right = deleteNode(root->right,target);
                return root;
            }
            else{
        // Leaf Node
            if(!root->left&&!root->right){
                delete root;
                return NULL;
            }

        // 1 Child
            else if(!root->right) // Left Child
            {
                Node *temp = root->left;
                delete root;
                return temp;
            }
            else if(!root->left) // Right Child
            {
                Node *temp = root->right;
                delete root;
                return temp;
            }
        // 2 Child
            else{
                // Find Greatest Element From Left
                Node *child = root->left;
                Node *parent = root;

                // Right Most Element Tak PahucNa Hai
                while(child->right){
                    parent = child;
                    child = child->right;
                }
                if(root!=parent){
                    parent->right = child->left;
                    child->left = root->left;
                    child->right = root->right;
                    delete root;
                    return child;
                }
                else{
                    child->right = root->right;
                    delete root;
                    return child;
                }
            }
        }
    }
int main() {
    int arr[] = {6, 3, 17, 5, 11, 18, 2, 1, 20, 14};
    Node* root = NULL;
    int n = sizeof(arr) / sizeof(arr[0]);

    for (int i = 0; i < n; i++) {
        root = insert(root, arr[i]);
    }

    // Traverse
    cout << "Inorder Traversal: ";
    inorder(root);
    cout << endl;

    // Search Element
    search(root, 14);

    return 0;
}


