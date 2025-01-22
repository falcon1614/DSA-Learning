#include<iostream>
#include<string>
using namespace std;
int main(){
    char str[10] = {'1','2','3','4','5'};
    char *ptr = str;
    cout << str << endl;  // print value
    cout << ptr << endl;
    // Print Address
    cout << (void*)str <<endl;
    cout << static_cast<void*> (str) <<endl;
    cout << (void*)ptr <<endl;
    //
    char name = 'a';
    char *ptr1 = &name;
    cout << (void*)&name << endl;
    cout << (void*)ptr1 << endl;
    // Pass by pointer
    void incr(int *ptr){
        *ptr = *ptr + 1;
    }
    int num = 10;
    int temp = num;
    incr(&num);
    cout << num <<endl;
    return 0;
}
