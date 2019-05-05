//
// Created by Sandeep on 4/7/2019.
//
#include <bits/stdc++.h>
using namespace std;
bool compare( pair<long long int, long long int> fst, pair<long long int, long long int> sec){
  return fst.first >= sec.first;
}

int main(){
  long long int n,k,a,b;
  cin>>n>>k;
  vector<pair<long long int,long long int>> inp;
  for(int i=0;i<n;i++){
    cin>>a>>b;
    inp.push_back({b,a});
  }
  sort(inp.begin(), inp.end(),compare);
  priority_queue<long long int , vector<long long int>, greater<long long int>> pq;
  long long int sum=0;
  long long int ans=0;
  for(int i=0;i<inp.size();i++){
   pq.push(inp[i].second);
    sum+=inp[i].second;
    while( pq.size()>k){
       sum=sum- pq.top();
       pq.pop();
    }
   ans=max( ans, (inp[i].first)*(sum));
  }
  cout<<ans<<endl;
  return 0;
}
