#include<bits/stdc++.h>
using namespace std;

int  main(){
  int a = 5, b = 3, c = 5;
  long long x  = 1;
  for(int i = 2; i <= a; i++){
    if((i-1)%b==0) x *= 2;
    if((i-1)%c==0) x--;
  }
  cout<<x<<endl;
  return 1;
}
