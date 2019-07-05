#include <bits/stdc++.h>
using namespace std;

int main(){

int n,m;
cin>>n;
vector<int> pr(n),a(n),b(n);
for(int i=0;i<n;i++) cin>>pr[i];
for(int i=0;i<n;i++) cin>>a[i];
for(int i=0;i<n;i++) cin>>b[i];	
cin>>m;
vector<int>c(m);
for(int i=0;i<m;i++) cin>>c[i];

set<int> s[4];

for(int i=0;i<n;i++){
   if(a[i]==b[i]){
      s[a[i]].insert(pr[i]);
   }
   else{
     s[a[i]].insert(pr[i]);
     s[b[i]].insert(pr[i]);
   }
}

for(int i=0;i<m;i++){
  if(!s[c[i]].empty()){
  	int val = *(s[c[i]].begin());
    cout<<val<<" ";
    for(int k=1;k<=3;k++) s[k].erase(val);
  }
  else
  	cout<<-1<<" ";
}
	return 0;
}