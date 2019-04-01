//
// Created by Sandeep on 10/17/2018.
//
#include <bits/stdc++.h>

using namespace std;
priority_queue<int>q1;
priority_queue<int, vector<int>, greater<int>> q2;
double k;
void rebalance(){
  int s1=q1.size();
  int s2=q2.size();
  int total_size=s1+s2;
  int ss1=total_size*k;
  if(s1> ss1){
    if(!q1.empty()) {
      q2.push(q1.top());
      q1.pop();
    }
  }
  if(s2>(total_size-ss1)){
    if(!q2.empty()) {
      q1.push(q2.top());
      q2.pop();
    }
  }
}
void add_numbers(int num){
  if(q1.size()==0 && q2.size()==0){
    q1.push(num);
    return;
  }
  if(num<=q1.top())
    q1.push(num);
  else
    q2.push(num);
  rebalance();
}
double cur_median(){
  double ans;
  ans=q1.top();
  return ans;
}

vector<double> runningMedian(vector<int> a) {
  vector<double> res;
  for(int i=0;i<a.size();i++){
    add_numbers(a[i]);
    double median = cur_median();
    res.push_back(median);
  }
  return res;
}


int main()
{
  int n,a;
  cin>>n>>k;
  vector<int> inp;
  for(int i=0;i<n;i++){
    cin>>a;
    inp.push_back(a);
  }
  vector<double> med= runningMedian(inp);
  cout<<"printing ans"<<endl;
  for(int i=0;i<n;i++){
    cout<<med[i]<<endl;
  }
  return 0;
}

