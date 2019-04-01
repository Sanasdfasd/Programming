#include <bits/stdc++.h>
using namespace std;
int n;
std::vector< pair < int , int > > vs;
long long int final_ans=-1000010;
int  find_value( long long int val)
{
  int i, res=1;
  for(i=0;i<n;i++)
  {
    if((vs[i].second)==1 && val <1900)
       	return (1900-val);
     if(vs[i].second ==2 && (val >1899))
     	return (1899-val);
     val =val+vs[i].first;
}
    final_ans=val;
  return res;

}

int main()
{


cin>>n;

int a,b,i,j;
long long int sumer=0;
for(i=0;i<n;i++)
  {
  	cin>>a>>b;
  	sumer=sumer+a;
  	vs.push_back( make_pair( a, b));
  }
 // cout<<sumer<<endl;

 long long int low= 0; long long int hi=0;
 long long int res=0;
 int tt=0;
if((vs[0].second)==1)
{
	low= 1900 ; hi= 1000000009;
	res=-1000010;
	tt=0;
}
else
{
	hi= 1899 ; low= -1000000009;
	res=-1000010;
	tt=1;
}

while( low<=hi)
{
 int mid= (low+hi)/2;
  int as= find_value(mid);
 //cout<<" the value of  low   "<< low<<"  "<<hi<<"   "<<mid<<"   "<<as<<endl;
  if( (as)< 0)
    hi= mid-1; 
  else if( as >=0)
  {
     res=final_ans;
     low=mid+1;
  }
}


if( res==-1000010)
	cout<<"Impossible"<<endl;
 else if((tt==0 && (sumer+(1000000009))==res))
 	cout<<"Infinity"<<endl;
 else
 	cout<<res<<endl;


	return 0;
}