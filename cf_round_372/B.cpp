#include <bits/stdc++.h>

using namespace std;

int ques[50005];
int ma[26];
int main()
{
	string s;
	cin>>s;
	int i,j;
	memset(ques,0,sizeof(ques));
	int br=1;
  for(i=0;i<(s.size());i++)
  {
  	if(i!=0)
  	ques[i]=ques[i]+ques[i-1];
  	if(s[i]=='?')
  		ques[i]+=1;
  }
  for(i=0;i<26;i++)
  	ma[i]=-100;
 vector <char> second_bag;
 int first_ind=0;
  for(i=0;i<s.size();i++)
  {
  	ma[s[i]-'A']=i;
      if(i>=25)
      {
      	int t;
      	int char_count=0;
      	vector<char>bag;
         for(t=0; t<26;t++)
         {
            if(!(ma[t]>=(i-25) && (ma[t]<=i)))
            {
               char_count++;
               char ss='A'+t;
               bag.push_back(ss);
            }
         }
         int ques_count=ques[i];
         if((i-25)>0)
           ques_count=ques_count-ques[i-26];
         if(char_count > ques_count)
         	bag.clear();
         else
         {
           int tt;
           first_ind=i-25;
           int vc_count=0;
           for(tt=(i-25);tt<=i;tt++)
           {
           	  if(s[tt]=='?')
           	  {
           	  	second_bag.push_back(bag[vc_count]);
           	  	vc_count++;
           	  }
           	  else
           	     second_bag.push_back(s[tt]);                 
           }
           br=0;
          break;
         }
      }
  }
if(br==0)
{
 i=0;
  while(i<s.size())
  {
  	if(i!=first_ind)
  	{
  		if(s[i]!='?')
  		cout<<s[i];
  	    else
  	    	cout<<'A';
  	}
     else
       {
       	int temp1=i-i;
       	for(temp1=0;temp1<26;temp1++)
       	{
          cout<<second_bag[temp1];
       		i=i+1;
       	}
         i=i-1;
       }
   i=i+1;   
  }
}

if(br==1)
cout<<-1<<endl;
	return 0;
}