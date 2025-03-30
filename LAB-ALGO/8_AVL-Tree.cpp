#include <iostream>
using namespace std;

// Node structure for AVL Tree
struct Node {
    int key;
    Node* left;
    Node* right;
    int height;

    Node(int value) {
        key = value;
        left = right = nullptr;
        height = 1;
    }
};

// Get the height of a node
int getHeight(Node* node) {
    return node ? node->height : 0;
}

// Get the balance factor of a node
int getBalanceFactor(Node* node) {
    return node ? getHeight(node->left) - getHeight(node->right) : 0;
}

// Update the height of a node
void updateHeight(Node* node) {
    if (node)
        node->height = 1 + max(getHeight(node->left), getHeight(node->right));
}

// Right rotate (LL Rotation)
Node* rightRotate(Node* y) {
    Node* x = y->left;
    Node* T2 = x->right;

    // Rotation
    x->right = y;
    y->left = T2;

    // Update heights
    updateHeight(y);
    updateHeight(x);

    return x;
}

// Left rotate (RR Rotation)
Node* leftRotate(Node* x) {
    Node* y = x->right;
    Node* T2 = y->left;

    // Rotation
    y->left = x;
    x->right = T2;

    // Update heights
    updateHeight(x);
    updateHeight(y);

    return y;
}

// Balance the tree after insertion or deletion
Node* balance(Node* node) {
    int balanceFactor = getBalanceFactor(node);

    // Left Heavy (LL case)
    if (balanceFactor > 1 && getBalanceFactor(node->left) >= 0)
        return rightRotate(node);

    // Left-Right Case (LR case)
    if (balanceFactor > 1 && getBalanceFactor(node->left) < 0) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    // Right Heavy (RR case)
    if (balanceFactor < -1 && getBalanceFactor(node->right) <= 0)
        return leftRotate(node);

    // Right-Left Case (RL case)
    if (balanceFactor < -1 && getBalanceFactor(node->right) > 0) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node;  // Balanced
}

// Insert a node in AVL Tree
Node* insert(Node* root, int key) {
    if (!root) return new Node(key);

    if (key < root->key)
        root->left = insert(root->left, key);
    else if (key > root->key)
        root->right = insert(root->right, key);
    else
        return root; // No duplicate keys

    updateHeight(root);
    return balance(root);
}

// Find the node with the smallest value
Node* getMinNode(Node* node) {
    while (node->left)
        node = node->left;
    return node;
}

// Delete a node from AVL Tree
Node* deleteNode(Node* root, int key) {
    if (!root) return nullptr;

    // Perform standard BST delete
    if (key < root->key)
        root->left = deleteNode(root->left, key);
    else if (key > root->key)
        root->right = deleteNode(root->right, key);
    else {
        if (!root->left || !root->right) { // One child or no child
            Node* temp = root->left ? root->left : root->right;
            delete root;
            return temp;
        }
        else { // Two children
            Node* temp = getMinNode(root->right);
            root->key = temp->key;
            root->right = deleteNode(root->right, temp->key);
        }
    }

    updateHeight(root);
    return balance(root);
}

// Search for a key in AVL Tree
bool search(Node* root, int key) {
    if (!root) return false;
    if (root->key == key) return true;
    if (key < root->key) return search(root->left, key);
    return search(root->right, key);
}

// Inorder Traversal (Sorted Order)
void inorder(Node* root) {
    if (!root) return;
    inorder(root->left);
    cout << root->key << " ";
    inorder(root->right);
}

// Driver Code
int main() {
    Node* root = nullptr;

    // Insert nodes
    root = insert(root, 60);
    root = insert(root, 40);
    root = insert(root, 80);
    root = insert(root, 20);
    root = insert(root, 55);
    root = insert(root, 75);
    root = insert(root, 95);

    cout << "Inorder traversal: ";
    inorder(root);
    cout << endl;

    // Delete node
    root = deleteNode(root, 40);

    cout << "After deleting 40: ";
    inorder(root);
    cout << endl;

    // Search for a value
    int searchKey = 55;
    cout << "Search " << searchKey << ": " << (search(root, searchKey) ? "Found" : "Not Found") << endl;

    return 0;
}

