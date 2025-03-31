#include<iostream>
using namespace std;
void fun(int *p){
    *p = *p + 10;
}
int main(){
    int n = 10;
    int *p = &n;
    int **p2 = &p;
    fun(p);
    cout<<n;
    return 0;
}
