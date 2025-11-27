#include<iostream>
using namespace std;
int factorial(int num){
    // Base Case
    if(num == 1 || num == 0){
        return 1;
    }
   return num = num * factorial(num-1);
}
int main(){
    int num;
    cout<<"Enter a number: ";
    cin >> num;
    // Handle Negative Numbers
    if (num < 0 ){
        cout << " Factorial does not exist for negative numbers";
        return 0;
    }
    // Call Function
    long long int ans = factorial(num);
    cout << ans ;
    return 0;
}
