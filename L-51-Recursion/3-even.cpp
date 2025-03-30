#include<iostream>
using namespace std;
void even(int n){
    // Base Case
    if (n==2){
        cout<<"2";
        return;
    }
    cout<<n<<" ";
    even(n-2);
}
int min(){
    int n;
    cin>>n;
    even(n);
    return 0;
}
