//
// Created by Sandeep on 10/17/2018.
//
#include <bits/stdc++.h>
using namespace std;
class pq{
 private:
  int sz;
   int ar[10000];
 public:
  pq();
  ~pq();
  void insert(int);
  int top();
  void pop();
};
pq::pq(){
  sz=-1;
}
pq::~pq(){
  cout<<"object's destructor is called "<<endl;
}
void pq::insert(int val){
  ar[++sz]=val;
  int cur=sz;
  int par=sz/2;
  while(par!=cur){
    if(ar[par]>ar[cur]){
      int temp=ar[cur];
      ar[cur]=ar[par];
      ar[par]=temp;
    }
    else
      break;
    cur=par;
    par=cur/2;
  }
}
int pq::top(){
 if(sz==-1)
   cout<<"No elements to return "<<endl;
 else
   return ar[0];
}
void pq::pop() {
  if (sz == -1)
    cout << "No elements to return " << endl;
  else {
    ar[0]=ar[sz];
    sz--;
    int cur=0,node;
    while(((cur*2+1)<=sz) ||((cur*2+2)<=sz)){
      if((cur*2+2)>sz || (ar[cur*2+1]<ar[cur*2+2]))
        node=cur*2+1;
      else
        node=cur*2+2;
      if(ar[node]>=ar[cur]) break;
        int temp=ar[node];
        ar[node]=ar[cur];
        ar[cur]=temp;
        cur=node;
    }
  }
}
int main(){
  int a;
  pq mx_pq;
  int n;
  cin>>n;
  while(n--){
    cin>>a;
    cout<<" inserting value "<<a<<endl;
    mx_pq.insert(a);
  }
  mx_pq.pop();
 cout<<" the top value returned is"<<mx_pq.top()<<endl;
  mx_pq.pop();
  cout<<" the top value returned is"<<mx_pq.top()<<endl;

  return 0;
}

