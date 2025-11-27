#include<iostream>
using namespace std;
class NODE{
    public:
    int data;
    NODE * next;
    NODE(int value){
        data = value;
        next = NULL;
    }
};
int main(){
    NODE * Head;
    Head =  NULL;

    NODE * Tail;
    Tail = NULL;

    int arr[5] = {1,2,3,4,5};
    // Insert Value In Last

    // Linked List Empty
    for(int i=0; i<5; i++){
        if(Head==NULL){
            Head = new NODE(arr[i]);
            Tail = Head;
        }
        // Linked List Exist
        else{
            Tail->next = new NODE(arr[i]);
            Tail = Tail->next;
        }
    }
    
    NODE * temp;
    temp = Head;
    while(temp){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    return 0;
}