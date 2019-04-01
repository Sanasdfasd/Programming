//
// Created by Sandeep on 3/10/2018.
//
#include <bits/stdc++.h>
using namespace std;
int visit[500+5][500+5]={};
int main(){

  int r,c,i,j;
  cin>>r>>c;
  queue<pair<int,int>> q;
  char val[r+5][c+5];

  for (int i = 0; i <r ; ++i) {
    for (int j = 0; j <c ; ++j) {
      cin>>val[i][j];
      if(val[i][j]=='.')
        val[i][j]='D';
      else if(val[i][j]=='W') {
        q.push({i, j});
        visit[i][j]=1;
      }
    }
  }
  bool ret=true;
  for (int i = 0; i <r ; ++i) {
    for (int j = 0; j <c ; ++j) {
      if(val[i][j]=='W'){
        if((i-1)>=0){
          if(val[i-1][j]=='S') ret=false;
        }
        if((i+1)<r){
          if(val[i+1][j]=='S') ret=false;
        }
        if((j+1)<c){
          if(val[i][j+1]=='S') ret=false;
        }
        if((j-1)>=0){
          if(val[i][j-1]=='S') ret=false;
        }
      }
      if(ret==false)
        break;
    }
     if(ret==false)
       break;
  }
 // cout<<"the ret valuee is "<<ret<< endl;
   if(!ret)
     cout<<"No"<<endl;
   else{
     cout<<"Yes"<<endl;
     for (int i = 0; i <r ; ++i) {
       for (int k = 0; k <c ; ++k) {
         cout<<val[i][k];
       }
       cout<<endl;
     }
   }

  return 0;
}