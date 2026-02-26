// https://codeforces.com/contest/1036/problem/C

#include<bits/stdc++.h>
using namespace std;
int dp[20][2][4]; // index tight countDigit

int dfs(string &s, int index, int tight, int count){

  // Base Condition
  if(count == s.size()){
    return 1;
  }

  // If compute return
  if(dp[index][tight][count] != -1){
    return dp[index][tight][count];
  }

  long long ans = 0;
  int limit = (tight == 1) : s[index] - '0':9;
  if(tight == 1){
    limit = s[index] - '0':9;
  }

  for(int i=0; i<limit; i++){

    int update_count = count;
    if(i != 0){
      update_count += 1;
    }
    else{
      update_count+=0;
    }

    int next_tight = (tight & (i== s[index] - '0'));
    if(update_count <= 3){
      ans += dfs(s, index+1, next_tight, update_count);
    }
  }

  dp[index][tight][count] = ans;
}

void solve(){
  int l,r;
  cin>>l>>r;

  string right_num = to_string(r);
  memset(dp, -1, sizeof(dp));
  int right = dfs(right_num, 0, 1, 0);

  string left_num = to_string(l-1);
  memset(dp, -1, sizeof(dp));
  int left = dfs(left_num, 0, 1, 0);

  cout << right - left <<"\n";
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

