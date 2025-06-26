// #include<iostream>
// using namespace std;
// class Node{
//   public:
//     int data;
//     Node *left,*right;
//     Node(int val){
//       data = val;
//       left = right = NULL;
//     }
// };
// void Leaf(Node *root, int &count){
//   // Base case
//   if(root==NULL) return;

//   if(!root->left&&!root->right){
//     count++;
//     return;
//   }
//   // Left Side
//   Leaf(root->left,count);
//   // Right Side
//   Leaf(root->right,count);
// }

// int CountLeaf(Node *root){
//   if(root==NULL) return;

//   if(!root->left&&!root->right){
//     return 1;
//   }
//   return(CountLeaf(root->left)+CountLeaf(root->right));
// }

// int main() {
//     // Construct a sample binary tree:
//     /*
//             10
//            /  \
//           5    20
//          / \     \
//         3   7     30
//              \
//               8
//     */
//     Node *root = new Node(10);
//     root->left = new Node(5);
//     root->right = new Node(20);
//     root->left->left = new Node(3);
//     root->left->right = new Node(7);
//     root->left->right->right = new Node(8);
//     root->right->right = new Node(30);

//     // Using Leaf with reference
//     int leafCountRef = 0;
//     Leaf(root, leafCountRef);
//     cout << "Leaf nodes (using reference): " << leafCountRef << endl;

//     // Using CountLeaf return value
//     int leafCountRet = CountLeaf(root);
//     cout << "Leaf nodes (using return):    " << leafCountRet << endl;

//     return 0;
// }


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

// Method 1: Count leaf nodes using a reference parameter
void Leaf(Node *root, int &count) {
    if (root == NULL) return;
    if (!root->left && !root->right) {
        count++;
        return;
    }
    Leaf(root->left, count);
    Leaf(root->right, count);
}

// Method 2: Count leaf nodes by returning the count
int CountLeaf(Node *root) {
    if (root == NULL)
        return 0;                // fixed: must return 0 when root is null
    if (!root->left && !root->right)
        return 1;
    return CountLeaf(root->left) + CountLeaf(root->right);
}

int main() {
    // Construct a sample binary tree:
    /*
            10
           /  \
          5    20
         / \     \
        3   7     30
             \
              8
    */
    Node *root = new Node(10);
    root->left = new Node(5);
    root->right = new Node(20);
    root->left->left = new Node(3);
    root->left->right = new Node(7);
    root->left->right->right = new Node(8);
    root->right->right = new Node(30);

    // Using Leaf with reference
    int leafCountRef = 0;
    Leaf(root, leafCountRef);
    cout << "Leaf nodes (using reference): " << leafCountRef << endl;

    // Using CountLeaf return value
    int leafCountRet = CountLeaf(root);
    cout << "Leaf nodes (using return):    " << leafCountRet << endl;

    return 0;
}
