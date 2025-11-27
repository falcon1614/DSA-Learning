// https://www.naukri.com/code360/problems/n-stacks-in-an-array_1164271?leftPanelTabValue=PROBLEM
// https://www.geeksforgeeks.org/problems/implement-two-stacks-in-an-array/1?utm_source=geeksforgeeks&utm_medium=ml_article_practice_tab&utm_campaign=article_practice_tab

#include<bits/stdc++.h>
using namespace std;

class Node{
  public:
  int data;

};

class Nstack{
  public:
  int *arr; // original dax
  Node **Top;
  stack<int>st;
  Nstack(int N, int s){
    arr = new int[s];
    Top = new Node*[N];
    for(int i=0; i<N; i++){
      Top[i] = NULL; // Initialize all stack tops to nullptr
      for(int j=0; j<s; j++){
        st.push(1);
      }
    }
  }
};
int main(){

  return 0;
}
