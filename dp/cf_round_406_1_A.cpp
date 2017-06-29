#include <bits/stdc++.h>
using namespace std;

int n;
vector <int> vs[2];
int visit[7005][2];
int marked[7005][2];
int dp[7000+5][2];
int dfs(int index, int ply)
{
//cout<<"the current index  and the player"<<index<<"  "<<ply<<endl;
if(dp[index][ply]!=-1)
{
	//cout<<" the value here is "<<dp[index][ply]<<endl;
int vv=dp[index][ply];
if(vv==0)
{
return 0;
}
else
{
	return ((vv+1)%3);
}
}
if(visit[index][ply]==1)
	return 0;
visit[index][ply]=1;
 int val=0;
  int i,j;
  for(i=0;i<vs[ply].size();i++)
  {
  	//cout<<" the value is "<<ply<<endl;
  	int prev_tt=(index+vs[ply][i]);
  	int tt=prev_tt%(n+1);
  	if(prev_tt>n)
  		tt=tt+1;
  	//cout<<"the value of the tt"<<tt<<endl;
  	 int ret= dfs(tt,(ply^1));
  	
  	// cout<<" my final value is "<<index<<"  "<<ply<<"  "<<ret<<endl;
  	 val= max(val,ret);
  	 //cout<<"end of iteration "<<endl;
  }
dp[index][ply]=val;

visit[index][ply]=0;
if(val==0)
	return val;
return ((val+1)%3); 
}

int main()
{
cin>>n;
int temp;
cin>>temp;
int i,j;
memset(visit,0,sizeof(visit));
for(i=0;i<7005;i++)
{
	for(j=0;j<2;j++)
		dp[i][j]=-1;
}
for(i=0;i<temp;i++)
{ int temp1;
     cin>>temp1;
    dp[n-(temp1-1)][0]=2;
	vs[0].push_back(temp1);
}
cin>>temp;
for(i=0;i<temp;i++)
{ int temp1;
     cin>>temp1;
    dp[n-(temp1-1)][1]=2;
	vs[1].push_back(temp1);
}

for(i=2;i<=n;i++)
{
	//if(i==8)
// cout<<"my iteration number is "<<i<<"******************"<<endl;
    dfs(i,0);
    marked[i][0]=1;
    //cout<<"the value at last set is "<<dp[i][0]<<endl;
}

for(i=2;i<=n;i++)
{
    dfs(i,1);
    marked[i][1]=1;
}
for(i=2;i<=n;i++)
{
		if(dp[i][0]==0)
		 cout<<"Lose"<<" ";
		else if(dp[i][0]==1)
			cout<<"Loop"<<" ";
		else
			cout<<"Win"<<" ";
}
cout<<endl;
for(i=2;i<=n;i++)
{
		if(dp[i][1]==0)
		 cout<<"Lose"<<" ";
		else if(dp[i][1]==1)
			cout<<"Loop"<<" ";
		else
			cout<<"Win"<<" ";
}
cout<<endl;



	return 0;
}
