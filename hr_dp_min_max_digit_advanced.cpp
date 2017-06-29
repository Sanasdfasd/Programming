#include <iostream>
#include <cstring>
#include <memory>
#include <stdlib.h> 
#include <time.h>    

//#define sizes 5

using namespace std;
long long int dp[105][2];
long long int dp1[105][2];

int as[14];
int as1[14];
long long int  void solve_min_max( int sizes)
{
	int i,j,k,l,m,sl;
long long int counter=0;

   for(i=1;i<=9;i++)
  {  if(as[0]==i)
  	{
	   dp[i][1]=1;
	   //dp[i][0]=1;
	   break;
  	}
  	else if(i<as[0])
  	{
      dp[i][0]=1;
  	}
 }
for(i=1;i<sizes;i++)
{
  	for(k=0;k<=9;k++)
  	{
      for(l=0;l<=9;l++)
       {
       	for(sl=0;sl<2;sl++)
       	{
       	  int val2=9;
         if(sl==1)
   	       val2=as[i];
       	for(m=0;m<=val2;m++)
       	{	
          if(i%2==0)
          {
            if(dp[(k*10)+l][sl]!=0)
            {
              //cout<<"the dp value that made me hereddd"<<(k*10)+l<<"when i is "<<i<<"m i s"<<m<<endl; 
              if(l<m)
              { 
              	//if(i==2)
              //	cout<<"the value is statt at "<<k<<l<<m<<endl; 
                 if(sl==1 && as[i]>m)
              	dp1[(l*10)+m][sl-1]=dp1[(l*10)+m][sl-1]+dp[(k*10)+l][sl];
                else
              	dp1[(l*10)+m][sl]=dp1[(l*10)+m][sl]+dp[(k*10)+l][sl];

              	//counter++;
              }
            }
          }
          else
          {
          	 if(dp[(k*10)+l][sl]!=0)
            {

              if(l>m)
              {
              	int tst=0;
                if(sl==1 && as[i]>m)
              	dp1[(l*10)+m][sl-1]=dp1[(l*10)+m][sl-1]+dp[(k*10)+l][sl];
               else
              	dp1[(l*10)+m][sl]=dp1[(l*10)+m][sl]+dp[(k*10)+l][sl];

              	//counter++;
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
	if(dp[i][sl]!=-1)
		counter=counter+dp[i][sl];
  }
}
cout<<"the counter is "<<counter<<endl;

memset(dp,0,sizeof(dp));
memset(dp1,0,sizeof(dp1));
return counter;
}
long long int void  solve_max(int sizes)
{
	int i,j,k,l,m,sl;
long long int counter=0;

   for(i=1;i<=9;i++)
  {  if(as[0]==i)
  	{
	   dp[i][1]=1;
	   //dp[i][0]=1;
	   break;
  	}
  	else if(i<as[0])
  	{
      dp[i][0]=1;
  	}
}
for(i=1;i<sizes;i++)
{
  	for(k=0;k<=9;k++)
  	{
      for(l=0;l<=9;l++)
       {
       	for(sl=0;sl<2;sl++)
       	{
       	  int val2=9;
         if(sl==1)
   	       val2=as[i];
       	for(m=0;m<=val2;m++)
       	{	
          if(i%2==0)
          {
            if(dp[(k*10)+l][sl]!=0)
            {
              //cout<<"the dp value that made me hereddd"<<(k*10)+l<<"when i is "<<i<<"m i s"<<m<<endl; 
              if(l>m)
              { int tst=0;
              	//if(i==2)
              //	cout<<"the value is statt at "<<k<<l<<m<<endl; 
                 if(sl==1 && as[i]>m)
              	dp1[(l*10)+m][sl-1]=dp1[(l*10)+m][sl-1]+dp[(k*10)+l][sl];
                else
              	dp1[(l*10)+m][sl]=dp1[(l*10)+m][sl]+dp[(k*10)+l][sl];

              	//counter++;
              }
            }
          }
          else
          {
          	 if(dp[(k*10)+l][sl]!=0)
            {

              if(l<m)
              {
              	int tst=0;
                if(sl==1 && as[i]>m)
              	dp1[(l*10)+m][sl-1]=dp1[(l*10)+m][sl-1]+dp[(k*10)+l][sl];
               else
              	dp1[(l*10)+m][sl]=dp1[(l*10)+m][sl]+dp[(k*10)+l][sl];

              	//counter++;
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
	if(dp[i][sl]!=-1)
		counter=counter+dp[i][sl];
  }
}
cout<<"the counter is "<<counter<<endl;

memset(dp,0,sizeof(dp));
memset(dp1,0,sizeof(dp1));
return counter;
}

void recursive_enumerate(int a1[sizes],int size,int k)
{
	if(size==sizes)
	{
		cout<<"the value of"<<a1[0]<<a1[1]<<a1[2]<<endl;
		return ;
	}
	int i,val=0;
	if(size==0)
		val=1;  
   int val2=9;
   if(k==1)
   	val2=as[size];
   int prev_k=k;
  for(i=val;i<=val2;i++)
  {
  	a1[size]=i;
  	if(i==as[size] && size==0)
  		k=1;
  	if(i==as[size] && k==1)
  	{// k=1;
  	  recursive_enumerate(a1,size+1,k);
  	   break;
    }
    else

    { k=0;
     if(i==as[size])
     	k=1;
      recursive_enumerate(a1,size+1,k);
    }
  }

}

int main()
{


int a1[14];
memset(dp,0,sizeof(dp));
memset(dp1,0,sizeof(dp1));
memset(a1,0,sizeof(a1));
memset(as,0,sizeof(as));

memset(as1,0,sizeof(as1));
//recursive_min_digit(a,0);
//cout<<"total count is "<<count<<endl;

//memcpy(dp1,dp,sizeof(dp));
long long int a,b;
cin>>a;
cin>>b;
 int i;
for(i=0;i<3;i++)
{
 cin>>as[i];
}

for(i=0;i<3;i++)
{
	cin>>as[i]
}
//recursive_enumerate(a1,0,0);


	return 0;
}