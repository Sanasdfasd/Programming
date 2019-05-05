// INCLUDE HEADER FILES NEEDED BY YOUR PROGRAM
// SOME LIBRARY FUNCTIONALITY MAY BE RESTRICTED
// DEFINE ANY FUNCTION NEEDED
// FUNCTION SIGNATURE BEGINS, THIS FUNCTION IS REQUIRED

#include <bits/stdc++.h>
using namespace std;

bool compare(pair<int, int> fst, pair<int, int> sec){

  return (fst.second<=sec.second);
}


int binarySearch( int deviceCapacity, int cur_value, vector<pair<int, int>>& backgroundAppList){

  int res=-1;

  int low=0, hi=backgroundAppList.size()-1;

  while( low<=hi){
    int mid=(low+hi)/2;

    if((backgroundAppList[mid].second+cur_value) <=deviceCapacity){
      res=mid;
      low=mid+1;
    }
    else{
      hi=mid-1;
    }
  }

  return res;
}


vector<pair<int, int> > optimalUtilization(
    int deviceCapacity,
    vector<pair<int, int> > foregroundAppList,
    vector<pair<int, int> > backgroundAppList)
{
  vector<pair<int, int>> res;
  map<int, vector<pair<int, int>>, greater<int>> mp;

  sort(backgroundAppList.begin(), backgroundAppList.end(), compare);

  for(int i=0;i<foregroundAppList.size();i++){

    int cur_value= foregroundAppList[i].second;
    if(cur_value<=deviceCapacity){
      int indx= binarySearch(deviceCapacity,cur_value,backgroundAppList);
      if(indx!=-1){
        mp[cur_value+backgroundAppList[indx].second].push_back({foregroundAppList[i].first, backgroundAppList[indx].first});
      }
    }
  }

  if(!mp.empty()){
    cout<<" the first value is "<<mp.begin()->first<<endl;
    return (mp.begin()->second);
  }


  return res;
}
// FUNCTION SIGNATURE ENDS