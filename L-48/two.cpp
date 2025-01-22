#include<iostream>
using namespace std;
int main(){
    int n = 10;
    int * p = &n; // Single Pointer
    int **p2 = &p; // Double Pointer
    int ***p3 = &p2; // Triple pointer
    cout << p <<endl;
    cout << &p <<endl;
    cout << p2 <<endl;
    cout << p3 <<endl;
    // Value Ko Modified Karna ho jo n me rakhe hai
    // *p = *p + 10;
    **p2 = **p2 + 10;
    cout<<n<<endl;
    return 0;
}
