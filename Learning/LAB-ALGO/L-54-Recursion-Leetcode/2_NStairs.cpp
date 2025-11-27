#include<iostream>
using namespace std;
int totalways(int n){
    // Base Case
    if(n<=1){
        return 1;
    }
    // Recursion Relation
    return totalways(n-1)+totalways(n-2);
}
int main(){
    int n;
    cout<<"Enter the number of elements: ";
    cin>>n;
    cout<<totalways(n)<<" ";
    return 0;
}
