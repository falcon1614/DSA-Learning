#include<iostream>
using namespace std;
int sum(int n){
    // Base condition
    if(n==1){
        return 1;
    }
    // Recursive condition
    return n + sum(n-1);
}
int main(){
    int n;
    cout <<"Enter Sum n Natural Number"<<endl;
    cin >> n;
    cout <<"sum Is: "<< sum(n);
    return 0;
}
