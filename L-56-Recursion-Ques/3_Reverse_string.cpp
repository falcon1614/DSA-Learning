#include<iostream>
using namespace std;
void reverse(string &str, int start, int end){
    // Base Case
    if(start >= end){
        return ;
    }
    char c = str[start];
    str[start] = str[end];
    str[end] = c;
    // Recursion Relation
    return reverse(str,start+1,end-1);
}
int main(){
    string str = "jay Forvass";
    int n = sizeof(str) / sizeof(str[0]);
    reverse(str,0,n);
    cout <<str<<endl;
    return 0;
}
