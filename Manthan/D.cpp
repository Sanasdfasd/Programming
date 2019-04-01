//
// Created by Sandeep on 9/4/2018.
//
#include <bits/stdc++.h>
using namespace std;
vector<int> adj[200005];

int main(){
  int n;
   cin>>n;
  int a,b;
  int inp[n+5]={};
  for (int i = 0; i <n-1 ; ++i) {
    cin>>a>>b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }
  for (int i = 0; i <n ; ++i) cin>>inp[i];

  queue<pair<pair< int, int>,int>> q;
  map< int , int> st;
  q.push({{1,0},0});
  while(!q.empty()){
   pair< pair<int,int>,int>& top = q.front();
   // cout<<" the vertex is "<<top.first.first<<endl;
    q.pop();
     st[top.first.first]=top.first.second;
    for (int i = 0; i <adj[top.first.first].size() ; ++i) {
       if(adj[top.first.first][i]!=top.second)
         q.push({{adj[top.first.first][i], top.second+1},top.first.first});
    }
  }
  int  prev_lev=-1;
  for (int i = 0; i <n ; ++i) {
      int cur_level= st[inp[i]];
    if(cur_level!=prev_lev && cur_level!=prev_lev+1){
       cout<<"No"<<endl;
      return 0;
    }
    else if( cur_level!=prev_lev)
      prev_lev=cur_level;
  }

cout<<"Yes"<<endl;

  return 0;
}
