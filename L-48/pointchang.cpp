#include<iostream>
using namespace std;
void fun(int **p0){
    **p0 = **p0+1;
}
int main(){
    int n =10;
    int *p = &n;
    int **p1 = &p;
    cout<<p<<endl;
    fun(p1);
    cout<<p<<endl;
}
