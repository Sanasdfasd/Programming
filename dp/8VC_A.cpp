//
// Created by Sandeep on 3/27/18.
//
#include <bits/stdc++.h>
using namespace std;
int main(){
  long long int a,b;
  cin>>a>>b;
  if(a<b)
    cout<<0<<endl;
  else {
    long long int diff = a - b;
    if ((diff % 2) != 0) {
      cout << 0 << endl;
      return 0;
    } else {
      diff /= 2;
      long long int val = diff & b;
      long long int v1= __builtin_popcountll(b);
      long long int ans=(long long int)pow(2L,v1);
      if (a == b)
       cout<<(ans-2L)<<endl;
      else if(val==0)
        cout<<ans<<endl;
      else
       cout<<0<<endl;
    }
  }
  return 0;
}
