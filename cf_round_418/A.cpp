#include <bits/stdc++.h>

using namespace std;
 
long long int gcd( long long int a,  long long int b) {
    return b == (long long int)0 ? a : gcd(b, a % b);
}
 int main()
{
int n,k;
cin>>n>>k;
int as[n+5];
vector <int> bs;
int i,j;
for(i=0;i<n;i++)
 cin>>as[i];
int a;
for(i=0;i<k;i++)
	{
		cin>>a;
		bs.push_back(a);
	}
sort(bs.begin(),bs.end());
reverse(bs.begin(),bs.end());
int tr=0;
int my_counter=0;
if(n==1 || k>=2)
{
cout<<"Yes"<<endl;
return 0;
}
for(i=0;i<n;i++)
{
   if(as[i]==0)
     as[i]=bs[0];
  if(as[i-1]>as[i] && (i!=0))
  { 
  	//cout<<" here"<<i<<endl;
  	tr=1;
  	 break;
  }
}

if(tr==0)
	cout<<"No"<<endl;
else
	cout<<"Yes"<<endl;


return 0;
}