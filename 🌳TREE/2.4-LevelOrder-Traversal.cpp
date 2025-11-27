// #include<iostream>
// #include<vector>
// #include<queue>
// using namespace std;

// class Node{
//   public:
//   int data;
//   Node *left,*right;
//   Node(int val){
//     data = val;
//     left = right = NULL;
//   }
// };

// // Level Order Traversing
// vector<int> LevelOrder(Node *root){
//   queue<Node *>q;
//   q.push(root);
//   vector<int>ans;
//   Node * temp;
//   while(!q.empty()){
//     temp = q.front();
//     q.pop();
//     ans.push_back(temp->data);
//     if(temp->left){
//       q.push(temp->left);
//     }
//     if(temp->right){
//       q.push(temp->right);
//     }
//   }
// }

// int main() {
//     // Construct a sample binary tree:
//     /*
//             1
//            / \
//           2   3
//          / \   \
//         4   5   6
//     */

//     Node *root = new Node(1);
//     root->left = new Node(2);
//     root->right = new Node(3);
//     root->left->left = new Node(4);
//     root->left->right = new Node(5);
//     root->right->right = new Node(6);

//     vector<int> result = LevelOrder(root);

//     cout << "Level Order Traversal: ";
//     for (int val : result) {
//         cout << val << " ";
//     }
//     cout << endl;

//     return 0;
// }

#include <iostream>
#include <vector>
#include <queue>
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

// Level Order Traversing
vector<int> LevelOrder(Node *root) {
    vector<int> ans;
    if (root == NULL) return ans;

    queue<Node *> q;
    q.push(root);
    Node *temp;

    while (!q.empty()) {
        temp = q.front();
        q.pop();
        ans.push_back(temp->data);
        if (temp->left) {
            q.push(temp->left);
        }
        if (temp->right) {
            q.push(temp->right);
        }
    }
    return ans;
}

int main() {
    // Construct a sample binary tree:
    /*
            1
           / \
          2   3
         / \   \
        4   5   6
    */

    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->right = new Node(6);

    vector<int> result = LevelOrder(root);

    cout << "Level Order Traversal: ";
    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}
