#include<bits/stdc++.h>
using namespace std;

vector<long long> prime;

bool is_prime(int num){
  for(int i=2; i*i <= num; i++){
    if(num % i == 0){
      return false;
    }
  }
  return true;
}

void solve(){
  int n;
  cin>>n;

  for(int i=0; i<n; i++){
    cout << prime[i] * prime[i+1] <<" ";
  }

  cout<<"\n";
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  for(int i=2; prime.size() <= 10005; i++){
    if(is_prime(i)){
      prime.push_back(i);
    }
  }

  int t;
  cin>>t;
  while(t--){
    solve();
  }
}
