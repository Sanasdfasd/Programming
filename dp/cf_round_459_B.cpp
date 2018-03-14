
#include <bits/stdc++.h>
using namespace std;
vector<pair<int, char>> adj[105];
int visit[105] = {};
queue<pair<pair<int, int>, int>> q;
vector<int> order;
int inDegree[105] = {};
int outDegree[105] = {};
int dp[105][105] = {};
void topologicalOrder(int ver) {
  visit[ver] = 1;
  for (pair<int, int> temp : adj[ver]) {
    int v = temp.first;
    if (!visit[v])
      topologicalOrder(v);
  }
  order.push_back(ver);
}
void Pos(int ply1, int ply2) {
  if (ply1 == ply2) {
    dp[ply1][ply2] = 1;
    return;
  }
  // int mover=ply1;
  if (outDegree[ply1] == 0) {
    dp[ply1][ply2] = 1;
    return;
  } else if (outDegree[ply2] == 0) {
    dp[ply1][ply2] = 0;
    return;
  } else {
    // int ans=1;
    for (int k = 0; k < adj[ply1].size(); ++k) {
      int ply1_move = adj[ply1][k].first;
      char ply1_move_char = adj[ply1][k].second;
      if (adj[ply1][k].first == ply2) {
        dp[ply1][ply2] = 0;
        return;
      } else {
        int tr = 0, cnt = 0;
        for (int i = 0; i < adj[ply2].size(); ++i) {
          int ply2_move = adj[ply2][i].first;
          int ply2_move_char = adj[ply2][i].second;
          if (((int)ply2_move_char) >= ((int)ply1_move_char)) {
            tr = 1;
            if (dp[ply1_move][ply2_move] == 1) {
              cnt = 1;
              break;
            }
          }
        }
        if (tr == 0 || cnt == 0) {
          dp[ply1][ply2] = 0;
          return;
        }
      }
    }
    dp[ply1][ply2] = 1;
  }
}

int main() {
  int n, m;
  cin >> n >> m;
  int a, b;
  char c;
  for (int i = 0; i < m; ++i) {
    cin >> a >> b >> c;
    adj[a - 1].push_back({b - 1, c});
    inDegree[b - 1]++;
    outDegree[a - 1]++;
  }
  for (int j = 0; j < n; ++j) {
    if (inDegree[j] == 0)
      topologicalOrder(j);
  }
  reverse(order.begin(), order.end());
  for (int k = 0; k < n; ++k)
    for (int i = 0; i < n; ++i) {
      dp[k][i] = -1;
    }

  for (int i = order.size() - 1; i >= 0; --i) {
    for (int j = i; j < order.size(); ++j) {
      int ply1 = order[i];
      int ply2 = order[j];
      Pos(ply1, ply2);
      if (ply1 != ply2)
        Pos(ply2, ply1);
    }
  }
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      if (dp[i][j] == 0)
        cout << 'A';
      else
        cout << 'B';
    }
    cout << endl;
  }
  return 0;
}
