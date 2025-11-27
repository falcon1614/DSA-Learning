#include<iostream>
using namespace std;
int power(int num, int n){
    // Base Condition
    if(n==0) return 1;
    if(n == 0){
        return num;
    }
    // Recursive Condition
    return  num * power(num, n-1);
}
int main(){
    int num,n;
    cout << "Enter Number :"<<endl;
    cin >>num;
    cout <<"Enter N :"<<endl;
    cin >>n;
    cout<<"Power of "<<num<<" is: "<<power(num,n);
}
