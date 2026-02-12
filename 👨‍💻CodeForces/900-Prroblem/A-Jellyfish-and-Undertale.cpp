#include<bits/stdc++.h>
using namespace std;

void solve(){
  long long a,b,n;
  cin >> a >> b >> n;
  vector<long long> ar(n);
  for(int i=0; i<n; i++){
    cin>>ar[i];
  }

  long long maximum_time = b;
  for (int i = 0; i < n; i++)
	maximum_time += min(ar[i], a - 1);

	cout << maximum_time << endl;
}
int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin>>t;
  while(t--){
    solve();
  }
  return 0;
}
