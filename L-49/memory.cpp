#include<iostream>
#include<vector>
using namespace std;
int main(){
    // Variable ka leya Heap Memory allocation
    int *ptr = new int;
    *ptr = 5;  // Value Assign
    cout<<ptr<<endl;

    float *ptr1 = new float;
    *ptr1 = 3.64;
    cout<<ptr1<<endl;

    int n;
    cout<<"Enter The Size of Array"<<endl;
    cin>>n;
    int *ptr2 = new int[n];
    // Assign Value
    for (int i = 0; i < n; i++)
    {
        ptr2[i] = i+1;
    }
    // Print Value
    for (int i = 0; i < n; i++)
    {
        cout<<ptr2[i]<<" ";
    }
    // Delete
    delete ptr;
    delete[]  ptr2;
    return 0;
}
