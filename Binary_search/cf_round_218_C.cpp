#include <bits/stdc++.h>
using namespace std;
string rec;
long long int pb,ps,pc;
long long int nb,ns,nc;
long long int ru;
long long int cou_b=0,cou_s=0,cou_c=0;

long long int code_check( long long int mid)
{ long long int res=1;

long long int rub=ru;

long long int temp1= pb-(mid *(cou_b));

 if( ((temp1*nb)+rub)<0 && ((temp1*nb)<0))
 	return (long long) -1;
 else if(temp1<=0)
   rub=rub+(temp1*nb);
 
long long int temp2= ps-(mid *(cou_s));
 if( ((temp2*ns)+rub)<0 && ((temp2*ns)<0))
 	return (long long int)-1;
 else if( temp2<=0)
   rub=rub+(temp2*ns);

long long int temp3= pc-(mid *(cou_c));
 if( ((temp3*nc)+rub)<0 && ((temp3 *nc)<0))
 	return (long long int) -1;
 else if(temp3 <=0)
   rub=rub+(temp3*nc);


return rub;
}

int main()
{
cin>>rec;
cin>>pb>>ps>>pc;
cin>>nb>>ns>>nc;
cin>>ru;
int i,j;
for(i=0;i<rec.size();i++)
{
	if(rec[i]=='B')
		 cou_b++;
    if(rec[i]=='S')
    	cou_s++;
     if(rec[i]=='C')
    	cou_c++;
}

long long int low=0,hi= 1000000000000009, res=0;;

while( low<=hi)
{
   long long int mid= (low+hi)/2;
   long long int re=code_check(mid);
   if(re<((long long int)0))
    hi=mid-1;
   else
   {
    low=mid+1;
   	res=mid;
   }
}
cout<<res<<endl;


	return 0;
}



