#include<bits/stdc++.h>
using namespace std;
int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  long long a,b,c,d;
  cin>>a>>b>>c>>d;
  string output = "NO";

  if(a + b - c == d) output = "YES";
  if(a + b * c == d) output = "YES";
  if(a - b + c == d) output = "YES";
  if(a - b * c == d) output = "YES";
  if(a * b + c == d) output = "YES";
  if(a * b - c == d) output = "YES";

  cout<<output<<endl;
}

