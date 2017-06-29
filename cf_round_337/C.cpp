#include <bits/stdc++.h>

using namespace std;

int prevs[512][512], ar[512][512];

void fn_create( int n)
{
  int i,j;
  int po= pow(2,n);
for(i=0;i<po;i++)
{
  for(j=0;j<po;j++)
  {
    if(i<(po/2))
    {
      int po1=pow(2,n-1);
      ar[i][j]=prevs[i%po1][j%po1];
    }
    else
    {

      int hl=((po/2));
      if(j>=(po/2))
        ar[i][j]=-ar[i-hl][j];  
      else
        ar[i][j]=ar[i-hl][j];
    }
  }
}
for(i=0;i<po;i++)
{
  for(j=0;j<po;j++)
  {
    prevs[i][j]=ar[i][j];
  }
}

}

int main()
{
long long int k;
cin>>k;
prevs[0][0]=1;
int i,j;
for(i=1;i<=k;i++)
fn_create(i);
int po=pow(2,k);

for(i=0;i<po;i++)
{
  for(j=0;j<po;j++)
  {
     if(prevs[i][j]==1)
       cout<<"+";
     else
      cout<<"*";
  }
  cout<<endl;
}

return 0;
}