//
// Created by Sandeep on 3/24/18.
//
#include <bits/stdc++.h>
using namespace std;
int main(){
  int n,u;
  cin>>n>>u;
   int ar[n+5];
  for (int i = 0; i <n ; ++i)
    cin>>ar[i];
  double ans=0.0;
  bool set= false;
  for (int i = 0; i <n-2 ; ++i) {
    int low=i+2, hi=n-1;
    while(low<=hi){
      int mid=(low+hi)/2;
       if(((ar[mid] - ar[i]) <= u)) {
         double eff = ((double)(ar[mid]-ar[i+1])/(double)(ar[mid]-ar[i]));
         ans= max(ans, eff);
         low=mid+1;
         set=true;
       }
      else
         hi=mid-1;
    }
  }
  if(set)
  cout << setprecision(12) << ans << endl;
  else
    cout<<-1<<endl;
  return 0;
}
