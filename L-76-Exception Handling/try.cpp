#include<iostream>
using namespace std;
int main(){
    int a,b;
    cin>>a>>b;
    try{
        if(b==0){
            throw "Division by zero is not allowed";
        }
        int  c = a/b;
        cout<<c<<endl;
    }
    catch(const char *e){
        cout<<"Exception Occurs"<<e<<endl;
    }
    return 0;
}
