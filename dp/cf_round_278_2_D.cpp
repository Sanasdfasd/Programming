//
// Created by Sandeep on 4/6/18.
//
#include <bits/stdc++.h>
using namespace std;

int main(){

  int n,s,l;
  cin>>n>>s>>l;
  vector<int> ar;
  int t;
  for (int i = 0; i <n ; ++i) {
    cin>>t;
    ar.push_back(t);
  }
  multiset<int> g;
  g.insert(ar[0]);
  vector<int> larg;
  larg.push_back((ar[0]<=s));
  for (int i = 1; i <n ; ++i) {
    cout<<" I am here"<<i<<endl;
    int k=0;
    int begin=*(g.begin());
    int end= *(--g.end());
    cout<<" the begin and end are "<<begin<<"  "<<end<<endl;
    if(abs(ar[i]-begin)<=s && abs(ar[i]-end)<=s) {
      larg.push_back(g.size()+1);g.insert(ar[i]);
      continue;}
      while(!g.empty() && (abs(ar[i]-(*(g.begin())))>s)) {
        g.erase(g.lower_bound(*(g.begin())));
        k++;
      }
      while(!g.empty() && (abs(ar[i]-(*(--g.end())))>s)) {
        cout<<" the value is "<<--g.end()
        g.erase(--g.end());
        k++;
      }
    larg.push_back(g.size()+1);
   g.insert(ar[i]);
  }
  cout<<" the largest is "<<endl;
  for (int j = 0; j <n ; ++j)
    cout<<larg[j]<<" ";

  cout<<endl;
  return 0;
}
