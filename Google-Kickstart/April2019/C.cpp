#include <bits/stdc++.h>
using namespace std;

int main(){

   int t;
   cin>>t;

   for(int tt=1;tt<=t;tt++){
   int ans=1;
   int n,s;
   cin>>n>>s;
   vector<int> inp(n);
   map<int,int> mp;
   deque<pair<int,int>> dq;
   for(int i=0;i<n;i++) cin>>inp[i];
   
   for(int i=0;i<n;i++){
      int elem= inp[i];
      mp[elem]++;
      if(mp[elem]>s){
         
      }
     else{
        
     }
   }




   cout<< "Case #"<<tt<<": "<<ans<<endl;
   }





	return 0;
}