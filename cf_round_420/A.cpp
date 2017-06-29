#include <bits/stdc++.h>

using namespace std;
 
long long int gcd( long long int a,  long long int b) {
    return b == (long long int)0 ? a : gcd(b, a % b);
}
 int main()
{
int n;
cin>>n;
int ar[n+5][n+5];
int i,j,k,t;
for(i=0;i<n;i++)
{
  for(j=0;j<n;j++)
     cin>>ar[i][j];
}
for(i=0;i<n;i++)
{
  for(j=0;j<n;j++)
  {
    if(ar[i][j]!=1)
    {

      int found=0;
     for(k=0;k<n;k++)
     {
        for(t=0;t<n;t++)
        {
            if(k!=i  && t!=j)
            {
                 if((ar[k][j]+ar[i][t]) == ar[i][j])
                 {
                  found=1;
                  break;
                 }
            }
          
        }
        if(found==1)
          break;
      }
      if(found==0)
      {
        cout<<"No"<<endl;
        return 0;
      }
    }
  }
}

cout<<"Yes"<<endl;
return 0;
}