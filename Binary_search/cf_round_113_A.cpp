#include <bits/stdc++.h>
using namespace std;

vector< pair < int , int > > vs;

bool compar( pair < int , int > t_a , pair < int , int > t_b)
{
 if( t_a.first > t_b.first)
 	return true;
 else if( t_a.first==t_b.first)
 {
   if(t_a.second > t_a.second)
   	  return true ;
 }
 return false;
}

int main()
{
int n, k;
cin>>n>>k; 
int arr[n+5];
memset(arr, 1,sizeof(arr));
int a,b;
for(i=0;i<n;i++)
{
  cin>>a>>b;
  vs.push_back( make_pair( a, b ));
}
sort(vs.begin(), vs.end(),compar);

for(i=0;i<n;i++)
{
  
 




}


	return 0;
}