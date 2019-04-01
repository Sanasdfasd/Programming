//
// Created by Sandeep on 9/29/2018.
//
#include <bits/stdc++.h>
using namespace std;

int main(){
  long long int nums;
  cin>>nums;
  int ans=0;
  for(long long i=2;i<=(1000000);i++){
    long long int val =i*i;
    long long int su = (2*nums - val);
    if((su%i)==0 && su>0){
       su=su/i;
       if((su+1LL)%2==0) {
         ans++;
       }
    }
  }
  cout<<ans<<endl;

  return 0;
}
