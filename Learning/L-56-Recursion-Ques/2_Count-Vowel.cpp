#include<iostream>
using namespace std;
int vowles(string str, int index){
    if(index == -1){
        return 0;
    }
    if(str[index]=='a'||str[index]=='e'||str[index]=='i'||str[index]=='o'||str[index]=='u'){
        return 1+vowles(str,index-1);
    }
    else
    {
        return vowles(str,index-1);
    }
}
int main(){
    string str = "Hello, World!";
    int n = sizeof(str) / sizeof(str[0]);
    cout <<vowles(str,n);
    return 0;
}
