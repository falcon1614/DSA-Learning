#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> A(n),B(n);
        // Take Input A
        for(int i=0; i<n; i++){
            cin>>A[i];
        }
        // Take Input B
        for(int i=0; i<n; i++){
            cin>>B[i];
        }
        // Calculate Sum
        int Sum_A, Sum_B;
        for(int i=0; i<n; i++){
            Sum_A += A[i];
            Sum_B += B[i];
        }

        if(Sum_A!=Sum_B){
            cout<<"No"<<endl;
            continue;
        }

        if (A == B) {
            cout << "Yes\n0\n";
            continue;
        }
        cout << "Yes\n0\n";
    }
    return 0;
}
