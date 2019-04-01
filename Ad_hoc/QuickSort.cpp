//
// Created by Sandeep on 12/17/2018.
//
#include<bits/stdc++.h>
using namespace std;
int retPivot(vector<int> ar){
  int temp=ar[0];
  ar[0]=ar[ar.size()-1];
  ar[ar.size()-1]=temp;
  int i=0, j=ar.size()-2;
  while(i<j){
    while( i<ar.size() && ar[i]<ar[ar.size()-1])
      i++;
    while(j>=0 && ar[j]>ar[ar.size()-1])
      j--;
    if(i<j){
      int temp
    }
  }

}

int main(){


  return 0;
}
