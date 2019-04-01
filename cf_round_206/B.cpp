#include <bits/stdc++.h>

using namespace std;
long long int mod = 1000000000+7;

long long int cal_power( long long int base, long long int exp){

  if(exp==0)
    return (long long int)1;

  long long int ans= cal_power(base,exp/(long long int)2)%mod;
  ans=(ans*ans)%mod;

  if((exp%2)!=0)
    ans=(ans*base)%mod;

  return ans%mod;
}


int drawingEdge(int n) {

  if(n==1)
    return 1;
  long long int val =n;

  int final_ans=1;

  long long int su = (val-1)*val /2;

  final_ans =cal_power(2,su)%mod;

  return final_ans;
}