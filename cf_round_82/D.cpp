//
// Created by Sandeep on 4/7/18.
//
#include <bits/stdc++.h>
using namespace std;
char ar[1005][1005];
const int dx[] = {0,0,1,-1};
const int dy[]= {-1,1,0,0};
int sum[1005][1005]={};
map<char, int> vl;
int n,m;
int k;
vector<pair <char,int> > dir;
bool inside(int x, int y){
  return ((x<n) && (y<m));
}
bool check2(int x1, int y1, int x2, int y2){
  if(!inside(x2,y2)) return false;


}
bool check (int x, int y){
  for (int i = 0; i <k ; ++i) {

  }
  return true;
}

int main(){
  vl['N']=0, vl['S']=1, vl['E']=2, vl['W']=3;
  cin>>n>>m;
  vector<pair<int,int>> pos;
  for (int i = 0; i <n ; ++i)
    for (int j = 0; j <m ; ++j) {
      cin >> ar[i][j];
      if(ar[i][j]>='A'&& ar[i][j]<='Z')
        pos.push_back({i,j});
    }
  cin>>k;
  char a; int b;
  for (int l = 0; l <k ; ++l) {
    cin>>a>>b;
    dir.push_back({a,b});
  }
  for (int i = 0; i <n ; ++i) {
    for (int j = 0; j <m ; ++j) {
      if(i==0 && j==0)
        sum[i][j]=(ar[i][j]=='#');
      else if(i==0)
        sum[i][j]=sum[i][j-1]+(ar[i][j]=='#');
      else if(j==0)
        sum[i][j]=sum[i-1][j]+(ar[i][j]=='#');
      else
      sum[i][j]=sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1]+(ar[i][j]=='#');
    }
  }
  vector<char> ans;
  for (int i = 0; i <pos.size() ; ++i) {
    if(check(pos[i].first, pos[i].second)) ans.push_back(ar[pos[i].first][pos[i].second]);
  }
 if(ans.empty())
   cout<<'No soltion'<<endl;
  else{
   sort(ans.begin(), ans.end());
   for (int i = 0; i <ans.size() ; ++i)
     cout<<ans[i];
 }
  return 0;
}
