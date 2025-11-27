#include<iostream>
using namespace std;
int main(){
    int arr[5] = {1,2,3,4,5};
    int *ptr = arr;
    int n = sizeof(arr)/arr[0];
    // Print the address of first element
    cout << "Address of first element: " << arr << endl;
    cout << "Address of first element: " << arr+0 << endl;
    cout << "Address of first element: " << &arr[0] << endl;
    cout << "Address of first element through pointer: " << ptr << endl;
    // Print the address of second element
    int *ptr1 = arr+1;
    cout << "Address of second element: " << arr+1 << endl;
    cout << "Address of second element: " << ptr1 << endl;
    cout << "Address of second element: " << &arr[1] << endl;
    // print the value of 0 index
    cout << "Value of 0 index element: " << arr[0] << endl;
    cout << "Value of 0 index element: " << *ptr << endl;
    cout << "Value of 0 index element: " << *(arr) << endl;
    cout << "Value of 0 index element: " << *(arr+0) <<endl;
    // Print all address
    for(int i=0; i<5; i++){
        cout<< arr + i;
    }
    // Print all value
    for(int i=0; i<5; i++){
        cout<< *(arr + i);
    }

    // Print all the value using pointer
    for(int i=0; i<5; i++){
        cout << ptr[i] <<" ";
    }
    // Print add address
    for(int i=0; i<5; i++){
        cout << ptr + i <<" ";
    }
    // Arithmetic operation on pointer ptr++, ptr---, ptr = Ptr+1;
    for(int i=0; i<5; i++){
        cout << *ptr <<endl;
        ptr++;
    }
    // Addition
    ptr = ptr+3;
    cout << *ptr <<endl;
    // Subtraction
    ptr = ptr-2;
    cout << *ptr <<endl;
    
    return 0;

}
