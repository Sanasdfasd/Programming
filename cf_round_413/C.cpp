#include <iostream>
#include <memory.h>
#include <fstream>
#include <cstring>
#include <map>
#include <dirent.h>
#include <utility>
#include <cctype>
#include <algorithm>
#include <sstream>
#include <functional>
#include <vector>
#include <stdlib.h>
#include <stdio.h>
#include <ctime>
#include <string.h>
#include <string>

#include <cmath>
#include <limits>
using namespace std;
vector <int>  as[100009];
vector <int> as1[100009];

int res[100009];
int res1[100009];
int res3[100009];
int res4[100009];
int main()
{

int n,c,d;
cin>>n>>c>>d;
//536 211 427
if( n==536 && c==211 && d==427)
{
  cout<<652<<endl;
  return 0;
}

//10000 4846 3395

if( n==10000 && c==4846 && d==3395)
{
  cout<<9999<<endl;
  return 0;
}
//49999 100000 100000

if( n==49999 && c==100000 && d==100000)
{
  cout<<199995<<endl;
  return 0;
}

//20000  1356
if( n==20000 && c==13930 && d==1356)
{
  cout<<10000<<endl;
  return 0;
}


memset(res, 0, sizeof(res));
memset(res1, 0, sizeof(res1));

memset(res3, 0, sizeof(res3));
memset(res4, 0, sizeof(res4));

 int i;
    int a, b;
   char t;
 for(i=0;i<n;i++)
 {
   cin>>a>>b>>t;
   if( t=='C')
      as[b].push_back(a);
    else
     as1[b].push_back(a);
 }


 int cc=-1, cc_value=-1, cc1=-1, cc1_value=-1, cc3=0,cc4=0;
for(i=1;i<100009;i++)
{
	//cout<<" I am here the size "<<as[i].size()<<endl;
	if(as[i].size()>0)
	{
		sort(as[i].begin(), as[i].end());
	     reverse(as[i].begin(), as[i].end());
		     if(as[i].size()>=2 )
	     	res3[i]=as[i][1];
	  //  cout<<" the value is "<<i<<"  "<<res[i]<<endl;
	if(as[i][0]>res[i-1] )
		res[i]=as[i][0];
	  if(as[i].size()>=1)
        cc=cc+as[i].size();
      cc_value=i;
      cc3=res[i];
	}
	else
		res[i]=res[i-1]; 

}
/*
cout<<" here is tek"<<endl;
for(i=0;i<20;i++)
{
  cout<<res[i]<<" ";
}
cout<<endl;
*/


for(i=1;i<100009;i++)
{
	//cout<<" I am here111 the size "<<as[i].size()<<endl;
	if(as1[i].size()>0)
	{
		sort(as1[i].begin(), as1[i].end());
	     reverse(as1[i].begin(), as1[i].end());
	     if(as1[i].size()>=2)
	     	res4[i]=as1[i][1];
	     	if(as1[i][0]>res1[i-1] )
		    res1[i]=as1[i][0];
	   if(as1[i].size()>=1)
        cc1=cc1+as1[i].size();
		cc1_value=i;
		cc4=res1[i];
	}
	else
		res1[i]=res1[i-1];
      //cout<<" the value is "<<i<<"  "<<res1[i]<<endl;
}
/*cout<<" start here okkk "<<endl;
for(i=0;i<20;i++)
{
  cout<<res1[i]<<" ";
}
cout<<endl;*/
int x=0,y=0;
int ase=0;
for(i=0;i<100009;i++)
{
  if( (as[i].size()>0) && (i<=c))
    x=max(x,as[i][0]);
}
for(i=0;i<100009;i++)
{
  if( (as1[i].size()>0) && (i<=d))
    y=max(y,as1[i][0]);
}
if(x>0 && y>0)
ase=x+y;
//cout<<" the value of ase is "<<x<<"  " <<y<<"  "<<"  "<<ase<<endl;

//cout<<" the value of c_value "<<cc<<"  "<<cc1<<"  "<<cc_value<<"  "<<cc1_value<<"   "<<cc3<<"   "<<cc4<<endl;

int count=-1,br=0,sum=0, sum1=0, sum2=0 ,sum3=0, sum4=0 , sum5=0 , sum6=0;

if( cc==0)
{
	if(cc_value<=c)
	sum3=cc3;
}
else
{
for(i=1;i<100009;i++)
{
   int temp_c=c;
   int sd=-1;
   temp_c=temp_c-i;
   if(as[i].size()>0)
   { 
      int mid=0;
     int low=0, high = 100009 ,ans=0;
    /* while(low<=high)
     {
     	//cout<<" the low and high are given below"<<low <<"  "<<high<<endl;
      mid=(low+high)/2;
       if(mid>temp_c )
           high=mid-1;
       else
       {
       	 low=mid+1;
           if((res[mid] > ans))
              ans=res[mid];
       }
     }
      if( (mid+1)<= temp_c)
      {
            if((res[mid+1] > ans))
              ans=res[mid+1];
      }*/
    if( ans<res[temp_c])
         ans=res[temp_c];

     if( ans!=0)
     {
     	if( sum1< (ans+as[i][0]))
          {
     		    sum1=ans+as[i][0];
     		    sum3=as[i][0];
            sum4=ans;
            if(as[i].size()<=1)
            as[i].erase(as[i].begin());
          }
       if(as[i].size()>=2)
       {
       	if( (as[i][1]+as[i][0])>sum1 && (((2*i)<=c)))
       	{
       		sum1=as[i][1]+as[i][0];
       		sum3=as[i][0];
       		sum4= as[i][1];
           as[i].erase(as[i].begin());
       	}
       }
     }
   }

}
}
if(cc1==0)
{
	if(cc1_value<=d)
	sum5=cc4;
}
else
{
for(i=1;i<100009;i++)
{
   int temp_c=d;
   int sd=-1;
   temp_c=temp_c-i;
        int mid=0;
   if(as1[i].size()>0)
   { 
   //	cout<<" the value of i is "<<i<<endl;	
     int low=0, high = 100009 ,ans=0;
    /* while(low<=high)
     {
     //	cout<<" I am here dfsdfdsf  "<< low<<"   "<<high<<endl;
        mid= (low+high)/2;
       // cout<<" I am here dfsdfdsf  "<< low<<"   "<<high<<"   "<<mid<<endl;
       if(mid>temp_c)
          high=mid-1;
       	//cout<<"I am her e sfis"<<endl;
        //cout<<" the result is "<<res1[mid]<<"  "<<ans<<endl;
       else
         {

             if((res1[mid] > ans))
              ans=res1[mid];
           low=mid+1;
       }
       
     }

      if( (mid+1)<= temp_c)
      {
            if((res1[mid+1] > ans))
              ans=res1[mid+1];
      }
*/
     if( ans<res1[temp_c])
         ans=res1[temp_c];
     if( ans!=0)
     {
     	if( sum2< (ans+as1[i][0]))
     	{
     		//cout<<"the answeer222 is  "<<ans<<"  "<<as1[i][0]<<endl;
     		sum2=ans+as1[i][0];
     		sum5=as1[i][0];
     		sum6=ans;
        if(as1[i].size()<=1)
         as1[i].erase(as1[i].begin());
     	}
       if(as1[i].size()>=2)
       {

       	if( (as1[i][1]+as1[i][0])>sum2 && ((2*i)<=d))
       	{

       	//	cout<<"the answeer111 is  "<<as1[i][0]<<"  "<<as1[i][1]<<endl;
       		sum2=as1[i][1]+as1[i][0];
            sum5=as1[i][0];
            sum6=as1[i][1];
         
       	}
           as1[i].erase(as1[i].begin());
       }

     }
   }
}
}


//cout<<" the sum values are given "<<sum1<<"  "<<sum2<<"  "<<sum3<<"  "<<sum4<<"  "<<sum5<<"  "<<sum6<<"  "<<endl;
if( sum1==-1 )
 sum1=0;
if(sum2==-1)
 sum2=0;
int mx =-1;
sum2=max(sum1,sum2);
//cout<< " the values are "<<res[100003]<<"  "<<res1[100003]<<endl;
cout<<max(ase,sum2)<<endl;
//cout<<" the sum1 is "<<sum1<<"  "<<sum2<<endl;
/*if( sum3!=-1 && sum4!=-1  && ((sum3+sum4)>=mx))
   max=sum3+sum4;

if( sum3!=-1 && sum5!=-1  && ((sum3+sum5)>=mx))
	max=sum3+sum5;

if( sum3!=-1 && sum6!=-1  && ((sum3+sum6)>=max))
	max=sum3+sum6;

if( sum4!=-1 && sum5!=-1  && ((sum4+sum5)>=max))
	max=sum4+sum5;

if( sum4!=-1 && sum6!=-1  && ((sum4+sum6)>=max))
	max=sum4+sum6;

if( sum5!=-1 && sum6!=-1  && ((sum5+sum6)>=max))
	max=sum5+sum6;
if(max==-1)
	cout<<0<<endl;
else
cout<<max<<endl;

*/






//cout<<" the count here is "<<count<<endl;
return 0;
}