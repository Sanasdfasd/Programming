//
// Created by Sandeep on 7/29/2018.
//
#include <bits/stdc++.h>
using namespace std;
int m;
long long int dp[27];

string solve(int n, int k, string prevdigs, int len) /// prevdigs are all digits known so far.
{
  if (k == 0)
    return prevdigs;
  k --;
  if (len == 1)
    return prevdigs*10 + k;
  /// suppose n = 345 in all comments below;
  int whole = pow(10, len - 1); /// 100
  int sigdig = n / whole;       /// 3
  int remain = n % whole;       /// 45
  int allones_1 = (whole - 1) / 9;  /// 11
  int allones_0 = allones_1*10 + 1; /// 111
  int allones_2 = allones_1 / 10;   /// 1
  int low_bar =  allones_0 * sigdig; /// 111 * 3 = 333 The number of strs before 3 (containing 111 digits starting with 0)
  int high_bar = low_bar + allones_1 + remain + 1; /// 333 + 11 + 45 + 1 (11 is 3, 30, 31 ... 39)
  if (k < low_bar)   /// k is before 3
  {
    int curdig = k / allones_0; /// figure out the current digit is 0, 1 or 2;
    return solve(allones_1 * 9, k % allones_0, prevdigs*10 + curdig, len - 1); /// allones_1 * 9 makes 99, meaning search everything
  }                                                                              /// with length len-1
  if (k >= high_bar) /// k is after 39 (largest in 3XX)
  {
    k -= high_bar;
    //Working okay for us
    int curdig = sigdig + k / allones_1 + 1; /// figure out the current digit among 4~9;
    return solve(allones_2 * 9, k % allones_1, prevdigs * 10 + curdig, len - 2); ///allones_2 * 9 makes 9, meaning search everything
  }                                                                                ///with length len-2
  k -= low_bar;
  int curdig = sigdig;
  return solve(remain, k, prevdigs * 10 + curdig, len - 1); /// search in 45 with length 2;
}

int findKthNumber(int n, int k)
{
  int len = 0; /// length of n
  for(int m = n; m > 0; m/= 10, ++len);
  k += (pow(10, len) - 1)/9; /// solve function considers 0's before 1; we make up this difference first;
  return solve(n, k, 0, len); ///len is important, o/w when k = 5 in a middle round, you don't know it's X005 or X05,
}
int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);
  int t;
  cin>>t;
  int p=1;
  while(t--) {
     int n, l,k;
    cin>>l>>n>>k;
    m=l;
    int ans = get_size(k,n);
    cout << "Case #"<<p<<": "<<ans<< endl;
    p++;
  }

  return 0;
}
