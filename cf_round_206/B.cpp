#include <bits/stdc++.h>

using namespace std;

int main()
{
int c1,c2,c3,c4;
int n,m;
cin>>c1>>c2>>c3>>c4;
cin>>n>>m;
int as[1005],bs[1005];
int i,j,a,b;
long long int tr1=0,tr2=0;
for(i=0;i<n;i++)
{
cin>>as[i];
tr1=tr1+as[i];
}
for(i=0;i<m;i++)
{
cin>>bs[i];
tr2=tr2+bs[i];
}
sort(as,as+n);
sort(bs,bs+m);
long long int mi=c3;
long long int pre_sum=0;
for(i=0;i<n;i++)
 {
  if(as[i]!=0)
  {
  pre_sum=(pre_sum+(as[i]*c1));
  long long int vl= (n-i-1)*(c2);
  //long long int ttt=;
  //cout<<" the value of i is"<< (pre_sum+vl) <<"  "<<mi<<endl;
  mi= min((pre_sum+vl),mi);
  }
 }
 pre_sum=0;
 mi= min(mi,(long long int)(n*c2));
// cout<<" the value of mi is "<<mi<<endl;
 long long int mi1=c3;
for(i=0;i<m;i++)
 {
   if(bs[i]!=0)
   {
  pre_sum=(pre_sum+(bs[i]*c1));
  long long int vl= (m-i-1)*(c2);

   mi1= min((pre_sum+vl),mi1);
  }
 }
  mi1= min(mi1,(long long int)(m*c2));
 if( tr1==0)
   mi=0;
 if(tr2==0)
  mi1=0;
 //cout<<" the value of mi11111 is "<<mi1<<endl;
long long int final_min=0;
final_min=min((mi1+mi), (long long int) c4 );
cout<<final_min<<endl;


return 0;
}