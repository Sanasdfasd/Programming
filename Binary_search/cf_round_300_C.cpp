#include <bits/stdc++.h>
using namespace std;

int main()
{
  long long int  n,m;
vector< pair < long long int , long long int > > vs;
cin>>n>>m;
int i,j,a,b;
vs.push_back(make_pair(0,0));
for(i=0;i<m;i++)
{
	cin>>a>>b;
	vs.push_back(make_pair( a , b));
}

long long int mx=0;
int br=0;
for(i=1;i<=m;i++)
{
 mx =max(mx, vs[i].second);
 if(i==1)
 	continue;
 if((vs[i].second) == (vs[i-1].second))
 {
    long long int days= (vs[i].first)-(vs[i-1].first)-1;
    days= (vs[i].second)+((days+1)/((long long int )2));
    mx=max(mx,days);
 }
 else
 {
     long long int diff= abs(vs[i].second-(vs[i-1].second));
     long long int diff1= vs[i].first- (vs[i-1].first);
     if( diff >  diff1)
     {
     	br=1;
     	break;
     }
     else
     {
         long long int days= (diff1)-(diff)-1;
         days= max((vs[i].second), vs[i-1].second)+((days+1)/((long long int )2));
         mx=max(mx,days);
     }
 }

}
  

  long long int prev_s= (vs[1].second) + ((vs[1].first) -1);
  mx=max(mx, prev_s);
 long long int end_s= vs[m].second+(n-(vs[m].first));
 mx=max(mx,end_s);



if( br==1)
	cout<<"IMPOSSIBLE"<<endl;
else
 cout<<mx<<endl;

	return 0;
}