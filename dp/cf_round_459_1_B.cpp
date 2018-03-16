#include <bits/stdc++.h>
using namespace std;

vector<pair<int,char> >adj[105];
int visit[105]={};
queue<pair<pair<int,int>,int> > q;
vector<int>order;
int inDegree[105]={};
int outDegree[105]={};
int dp[105][105][27][2]={};

void topologicalOrder(int ver){
  visit[ver]=1;
  for(pair<int,int> temp:adj[ver]){
    int v=temp.first;
    if(!visit[v])
      topologicalOrder(v);

  }
  order.push_back(ver);
}


void Pos(int ply1,int ply2,int val,int move) {
    if (dp[ply1][ply2][val][move] != -1)
      return;
  int sz=adj[ply1].size();
  vector<pair<int,char>> vls=adj[ply1];
  if(move==1) {
    sz = static_cast<int>(adj[ply2].size());
    vls = adj[ply2];
  }
  int loose_count=0;
  int cnt=0;
  for (int i = 0; i < sz; ++i) {
    int newPos=vls[i].first;
    int newChar=vls[i].second-(int)'a'+1;
    if(newChar>=val) {
      cnt++;
      if (move == 0) {
        Pos(newPos, ply2, newChar, move ^ 1);
        if(dp[newPos][ply2][newChar][move^1]==(move^1))
          loose_count++;
      }
      else {
        Pos(ply1, newPos, newChar, move ^ 1);
        if(dp[ply1][newPos][newChar][move^1]==(move^1))
          loose_count++;
      }
    }
  }
  if(loose_count==cnt)
    dp[ply1][ply2][val][move]=(move^1);
  else
    dp[ply1][ply2][val][move]=move;
}

int main(){
  int n,m;
  cin>>n>>m;
  int a,b;char c;
  for (int i = 0; i <m ; ++i) {
    cin>>a>>b>>c;
    adj[a-1].emplace_back(b-1,c);
    inDegree[b-1]++;
    outDegree[a-1]++;
  }
  for (int j = 0; j < n; ++j) {
    if(inDegree[j]==0)
      topologicalOrder(j);
  }
  reverse(order.begin(),order.end());
  for (int k = 0; k <n ; ++k)
    for (int i = 0; i <n ; ++i) {
      for (int j = 0; j < 27; ++j) {
        for (int l = 0; l <2 ; ++l) {
          dp[i][k][j][l]=-1;
        }
      }
    }

  int i;
  for (i = static_cast<int>(order.size()-1); i >=0; --i) {
    for (int j = i; j <order.size() ; ++j) {
      int ply1=order[i];
      int ply2=order[j];
      Pos(ply1,ply2,0,0);
      if(ply1!=ply2)
        Pos(ply2,ply1,0,0);
    }
  }
  for (int i = 0; i <n ; ++i) {
    for (int j = 0; j <n; ++j) {
     if(dp[i][j][0][0]==0)
       cout<<'A';
      else
       cout<<'B';
    }
    cout<<endl;
  }
  return 0;
}
