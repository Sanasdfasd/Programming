#include <bits/stdc++.h>
using namespace std;
int k;
string s;
int arr[10000005];

int lower_bound( int i)
{
 int res=-1;
 int low=i, hi=s.size()-1;
 while(low<=hi)
 {
 	int mid=(low+hi)/2;
 	//cout<<" the lower bound is "<< low<<"   "<<hi<<"  "<<mid<<endl;
   if((arr[mid]-arr[i-1])==k)
   {
   	res=mid;
   	low=mid+1;
   }
   else if((arr[mid]-arr[i-1])<k )
    low=mid+1;
   else
   	hi=mid-1;
 }

 return res;
}
int upper_bound( int i)
{
 int res=-1;
 int low=i, hi=s.size()-1;
 while(low<=hi)
 {
 		int mid=(low+hi)/2;
 //	cout<<" the upper bound is "<< low<<"   "<<hi<<"  "<<mid<<endl;
   if((arr[mid]-arr[i-1])==k)
   {
   	res=mid;
   	hi=mid-1;
   }
   else if((arr[mid]-arr[i-1])<k )
    low=mid+1;
   else
   	hi=mid-1;
 }

return res;
}


int main()
{

cin>>k>>s;

arr[0]=s[0]-48;
//cout<<arr[0]<<endl;
int i;
for(i=1;i<s.size();i++)
{
  arr[i]=arr[i-1]+(s[i]-48);
}
long long int res=0;

for(i=0;i<s.size();i++)
{
  //cout<<" the iteration is   "<<i<<endl;
    int val1= upper_bound(i);
    int val2= lower_bound(i);
  //  cout<<"val 1 is "<<val1<<"   "<<val2<<endl;
  if((val1!=-1) && (val2!=-1))
     res=res+(val2-val1+1);    

}


cout<<res<<endl;

	return 0;
}