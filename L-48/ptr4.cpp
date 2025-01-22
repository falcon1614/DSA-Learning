#include<iostream>
using namespace std;
int main(){
    int a = 5;
    int b = 10;
    int &name = a;
    int *ptr = &a;
    *ptr++;
    ptr = &b;
    *ptr += 5;
    return 0;
}
