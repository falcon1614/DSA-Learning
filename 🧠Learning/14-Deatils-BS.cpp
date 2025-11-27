#include<bits/stdc++.h>
using namespace std;


// ************************ Minimum Mismatch *************************
int main() {

    int arr[7] = {0, 1, 2, 3, 4, 5, 7};

    // Linear way or Brutforce
    for(int i=0; i<7; i++){
        if(arr[i] != i){
            cout << "Mismatch found at index " << i << endl;
            return 0;
        }
    }
    cout << "No mismatch found" << endl;
    return 0;
}
