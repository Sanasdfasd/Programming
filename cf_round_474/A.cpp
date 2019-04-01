//
// Created by Sandeep on 4/7/18.
//
#include <bits/stdc++.h>
using namespace std;
void yes(){
  cout<<"YES"<<endl;
  exit(0);
}
void no(){
  cout<<"NO"<<endl;
  exit(0);
}

int main(){
  string s;
  cin>>s;
  int set=-1;
  int cnt_a=0, cnt_b=0, cnt_c=0;
  for (int i = 0; i <s.size() ; ++i) {
  if(set==-1) {
    if (s[i] == 'b' || s[i] == 'c')
      no();
    set = 1;
   // cout<<" here "<<endl;
    cnt_a++;
  }
    else if(set==1){
   // cout<<" here 1"<<endl;
    if(s[i]=='c') no();
    if(s[i]=='b') {set++; cnt_b++;}
    else
    cnt_a++;
  }
  else if(set==2){
  //  cout<<" here 2"<<endl;
    if(s[i]=='a') no();
    if(s[i]=='c') {set++; cnt_c++;}
    else
    cnt_b++;
  }
    else{
    //cout<<" here 2"<<endl;
    if(s[i]=='a'|| s[i]=='b') no();
    else
    cnt_c++;
  }
  }
//  cout<<" here a fdsa"<<cnt_a<<" "<< cnt_b<<" "<<cnt_c<<endl;
  if(cnt_a==0  || cnt_b==0) no();
  if( cnt_c==cnt_a||cnt_c==cnt_b ) yes();
  else no();
  return 0;
}

