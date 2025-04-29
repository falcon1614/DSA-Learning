#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node *next;
    Node(int value){
        data = value;
        next = NULL;
    }
};
// Create Linked list
Node *createLinkedList(int arr[], int index, int size){
    // Base Condition
    if(index == size){
        return NULL;
    }
    Node *temp;
    temp = new Node(arr[index]);
    temp->next = createLinkedList(arr,index+1,size);
    return temp;
}
// Main Function
int main(){
    Node *Head;
    Head = NULL;

    int arr[5] = {1,2,3,4,5};
    Head = createLinkedList(arr,0,5);

    // Delete A Node
    if(Head!=NULL){
        Node * temp;
        temp = Head;
        Head = Head->next;
        delete temp;
    }

    // Print Value
    Node *temp;
    temp = Head;
    while(temp){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    return 0;
}