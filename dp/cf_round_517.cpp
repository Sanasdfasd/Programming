//
// Created by Sandeep on 4/1/2019.
//
#include <bits/stdc++.h>
using namespace std;
class node{
 public:
  int row;
  int col;
  int k_left;
  char v;
  node(int row,int col, int k_left=INT_MAX, char v){
    this->row=row;
    this->col=col;
    this->k_left=k_left;
    this->v= v;
  }
};
bool check ( int row, int col, int n){
  if(row<n && col <n)
    return true;
  return false;
}
vector< vector<node*> > vec (2007, vector<node*>(2007));
void updaterow( )
int main(){
 int n, k;
for(int i=0;i<2000;i++){
  for(int j=0;j<2000;j++) vec[i][j] = new node(-1,-1, -1,'a');
}
cin>>n;
  cin>>k;
  queue<node*> q;
  char inp[n][n];
  for(int i=0;i<n;i++){
    cin>>inp[i];
  }
  if(k>0  && inp[0][0]!='a') {
     q.push(new node(0, 0,k-1,'z'));
  }
  else{
    q.push(new node(0, 0,k,'a'));
  }
  while(!q.empty()){
    node* top= q.front();
    //look at the neighbors and
    // right and down
    int row=top->row;
    int col=top->col+1;
    if( check(row,col,n)) {
      if (top->k_left > 0 && inp[row][col]!='a'){
            if( vec[row][col]->k_left  < top->k_left-1){
              vec[row][col]->row=top->row;
              vec[row][col]->col=top->col;
              vec[row][col]->k_left=top->k_left-1;
              vec[row][col]->v='a';
              q.push(vec[row][col]);
            }
           else if(vec[row][col]->k_left  == (top->k_left-1) && ((int)vec[row][col]->v<(int)top->v )){
              vec[row][col]->row=top->row;
              vec[row][col]->col=top->col;
              vec[row][col]->k_left=top->k_left-1;
              vec[row][col]->v='a';
              q.push(vec[row][col]);
            }
      }

    }


  }



  return 0;
}



