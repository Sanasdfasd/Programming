#include <bits/stdc++.h>
using namespace std;

int n;
int dp[7005][2] = {};
int deg[7005][2] = {};
vector<int> turns[2];

queue<pair<int, int>> q;

int main()
{
  cin >> n;
  int i, j, k, t;
  int s1_size, s2_size;
  cin >> s1_size;
  for (i = 0; i < s1_size; i++) {
    int val;
    cin >> val;
    turns[0].push_back(val);

  }
  cin >> s2_size;
  for (i = 0; i < s2_size; i++) {
    int val;
    cin >> val;
    turns[1].push_back(val);
  }
  memset(dp, -1, sizeof(dp));
  dp[0][0] = 0;
  dp[0][1] = 0;
  q.push({0, 0});
  q.push({0, 1});
  while (!q.empty()) {
    pair<int, int> top = q.front();
    int ply = top.second;
    int pos = top.first;
    q.pop();
    int prev_ply = (ply ^ 1);
    for (int i = 0; i < turns[prev_ply].size(); i++) {
      int prev_pos = (((pos - turns[prev_ply][i]) + n) % n);
      if (dp[prev_pos][prev_ply] != -1)
        continue;
      if (!dp[pos][ply]) {
        dp[prev_pos][prev_ply] = 2;
        q.push({prev_pos, prev_ply});
      } else {
        deg[prev_pos][prev_ply]++;
        if (deg[prev_pos][prev_ply] == turns[prev_ply].size()) {
          dp[prev_pos][prev_ply] = 0;
          q.push({prev_pos, prev_ply});
        }
      }
    }
  }

  for (j = 0; j < 2; j++) {
    for (i = 1; i < n; i++) {
      if (dp[i][j] == 0)
        cout << "Lose" << " ";
      else if (dp[i][j] == -1)
        cout << "Loop" << " ";
      else
        cout << "Win" << " ";
    }
    cout << endl;
  }
  return 0;
}