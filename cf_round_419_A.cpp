#include <bits/stdc++.h>
using namespace std;

int h1,h2,m1,m2;
int res=0;

 void dfs(int h, int m)
 {
  int t2=h%10;
  int t1= h/10;
  int t4=m%10;
  int t3=m/10;
  if(t1==t4 && t2==t3)
  	return ;
  else
  {
    if(m==59 && h==23)
    {
    	m=0;
    	h=0;
    	res=res+1;
    	dfs(h,m );
    }
    else if(m==59)
    {    m=0;
    	res=res+1;
    	dfs(h+1,m);

    }
    else
    {
    	res=res+1;
    	dfs(h,m+1);
    }

  }

 }
int main()
{
char h1,h2,d1,m1,m2;
cin>>h1>>h2>>d1>>m1>>m2;
int h= (((int)(h1)-48)*10)+((int)h2-48);
int m= (((int)(m1)-48)*10)+((int)m2-48);
 dfs(h,m);

cout<<res<<endl;

	return 0;
}