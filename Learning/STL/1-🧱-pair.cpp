#include<bits/stdc++.h>
using namespace std;


int main(){

  // pair<string,int>p;
  // // Two method insert
  // p = make_pair("jayant",30);
  // cout<<p.first<<" "<<p.second<<endl;

  pair<string,pair<int,int>> p;
  // p.first = "jayant";
  // p.second.first = 30;
  // p.second.second = 40;

  p = make_pair("jayant", make_pair(30, 40));


  cout<<p.first<<" "<<p.second.first<<" "<<p.second.second<<endl;
}
