#include <iostream>
#include <cstring>
#include <memory>
#include <stdlib.h> 
#include <time.h>    

//#define sizes 5

using namespace std;
long long int dp[105][11][11][2];
long long int dp1[105][11][11][2];
long long int dps[12];

int as[14];
int as1[14];
long long int solve_min_max( int sizes)
{
	int i,j,k,l,m,sl,ire,ire1;
long long int counter=0;

   for(i=1;i<=9;i++)
  {  if(as[0]==i)
  	{
	   dp[i][0][0][1]=1;
	   break;
  	}
  	else if(i<as[0])
  	{
      dp[i][0][0][0]=1;
  	}
 }

for(i=1;i<sizes;i++)
{
  	for(k=0;k<=9;k++)
  	{
      for(l=0;l<=9;l++)
       {
        for(ire=0;ire<=10;ire++)
        {
          for(ire1=0;ire1<=10;ire1++)
          {
       	 for(sl=0;sl<2;sl++)
       	 {
       	  int val2=9;
         if(sl==1)
   	       val2=as[i];
       	for(m=0;m<=val2;m++)
       	{	
            if(dp[(k*10)+l][ire][ire1][sl]!=0)
            {
              /*if(i==3)
                cout<<"the value laughing is "<<k<<l<<m<<endl;*/
              //cout<<"the dp value that made me hereddd"<<(k*10)+l<<"when i is "<<i<<"m i s"<<m<<endl; 
              if(l<k && l<m && i!=1)
              {  
                 if(sl==1 && as[i]>m )
              	  dp1[(l*10)+m][ire+1][ire1][sl-1]=dp1[(l*10)+m][ire+1][ire1][sl-1]+dp[(k*10)+l][ire][ire1][sl];
                else
              	  dp1[(l*10)+m][ire+1][ire1][sl]=dp1[(l*10)+m][ire+1][ire1][sl]+dp[(k*10)+l][ire][ire1][sl];
              }
              else if( l>k && l>m && i!=1)
              {
                  if(sl==1 && as[i]>m)
                  dp1[(l*10)+m][ire][ire1+1][sl-1]=dp1[(l*10)+m][ire][ire1+1][sl-1]+dp[(k*10)+l][ire][ire1][sl];
                else
                  dp1[(l*10)+m][ire][ire1+1][sl]=dp1[(l*10)+m][ire][ire1+1][sl]+dp[(k*10)+l][ire][ire1][sl];
              }
              else
              {
                   if(sl==1 && as[i]>m)
                  dp1[(l*10)+m][ire][ire1][sl-1]=dp1[(l*10)+m][ire][ire1][sl-1]+dp[(k*10)+l][ire][ire1][sl];
                   else
                  dp1[(l*10)+m][ire][ire1][sl]=dp1[(l*10)+m][ire][ire1][sl]+dp[(k*10)+l][ire][ire1][sl];
              }
            }
         }
        }
        }
       }
       }
    }
 memset(dp,0,sizeof(dp));
 memcpy(dp,dp1,sizeof(dp));
 memset(dp1,0,sizeof(dp));
}
for(sl=0;sl<2;sl++)
{
 for(i=0;i<105;i++)
  {
    for(ire=0;ire<=10;ire++)
    {
      for(ire1=0;ire1<=10;ire1++)
      {
	        if(dp[i][ire][ire1][sl]!=0)
          { 
             // cout<<"the ire must be "<<ire+ire1<<endl;
		         counter=counter+((dp[i][ire][ire1][sl])*(ire+ire1));
          }
      }
    }
  }
}
//cout<<"the counter is "<<counter<<endl;

memset(dp,0,sizeof(dp));
memset(dp1,0,sizeof(dp1));
return counter;
}
int convert(long long int a)
{
  int i;
int as_temp[14];
int ss=0;
int sizes=0;
while(ss!=1)
{
   as_temp[sizes]=a%10;
   a=a/10;
   sizes=sizes+1;
   if(a==0)
     ss=1;
}
for(i=sizes-1;i>=0;i--)
{
 as[sizes-1-i]=as_temp[i];
}
  return sizes;
}
long long int add_offset(int sizes)
{
  long long int temps=0;
  int i;
  for(i=0;i<sizes-1;i++)
  {
    temps=temps+dps[i];
  }
 return temps;
}

long long int compute_min_max_sum_num(int size)
{
int i;
long long int min_sum=0,max_sum=0;
for(i=1;i<size-1;i=i+1)
{
  if(as[i]<as[i-1] && as[i]<as[i+1])
    min_sum++;
  else if(as[i]>as[i-1] && as[i]>as[i+1])
    max_sum++;
}
 return min_sum+max_sum;
}

int main()
{

int a1[14];
memset(dp,0,sizeof(dp));
memset(dp1,0,sizeof(dp1));
memset(a1,0,sizeof(a1));
memset(as,0,sizeof(as));
memset(as1,0,sizeof(as1));
memset(dps,0,sizeof(dps));
//recursive_min_digit(a,0);
//cout<<"total count is "<<count<<endl;

//memcpy(dp1,dp,sizeof(dp));
long long int a,b;
cin>>a;
cin>>b;
 int i;
 as[0]=9;
 as[1]=9;
  int sizes=2,sizes1=4;
 for(i=2;i<12;i++)
 {
   as[i]=9;
   sizes=sizes+1;
  long long int temp= solve_min_max(sizes);
 // cout<<"for the "<<i+1<<"  digits "<<temp<<endl;
  dps[i]=temp;
 }
sizes=0;
sizes1=0;
 sizes=convert(a);
 long long int val1_to=0;
 if(sizes>3)
 {
  val1_to=add_offset(sizes);
 }
 //cout<<"after the call"<<sizes<<endl;
long long int val_to=compute_min_max_sum_num(sizes);
//cout<<"the val_to is "<<val_to<<endl;

long long int val1=solve_min_max(sizes);
//cout<<"the value 1 obtained is "<<val1<<endl;
val1=val1+val1_to;
sizes1=convert(b);
//cout<<"after the call"<<sizes1<<endl;
long long int val2=0;
val2=solve_min_max(sizes1);
long long int val2_to=0;
 if(sizes1>3)
 {
  val2_to=add_offset(sizes1);
 }
 val2=val2+val2_to;
//cout<<"the value 2 obatined is "<<val2<<endl;
long long int diff=val2-val1+val_to;
cout<<diff<<endl;
//recursive_enumerate(a1,0,0);


	return 0;
}