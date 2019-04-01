#include<bits/stdc++.h>
using namespace std;

int main(){
  long long int n,s;
  cin>>n>>s;
  vector<long long int> vs;
  long long int a;
  long long int su=0;
  for(int i=0;i<n;i++) {
   cin>>a;
    su+=a;
    vs.push_back(a);
  }
  if(s>su)
   cout<<-1<<endl;
  else{
    long long int mi=vs[0];
    for(int i=1;i<vs.size();i++)
      mi=min(mi, vs[i]);
    long long int more=0;
    for(int i=0;i<vs.size();i++){
      more+=vs[i]-mi;
    }
    if(more>=s)
      cout<<mi<<endl;
    else{
      s=s-more;
      cout<<mi-((s-1LL)/(long long int)vs.size())-1LL<<endl;
    }
  }
  return 0;
}