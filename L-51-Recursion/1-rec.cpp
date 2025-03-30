#include<iostream>
using namespace std;
void birthday(int n){
    if(n==0){
        cout<< " Happy Birthday"<<endl;
        return;
    }
    cout<<n<<"days Left For Birthday"<<endl;
    birthday(n-1);
}
int main(){
    int n = 5;
    birthday(n);
    return 0;
}
