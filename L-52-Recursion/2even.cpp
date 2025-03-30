#include<iostream>
using namespace  std;
void print(int n){
    if(n==2){
        cout<<n<<endl;
        return;
    }
    print(n-2);
    cout << n <<" ";
}
int main(){
    int n;
    cout << " Enter the number of elements: ";
    cin >> n;
}
