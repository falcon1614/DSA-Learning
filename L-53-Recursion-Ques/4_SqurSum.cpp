#include<iostream>
using namespace std;
int sqSum(int n){
    // Base Condition
    if(n==1){
        return 1;
    }
    // Recursive Condition
    return n*n + sqSum(n-1);
}
int min(){
    int n;
    cout <<"Enter n"<<endl;
    cin>>n;
    cout<< sqSum(n)<<endl;
    return 0;
}
