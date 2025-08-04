#include<bits/stdc++.h>
using namespace std;

int main(){

  int n;
  cin>>n;
  string binary = " ";

  while(n>0){
    int rem = n%2;
    binary += to_string(rem);
    n/=2;
  }
  reverse(binary.begin(),binary.end());
  cout<<binary<<" ";
  cout<<endl;
  return 0;
}
