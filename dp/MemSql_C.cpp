//
// Created by Sandeep on 3/8/18.
//
#include <bits/stdc++.h>
using namespace std;
int pr_sums[55] = {};
int dp[55] = {};

int main() {
  int n;
  cin >> n;
  int vals[n + 5];
  for (int i = 0; i < n; i++) cin >> vals[i];
  for (int j = n - 1; j >= 0; --j)
    pr_sums[j] = pr_sums[j + 1] + vals[j];
  for (int i = n - 1; i >= 0; i--) {
    dp[i] = max(dp[i + 1], ((pr_sums[i + 1] - dp[i + 1]) + vals[i]));
  }
  cout << (pr_sums[0] - dp[0]) << " " << dp[0] << endl;

  return 0;
}
