//
// Created by Sandeep on 2/18/2019.
//
#include <bits/stdc++.h>
using namespace std;

class segtree{
 private:
  vector<int> lo;
  vector<int>  hi;
  vector<int> mx;
  int n;
 public:
  segtree(int n){
    this->n=n;
     lo.resize(4*n+5);
     hi.resize(4*n+5);
     mx.resize(4*n+5);
    Init(1,0,n-1);
  }
 void Init( int i, int a, int b){
   lo[i]=a;
   hi[i]=b;
   mx[i]=-1;
   if(a==b){
     return ;
   }
   int mid=(a+b)/2;
   Init(2*i,a,mid);
   Init(2*i+1, mid+1, b);
 }
void update(int i, int a, int b, int v){
  if(b<lo[i] || a>hi[i]){ // a__b: 0___3   lo[i] =0,
    return ;
  }
  if(lo[i]>=a && hi[i]<=b){
   mx[i]=v;
    return ;
 }
  update(2*i, a,b,v);
  update(2*i+1,a,b,v);
}
void maxIndex(int i, int a,int & mi){
  mi=max(mi,mx[i]);
  if(lo[i]==hi[i]){
    return;
  }
  int mid=(lo[i]+hi[i])/2;
  if(a<=mid){
    maxIndex(2*i,a,mi);
  }
  else{
    maxIndex(2*i+1,a,mi);
  }
}
};
int main(){
  int n=7;
  segtree * s= new segtree(n);
  string inp="qwertyt";
  vector<pair<pair<int,int>,char>> intervals;
  intervals.push_back({{0,3},'b'});
  intervals.push_back({{2,4},'i'});
  intervals.push_back({{1,5},'s'});
  intervals.push_back({{2,3},'u'});
  for(int i=0;i<intervals.size();i++){
    s->update(1,intervals[i].first.first, intervals[i].first.second, i);
  }
 for(int i=0;i<inp.size();i++){
  // cout<<" the zeroth  value is "<<i<<endl;
    int mi=-1;
    s->maxIndex(1,i,mi);
    if(mi!=-1){
      inp[i]=intervals[mi].second;
    }
  }

 cout<<" the replaced string is:  "<<inp<<endl;

  return 0;
}

