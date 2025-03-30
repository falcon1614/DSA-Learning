#include<iostream>
using namespace std;
void print(int n){
    if(n==0){
        cout<<"0"<<endl;
        return;
    }
    cout<<n<<" ";
    print(n-1);
}
int main(){
    return 0;
}
