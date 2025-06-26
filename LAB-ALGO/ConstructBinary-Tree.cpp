#include <iostream>
#include <unordered_map>
using namespace std;

class Node {
public:
    char data;
    Node* left;
    Node* right;
    Node(char val) : data(val), left(NULL), right(NULL) {}
};

int preIndex = 0;

Node* buildTree(char in[], char pre[], int inStart, int inEnd, unordered_map<char, int>& inMap) {
    if (inStart > inEnd) return NULL;

    char curr = pre[preIndex++];
    Node* tNode = new Node(curr);

    if (inStart == inEnd) return tNode;

    int inIndex = inMap[curr];

    tNode->left = buildTree(in, pre, inStart, inIndex - 1, inMap);
    tNode->right = buildTree(in, pre, inIndex + 1, inEnd, inMap);

    return tNode;
}

void printInorder(Node* node) {
    if (node == NULL) return;
    printInorder(node->left);
    cout << node->data << " ";
    printInorder(node->right);
}

void printPreorder(Node* node) {
    if (node == NULL) return;
    cout << node->data << " ";
    printPreorder(node->left);
    printPreorder(node->right);
}

void printPostorder(Node* node) {
    if (node == NULL) return;
    printPostorder(node->left);
    printPostorder(node->right);
    cout << node->data << " ";
}

int main() {
    char in[] = {'D', 'B', 'E', 'A', 'F', 'C'};
    char pre[] = {'A', 'B', 'D', 'E', 'C', 'F'};
    int len = sizeof(in) / sizeof(in[0]);

    unordered_map<char, int> inMap;
    for (int i = 0; i < len; i++) {
        inMap[in[i]] = i;
    }

    Node* root = buildTree(in, pre, 0, len - 1, inMap);

    cout << "Inorder: ";
    printInorder(root);
    cout << endl;

    cout << "Preorder: ";
    printPreorder(root);
    cout << endl;

    cout << "Postorder: ";
    printPostorder(root);
    cout << endl;

    return 0;
}

