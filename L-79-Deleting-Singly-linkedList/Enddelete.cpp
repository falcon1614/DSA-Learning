#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node *next;
    Node(int  value){
        data = value;
        next = NULL;
    }
};
// Create linked List
Node *createLinkedList(int arr[], int index, int size){
    // Base case
    if(index == size){
        return NULL;
    }
    Node *temp;
    temp = new Node(arr[index]);
    temp->next = createLinkedList(arr,index+1,size);
    return temp;
}
int main(){
     Node *Head;
     Head = NULL;

    int arr[5] = {1,2,3,4,5};
    Head = createLinkedList(arr,0,5);

    // Delete a Node 
    if(Head!=NULL){
        // Only one Noe Is Present
        if(Head->next==NULL){
            Node *temp;
            delete temp;
            Head = NULL;
        }
        // More than 1 node is present
        else{
            Node *curr = Head;
            Node *prev = NULL;
            // curr->next not null
            while(curr->next!=NULL){
                prev = curr;
                curr = curr->next;
            }
        }
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