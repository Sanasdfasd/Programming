#include <bits/stdc++.h>

using namespace std;

long long int n;
double limit1, limit2;
std::vector< pair < double  , double > > vs;


double check( double mid)
{
std::vector < double > val;
  double res=0;  
  int i;
  double vss=0;
  for(i=0;i<n;i++)
  {

    double ss= ((vs[i].first) * mid) + vs[i].second;
    vss=vss+ss;
    if ( std::find(val.begin(), val.end(),ss) != val.end() )
    {
        return (double) 0;
    }
    else
    {
   	 val.push_back(ss);
    }
  }
//cout<< " teh value of vs is "<<vss<<endl;
return vss;
}





int main()
{
cin>>n;
cin>>limit1>>limit2;
int a,b,i;
for(i=0;i<n;i++)
{
	cin>>a>>b;
	vs.push_back(make_pair( a, b));
}
sort(vs.begin(), vs.end());

double low=limit1+0.0000000000001 , hi= limit2-0.0000000000001; 
double res=-1;
while(low<=hi)
{

   double mid= (low+hi)/ (double)2;
   cout<<" the low value "<<low<<"  "<<hi<<"  "<<mid<<"  "<<check(mid)<<endl;
   if( check(mid)== (double)0 && mid>limit1 && mid<limit2)
   {
   	//cout<< " the value of mid is"<< mid<<endl;
   	 cout<<"YES"<<endl;
   	 return 0;
   }
   else
   {
      if( check(mid)> (double )0)
        hi=mid-0.0000000000001;
      else
      	low=mid+0.0000000000001;
   }

}
	cout<<"NO"<<endl;



return 0;
}