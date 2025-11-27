#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    int data;
    Node *left;
    Node *right;
    Node(int val){
        data = val;
        left = NULL;
        right = NULL;
    }
};
Node * Create_Binary_Tree(){
    int x;
    cin>>x;
    Node * root = new Node(x);
    if(x== -1){
        return NULL;
    }
    root->left =  Create_Binary_Tree();
    root->right = Create_Binary_Tree();
    return root;
}

//************************************* Traversal ***************************************
// PreOrder
void PreOrder(Node *root){
    if(root==NULL){
        return;
    }
    cout<<root->data<<" ";
    PreOrder(root->left);
    PreOrder(root->right);
}

void PostOrder(Node *root){
    if(root==NULL){
        return;
    }
    PostOrder(root->left);
    PostOrder(root->right);
    cout<<root->data<<" ";
}

void InOrder(Node *root){
    if(root==NULL){
        return;
    }
    InOrder(root->left);
    cout<<root->data<<" ";
    InOrder(root->right);
}

// ****************************************** Level Order Traversal //****************

void LevelOrder(Node *root){
    if(!root){
        return;
    }
    queue<Node *> q;
    q.push(root);
    while (q.empty()){
        Node *temp = q.front();
        q.pop();
        cout<<temp->data<<" ";
        q.push(temp->left);
        q.push(temp->right);
    }
}


int main(){
    Node *root = Create_Binary_Tree();
    return 0;
}
