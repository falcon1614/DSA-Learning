#include<bits/stdc++.h>
using namespace std;
int main(){
    long long sum_of_square = 0;
    long long square_of_sum = 0;
    int n = 100;
    for(int i=1; i<=n; i++){
        sum_of_square += i*i;
    }
    square_of_sum = (n*(n+1))/2;
    square_of_sum *= square_of_sum;

    cout<<square_of_sum<<" "<<sum_of_square<<endl;

    cout<<square_of_sum-sum_of_square<<endl;
    return 0;
}
