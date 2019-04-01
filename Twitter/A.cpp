//
// Created by Sandeep on 8/4/2018.
//
#include <bits/stdc++.h>
using namespace std;
string decode(string encoded) {
  string res;
  reverse(encoded.begin(), encoded.end());
  int counter = 0;
  while (counter < encoded.size()) {
    if (encoded[counter] == '1') {
      int val = (encoded[counter] - '0') * 100 + (encoded[counter + 1] - '0') * 10 + encoded[counter+2] - '0';
      res+=char(val);
      counter+=3;
    }
    else{
      int val =(encoded[counter] - '0') * 10 + encoded[counter+1] - '0';
      res+=char(val);
      counter+=2;
    }
  }
  return res;
}

int main(){
  string s;
  cin>>s;
  string res=decode(s);
  cout<<res<<endl;

  return 0;
}
