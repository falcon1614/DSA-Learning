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
NODE * createLinkedList(int arr[], int index, int size){
    if(index==size){
        return NULL;
    }
    NODE * temp;
    temp = new NODE(arr[index]);
    temp->next = createLinkedList(arr,index+1,size);
    return temp;

}
int main(){
    NODE * Head;
    Head = NULL;
    
    int arr[5] = {1,2,3,4,5};
    Head = createLinkedList(arr,0,5);

    // Print Value
    NODE * temp;
    temp = Head;
    while(temp){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    return 0;
}