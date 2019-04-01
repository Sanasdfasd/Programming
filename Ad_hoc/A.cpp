//
// Created by Sandeep on 8/30/2018.
//
//Blooming flowers problem
#include <bits/stdc++.h>
using namespace std;
int n,k;
set<int> vls;
set<int>::iterator it;

bool compute(int cur_index, int prev_index, int up){
  if (vls.find(prev_index) != vls.end()) {
    it=vls.find(prev_index);
    if(up)it=it++;
    else it--;
    cout<<" the current index is "<<cur_index<<" "<<prev_index<<" "<<(*it)<<endl;
    if(*(it)==cur_index)
      return true;
  }
  return false;
}
int main(){
  cin>>n>>k;
 int flow[n+5];
  for (int i = 0; i <n ; ++i) 
    cin>>flow[i];
  int res=-1;
  for (int j = 0; j <n ; ++j) {
    vls.insert(flow[j]);
    if((flow[j]-k-1)>0) {
      if(compute(flow[j],flow[j] - k-1, 1))
        res=j+1;
    }
    if((flow[j]+k+1)<=n)
      if(compute(flow[j],flow[j]+k+1,0))
        res=j+1;
  }
  cout<<res<<endl;
  return 0;
}
