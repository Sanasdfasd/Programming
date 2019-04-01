//
// Created by Sandeep on 8/31/2018.
//
//
// Created by Sandeep on 8/31/2018.
//
#include <bits/stdc++.h>

using namespace std;

class Time {
 public: int h; // >= 0
 public: int m; // 0-59
};
Time org;
  bool cmp(  Time* t1, Time* t2)
  {
    //cout<<" the times are"<<t1.h<<" "<<t1.m<<" "<<t2.h<<" "<<t2.m<<endl;
    int tt_time= 24*60;
    int org_min= org.h*60+org.m;
    int t1_min=((t1->h*60+t1->m)-org_min+tt_time)%tt_time;
    int t2_min=((t2->h*60+t2->m)-org_min+tt_time)%tt_time;
    //cout<<" the t1_min"<<t1_min<<" "<<t2_min<<endl;
    return  (t1_min<t2_min);
  }


int main()
{
  // std::priority_queue<int, std::vector<int>, decltype(cmp)> q3(cmp);
  string tim;
  cin>>tim;
  istringstream tims(tim);
  string interm;
  int ar[4];
  int cnt=0;
  while(getline(tims,interm,':')){
    ar[cnt++]=interm[0]-'0';
    ar[cnt++]=interm[1]-'0';
  }

  org.h=ar[0]*10+ar[1];
  org.m=ar[2]*10+ar[3];
  Time *cur = new Time();
  Time *temp = new Time();
  for (int i = 0; i <4 ; ++i) {
    for(int j=0;j<4;j++){
      for (int k = 0; k <4 ; ++k) {
        for (int l = 0; l <4 ; ++l) {
          temp->h=ar[i]*10+ar[j];
          temp->m = ar[k]*10+ar[l];
          if(temp->h==org.h && temp->m==org.m) continue;
          if(temp->h<=23 && temp->m<=59 ) {
            if(cur==NULL) cur=temp;
            else{
              if(cmp(temp, cur)){
                cur->h =temp->h;
                cur->m =temp->m;
              }
            }
          }
        }
      }
    }
  }
  Time v= *cur;
  //Time v = *it;
  cout << setw(3) << v.h << " " << setw(3) << v.m << " " << endl;
  return 0;
}


