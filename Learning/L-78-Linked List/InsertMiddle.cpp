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
// Create LinkedList
Node * createLinkedList(int arr[], int index, int size){
    if(index==size){
        return NULL;
    }
    Node * temp;
    temp = new Node(arr[index]);
    temp->next = createLinkedList(arr,index+1,size);
    return temp;
}
int main(){
    Node * Head;
    Head = NULL;

    int arr[6] = {23,6,7,94,7,90};
    Head = createLinkedList(arr,0,6);

    // Insert Node at Particular position
    int x = 3; // Insert position
    int value = 30;
     
    Node *temp = Head;
    x--;
    while(x--){
        temp = temp->next;
    };
    Node *temp2 = new Node(value);
    temp2->next = temp->next;
    temp->next = temp2;

    // Print 
    // Node *temp;
    temp = Head;
    while(temp){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    return 0;
}