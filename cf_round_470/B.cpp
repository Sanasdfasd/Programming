//
// Created by Sandeep on 3/10/2018.
//
#include <bits/stdc++.h>
using namespace std;
int maxPrimeFactors(int n)
{
  // Initialize the maximum prime factor
  // variable with the lowest one
  int maxPrime = -1;

  // Print the number of 2s that divide n
  while (n % 2 == 0) {
    maxPrime = 2;
    n >>= 1; // equivalent to n /= 2
  }

  // n must be odd at this point, thus skip
  // the even numbers and iterate only for
  // odd integers
  for (int i = 3; i <= sqrt(n); i += 2) {
    while (n % i == 0) {
      maxPrime = i;
      n = n / i;
    }
  }

  // This condition is to handle the case
  // when n is a prime number greater than 2
  if (n > 2)
    maxPrime = n;

  return maxPrime;
}

int main(){

int x2;
  cin>>x2;
  int l1=maxPrimeFactors(x2);
    int mx=x2;
    for(int i=(x2-l1+1);i<=x2;i++){
      int t1=maxPrimeFactors(i);
      if(t1==i){
        mx=min(mx,t1);
        continue;
      }
      mx= min(mx,(i-t1)+1);
    }
    cout<<mx<<endl;

  return 0;
}
