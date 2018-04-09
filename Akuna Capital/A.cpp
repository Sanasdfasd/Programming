#include <bits/stdc++.h>
using namespace std;

bool is_3d_array_size(int a_size) {
  if(a_size<8)
    return false;
   bool is_prime[10000000];
  memset(is_prime,true, sizeof(is_prime));
  int cnt=0;
  vector<int> factors;
  for (long long int i = 2L; (i*i) <=a_size ; ++i) {
    if(is_prime[i]== true) {
      if((a_size%i)==0) factors.push_back(i);
      for (long long int j = i * 2L; j <= a_size; j = j + i) {
        is_prime[j] = false;
      }
    }
  }
 if(factors.size()>=3) return true;
 else if(factors.size()==1){
   long long int value= factors[0]*(factors[0])*(factors[0]);
   if(value==a_size) return true;
   else
     return false;
 }
  else if(factors.size()==2){
   long long int value1=factors[0]*(factors[0])*(factors[1]);
   long long int value2=factors[1]*(factors[1])*(factors[0]);
   return (value1==a_size) ||(value2==a_size)
 }
  return false;
}
int main(){

  return 0;
}

