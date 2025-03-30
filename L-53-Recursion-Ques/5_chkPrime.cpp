// 3: Given a Number N, check whether it is prime or not using Recursion.
#include<iostream>
using namespace std;
int prime(int n){
    int m = n;
    // Base Condition
    if(n==1){
        cout <<"Prime number"<<endl;
        return ;
    }
    // Recursion Condition
    if(m%n==0){
        cout <<"Not Prime Number"<<endl;
        return ;
    }
    prime(n-1);
}
int main(){
    int n;
    cout <<"Enter number of: "<<endl;
    cin>>n;
    cout<<prime(n)<<endl;
    return 0;
}
