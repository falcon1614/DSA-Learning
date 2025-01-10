#include<iostream>
using namespace std;
int main(){
    int a = 10;
    int * ptr = &a;
    cout << "Value of a: " << &a << endl;
    cout << "Value of ptr: " << ptr << endl;
    cout << "Size of ptr: " << sizeof(ptr) << endl;
    cout << "Value of a using ptr: " << *ptr << endl;
    float b = 10.5;
    float * ptr1 = &b;
    cout << "Value of b: " << &b << endl;
    cout << "Value of ptr1: " << ptr1 << endl;
    cout << "Size of ptr1: " << sizeof(ptr1) << endl;
    cout << "Value of b using ptr1: " << *ptr1 << endl;

    return 0;
}
