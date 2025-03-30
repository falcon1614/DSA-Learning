#include<iostream>
using namespace std;
void lower(string &str, int index){
    if(index==-1){
        return;
    }
    str[index] = 'A' + str[index]+'a';
    return lower(str,index-1);
}
int main(){
    string str = "FORVASS";
    int n = sizeof(str)/sizeof(str[0]);
    lower(str,n);
    cout<<str<<" ";
    return 0;
}
