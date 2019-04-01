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
class dist {
 public:
  bool operator()( const Time& t1, const Time& t2) const
  {
    //cout<<" the times are"<<t1.h<<" "<<t1.m<<" "<<t2.h<<" "<<t2.m<<endl;
    int tt_time= 24*60;
    int org_min= org.h*60+org.m;
    int t1_min=((t1.h*60+t1.m)-org_min+tt_time)%tt_time;
    int t2_min=((t2.h*60+t2.m)-org_min+tt_time)%tt_time;
    //cout<<" the t1_min"<<t1_min<<" "<<t2_min<<endl;
    return  (t1_min>t2_min);
  }
};

int main()
{
 // std::priority_queue<int, std::vector<int>, decltype(cmp)> q3(cmp);
  priority_queue<Time,vector<Time>, dist> pq;
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

  Time t[300];
  cnt=0;
  for (int i = 0; i <4 ; ++i) {
    for(int j=0;j<4;j++){
      for (int k = 0; k <4 ; ++k) {
        for (int l = 0; l <4 ; ++l) {
          t[cnt].h=ar[i]*10+ar[j];
          t[cnt].m = ar[k]*10+ar[l];
          if(t[cnt].h==org.h && t[cnt].m==org.m) continue;
          if(t[cnt].h<=23 && t[cnt].m<=59 )
            pq.push(t[cnt]);
              cnt++;
        }
      }
    }
  }
    Time v= pq.top();
    //Time v = *it;
    cout << setw(3) << v.h << " " << setw(3) << v.m << " " << endl;
  return 0;
}

