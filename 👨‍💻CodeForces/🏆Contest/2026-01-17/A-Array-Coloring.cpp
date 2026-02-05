
#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin >> n;

    vector<pair<int, char>> col;

    for(int i = 0; i < n; i++){
        int temp;
        cin >> temp;
        if(i % 2 == 0)
            col.push_back({temp, 'R'});
        else
            col.push_back({temp, 'B'});
    }

    sort(col.begin(), col.end());

    for(int i = 0; i + 1 < n; i++){
        if(col[i].second == col[i+1].second){
            cout << "NO" << endl;
            return;
        }
    }

    cout << "YES" << endl;
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
