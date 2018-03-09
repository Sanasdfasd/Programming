//
// Created by A, Sandeep on 3/6/18.
//
#include <bits/stdc++.h>
using namespace std;
int visit[100005][2]={};
vector<int> adj[100005];
bool draw= false;
int par[100005][2]={};
bool win= false;
int lastVertex=-1;
int tempVisit[100005]={};
int completed[100005]={};

void dfs(int v,int player){
    int outCount=0;
    for(int ver:adj[v]){
        outCount++;
        if(!completed[ver]&& !tempVisit[ver]) tempVisit[ver]=1;
        else if(tempVisit[ver] && !completed[ver]) draw=true;
        if(!visit[ver][player^1] && !win){
            visit[ver][player^1]=1;
            par[ver][(player^1)]=v;
            dfs(ver,(player^1));
        }
    }
    if((outCount==0) && (player==1) && (!win)){
        win= true;
        lastVertex=v;
    }
    completed[v]=1;
}

int main(){
    int n,m;
    cin>>n>>m;
    int t,a;
    for (int i = 0; i <n ; ++i) {
        cin>>t;
        for (int j = 0; j < t; ++j) {
            cin>>a;
            adj[i+1].push_back(a);
        }
    }
    cin>>t;
    visit[t][0]=1;
    par[t][0]=-1;
    tempVisit[t]=1;
    dfs(t,0);
    if(win){
        vector<int> vls;
        int prev=1;
        int val=par[lastVertex][prev];
        vls.push_back(lastVertex);
        while(val!=-1){
            vls.push_back(val);
            prev=(prev^1);
            val=par[val][prev];
        }
        reverse(vls.begin(),vls.end());
        cout<<"Win"<<endl;
        for (int i = 0; i <vls.size() ; ++i)
            cout<<vls[i]<<" ";
    }
    else if(draw)
        cout<<"Draw"<<endl;
    else
        cout<<"Lose"<<endl;



    return 0;
}