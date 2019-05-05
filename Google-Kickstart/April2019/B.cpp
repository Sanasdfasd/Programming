#include <bits/stdc++.h>
using namespace std;

bool compare(pair<pair<int,int>,int> fst, pair<pair<int,int>,int> sec){
  return ((fst.first.first* sec.second)<(sec.first.first* fst.second));
}

int main(){
  int t;
  cin>>t;
  for(int it=1;it<=t;it++){
   int n;
   cin>>n;
   vector<pair < pair<int, int>,int > > inp;
   int s, e,l;
   for(int i=0;i<n;i++){
   	 cin>>s>>e>>l;
     inp.push_back({{s,e},l});
   }
   sort(inp.begin(), inp.end(),compare);
   int dp[10005]={};

   for(int i=0;i<n;i++){
     int s=inp[i].first.first;
     int e=inp[i].first.second;
     int l=inp[i].second;
    for(int j=9999;j>=0;j--){
       if((j+s) <=10000 && (dp[j]!=0 ||(j==0))){
          dp[j+s]=max( dp[j+s], dp[j]+e-(j*l));
       }
      }
    }
    
  int ans=0;
  for(int i=0;i<=10000;i++){
     ans=max( ans, dp[i]);
     
  }
   cout << "Case #" << it << ": "<<ans<<"\n";
  }
 
	return 0;
}