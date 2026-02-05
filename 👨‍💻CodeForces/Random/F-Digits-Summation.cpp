#include<bits/stdc++.h>
using namespace std;
int main(){
  long long n,m;
  cin>>n>>m;
  int digit_1 = n%10;
  int digit_2 = m%10;
  cout<<digit_1+digit_2<<endl;
  return 0;
}
