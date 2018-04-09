//
// Created by Sandeep on 4/7/18.
//
#include <bits/stdc++.h>
using namespace std;
bool cmp(pair<int, int> fst, pair<int, int> sec){
  if(abs(fst.first -fst.second)>=abs(sec.first - sec.second))
    return true;
  else
    return false;
}
int main() {
  vector<pair<int, int>> vls;
  long long int n, k1, k2;
  cin >> n >> k1 >> k2;
  int a, b;
  vector<int> as;
  vector<int> bs;
  for (int i = 0; i < n; ++i) {
    cin >> a ;
    as.push_back(a);
  }
  for (int i = 0; i < n; ++i) {
    cin >> b ;
    bs.push_back(b);
  }
  for (int j = 0; j <n ; ++j) {
    vls.push_back({as[j],bs[j]});
  }

  sort(vls.begin(), vls.end(), cmp);
  long long int ans = 0;
  for (int i = 0; i < n; ++i) {
    // cout<<" the pair is "<<vls[i].first<<" "<<vls[i].second<<endl;
    long long int diff = abs(vls[i].first - vls[i].second);
    if((k1+k2)<=diff){
      diff-=(k1+k2);
      k1=0;
      k2=0;
    }
    else{
      if(k1>k2){
        k1=(k1+k2)-diff;
        k2=0;
        diff=0;
      }
      else{
        k2=(k1+k2)-diff;
        k1=0;
        diff=0;
      }
    }
    ans=ans+(diff*diff);
  }
  if(k1<=k2){k2=k2-k1;k1=0;}
  else{
    k1=k1-k2;
    k2=0;
  }
  if(k1!=0 || k2!=0) {
    if((k1+k2)<=n){
      ans=ans+(k1+k2);
    }
    else{
      long long int bs=(k1+k2)/n;
      long long int rem=(k1+k2)%n;
      long long int nfs=bs+1LL;
      ans+=(nfs*nfs)*(rem)+(long long int)(n-rem)*(bs*bs);
    }
  }
  cout<<ans<<endl;
  return 0;
}

