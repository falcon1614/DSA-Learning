#include<iostream>
#include<exception>
using namespace std;
int main(){
    try{
        int *p = new int[10000000000000000000];
        cout<<"Memory Allocated is sucessfully"<<endl;
        delete []p;
    }
    catch(const bad_exception &e){
        cout<<"Exception Handling"<<e.what()<<endl;
    }
    return 0;
}
