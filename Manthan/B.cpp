//
// Created by Sandeep on 9/4/2018.
//
#include <bits/stdc++.h>
using namespace std;
int main(){
int n,m;
  cin>>n>>m;
  long long int ar[n+5];
  long long int  prefix_sum[n+5]={};
  prefix_sum[0]=0;
  for(int i=0;i< n;i++){ cin>> ar[i]; }
  sort(ar, ar+n);
  if( n==1){ cout<<abs(ar[0]-m);
    return 0;}
  for(int i=0;i<n;i++)
    prefix_sum[i+1]=prefix_sum[i]+ar[i];

  prefix_sum[n+1]+=prefix_sum[n];
  ar[n]=INT_MAX;

  if( ar[n/2]==m)
    return 0;
if( ar[n-1]<m){
  long long int t1=(n-n/2);
  long long int t2 = m;
  cout<<llabs((t1*t2) - prefix_sum[n]);
  return 0;
}
  int i=0;
  while(i<n){
    if( ar[i]>m || ( ar[i]==m && i>n/2))
      break;
    i++;
  }
  long long int res=0;
  int index=i;
 // cout<<" the index is "<<index<<" "<<ar[n/2]<<" "<<prefix_sum[index]<<" "<<prefix_sum[(n / 2)]<<endl;
  if(index > (n/2)) {
    long long int t1=llabs(n/2-index);
    long long int t2 = m;
    res = llabs(t1*t2 - llabs(-prefix_sum[(n / 2)] + prefix_sum[index]));
  }
else{
    long long int t1=llabs(n/2-index+1);
    long long int t2 = m;
   // cout<<" the index is "<<index<<" "<<" "<<abs(m*(abs((n/2)-index+1)))<<" "<<ar[n/2]<<" "<<prefix_sum[index]<<" "<<prefix_sum[(n / 2)+1]<<endl;
    res=llabs(t1*t2- llabs(prefix_sum[((n/2)+1)]-prefix_sum[index]));
  }
  cout<<res<<endl;

  return 0;
}
