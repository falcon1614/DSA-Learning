#include<iostream>
using namespace std;
// Create Node
class NODE{
    public:
    int data;
    NODE * next;
    NODE(int value){
        data = value;
        next = NULL;
    }
};
// Create LinkedList
NODE *createLinkedList(int arr[],int index, int size, NODE *prev){
    // Base Case 
    if(index==size){
        return prev;
    }
    NODE * temp;
    temp = new NODE(arr[index]);
    temp->next = prev;
    return createLinkedList(arr,index+1,size,temp);
}
int main(){
    NODE * Head;
    Head = NULL;

    int arr[6] = {23,6,7,94,7,90};

    Head = createLinkedList(arr,0,6,Head);

    // Print Value
    NODE *temp;
    temp = Head;
    while(temp){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    return 0;
}