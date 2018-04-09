//
// Created by Sandeep on 3/24/18.
//
#include <bits/stdc++.h>
using namespace std;
int n,m;
char ms[55][55];

int main(){
  cin>>n>>m;
  for (int i = 0; i <n ; ++i)
    for (int j = 0; j <m ; ++j)
      cin>>ms[i][j];
  for (int i = 0; i <n ; ++i) {
    vector<int> rows;
    for (int j = 0; j <m ; ++j) {
      if(ms[i][j]=='#'){
        for (int k = 0; k <n; ++k) {
          if(ms[k][j]=='#')
           rows.push_back(k);
        }
      }
    }
    for (int l = 0; l <rows.size() ; ++l) {
      for (int j = 0; j <m ; ++j) {
        if(ms[i][j]!=ms[rows[l]][j]){
          cout<<"No"<<endl;
          return 0;
        }
      }
    }
  }

cout<<"Yes"<<endl;
  return 0;
}

