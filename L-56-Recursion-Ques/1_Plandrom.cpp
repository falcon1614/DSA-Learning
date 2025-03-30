#include<iostream>
using namespace std;
bool Palindrome(string str, int start, int end){
    // Base Case
    if(start>=end){
        return true;
    }
    // Not Palindrome
    if(str[start]!=str[end]){
        return false;
    }
    // Recursion Condition
    return Palindrome(str,start+1,end-1);
}
int main(){
    string str = "naman";
    cout<<Palindrome(str,0,4);
    return 0;
}
