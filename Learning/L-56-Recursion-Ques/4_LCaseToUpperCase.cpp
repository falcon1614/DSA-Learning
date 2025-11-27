#include<iostream>
using namespace std;
void upper(string &str, int index){
    if(index==-1){
        return;
    }
    str[index] = 'A' + str[index]-'a';
    return upper(str,index-1);
}
int main(){
    string str = "forvass";
    int n = sizeof(str)/sizeof(str[0]);
    upper(str,n);
    cout <<str<<" ";
    return 0;
}
