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
    NODE *Head;
    Head = new h1(3);
    cout<<Head->data;
    cout<<Head->next;

    // Insert  the Node at Beginning

    // Linked List Dosent exit
    if(Head==NULL){
        Head = new Node(5);
    }
    // Linked List exist Karta hoo
    else{
        
    }
    return 0;
}