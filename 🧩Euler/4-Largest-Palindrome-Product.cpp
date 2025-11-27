#include<bits/stdc++.h>
using namespace std;
int reverse_num(int n) {
    int rev = 0;
    while (n) {
        rev = rev * 10 + n % 10;
        n /= 10;
    }
    return rev;
}

int main(){
    int largest_palindrome = 0;
    for(int i=999; i>=100; i--){
        for(int j=i; j>=100; j--){
            int temp = i*j;
            if(temp==reverse_num(temp)){
                // cout<<i<<" "<<j;
                // largest_palindrome = temp;
                // cout<<endl;
                // cout<<largest_palindrome;
                // return 0;
                largest_palindrome = max(largest_palindrome,temp);
            }
        }
    }
    cout<<largest_palindrome;
    return 0;
}
