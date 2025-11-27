#include<iostream>
using namespace std;
int fib(int n){
    // Base Condition
    if(n<=1){
        return n;
    }
    // Recursive call
    return fib(n-1)+fib(n-2);
}
int main(){
    int n;
    cout <<"Enter a number: ";
    cin>>n;
    cout<<fib(n)<<" ";
    return 0;
}
