#include<iostream>
using namespace std;
void print(int num, int n){
    if(num == n){
        cout << num << endl;
        return;
    }
    cout << num << " ";
    print(num+1, n);
}
int main(){
    int n;
    cout << " Enter the number of elements: ";
    cin >> n;
    int num;
    cout << " Enter the number: ";
    cin >> num;
    print(num, n);
    return 0;
}
